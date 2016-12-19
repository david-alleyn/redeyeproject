// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainWindow.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
	// This is a test comment

};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MainWindow *frame = new MainWindow();
	frame->Show(true);
	return true;
}
