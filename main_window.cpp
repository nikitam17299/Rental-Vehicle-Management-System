#include "main_window.h"
#include "controller.h"
#include "rental_site.h"
//#include "view.h"
Main_window::Main_window() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //   F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
   Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);

    //Vehicle
    //Create a vehicle menu and add to the menu bar
    Gtk::MenuItem *menuitem_vehicle=Gtk::manage(new Gtk::MenuItem("Vehicle",true));
    menubar->append(*menuitem_vehicle);
    Gtk::Menu *vehiclemenu=Gtk::manage(new Gtk::Menu());
    menuitem_vehicle->set_submenu(*vehiclemenu);
	
	//Renter
    //Create a renter menu and add to the menu bar
    Gtk::MenuItem *menuitem_renter=Gtk::manage(new Gtk::MenuItem("Renter",true));
    menubar->append(*menuitem_renter);
    Gtk::Menu *rentermenu=Gtk::manage(new Gtk::Menu());
    menuitem_renter->set_submenu(*rentermenu);
	
	//add renter
	 Gtk::MenuItem *menuitem_addRenter=Gtk::manage(new Gtk::MenuItem("New",true));
    menuitem_addRenter->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_addRenter_click));
    rentermenu->append(*menuitem_addRenter);
	
	//List renter
	 Gtk::MenuItem *menuitem_listRenter=Gtk::manage(new Gtk::MenuItem("List",true));
    menuitem_listRenter->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_listRenter_click));
    rentermenu->append(*menuitem_listRenter);

    //add vehicle
    Gtk::MenuItem *menuitem_addVehicle=Gtk::manage(new Gtk::MenuItem("New",true));
    menuitem_addVehicle->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_addVehicle_click));
    vehiclemenu->append(*menuitem_addVehicle);

    //list vehicle
    Gtk::MenuItem *menuitem_listVehicle=Gtk::manage(new Gtk::MenuItem("List",true));
    menuitem_listVehicle->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_listVehicle_click));
    vehiclemenu->append(*menuitem_listVehicle);

    //rent vehicle
    Gtk::MenuItem *menuitem_rentVehicle=Gtk::manage(new Gtk::MenuItem("Rent",true));
    menuitem_rentVehicle->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_rentVehicle_click));
    vehiclemenu->append(*menuitem_rentVehicle);

    //retrun vehicle
    Gtk::MenuItem *menuitem_returnVehicle=Gtk::manage(new Gtk::MenuItem("Return",true));
    menuitem_returnVehicle->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_returnVehicle_click));
    vehiclemenu->append(*menuitem_returnVehicle);
    
    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

   
//
//    //     Q U I T
//    // Add a icon for quitting
   Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
   quit_button->set_tooltip_markup("Exiting");
   quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
   Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
   sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);


    // Make the box and everything in it visible
    vbox->show_all();

    
}

Main_window::~Main_window() { }



void Main_window::on_addVehicle_click(){
  c.execute_cmd(1) ;
}
void Main_window::on_listVehicle_click(){
  c.execute_cmd(2) ;
}
void Main_window::on_rentVehicle_click(){
  c.execute_cmd(3) ;
}
void Main_window::on_returnVehicle_click(){
  c.execute_cmd(4) ;
}

void Main_window::on_addRenter_click(){
	c.execute_cmd(5);
}

void Main_window::on_listRenter_click(){
	c.execute_cmd(6);
}


void Main_window::on_quit_click() {
    hide();
}

void Main_window::on_about_click() {
  
  v.help();
  
}

