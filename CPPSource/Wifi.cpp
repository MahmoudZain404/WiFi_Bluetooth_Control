
#include "../CPPHeaders/WIFI.hpp"

void Change_WiFi_Name()
{
    std::string command;
    std::vector<std::string> args; 
    std::string New_Name, Old_Name;
    std::cout <<"\nPlease Enter The Old WiFi Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, Old_Name);
    std::cout <<"\nPlease Enter The New WiFi Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, New_Name);
    args = {"connection", "modify", Old_Name, "802-11-wireless.ssid", New_Name} ;
    execvp_Command(command, args);

}
void connection_up_Network(std::string WiFi_Name)
{
    std::string command;
    std::vector<std::string> args;
    command = "nmcli";
    args = {"connection", "up", WiFi_Name} ;
    execvp_Command(command, args);
}
void Change_WiFi_Password()
{
    std::string command;
    std::vector<std::string> args;
    command = "nmcli";
    std::string New_Password, WiFi_Name;
    std::cout <<"\nPlease Enter The WiFi Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, WiFi_Name);
    std::cout <<"\nPlease Enter The New WiFi Password (at least 8 characters): ";
    std::getline(std::cin, New_Password);
    std::cout <<"\nPlease Wait Connection is Being Restarted with New Password..."<<std::endl;
    args = {"connection", "modify", WiFi_Name,"802-11-wireless-security.psk", New_Password} ;
    execvp_Command(command, args);

    connection_up_Network(WiFi_Name);
}




void Remove_Saved_Network() {

    std::string UUID_Input;
    std::cout << "\nPlease Enter The UUID of The Network You Want to Remove: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, UUID_Input);
    const char* UUID = UUID_Input.c_str();

    std::string command;
    std::vector<std::string> args;
    command = "nmcli";
    args = {"connection", "delete", UUID} ;
    execvp_Command(command, args);
}


void Connect_to_WiFi_Net() 
{
    
    std::string command;
    std::vector<std::string> args;
    command = "nmcli";
    std::string SSID_input, Password_input;
    const char *SSID, *Password;
    std::cout << "\nPlease Enter the Network SSID: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, SSID_input);
    SSID=SSID_input.c_str();
    std::cout << "\nPlease Enter the Network Password: ";
    std::getline(std::cin, Password_input);
    Password = Password_input.c_str();
    args = {"device", "wifi", "connect", SSID, "password", Password} ;
    execvp_Command(command, args);
}

void connection_show()
{
    std::string command;
    std::vector<std::string> args;
    command = "nmcli";
    args = {"connection", "show"} ;
    execvp_Command(command, args);
}
void Nearby_WiFi()
{
    std::string command;
    std::vector<std::string> args;
    command = "nmcli";
    args = {"device", "wifi", "list"} ;
    execvp_Command(command, args);

}

void Turn_WiFi_ON_OFF(const char* status) 
{
    std::string command;
    std::vector<std::string> args;
    command = "nmcli";
    args = {"radio", "wifi", status} ;
    std::cout << "\n--------------------\nYour WiFi is: " << status << std::endl;
    execvp_Command(command, args);
}


void Display_WiFi_Status()
{
    std::string command;
    std::vector<std::string> args;
    command = "nmcli";
    args = {"radio", "wifi"} ;
    std::cout << "\n--------------------\nYour WiFi Status is: " << std::endl;
    execvp_Command(command, args);
}


void Wifi_Menu()
{
    while(1)
    {
        int Option_Num;

        std::cout <<"\nWifi Control Program"
        <<"\n-------------------\n" 
        <<"1. Display WiFi Status\n"
        <<"2. Turn WiFi On\n"
        <<"3. Turn WiFi Off\n"
        <<"4. Connect to WiFi Network\n"
        <<"5. Remove a Saved Network\n"
        <<"6. Modify a Saved Network\n"
        <<"7. Search for a Network\n"
        <<"8. Back to Main Menu"<< std::endl;
        std::cout <<  "\nPlease Select Option: ";
        std::cin >> Option_Num;

        switch (Option_Num)
        {
        case (1):
            Display_WiFi_Status();
            break;
        case (2):
            Turn_WiFi_ON_OFF("on");
            break;        
        case (3):
            Turn_WiFi_ON_OFF("off");        
            break;
        case (4):
            std::cout << "\n*---------Press 'Enter' to Extend the List and 'q' to Continue 'Connect to WiFi Network Function'---------*\n"<< std::endl;
            Nearby_WiFi();         
            std::cout << "\nHere is a List of Nearby WiFi Networks" << std::endl;
            Connect_to_WiFi_Net();
            std::cout << "\n--------------------\n" << std::endl;
            break;
        case (5):
            connection_show();
            std::cout << "\nHere is Your Saved WiFi Networks" << std::endl;
            Remove_Saved_Network();
            break;
        case (6):
            int temp;
            std::cout <<"\nWifi Control Program"
            <<"\n-------------------\n" 
            <<"1. Modify WiFi Name\n"
            <<"2. Modify WiFi Password\n"<<std::endl;
            std::cout <<  "\nPlease Select Option: ";
            std::cin >> temp;
            switch(temp)
            {
                case(1):
                    Change_WiFi_Name();
                    break;
                case(2):
                    Change_WiFi_Password();
                    break;
                default:
                    std::cout << "Error" << std::endl;
                    break;
            }
            break;
        case (7):
            std::cout << "\n*---------Press 'Enter' to Extend the List and 'q' to Step Back to WiFi Menu---------*\n"<< std::endl;
            Nearby_WiFi();
            break;

        case(8):
            Main_Menu();
            break;

        default:
                std::cout <<"\nInvalid Input Please Try Again\n";
            break;
        }
    }
    
}
