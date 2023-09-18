#include "LoginFrame.h"
#include <wx/gbsizer.h>

LoginFrame::LoginFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) 
{
	//
	// GENERAL
	//
	wxPanel* contentsPanel = new wxPanel(this, wxID_ANY);
	wxStaticText* st_username = new wxStaticText(contentsPanel, wxID_ANY, "Username:");
	wxStaticText* st_password = new wxStaticText(contentsPanel, wxID_ANY, "Password:");
	this->tc_username = new wxTextCtrl(contentsPanel, wxID_ANY);
	this->tc_password = new wxTextCtrl(
		contentsPanel, wxID_ANY, "", 
		wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD
	);

	//
	// BUTTONS
	// 
	wxPanel* buttonsPanel = new wxPanel(contentsPanel, wxID_ANY);
	wxButton* btn_login = new wxButton(buttonsPanel, wxID_ANY, "Login");
	wxButton* btn_cancel = new wxButton(buttonsPanel, wxID_ANY, "Cancel");
	btn_login->Bind(wxEVT_BUTTON, &LoginFrame::OnOkButtonClicked, this);
	btn_cancel->Bind(wxEVT_BUTTON, &LoginFrame::OnCancelButtonClicked, this);

	//
	// BAG SIZER START
	//
	wxGridBagSizer* gbs = new wxGridBagSizer(2, 10);
	gbs->Add(st_username, { 0, 0 }, { 1, 1 }, wxEXPAND| wxALIGN_CENTER | wxLEFT | wxTOP, 10);
	gbs->Add(st_password, { 1, 0 }, { 1, 1 }, wxEXPAND | wxALIGN_CENTER | wxLEFT, 10);
	gbs->Add(this->tc_username, { 0, 1 }, { 1, 2 }, wxEXPAND | wxRIGHT | wxTOP, 10);
	gbs->Add(this->tc_password, { 1, 1 }, { 1, 2 }, wxEXPAND | wxRIGHT, 10);
	// BUTTONS SIZER
	wxBoxSizer* buttons_sizer = new wxBoxSizer(wxHORIZONTAL);
	buttons_sizer->Add(btn_login, 1, wxBOTTOM | wxRIGHT | wxTOP, 10);
	buttons_sizer->Add(btn_cancel, 1, wxBOTTOM | wxLEFT | wxTOP, 10);
	buttonsPanel->SetSizerAndFit(buttons_sizer);
	gbs->Add(buttonsPanel, { 2, 0 }, { 1, 3 }, wxEXPAND| wxALIGN_CENTER | wxLEFT | wxRIGHT, 50);
	gbs->AddGrowableCol(1);
	gbs->AddGrowableRow(2);
	
	// ALL TOGETHER
	contentsPanel->SetSizer(gbs);
	wxBoxSizer* main_sizer= new wxBoxSizer(wxVERTICAL);
	main_sizer->Add(contentsPanel, 1, wxEXPAND);
	this->SetSizerAndFit(main_sizer);
	this->Center();
	this->Show();
}

void LoginFrame::OnOkButtonClicked(wxCommandEvent& evt) {
	wxString username = this->tc_username->GetValue();
	wxString password = this->tc_password->GetValue();

	wxMessageBox(wxString::Format("(Username: %s, Password: %s)", username, password));
}

void LoginFrame::OnCancelButtonClicked(wxCommandEvent& evt) {
	exit(0);
}
