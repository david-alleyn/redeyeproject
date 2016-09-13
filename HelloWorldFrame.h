#pragma once
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include "DisplayEngine.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnSDLInit(wxCommandEvent& event);

	DisplayEngine* displayEngine;
};



enum
{
	ID_Hello = 1,
	ID_SDLInitButton
};