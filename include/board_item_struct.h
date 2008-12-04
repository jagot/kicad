/**********************************************************************************************/
/*  board_item_struct.h :  Classes BOARD_ITEM and BOARD_CONNECTED_ITEM                        */
/**********************************************************************************************/

#ifndef BOARD_ITEM_STRUCT_H
#define BOARD_ITEM_STRUCT_H


#include <boost/ptr_container/ptr_vector.hpp>


/* Shapes for segments (graphic segments and tracks) ( .shape member ) */
enum Track_Shapes {
    S_SEGMENT = 0,      /* usual segment : line with rounded ends */
    S_RECT,             /* segment with non rounded ends */
    S_ARC,              /* Arcs (with rounded ends)*/
    S_CIRCLE,           /* ring*/
    S_ARC_RECT,         /* Arcs (with non rounded ends) (GERBER)*/
    S_SPOT_OVALE,       /* Oblong spot (for GERBER)*/
    S_SPOT_CIRCLE,      /* rounded spot (for GERBER)*/
    S_SPOT_RECT,        /* Rectangular spott (for GERBER)*/
    S_POLYGON           /* polygonal shape */
};


/**
 * Class BOARD_ITEM
 * is a base class for any item which can be embedded within the BOARD
 * container class, and therefore instances of derived classes should only be
 * found in PCBNEW or other programs that use class BOARD and its contents.
 * The corresponding class in EESCHEMA is SCH_ITEM.
 */
class BOARD_ITEM : public EDA_BaseStruct
{
protected:
    int m_Layer;

public:

    BOARD_ITEM( BOARD_ITEM* aParent, KICAD_T idtype ) :
        EDA_BaseStruct( aParent, idtype )
        , m_Layer( 0 )
    {
    }


    BOARD_ITEM( const BOARD_ITEM& src ) :
        EDA_BaseStruct( src.m_Parent, src.Type() )
        , m_Layer( src.m_Layer )
    {
        m_Flags = src.m_Flags;
    }


    /**
     * A value of wxPoint(0,0) which can be passed to the Draw() functions.
     */
    static wxPoint  ZeroOffset;

    BOARD_ITEM* Next() const { return (BOARD_ITEM*) Pnext; }
    BOARD_ITEM* Back() const { return (BOARD_ITEM*) Pback; }
    BOARD_ITEM* GetParent() const { return (BOARD_ITEM*) m_Parent; }

    /**
     * Function GetPosition
     * returns the position of this object.
     * @return wxPoint& - The position of this object, non-const so it
     *          can be changed
     */
    virtual wxPoint& GetPosition() = 0;

    /**
     * Function GetLayer
     * returns the layer this item is on.
     */
    int GetLayer() const { return m_Layer; }

    /**
     * Function SetLayer
     * sets the layer this item is on.
     * @param aLayer The layer number.
     */
    void  SetLayer( int aLayer )  { m_Layer = aLayer; }


    /**
     * Function Draw
     * BOARD_ITEMs have their own color information.
     */
    virtual void Draw( WinEDA_DrawPanel* panel, wxDC* DC,
                      int aDrawMode, const wxPoint& offset = ZeroOffset ) = 0;


    /**
     * Function IsOnLayer
     * tests to see if this object is on the given layer.  Is virtual so
     * objects like D_PAD, which reside on multiple layers can do their own
     * form of testing.
     * @param aLayer The layer to test for.
     * @return bool - true if on given layer, else false.
     */
    virtual bool IsOnLayer( int aLayer ) const
    {
        return m_Layer == aLayer;
    }


    /**
     * Function IsLocked
     * @return bool - true if the object is locked, else false
     */
    virtual bool IsLocked() const
    {
        return false;   // only MODULEs can be locked at this time.
    }


    /**
     * Function UnLink
     * detaches this object from its owner.  This base class implementation
     * should work for all derived classes which are held in a DLIST<>.
     */
    virtual void UnLink();


    /**
     * Function DeleteStructure
     * deletes this object after UnLink()ing it from its owner.
     */
    void DeleteStructure()
    {
        UnLink();
        delete this;
    }


    /**
     * Function MenuText
     * returns the text to use in any menu type UI control which must uniquely
     * identify this item.
     * @param aBoard The PCB in which this item resides, needed for Net lookup.
     * @return wxString
     * @todo: maybe: make this virtual and split into each derived class
     */
    wxString        MenuText( const BOARD* aBoard ) const;


    /**
     * Function MenuIcon
     * @return const char** - The XPM to use in any UI control which can help
     *  identify this item.
     * @todo: make this virtual and split into each derived class
     */
    const char**    MenuIcon() const;


    /**
     * Function ShowShape
     * converts the enum Track_Shapes integer value to a wxString.
     */
    static wxString ShowShape( Track_Shapes aShape );


    /**
     * Function Save
     * writes the data structures for this object out to a FILE in "*.brd" format.
     * @param aFile The FILE to write to.
     * @return bool - true if success writing else false.
     */
    virtual bool    Save( FILE* aFile ) const = 0;
};


/**
 * Class BOARD_CONNECTED_ITEM
 * This is a base class derived from BOARD_ITEM for items that can be connected
 * mainly: tracks and pads
 * Handle connection info
 */
class BOARD_CONNECTED_ITEM : public BOARD_ITEM
{
protected:
    int         m_NetCode;          // Net number

    int         m_Subnet;           /* In rastnest routines : for the current net,
                                     *  block number (number common to the current connected items found)
                                     */

    int         m_ZoneSubnet;   	   // variable used in rastnest computations : for the current net,
                                    // handle block number in zone connection

public:
    BOARD_CONNECTED_ITEM( BOARD_ITEM* aParent, KICAD_T idtype );
    BOARD_CONNECTED_ITEM( const BOARD_CONNECTED_ITEM& src );

    /**
     * Function GetNet
     * @return int - the net code.
     */
    int GetNet() const;
    void SetNet( int aNetCode );

    /**
     * Function GetSubNet
     * @return int - the sub net code.
     */
    int GetSubNet() const;
    void SetSubNet( int aSubNetCode );

    /**
     * Function GetZoneSubNet
     * @return int - the sub net code in zone connections.
     */
    int GetZoneSubNet() const;
    void SetZoneSubNet( int aSubNetCode );
};


class BOARD_ITEM_LIST : public BOARD_ITEM
{
    typedef boost::ptr_vector<BOARD_ITEM>   ITEM_ARRAY;

    ITEM_ARRAY   myItems;

    BOARD_ITEM_LIST( const BOARD_ITEM_LIST& other ) :
        BOARD_ITEM( NULL, TYPE_BOARD_ITEM_LIST )
    {
        // copy constructor is not supported, is private to cause compiler error
    }

public:

    BOARD_ITEM_LIST( BOARD_ITEM* aParent = NULL ) :
        BOARD_ITEM( aParent, TYPE_BOARD_ITEM_LIST )
    {}

    //-----< satisfy some virtual functions >------------------------------
    wxPoint& GetPosition()
    {
        static wxPoint dummy;
        return dummy;
    }

    void Draw( WinEDA_DrawPanel* DrawPanel, wxDC* DC,
               int aDrawMode, const wxPoint& offset = ZeroOffset )
    {
    }

    void UnLink()
    {
        /* if it were needed:
        DHEAD* list = GetList();

        wxASSERT( list );

        list->remove( this );
        */
    }

    bool Save( FILE* aFile ) const
    {
        return true;
    }

    //-----</ satisfy some virtual functions >-----------------------------


    /**
     * Function GetCount
     * returns the number of BOARD_ITEMs.
     */
    int GetCount() const
    {
        return myItems.size();
    }

    void    Append( BOARD_ITEM* aItem )
    {
        myItems.push_back( aItem );
    }

    BOARD_ITEM*   Replace( int aIndex, BOARD_ITEM* aItem )
    {
        ITEM_ARRAY::auto_type ret = myItems.replace( aIndex, aItem );
        return ret.release();
    }

    BOARD_ITEM*   Remove( int aIndex )
    {
        ITEM_ARRAY::auto_type ret = myItems.release( myItems.begin()+aIndex );
        return ret.release();
    }

    void    Insert( int aIndex, BOARD_ITEM* aItem )
    {
        myItems.insert( myItems.begin()+aIndex, aItem );
    }

    BOARD_ITEM*   At( int aIndex ) const
    {
        // we have varying sized objects and are using polymorphism, so we
        // must return a pointer not a reference.
        return (BOARD_ITEM*) &myItems[aIndex];
    }

    BOARD_ITEM* operator[]( int aIndex ) const
    {
        return At( aIndex );
    }

    void    Delete( int aIndex )
    {
        myItems.erase( myItems.begin()+aIndex );
    }

    void PushBack( BOARD_ITEM* aItem )
    {
        Append( aItem );
    }

    BOARD_ITEM* PopBack()
    {
        if( GetCount() )
            return Remove( GetCount()-1 );
        return NULL;
    }
};


#endif /* BOARD_ITEM_STRUCT_H */

