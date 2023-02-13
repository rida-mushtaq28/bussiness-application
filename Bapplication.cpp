#include <iostream>
#include <conio.h>
using namespace std;

const int userarrsize=100;                                                 //constant size of all global arrays

string passwords[userarrsize];                                             //array to store name of registeredusers i.e owner ,customer...
string names[userarrsize];                                                 //array to store passwords of all registered users
string roles[userarrsize];                                                 //array to store roles of registered users i.e owner,manager & customer
string name;                                                               //ask user to enter name
string role;                                                               //ask user to enter password
string password;                                                           //ask user to enter role of the user


int usercount=0;                                                           //variable to count no of users that are registered.

void header();                                                             //prints header of the system
void subMenubeforeMainMenu(string submenu);                                //prints submenu before mainmenu
void subMenu(string submenu);                                              //prints submenu   
void clearscreen();                                                        //enters to proceed further
int loginoption();                                                         //prints login menu and enter the choce
string signIn(string name,string password);                                //signin to enter credential for already existed account
bool signUp(string name,string password,string role);                      //signup to input credential to make account
int OwnerMenu();                                                           //prints ownermenu and enter the choice
void OwnerInterface();                                                     //further proceeding of owner
int ManagerMenu();                                                         //prints manager menu and enter choice
void ManagerInterface();                                                   //further proceeding of manager
int CustomerMenu();                                                        //prints customer menu and enter choice
void CustomerInterface();                                                  //further proceeding of customer

main()
    {

         int option=0;
         while(option!=3)
         {
            header();
            subMenubeforeMainMenu("Login");
            option=loginoption();
            if  (option==1)
               {
                 system("cls");

                 header();
                 subMenubeforeMainMenu("SignIn");
                 cout << "Enter the Name:"<< endl;
                 cin >> name;
                 cout << "Enter Password:"<< endl;
                 cin >> password;
                 role=signIn(name,password);

                 if (role=="owner")
                   {
                      clearscreen();
                      OwnerInterface();
                   }

                 if (role=="manager")
                   {
                      clearscreen();
                      ManagerInterface();
                   }

                 if (role=="customer")
                   {
                      clearscreen();
                      CustomerInterface();
                   }    

               }

              else if  (option==2)
               {
                 system("cls");

                 header();
                 subMenubeforeMainMenu("SignUp");
                 cout << "Enter the Name:"<< endl;
                 cin >> name;
                 cout << "Enter Password:"<< endl;
                 cin >> password;
                 cout << "Enter Role(Owner/Manager/customer):"<< endl;
                 cin >> role;

                 bool credential = signUp(name,password,role);
                 if (credential)
                   {
                     cout << "SignedUp Successfully!!!" << endl;
                   }
                 if (!credential)
                   {
                     cout << "No more Space for the Users!!" << endl;
                   }  

                 clearscreen();

               }
        }

    }


void header()
    {
      cout << "*********************************************" << endl;
      cout<<  "*                                           *" << endl;
      cout << "*          HOTEL MANAGEMENT SYSTEM          *" << endl;
      cout<<  "*                                           *" << endl;
      cout << "*********************************************" << endl;
    }

void subMenubeforeMainMenu(string submenu)
    {
        string title = submenu + "Menu";
        cout << title << endl;
        cout << "________________________________" << endl;
        cout << endl;
    }

void subMenu(string submenu)
    {
        string title =  "Main Menu >"+ submenu;
        cout << title << endl;
        cout << "________________________________" << endl;
        cout << endl;
    }

void clearscreen()
    {
        cout << "Press any key to Continue..." << endl;
        getch();
        system ("cls");
    }

int loginoption()
    {
        int option=0;

        cout << "1.  Signin to the Account " << endl;
        cout << "2.  Signup for the Account" << endl;
        cout << "3.  Exit the Login Menu   " << endl;

        cout << "Select the option of your choice =";
        cin >> option;
        return option;

    }

string signIn(string name,string password)
    {
         for (int idx=0; idx<usercount; idx++)
           {
               if  (names[idx]==name && passwords[idx]==password)
                  {
                     return roles[idx];
                  }
           }
         return "Undefined";
    }

bool signUp(string name,string password,string role)
    {
        bool credential=false;
        for (int idx=0; idx<usercount; idx++)
          {
              if   (names[idx]==name && passwords[idx]==password)
                  {
                     credential=true;
                     break;
                  }
          }
        if  (credential==true)
          {
              return 0;
              cout << "This User is Already Present!"<< endl;
          }
        else if  (usercount < userarrsize)
          {
            names[usercount]=name;
            passwords[usercount]=password;
            roles[usercount]=role;
            usercount++;
            return true;
          }
        else 
          {
            return false;
          }  

        
    }

int OwnerMenu()
    {
       int option;
       cout << "Select any Option of your Choice.  "<< endl;
       cout << "1.  View List of Rooms             "<< endl;
       cout << "2.  Customers                      "<< endl;
       cout << "3.  Food                           "<< endl;
       cout << "4.  Add Rooms                      "<< endl;
       cout << "5.  Remove Rooms                   "<< endl;
       cout << "6.  View Feedbacks                 "<< endl;
       cout << "7.  Log Out                        "<< endl;
       cout << "Enter your Choice:                 "<< endl;
       cin >> option;
       return option;
    }
void OwnerInterface()
    {
       int OwnerOption=0;
       while(OwnerOption!=7)
        {
          header();
          subMenu("AdminMenu");
          OwnerOption=OwnerMenu();
          if (OwnerOption==1)
             {
                system("cls");
                header();
                subMenu("View List Of Rooms");
             }
          else if (OwnerOption==2)
             {
                system("cls");
                header();
                subMenu("Customers");
             }   
          else if (OwnerOption==3)
             {
                system("cls");
                header();
                subMenu("Foods");
             }
          else if (OwnerOption==4)
             {
                system("cls");
                header();
                subMenu("Add Rooms");
             }
          else if (OwnerOption==5)
             {
                system("cls");
                header();
                subMenu("Remove Rooms");
             }
          else if (OwnerOption==6)
             {
                system("cls");
                header();
                subMenu("View Feedbacks");
             }   
                                
          
        }
    }

int CustomerMenu()
    {
       int option;
       cout << "Select any Option of your Choice.  "<< endl;
       cout << "1.  Persons                        "<< endl;
       cout << "2.  Number Of Rooms                "<< endl;
       cout << "3.  Types Of Rooms                 "<< endl;
       cout << "4.  Check_In & Check_Out           "<< endl;
       cout << "5.  Food                           "<< endl;
       cout << "6.  Give Feedbacks                 "<< endl;
       cout << "7.  Log Out                        "<< endl;
       cout << "Enter your Choice:                 "<< endl;
       cin >> option;
       return option;

    }
void CustomerInterface()
    {
       int CustomerOption=0;
       while(CustomerOption!=7)
        {
          header();
          subMenu("CustomerMenu");
          CustomerOption=CustomerMenu();
          if (CustomerOption==1)
             {
                system("cls");
                header();
                subMenu("Persons");
             }
          else if (CustomerOption==2)
             {
                system("cls");
                header();
                subMenu("No of Rooms");
             }   
          else if (CustomerOption==3)
             {
                system("cls");
                header();
                subMenu("Types of Rooms");
             }
          else if (CustomerOption==4)
             {
                system("cls");
                header();
                subMenu("Check_In & Check_Out");
             }
          else if (CustomerOption==5)
             {
                system("cls");
                header();
                subMenu("Foods");
             }
          else if (CustomerOption==6)
             {
                system("cls");
                header();
                subMenu("Feedbacks");
             }   
                                
          
        }
    }

int ManagerMenu()
    {
       int option;
       cout << "Select any Option of your Choice.  "<< endl;
       cout << "1.  Add Rooms                      "<< endl;
       cout << "2.  Remove Rooms                   "<< endl;
       cout << "3.  Bill of Bookings               "<< endl;
       cout << "4.  Log Out                        "<< endl;
       cout << "Enter your Choice:                 "<< endl;
       cin >> option;
       return option;

    }
void ManagerInterface()
    {
       int ManagerOption=0;
       while(ManagerOption!=4)
        {
          header();
          subMenu("ManagerMenu");
          ManagerOption=ManagerMenu();
          if (ManagerOption==1)
             {
                system("cls");
                header();
                subMenu("Add Rooms");
             }
          else if (ManagerOption==2)
             {
                system("cls");
                header();
                subMenu("Remove Rooms");
             }   
          else if (ManagerOption==3)
             {
                system("cls");
                header();
                subMenu("Bills of Bookings");
             }
                                
          
        }
    }    


