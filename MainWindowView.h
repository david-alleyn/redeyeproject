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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
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
		wxMenuBar* m_menubar;
		wxMenu* m_fileMenu;
		wxButton* m_displayConfButton;
		wxButton* m_experimentConfButton;
		wxButton* m_runExperimentButton;
		wxStaticText* m_logTextTitle;
		wxTextCtrl* m_logTextControl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLoadConfiguration( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveConfiguration( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDisplayConfiguration( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExperimentConfiguration( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRunExperiment( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainWindowView( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Red Eye Project"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainWindowView();
	
};

#endif //__MAINWINDOWVIEW_H__
