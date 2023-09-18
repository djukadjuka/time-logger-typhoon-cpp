#pragma once
#include <wx/wx.h>

class LoginFrame : public wxFrame
{
	wxTextCtrl* tc_username;
	wxTextCtrl* tc_password;

	void OnOkButtonClicked(wxCommandEvent& evt);
	void OnCancelButtonClicked(wxCommandEvent& evt);
public:
	LoginFrame(const wxString& title);
};

