/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2015 Cirilo Bernardo <cirilo.bernardo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */


#include <set>
#include <map>
#include <utility>
#include <iterator>
#include <cctype>
#include <iostream>
#include <algorithm>

#include "vrml2_node.h"
#include "vrml2_helpers.h"


static std::set< std::string > badNames;

typedef std::pair< std::string, WRL2NODES > NODEITEM;
typedef std::map< std::string, WRL2NODES > NODEMAP;
static NODEMAP nodenames;


WRL2NODE::WRL2NODE()
{
    m_Parent = NULL;
    m_Type = WRL2_END;

    if( badNames.empty() )
    {
        badNames.insert( "DEF" );
        badNames.insert( "EXTERNPROTO" );
        badNames.insert( "FALSE" );
        badNames.insert( "IS" );
        badNames.insert( "NULL" );
        badNames.insert( "PROTO" );
        badNames.insert( "ROUTE" );
        badNames.insert( "TO" );
        badNames.insert( "TRUE" );
        badNames.insert( "USE" );
        badNames.insert( "eventIn" );
        badNames.insert( "eventOut" );
        badNames.insert( "exposedField" );
        badNames.insert( "field" );
    }

    if( nodenames.empty() )
    {
        nodenames.insert( NODEITEM( "Anchor", WRL2_ANCHOR ) );
        nodenames.insert( NODEITEM( "Appearance", WRL2_APPEARANCE ) );
        nodenames.insert( NODEITEM( "Audioclip", WRL2_AUDIOCLIP ) );
        nodenames.insert( NODEITEM( "Background", WRL2_BACKGROUND ) );
        nodenames.insert( NODEITEM( "Billboard", WRL2_BILLBOARD ) );
        nodenames.insert( NODEITEM( "Box", WRL2_BOX ) );
        nodenames.insert( NODEITEM( "Collision", WRL2_COLLISION ) );
        nodenames.insert( NODEITEM( "Color", WRL2_COLOR ) );
        nodenames.insert( NODEITEM( "ColorInterpolator", WRL2_COLORINTERPOLATOR ) );
        nodenames.insert( NODEITEM( "Cone", WRL2_CONE ) );
        nodenames.insert( NODEITEM( "Coordinate", WRL2_COORDINATE ) );
        nodenames.insert( NODEITEM( "CoordinateInterpolator", WRL2_COORDINATEINTERPOLATOR ) );
        nodenames.insert( NODEITEM( "Cylinder", WRL2_CYLINDER ) );
        nodenames.insert( NODEITEM( "CylinderSensor", WRL2_CYLINDERSENSOR ) );
        nodenames.insert( NODEITEM( "DirectionalLight", WRL2_DIRECTIONALLIGHT ) );
        nodenames.insert( NODEITEM( "ElevationGrid", WRL2_ELEVATIONGRID ) );
        nodenames.insert( NODEITEM( "Extrusion", WRL2_EXTRUSION ) );
        nodenames.insert( NODEITEM( "Fog", WRL2_FOG ) );
        nodenames.insert( NODEITEM( "FontStyle", WRL2_FONTSTYLE ) );
        nodenames.insert( NODEITEM( "Group", WRL2_GROUP ) );
        nodenames.insert( NODEITEM( "ImageTexture", WRL2_IMAGETEXTURE ) );
        nodenames.insert( NODEITEM( "IndexedFaceSet", WRL2_INDEXEDFACESET ) );
        nodenames.insert( NODEITEM( "IndexedLineSet", WRL2_INDEXEDLINESET ) );
        nodenames.insert( NODEITEM( "Inline", WRL2_INLINE ) );
        nodenames.insert( NODEITEM( "LOD", WRL2_LOD ) );
        nodenames.insert( NODEITEM( "Material", WRL2_MATERIAL ) );
        nodenames.insert( NODEITEM( "MovieTexture", WRL2_MOVIETEXTURE ) );
        nodenames.insert( NODEITEM( "NavigationInfo", WRL2_NAVIGATIONINFO ) );
        nodenames.insert( NODEITEM( "Normal", WRL2_NORMAL ) );
        nodenames.insert( NODEITEM( "NormalInterpolator", WRL2_NORMALINTERPOLATOR ) );
        nodenames.insert( NODEITEM( "OrientationInterpolator", WRL2_ORIENTATIONINTERPOLATOR ) );
        nodenames.insert( NODEITEM( "PixelTexture", WRL2_PIXELTEXTURE ) );
        nodenames.insert( NODEITEM( "PlaneSensor", WRL2_PLANESENSOR ) );
        nodenames.insert( NODEITEM( "PointLight", WRL2_POINTLIGHT ) );
        nodenames.insert( NODEITEM( "PointSet", WRL2_POINTSET ) );
        nodenames.insert( NODEITEM( "PositionInterpolator", WRL2_POSITIONINTERPOLATOR ) );
        nodenames.insert( NODEITEM( "ProximitySensor", WRL2_PROXIMITYSENSOR ) );
        nodenames.insert( NODEITEM( "ScalarInterpolator", WRL2_SCALARINTERPOLATOR ) );
        nodenames.insert( NODEITEM( "Script", WRL2_SCRIPT ) );
        nodenames.insert( NODEITEM( "Shape", WRL2_SHAPE ) );
        nodenames.insert( NODEITEM( "Sound", WRL2_SOUND ) );
        nodenames.insert( NODEITEM( "Sphere", WRL2_SPHERE ) );
        nodenames.insert( NODEITEM( "SphereSensor", WRL2_SPHERESENSOR ) );
        nodenames.insert( NODEITEM( "SpotLight", WRL2_SPOTLIGHT ) );
        nodenames.insert( NODEITEM( "Switch", WRL2_SWITCH ) );
        nodenames.insert( NODEITEM( "Text", WRL2_TEXT ) );
        nodenames.insert( NODEITEM( "TextureCoordinate", WRL2_TEXTURECOORDINATE ) );
        nodenames.insert( NODEITEM( "TextureTransform", WRL2_TEXTURETRANSFORM ) );
        nodenames.insert( NODEITEM( "TimeSensor", WRL2_TIMESENSOR ) );
        nodenames.insert( NODEITEM( "TouchSensor", WRL2_TOUCHSENSOR ) );
        nodenames.insert( NODEITEM( "Transform", WRL2_TRANSFORM ) );
        nodenames.insert( NODEITEM( "ViewPoint", WRL2_VIEWPOINT ) );
        nodenames.insert( NODEITEM( "VisibilitySensor", WRL2_VISIBILITYSENSOR ) );
        nodenames.insert( NODEITEM( "WorldInfo", WRL2_WORLDINFO ) );
    }

    return;
}


WRL2NODE::~WRL2NODE()
{
    if( m_Parent )
        m_Parent->unlinkChildNode( this );

    std::list< WRL2NODE* >::iterator sBP = m_BackPointers.begin();
    std::list< WRL2NODE* >::iterator eBP = m_BackPointers.end();

    while( sBP != eBP )
    {
        (*sBP)->unlinkRefNode( this );
        ++sBP;
    }

    m_Refs.clear();
    std::list< WRL2NODE* >::iterator sC = m_Children.begin();
    std::list< WRL2NODE* >::iterator eC = m_Children.end();

    while( sC != eC )
    {
        (*sC)->SetParent( NULL );
        delete (*sC);
        ++sC;
    }

    m_Children.clear();
    return;
}


void WRL2NODE::addNodeRef( WRL2NODE* aNode )
{
    std::list< WRL2NODE* >::iterator np =
        std::find( m_BackPointers.begin(), m_BackPointers.end(), aNode );

    if( np != m_BackPointers.end() )
        return;

    m_BackPointers.push_back( aNode );

    return;
}


void WRL2NODE::delNodeRef( WRL2NODE* aNode )
{
    std::list< WRL2NODE* >::iterator np =
        std::find( m_BackPointers.begin(), m_BackPointers.end(), aNode );

    if( np != m_BackPointers.end() )
    {
        m_BackPointers.erase( np );
        return;
    }

    #ifdef DEBUG
    std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
    std::cerr << " * [BUG] delNodeRef() did not find its target\n";
    #endif

    return;
}


WRL2NODES WRL2NODE::GetNodeType( void ) const
{
    return m_Type;
}


WRL2NODE* WRL2NODE::GetParent( void )
{
    return m_Parent;
}


std::string WRL2NODE::GetName( void )
{
    return m_Name;
}


bool WRL2NODE::SetName( const std::string& aName )
{
    std::set< std::string >::iterator item = badNames.find( aName );

    if( item != badNames.end() )
    {
        #ifdef DEBUG
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << " * [INFO] invalid node name '" << *item << "' (matches restricted word)\n";
        #endif
        return false;
    }


    if( isdigit( aName[0] ) )
    {
        #ifdef DEBUG
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << " * [INFO] invalid node name '" << *item << "' (begins with digit)\n";
        #endif
        return false;
    }

    #define BAD_CHARS1 "\"\'#+,-.\\[]{}\x00\x01\x02\x03\x04\x05\x06\x09\x0A\x0B\x0C\x0D\x0E\x0F"
    #define BAD_CHARS2 "\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F"

    if( std::string::npos != aName.find_first_of( BAD_CHARS1 )
        || std::string::npos != aName.find_first_of( BAD_CHARS2 ) )
    {
        #ifdef DEBUG
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << " * [INFO] invalid node name '" << *item;
        std::cerr<< "' (contains invalid character)\n";
        #endif
        return false;
    }

    m_Name = aName;

    return true;
}


const char* WRL2NODE::GetNodeTypeName( WRL2NODES aNodeType ) const
{
    if( aNodeType < WRL2_BEGIN || aNodeType >= WRL2_END )
        return NULL;

    NODEMAP::iterator it = nodenames.begin();
    advance( it, aNodeType );

    return it->first.c_str();
}


WRL2NODES WRL2NODE::getNodeTypeID( const std::string aNodeName )
{
    NODEMAP::iterator it = nodenames.find( aNodeName );

    if( nodenames.end() != it )
        return it->second;

    return WRL2_INVALID;
}


std::string WRL2NODE::GetError( void )
{
    return m_error;
}


WRL2NODE* WRL2NODE::FindNode( const std::string& aNodeName, const WRL2NODE *aCaller )
{
    if( aNodeName.empty() )
        return NULL;

    if( !m_Name.compare( aNodeName ) )
        return this;

    FIND_NODE( aNodeName, m_Children, this );

    return NULL;
}


bool WRL2NODE::SetParent( WRL2NODE* aParent )
{
    if( aParent == m_Parent )
        return true;

    if( NULL != m_Parent )
        m_Parent->unlinkChildNode( this );

    m_Parent = aParent;

    if( NULL != m_Parent )
        m_Parent->AddChildNode( this );

    return true;
}


bool WRL2NODE::AddChildNode( WRL2NODE* aNode )
{
    if( aNode->GetNodeType() == WRL2_BASE )
    {
        #ifdef DEBUG
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << " * [BUG] attempting to add a base node to another node\n";
        #endif
        return false;
    }

    std::list< WRL2NODE* >::iterator sC = m_Children.begin();
    std::list< WRL2NODE* >::iterator eC = m_Children.end();

    while( sC != eC )
    {
        if( *sC == aNode )
            return false;
    }

    aNode->SetParent( this );
    m_Children.push_back( aNode );

    return true;
}


bool WRL2NODE::AddRefNode( WRL2NODE* aNode )
{
    if( NULL == aNode )
    {
        #ifdef DEBUG
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << " * [BUG] NULL passed as node pointer\n";
        #endif
        return false;
    }

    if( aNode->GetNodeType() == WRL2_BASE )
    {
        #ifdef DEBUG
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << " * [BUG] attempting to add a base node ref to another base node\n";
        #endif
        return false;
    }

    std::list< WRL2NODE* >::iterator sR = m_Refs.begin();
    std::list< WRL2NODE* >::iterator eR = m_Refs.end();

    while( sR != eR )
    {
        if( *sR == aNode )
            return false;
    }

    m_Refs.push_back( aNode );

    return true;
}
