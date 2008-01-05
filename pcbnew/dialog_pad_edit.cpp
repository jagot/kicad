/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_pad_edit.cpp
// Purpose:     
// Author:      jean-pierre Charras
// Modified by: 
// Created:     28/02/2006 13:34:48
// RCS-ID:      
// Copyright:   License GNU
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 28/02/2006 13:34:48

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dialog_pad_edit.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "dialog_pad_edit.h"

////@begin XPM images
////@end XPM images

/*!
 * WinEDA_PadPropertiesFrame type definition
 */

IMPLEMENT_DYNAMIC_CLASS( WinEDA_PadPropertiesFrame, wxDialog )

/*!
 * WinEDA_PadPropertiesFrame event table definition
 */

BEGIN_EVENT_TABLE( WinEDA_PadPropertiesFrame, wxDialog )

////@begin WinEDA_PadPropertiesFrame event table entries
    EVT_RADIOBOX( ID_RADIOBOX_DRILL_SHAPE, WinEDA_PadPropertiesFrame::OnRadioboxDrillShapeSelected )

    EVT_RADIOBOX( ID_LISTBOX_ORIENT_PAD, WinEDA_PadPropertiesFrame::OnListboxOrientPadSelected )

    EVT_RADIOBOX( ID_LISTBOX_SHAPE_PAD, WinEDA_PadPropertiesFrame::OnListboxShapePadSelected )

    EVT_RADIOBOX( ID_LISTBOX_TYPE_PAD, WinEDA_PadPropertiesFrame::OnListboxTypePadSelected )

    EVT_BUTTON( wxID_OK, WinEDA_PadPropertiesFrame::OnOkClick )

    EVT_BUTTON( wxID_CANCEL, WinEDA_PadPropertiesFrame::OnCancelClick )

////@end WinEDA_PadPropertiesFrame event table entries

END_EVENT_TABLE()

/*!
 * WinEDA_PadPropertiesFrame constructors
 */

WinEDA_PadPropertiesFrame::WinEDA_PadPropertiesFrame( )
{
}

WinEDA_PadPropertiesFrame::WinEDA_PadPropertiesFrame( WinEDA_BasePcbFrame* parent,
            D_PAD * Pad,wxDC * DC,
            wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
	m_Parent = parent;
	m_DC = DC;
	m_Module = NULL;
	CurrentPad = Pad;

	if ( CurrentPad )
	{
		Current_PadNetName = CurrentPad->m_Netname;
		g_Current_PadName = CurrentPad->ReturnStringPadName();
		m_Module = (MODULE*) CurrentPad->m_Parent;
	}

    Create(parent, id, caption, pos, size, style);
}

/*!
 * WinEDA_PadPropertiesFrame creator
 */

bool WinEDA_PadPropertiesFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin WinEDA_PadPropertiesFrame member initialisation
    m_LeftBoxSizer = NULL;
    m_PadNumCtrl = NULL;
    m_PadNetNameCtrl = NULL;
    m_PadPositionBoxSizer = NULL;
    m_DrillShapeBoxSizer = NULL;
    m_DrillShapeCtrl = NULL;
    m_PadOptSizer = NULL;
    m_PadOrient = NULL;
    m_PadShape = NULL;
    m_PadType = NULL;
    m_PadLayerCu = NULL;
    m_PadLayerCmp = NULL;
    m_PadLayerAdhCmp = NULL;
    m_PadLayerAdhCu = NULL;
    m_PadLayerPateCmp = NULL;
    m_PadLayerPateCu = NULL;
    m_PadLayerSilkCmp = NULL;
    m_PadLayerSilkCu = NULL;
    m_PadLayerMaskCmp = NULL;
    m_PadLayerMaskCu = NULL;
    m_PadLayerECO1 = NULL;
    m_PadLayerECO2 = NULL;
    m_PadLayerDraft = NULL;
////@end WinEDA_PadPropertiesFrame member initialisation

////@begin WinEDA_PadPropertiesFrame creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end WinEDA_PadPropertiesFrame creation
    return true;
}

/*!
 * Control creation for WinEDA_PadPropertiesFrame
 */

void WinEDA_PadPropertiesFrame::CreateControls()
{    
	SetFont(*g_DialogFont);
////@begin WinEDA_PadPropertiesFrame content construction
    // Generated by DialogBlocks, 27/08/2007 21:03:59 (unregistered)

    WinEDA_PadPropertiesFrame* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_LeftBoxSizer = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(m_LeftBoxSizer, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Pad Num :"), wxDefaultPosition, wxDefaultSize, 0 );
    m_LeftBoxSizer->Add(itemStaticText4, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);

    m_PadNumCtrl = new wxTextCtrl( itemDialog1, ID_TEXTCTRL_PADNUM, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    m_LeftBoxSizer->Add(m_PadNumCtrl, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemDialog1, wxID_STATIC, _("Pad Net Name :"), wxDefaultPosition, wxDefaultSize, 0 );
    m_LeftBoxSizer->Add(itemStaticText6, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);

    m_PadNetNameCtrl = new wxTextCtrl( itemDialog1, ID_TEXTCTRL_NETNAME, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    m_LeftBoxSizer->Add(m_PadNetNameCtrl, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PadPositionBoxSizer = new wxBoxSizer(wxVERTICAL);
    m_LeftBoxSizer->Add(m_PadPositionBoxSizer, 0, wxGROW|wxTOP, 5);

    m_DrillShapeBoxSizer = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(m_DrillShapeBoxSizer, 0, wxGROW|wxTOP, 5);

    wxArrayString m_DrillShapeCtrlStrings;
    m_DrillShapeCtrlStrings.Add(_("Circle"));
    m_DrillShapeCtrlStrings.Add(_("Oval"));
    m_DrillShapeCtrl = new wxRadioBox( itemDialog1, ID_RADIOBOX_DRILL_SHAPE, _("Drill Shape:"), wxDefaultPosition, wxDefaultSize, m_DrillShapeCtrlStrings, 1, wxRA_SPECIFY_COLS );
    m_DrillShapeCtrl->SetSelection(0);
    m_DrillShapeBoxSizer->Add(m_DrillShapeCtrl, 0, wxGROW|wxALL, 5);

    m_PadOptSizer = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(m_PadOptSizer, 0, wxGROW|wxALL, 5);

    wxArrayString m_PadOrientStrings;
    m_PadOrientStrings.Add(_("0"));
    m_PadOrientStrings.Add(_("90"));
    m_PadOrientStrings.Add(_("-90"));
    m_PadOrientStrings.Add(_("180"));
    m_PadOrientStrings.Add(_("User"));
    m_PadOrient = new wxRadioBox( itemDialog1, ID_LISTBOX_ORIENT_PAD, _("Pad Orient:"), wxDefaultPosition, wxDefaultSize, m_PadOrientStrings, 1, wxRA_SPECIFY_COLS );
    m_PadOrient->SetSelection(0);
    m_PadOptSizer->Add(m_PadOrient, 0, wxGROW|wxALL, 5);

    wxArrayString m_PadShapeStrings;
    m_PadShapeStrings.Add(_("Circle"));
    m_PadShapeStrings.Add(_("Oval"));
    m_PadShapeStrings.Add(_("Rect"));
    m_PadShapeStrings.Add(_("Trapezoidal"));
    m_PadShape = new wxRadioBox( itemDialog1, ID_LISTBOX_SHAPE_PAD, _("Pad Shape:"), wxDefaultPosition, wxDefaultSize, m_PadShapeStrings, 1, wxRA_SPECIFY_COLS );
    m_PadShape->SetSelection(0);
    m_PadOptSizer->Add(m_PadShape, 0, wxGROW|wxALL, 5);

    wxArrayString m_PadTypeStrings;
    m_PadTypeStrings.Add(_("Standard"));
    m_PadTypeStrings.Add(_("SMD"));
    m_PadTypeStrings.Add(_("Conn"));
    m_PadTypeStrings.Add(_("Hole"));
    m_PadTypeStrings.Add(_("Mechanical"));
    m_PadType = new wxRadioBox( itemDialog1, ID_LISTBOX_TYPE_PAD, _("Pad Type:"), wxDefaultPosition, wxDefaultSize, m_PadTypeStrings, 1, wxRA_SPECIFY_COLS );
    m_PadType->SetSelection(0);
    m_PadOptSizer->Add(m_PadType, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(itemBoxSizer15, 0, wxGROW|wxALL, 5);

    wxButton* itemButton16 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton16->SetForegroundColour(wxColour(204, 0, 0));
    itemBoxSizer15->Add(itemButton16, 0, wxGROW|wxALL, 5);

    wxButton* itemButton17 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton17->SetForegroundColour(wxColour(0, 0, 255));
    itemBoxSizer15->Add(itemButton17, 0, wxGROW|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer18Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Layers:"));
    wxStaticBoxSizer* itemStaticBoxSizer18 = new wxStaticBoxSizer(itemStaticBoxSizer18Static, wxVERTICAL);
    itemBoxSizer15->Add(itemStaticBoxSizer18, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 5);

    m_PadLayerCu = new wxCheckBox( itemDialog1, ID_CHECKBOX, _("Copper layer"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerCu->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerCu, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    m_PadLayerCmp = new wxCheckBox( itemDialog1, ID_CHECKBOX1, _("Comp layer"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerCmp->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerCmp, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemStaticBoxSizer18->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_PadLayerAdhCmp = new wxCheckBox( itemDialog1, ID_CHECKBOX2, _("Adhesive Cmp"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerAdhCmp->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerAdhCmp, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    m_PadLayerAdhCu = new wxCheckBox( itemDialog1, ID_CHECKBOX3, _("Adhesive Copper"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerAdhCu->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerAdhCu, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    m_PadLayerPateCmp = new wxCheckBox( itemDialog1, ID_CHECKBOX4, _("Solder paste Cmp"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerPateCmp->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerPateCmp, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    m_PadLayerPateCu = new wxCheckBox( itemDialog1, ID_CHECKBOX5, _("Solder paste Copper"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerPateCu->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerPateCu, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    m_PadLayerSilkCmp = new wxCheckBox( itemDialog1, ID_CHECKBOX6, _("Silkscreen Cmp"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerSilkCmp->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerSilkCmp, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    m_PadLayerSilkCu = new wxCheckBox( itemDialog1, ID_CHECKBOX7, _("Silkscreen Copper"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerSilkCu->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerSilkCu, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    m_PadLayerMaskCmp = new wxCheckBox( itemDialog1, ID_CHECKBOX8, _("Solder mask Cmp"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerMaskCmp->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerMaskCmp, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    m_PadLayerMaskCu = new wxCheckBox( itemDialog1, ID_CHECKBOX9, _("Solder mask Copper"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerMaskCu->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerMaskCu, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    m_PadLayerECO1 = new wxCheckBox( itemDialog1, ID_CHECKBOX10, _("E.C.O.1 layer"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerECO1->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerECO1, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    m_PadLayerECO2 = new wxCheckBox( itemDialog1, ID_CHECKBOX11, _("E.C.O.2 layer"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerECO2->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerECO2, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    m_PadLayerDraft = new wxCheckBox( itemDialog1, ID_CHECKBOX12, _("Draft layer"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_PadLayerDraft->SetValue(false);
    itemStaticBoxSizer18->Add(m_PadLayerDraft, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

////@end WinEDA_PadPropertiesFrame content construction

	SetOthersControls();
}

/*!
 * Should we show tooltips?
 */

bool WinEDA_PadPropertiesFrame::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap WinEDA_PadPropertiesFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin WinEDA_PadPropertiesFrame bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end WinEDA_PadPropertiesFrame bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon WinEDA_PadPropertiesFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin WinEDA_PadPropertiesFrame icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end WinEDA_PadPropertiesFrame icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void WinEDA_PadPropertiesFrame::OnOkClick( wxCommandEvent& event )
{
	PadPropertiesAccept(event);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void WinEDA_PadPropertiesFrame::OnCancelClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in WinEDA_PadPropertiesFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in WinEDA_PadPropertiesFrame. 
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_LISTBOX_ORIENT_PAD
 */

void WinEDA_PadPropertiesFrame::OnListboxOrientPadSelected( wxCommandEvent& event )
{
	PadOrientEvent(event);
}

/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_LISTBOX_SHAPE_PAD
 */

void WinEDA_PadPropertiesFrame::OnListboxShapePadSelected( wxCommandEvent& event )
{
	switch (m_PadShape->GetSelection() )
	{
		case 0: //CIRCLE:
			m_PadDeltaSizeCtrl->Enable(FALSE, FALSE);
			m_PadSizeCtrl->Enable(TRUE, FALSE);
			break;

		case 1: //OVALE:
			m_PadDeltaSizeCtrl->Enable(FALSE, FALSE);
			m_PadSizeCtrl->Enable(TRUE, TRUE);
			break;

		case 2: // PAD_RECT:
			m_PadDeltaSizeCtrl->Enable(FALSE, FALSE);
			m_PadSizeCtrl->Enable(TRUE, TRUE);
			break;

		case 3: //TRAPEZE:
			m_PadDeltaSizeCtrl->Enable(TRUE, TRUE);
			m_PadSizeCtrl->Enable(TRUE, TRUE);
			break;
	}
}

/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_LISTBOX_TYPE_PAD
 */

void WinEDA_PadPropertiesFrame::OnListboxTypePadSelected( wxCommandEvent& event )
{
	PadTypeSelectedEvent(event);
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_RADIOBOX_DRILL_SHAPE
 */

void WinEDA_PadPropertiesFrame::OnRadioboxDrillShapeSelected( wxCommandEvent& event )
{
	switch ( m_DrillShapeCtrl->GetSelection() )
	{
		case 0: //CIRCLE:
			m_PadDrillCtrl->Enable(TRUE,FALSE);
			break;

		case 1: //OVALE:
			m_PadDrillCtrl->Enable(TRUE, TRUE);
			break;
	}
}


