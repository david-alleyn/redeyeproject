///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 14 2016)
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
#include <wx/clrpicker.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class ExperimentConfigurationDialogView
///////////////////////////////////////////////////////////////////////////////
class ExperimentConfigurationDialogView : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* experimentParametersLabel;
		wxStaticText* experimentDurationLabel;
		wxChoice* experimentDuration;
		wxStaticText* timeInSecondsLabel;
		wxTextCtrl* timeInSeconds;
		wxStaticText* movingObjectTypeLabel;
		wxChoice* movingObjectType;
		wxStaticText* numberOfObjectsLabel;
		wxTextCtrl* numberOfObjects;
		wxStaticText* sizeOfObjectsLabel;
		wxTextCtrl* sizeOfObjects;
		wxStaticText* objectColorLabel;
		wxColourPickerCtrl* selectedColour;
		wxStaticText* behavioralModelLabel;
		wxChoice* behavioralModel;
		wxStaticText* objectSpeedLabel;
		wxTextCtrl* objectSpeed;
		wxStaticLine* parametersLineSeperator;
		wxStaticText* gridParametersLabel;
		wxStaticText* rowsLabel;
		wxTextCtrl* gridRows;
		wxStaticText* columnsLabel;
		wxTextCtrl* gridColumns;
		wxStaticText* leftMarginLabel;
		wxTextCtrl* gridLeftMargin;
		wxStaticText* rightMarginLabel;
		wxTextCtrl* gridRightMargin;
		wxStaticText* topMarginLabel;
		wxTextCtrl* gridTopMargin;
		wxStaticText* bottomMarginLabel;
		wxTextCtrl* gridBottomMargin;
		wxStaticText* verticalSeperationLabel;
		wxTextCtrl* gridVerticalSeperation;
		wxStaticText* horizontalSeperationLabel;
		wxTextCtrl* gridHorizontalSeperation;
		wxButton* okButton;
		wxButton* cancelButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnTimeSelectHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ExperimentConfigurationDialogView( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Experiment Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~ExperimentConfigurationDialogView();
	
};

#endif //__EXPERIMENTCONFIGURATIONDIALOGVIEW_H__
