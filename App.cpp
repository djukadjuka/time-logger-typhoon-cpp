#include "App.h"
#include "LoginFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() 
{
	LoginFrame* login_frame = new LoginFrame("Redmine Logger");
	return true;
}
