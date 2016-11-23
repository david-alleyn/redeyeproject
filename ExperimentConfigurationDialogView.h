///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __EXPERIMENTCONFIGURATIONDIALOGVIEW_H__
#define __EXPERIMENTCONFIGURATIONDIALOGVIEW_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class ExperimentConfigurationDialogView
///////////////////////////////////////////////////////////////////////////////
class ExperimentConfigurationDialogView : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText23;
		wxStaticText* m_staticText2;
		wxChoice* experimentDuration;
		wxStaticText* m_staticText3;
		wxTextCtrl* timeInSeconds;
		wxStaticText* m_staticText22;
		wxChoice* movingObjectType;
		wxStaticText* m_staticText22221;
		wxTextCtrl* numberOfObjects;
		wxStaticText* m_staticText222211;
		wxTextCtrl* sizeOfObjects;
		wxStaticText* m_staticText221;
		wxButton* colourPickerButton;
		wxStaticText* m_staticText20;
		wxButton* currentColourAsAButton;
		wxStaticText* m_staticText222;
		wxChoice* behavioralModel;
		wxStaticText* m_staticText2222;
		wxTextCtrl* objectSpeed;
		wxStaticLine* m_staticline5;
		wxStaticText* m_staticText22215;
		wxStaticText* m_staticText2221;
		wxTextCtrl* gridRows;
		wxStaticText* m_staticText22211;
		wxTextCtrl* gridColumns;
		wxStaticText* m_staticText22212;
		wxTextCtrl* gridLeftMargin;
		wxStaticText* m_staticText22213;
		wxTextCtrl* gridRightMargin;
		wxStaticText* m_staticText22214;
		wxTextCtrl* gridTopMargin;
		wxStaticText* m_staticText222141;
		wxTextCtrl* gridBottomMargin;
		wxStaticText* m_staticText222142;
		wxTextCtrl* gridVerticalSeperation;
		wxStaticText* m_staticText2221421;
		wxTextCtrl* gridHorizontalSeperation;
		wxButton* okButton;
		wxButton* cancelButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnTimeSelectHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnObjectTypeSelectHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnColourPickerHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBehaviorModelSelectHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ExperimentConfigurationDialogView( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Experiment Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~ExperimentConfigurationDialogView();
	
};

#endif //__EXPERIMENTCONFIGURATIONDIALOGVIEW_H__
