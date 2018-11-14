#include <iostream>
#include "Controller.h"
#include<gtkmm.h>
#include "main_window.h"

int main(int argc, char *argv[])
{
  //  Gtk::Main kit(argc,argv);

    //Controller c;
    
  //  c.cli();

	auto app=Gtk::Application::create(argc,argv,"edu.uta.cse1325.example");
	Main_window win;

	return app->run(win);

}
