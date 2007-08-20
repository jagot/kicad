/*******************************************************************/
/*	class_track.h: definition des structures de donnees type track */
/*******************************************************************/

#ifndef CLASS_TRACK_H
#define CLASS_TRACK_H

#include "base_struct.h"

/* Type des Vias (shape)*/

/* Forme des Vias ( parametre .shape ) */
#define VIA_NORMALE     3           /* type via : traversante (throught via) */
#define VIA_ENTERREE    2           /* type via : enterree ou aveugle (blind via) */
#define VIA_BORGNE      1           /* type via : borgne ou demi-traversante (buried via) */
#define VIA_NOT_DEFINED 0           /* reserved */
#define SQUARE_VIA      0x80000000  /* Flag pour forme carree */


/***/

class TRACK : public EDA_BaseLineStruct
{
public:
    int             m_Shape;        // vias: shape and type, Track = shape..
    int             m_Drill;        // for vias: via drill (- 1 for default value)
    EDA_BaseStruct* start, * end;   // pointers on a connected item (pad or track)
    int             m_NetCode;      // Net number
    int             m_Sous_Netcode; /* In rastnest routines : for the current net,
                                     *  block number (number common to the current connected items found) */

    // chain = 0 indique une connexion non encore traitee
    int             m_Param;        // Auxiliary variable ( used in some computations )

public:
    TRACK( EDA_BaseStruct* StructFather, DrawStructureType idtype = TYPETRACK );
    TRACK( const TRACK& track );

    TRACK* Next( void );    // Retourne le chainage avant

    TRACK* Back( void )     // Retourne le chainage avant
    {
        return (TRACK*) Pback;
    }


    /* supprime du chainage la structure Struct */
    void    UnLink( void );

    // Read/write data
    bool    WriteTrackDescr( FILE* File );

    /* Ajoute un element a la liste */
    void    Insert( BOARD* Pcb, EDA_BaseStruct* InsertPoint );

    /* Recherche du meilleur point d'insertion */
    TRACK*  GetBestInsertPoint( BOARD* Pcb );

    /* Copie d'un Element d'une chaine de n elements */
    TRACK*  Copy( int NbSegm = 1 );

    /* Recherche du debut du net
     *  ( les elements sont classes par net_code croissant ) */
    TRACK*  GetStartNetCode( int NetCode );

    /* Recherche de la fin du net */
    TRACK*  GetEndNetCode( int NetCode );

    /* Display on screen: */
    void    Draw( WinEDA_DrawPanel* panel, wxDC* DC, int draw_mode );

    /* divers */
    int Shape( void ) { return m_Shape & 0xFF; }

    int     ReturnMaskLayer( void );
    int     IsPointOnEnds( const wxPoint& point, int min_dist = 0 );
    bool    IsNull( void ); // return TRUE if segment lenght = 0

    
    /**
     * Function Display_Infos
     * has knowledge about the frame and how and where to put status information
     * about this object into the frame's message panel.
     * Is virtual from EDA_BaseStruct.
     * @param frame A WinEDA_BasePcbFrame in which to print status information.
     */ 
    void    Display_Infos( WinEDA_DrawFrame* frame );

    
    /**
     * Function HitTest
     * tests if the given wxPoint is within the bounds of this object.
     * @param refPos A wxPoint to test
     * @return bool - true if a hit, else false
     */
    bool    HitTest( const wxPoint& refPos );

#if defined(DEBUG)
    /**
     * Function GetClass
     * returns the class name.
     * @return wxString
     */
    wxString GetClass() const
    {
        return wxT("TRACK");
    }
    
    /**
     * Function Show
     * is used to output the object tree, currently for debugging only.
     * @param nestLevel An aid to prettier tree indenting, and is the level 
     *          of nesting of this object within the overall tree.
     * @param os The ostream& to output to.
     */
    void Show( int nestLevel, std::ostream& os );
    
#endif
    
};

class SEGZONE : public TRACK
{
public:
    SEGZONE( EDA_BaseStruct* StructFather );
    
#if defined(DEBUG)
    /**
     * Function GetClass
     * returns the class name.
     * @return wxString
     */
    wxString GetClass() const
    {
        return wxT("ZONE");
    }
#endif
    
};

class SEGVIA : public TRACK
{
public:
    SEGVIA( EDA_BaseStruct* StructFather );
    bool    IsViaOnLayer( int layer );
    void    SetLayerPair( int top_layer, int bottom_layer );
    void    ReturnLayerPair( int* top_layer, int* bottom_layer );
    
#if defined(DEBUG)
    /**
     * Function GetClass
     * returns the class name.
     * @return wxString
     */
    wxString GetClass() const
    {
        return wxT("VIA");
    }
#endif
    
};


#endif /* CLASS_TRACK_H */
