///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINWINDOWVIEW_H__
#define __MAINWINDOWVIEW_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainWindowView
///////////////////////////////////////////////////////////////////////////////
class MainWindowView : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* instructionLabel1;
		wxButton* displayConfButton;
		wxStaticText* instructionLabel2;
		wxButton* experimentConfButton;
		wxStaticText* instructionLabel3;
		wxButton* stageExperimentButton;
		wxStaticText* instructionLabel4;
		wxButton* runExperimentButton;
		wxButton* loadConfButton;
		wxButton* saveConfButton;
		wxStaticText* logTextTitle;
		wxTextCtrl* logTextControl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDisplayConfiguration( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExperimentConfiguration( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStageExperiment( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRunExperiment( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadConfiguration( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveConfiguration( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainWindowView( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Red Eye Project"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainWindowView();
	
};

#endif //__MAINWINDOWVIEW_H__
