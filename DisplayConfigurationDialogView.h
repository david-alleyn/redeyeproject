///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 14 2016)
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
		wxStaticText* instructionLabel1;
		wxStaticText* instructionLabel2;
		wxStaticText* instructionLabel3;
		wxStaticText* firstDisplayIndexLabel;
		wxChoice* firstDisplayIndex;
		wxStaticText* lastDisplayIndexLabel;
		wxChoice* lastDisplayIndex;
		wxButton* okButton;
		wxButton* cancelButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DisplayConfigurationDialogView( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Display Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DisplayConfigurationDialogView();
	
};

#endif //__DISPLAYCONFIGURATIONDIALOGVIEW_H__
