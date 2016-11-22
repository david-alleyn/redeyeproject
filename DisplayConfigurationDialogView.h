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
#include <wx/choice.h>
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
		wxStaticText* m_staticText21;
		wxStaticText* m_numDisplays1;
		wxStaticText* m_staticText41;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText6;
		wxChoice* firstDisplayIndex;
		wxStaticText* m_staticText61;
		wxChoice* lastDisplayIndex;
		wxButton* m_okButton;
		wxButton* m_cancelButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DisplayConfigurationDialogView( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Display Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DisplayConfigurationDialogView();
	
};

#endif //__DISPLAYCONFIGURATIONDIALOGVIEW_H__
