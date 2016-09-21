///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DISPLAYCONFIGURATIONDIALOGVIEW_H__
#define __DISPLAYCONFIGURATIONDIALOGVIEW_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class DisplayConfigurationDialogView
///////////////////////////////////////////////////////////////////////////////
class DisplayConfigurationDialogView : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxStaticText* m_numDisplays;
		wxStaticText* m_staticText4;
		wxStaticText* m_maxDisplayIndex;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_firstDisplayIndex;
		wxStaticText* m_staticText7;
		wxTextCtrl* m_lastDisplayIndex;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxButton* m_unlockModificationButton;
		wxButton* m_okButton;
		wxButton* m_cancelButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnUnlock( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DisplayConfigurationDialogView( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Display Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DisplayConfigurationDialogView();
	
};

#endif //__DISPLAYCONFIGURATIONDIALOGVIEW_H__
