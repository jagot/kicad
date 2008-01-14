/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_gendrill.h
// Purpose:     
// Author:      jean-pierre Charras
// Modified by: 
// Created:     13/01/2008 17:26:27
// RCS-ID:      
// Copyright:   License GNU
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 13/01/2008 17:26:27

#ifndef _DIALOG_GENDRILL_H_
#define _DIALOG_GENDRILL_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/valgen.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxBoxSizer;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WINEDA_DRILLFRAME 10000
#define ID_SEL_DRILL_UNITS 10002
#define ID_SEL_ZEROS_FMT 10001
#define ID_SEL_PRECISION 10003
#define ID_SEL_DRILL_SHEET 10004
#define ID_SEL_DRILL_REPORT 10010
#define ID_TEXTCTRL2 10007
#define ID_TEXTCTRL 10006
#define ID_CHECKBOX2 10011
#define ID_CHECKBOX3 10012
#define SYMBOL_WINEDA_DRILLFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_WINEDA_DRILLFRAME_TITLE _("WinEDA_DrillFrame")
#define SYMBOL_WINEDA_DRILLFRAME_IDNAME ID_WINEDA_DRILLFRAME
#define SYMBOL_WINEDA_DRILLFRAME_SIZE wxSize(400, 300)
#define SYMBOL_WINEDA_DRILLFRAME_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * WinEDA_DrillFrame class declaration
 */

class WinEDA_DrillFrame: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( WinEDA_DrillFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    WinEDA_DrillFrame();
    WinEDA_DrillFrame( WinEDA_PcbFrame* parent,
        wxWindowID id = SYMBOL_WINEDA_DRILLFRAME_IDNAME,
        const wxString& caption = SYMBOL_WINEDA_DRILLFRAME_TITLE,
        const wxPoint& pos = SYMBOL_WINEDA_DRILLFRAME_POSITION,
        const wxSize& size = SYMBOL_WINEDA_DRILLFRAME_SIZE,
        long style = SYMBOL_WINEDA_DRILLFRAME_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WINEDA_DRILLFRAME_IDNAME, const wxString& caption = SYMBOL_WINEDA_DRILLFRAME_TITLE, const wxPoint& pos = SYMBOL_WINEDA_DRILLFRAME_POSITION, const wxSize& size = SYMBOL_WINEDA_DRILLFRAME_SIZE, long style = SYMBOL_WINEDA_DRILLFRAME_STYLE );

    /// Destructor
    ~WinEDA_DrillFrame();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin WinEDA_DrillFrame event handler declarations

    /// wxEVT_CLOSE_WINDOW event handler for ID_WINEDA_DRILLFRAME
    void OnCloseWindow( wxCloseEvent& event );

    /// wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_SEL_DRILL_UNITS
    void OnSelDrillUnitsSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_SEL_ZEROS_FMT
    void OnSelZerosFmtSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CLOSE
    void OnCloseClick( wxCommandEvent& event );

////@end WinEDA_DrillFrame event handler declarations

////@begin WinEDA_DrillFrame member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end WinEDA_DrillFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin WinEDA_DrillFrame member variables
    wxBoxSizer* m_LeftBoxSizer;
    wxRadioBox* m_Choice_Unit;
    wxRadioBox* m_Choice_Zeros_Format;
    wxRadioBox* m_Choice_Precision;
    wxRadioBox* m_Choice_Drill_Offset;
    wxRadioBox* m_Choice_Drill_Map;
    wxRadioBox* m_Choice_Drill_Report;
    wxTextCtrl* m_PenSpeed;
    wxTextCtrl* m_PenNum;
    wxCheckBox* m_Check_Mirror;
    wxCheckBox* m_Check_Minimal;
    wxStaticBox* m_DefaultViasDrillSizer;
    wxStaticText* m_ViaDrillValue;
    wxStaticBox* m_MicroViasDrillSizer;
    wxStaticText* m_MicroViaDrillValue;
    wxStaticText* m_PadsCountInfoMsg;
    wxStaticText* m_ThroughViasInfoMsg;
    wxStaticText* m_MicroViasInfoMsg;
    wxStaticText* m_BuriedViasInfoMsg;
////@end WinEDA_DrillFrame member variables

private:
	WinEDA_PcbFrame*  m_Parent;
	int  m_PadsHoleCount;
	int m_ThroughViasCount;
	int m_MicroViasCount;
	int m_BlindOrBuriedViasCount;

private:
    void    InitDisplayParams(void);
    void    SetParams(void);
    void    GenDrillFiles( wxCommandEvent& event );
    void    GenDrillMap( int format );
    void    UpdatePrecisionOptions( wxCommandEvent& event );
    void    UpdateConfig();
    int     Plot_Drill_PcbMap( DRILL_TOOL* buffer, int format );
    void    GenDrillReport();
    int     Gen_Liste_Forets( DRILL_TOOL* buffer, bool print_header );
    int     Create_Drill_File_EXCELLON( DRILL_TOOL* buffer );
    void    Init_Drill();
};

#endif
    // _DIALOG_GENDRILL_H_
