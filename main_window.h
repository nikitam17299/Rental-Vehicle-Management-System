#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include "View.h"
#include <gtkmm.h>
#include "Rental_Site.h"
#include "Vehicle.h"
#include "Controller.h"


class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();
    protected:


        void on_about_click();           // Display About dialog
      void on_quit_click();           // Exit the game
	void on_addVehicle_click();
	void on_listVehicle_click();
	void on_rentVehicle_click();
	void on_returnVehicle_click();
	void on_addRenter_click();
	void on_listRenter_click();
//void on_magic_click();

    private:
		View  v;
		Renter_Site renter_site;
	Controller c;

};
#endif 

