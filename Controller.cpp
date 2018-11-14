#include "Controller.h"
#include"Dialogs.h"
#include"Rental_Site.h"
#include <string>
#include<iostream>
#include<sstream>

Controller::Controller()
{
	Renter_Site r;
	renter_site=r;
}
	
void Controller::cli()
{View view;
//   int temp;
   int cmd=-1;
   //while(true)
    while(cmd!=0)
    {
       cmd = view.main_menu();
	 // int a = view.main_menu();
        //std::cout<<a;
        //std::cin>>temp;
        //if(temp==0)
        //return;
       // execute_cmd(temp)
       // ;
    //   if(cmd==0)
      
      // {
///	break;	 
  //     }
       execute_cmd(cmd);
    }
}

//void Controller::execute_cmd(int command)
void Controller::execute_cmd(int cmd)
{ //View view;
    switch(cmd)
    {
        //	case 0: cli();
	    case 1: {
                int _year,b_body_style;
                std::string _make,_model;
                Body_Style _body_style_;
               
		string s_year;
		string s_body_style;

	//	Dialogs::message("Enter details of the Vehicle: ");
		 s_year = Dialogs::input("Year?","Enter details of the Vehicle");
		try{

		if(s_year=="CANCEL")
			{
				cli();
				
			}
		else 
		{
		 _year = stoi(s_year);
		}
		}
		catch(...)
		{exit(0);
		}
 		 //std::cout<<"Year? :
                //std::cin>>_year;
                
		//std::cout<<"Make? :";
                //std::cin>>_make;
               
		std::string s_make = Dialogs::input("Make?","Enter the details of the vehicle");
		try{
			if(s_make=="CANCEL")
			{
				cli();
			}

			else 
			{
				_make = s_make;
			}
			
		  }

		catch(...)
		{
			exit(0);
		}
		std::string s_model = Dialogs::input("Model?","Enter the details of the Vehicle");

try
{

	if(s_model=="CANCEL")
	{
		cli();
	}
	
	else 
	{
         _model = s_model;
	}
}
catch(...)
{
	exit(0);
}
	//	 std::cout<<"Model? :";
          //      std::cin>>_model;
                
		//Dialogs::message("1. SEDAN 2. HATCHBACK 3.MINIVAN 4.TRUCK 5.SUV 6.CROSSOVER");
                //std::cout<<"Which Body style is it: ";
                //std::cin>>b_body_style;
		
		s_body_style = Dialogs::input("Which body style is it: ","1.SEDAN 2. HATCHBACK 3.MINIVAN 4.TRUCK 5.SUV");
		try 
		{
			if(s_body_style=="CANCEL")
			{
				cli();
			}
		
			else 
			{

		b_body_style = stoi(s_body_style);	
			}
		}
catch(...)
{
	exit(0);
}
		if(b_body_style==1)
                        _body_style_ = Body_Style::SEDAN;
                else if(b_body_style==2)  
                         _body_style_ = Body_Style::HATCHBACK;
                else if(b_body_style==3)
                         _body_style_ = Body_Style::MINIVAN;
                else if(b_body_style==4)
                         _body_style_ = Body_Style::TRUCK;
                else if(b_body_style==5)
                         _body_style_ = Body_Style::SUV;
                else
                         _body_style_ = Body_Style::CROSSOVER;
                Vehicle temp(_year,_make,_model,_body_style_);
                renter_site.add_vehicle(temp);
                return;}
        case 2: {
                std::vector<Vehicle> vehicle = renter_site.return_vehicles();
std: string s_vehicles="";
     std::ostringstream os;	
     for(int i=0;i<vehicle.size();i++)
                {
                 os<<i+1<<")"<<vehicle[i];
		//std::string s_index = to_string(i+1);
		//std:: string ss = vehicle[i].;
		//s_vehicles += s_index + vehicle[i];
	 	 //std:: string index = to_string(i+1);	
		    //	s_vehicles += index + ")" + vehicle[i] + '\n';
			//s_vehicles += vehicle[i]+
			//s_vehicles += std::to_string(i+1) + " " +vehicle[i]+'\n';
				//Dialogs::message(i+1,vehicle[i]);
			
			if(vehicle[i].get_is_rented())
         os<<vehicle[i].r_to_string()<<"\n";
		//	s_vehicles +=vehicle[i].r_to_string();
         //      	s_vehicles += std::to_string(i+1)+ vehicle[i].r_to_string()+ '\n';
			//Dialogs::message(os.str());
		}
	Dialogs::message(os.str(),"List of all vehicles available");
     //	Dialogs::message(s_vehicles,"List of all vehicles:");
		return;}
        case 3: {
                int num,number;
		std::string s_num;
	       	std::string name,renter_dl,phone;
                execute_cmd(2);
               // std::cout<<"Which vehicle do you want to rent:\n";
               // std::cin>>num;
		try{
		s_num = Dialogs::input("Which vehicle do you want to rent:","");
		if(s_num=="CANCEL")
		{
			cli();
		}
		else{
		num = stoi(s_num);
		}
		}
		catch(...)
		{
			exit(0);
		}
		std::vector<Vehicle> vehicle_v = renter_site.return_vehicles();
                if(vehicle_v[num-1].get_is_rented()==true)
                {
			Dialogs::message("Sorry! Vehicle is already Rented","");
                     return;
                }
		std::string s_number;
		std::string text = R"(
				  (1) Previous Renter
     			          (2) New Renter)";
		try{
		
		s_number = Dialogs::input(text,"");
		
		if(s_number=="CANCEL")
		{
			cli();
		}	

		else{	
		//std::cin>>number;
                //std::cout<<"\n\n";
                number = stoi(s_number);
		}

		}

		catch(...)
		{
			exit(0);
		}

		if(number==1)
                {
                    int n;
                    execute_cmd(6);
                    std::vector<Renter> r = renter_site.return_renters();
                  //  std::cin>>n;
		    std::string s_s_n =Dialogs::input("Which renter","");
		   try{

			  if(s_s_n=="CANCEL")
			  {
				cli();
			} 
			 else 
			 {	 
		    		n = stoi(s_s_n);
			 }
		renter_site.rent_vehicle(num-1,r[n-1]);
			 
		   }
		   catch(...)
		   {
		  	exit(0); 
		   }
		    return;
                }
                else if(number == 2)
                {
                    //std::cout<<"Enter the renters details: \n";
                  //std::cin.ignore();
                  name = Dialogs::input("Renter's Name: ","Enter the renter's details");  
		//std::cout<<"Renter's Name: ";
                  //  getline(std::cin,name);
                    //std::cout<<"Driver's License Number: ";
                    //getline(std::cin,renter_dl);
                  renter_dl = Dialogs::input("Driver's License Number: ","Enter the Driver's License Number");

		//  std::cout<<"Phone Number: ";
                  //  getline(std::cin,phone);
                 phone = Dialogs::input("Phone Number: ");  
		  Renter temp;
                    temp.details(name,renter_dl,phone);
                    renter_site.rent_vehicle(num-1,temp);
                    renter_site.add_renter(temp);
                    return;}
                else
                    Dialogs::message("##Invalid Input##");
                    return;
                }      
        case 4: {
                int n;
		std::string s_n;
		  execute_cmd(2);
                //std::cout<<"Which Vehicle do you want to Return? :\n";
                //std::cin>>n;
                s_n=Dialogs::input("Which Vechicle do you want to return?","");
		n=stoi(s_n);
		  renter_site.return_vehicle(n-1);
                return;}
        case 5: {
                    std::string n,D_L,PH;
                    //std::cout<<"Enter details of the Renter:\n";
                    //std::cout<<"Renter's Name :";
                    //std::cin.ignore();
                    //getline(std::cin,n);
                    n=Dialogs::input("Renter's Name:","Renter's details");
		    //std::cout<<"Driver's License Number: ";
                    //getline(std::cin,D_L);
                    D_L=Dialogs::input("Driver's License Number:","Renter's details");
		    //std::cout<<"Phone Number :";
                    //getline(std::cin,PH);
                    PH=Dialogs::input("Phone Number :","Renter's details");
		    Renter temp;
                    temp.details(n,D_L,PH);
                    renter_site.add_renter(temp);
                   break;
                }
        case 6: {
                std::vector<Renter> r = renter_site.return_renters();
		std::string ss = "";
		for(int i=0;i<r.size();i++)
                {
			
			std::string s_index = to_string(i+1);
		//	std::cout<<i+1<<")";
		    std:: string s =  r[i].print_details();
                    ss += s_index + s;
		    //Dialogs::message(ss,"");
		  //  std::cout<<s<<"\n";
                }
		Dialogs::message(ss,"");
		break;
                }   
        case 9: {
                //view.help();
                //std::cout<<a;
              //view.main_menu();
			Dialogs::message("Adding a vehicle(option 1) requires a year , make , model  and bodystyle. Listing all Vehicles (option 2) displays all information  known about the vehicles, including the identity of their respective renters.Renting a vehicle(option 3) requires a renters name, driver's license number , and phone number.All 3 are arbitary strings.Returning Vehicle requires no additional information.");
			return ;
		}
	
			//default: Dialogs::message("Invalid Input","error");
                 //cli();	 
		//exit(0);
	//return;

    }
}
