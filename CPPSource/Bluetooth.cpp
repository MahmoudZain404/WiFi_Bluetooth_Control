#include "../CPPHeaders/BLUETOOTH.hpp"


void Connect_to_Device()
{
    std::string MAC_Add;
    std::cout<<"\nPlease Enter the Device MAC Address: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, MAC_Add);
    std::string command;
    std::vector<std::string> args;
    command = "bluetoothctl";
    args = {"pair", MAC_Add} ;
    execvp_Command(command, args);

    args = {"connect", MAC_Add} ;
    execvp_Command(command, args);

}

void Bluetooth_list() 
{
    std::string command;
    std::vector<std::string> args;
    command = "hcitool";
    args = {"scan"} ;
    execvp_Command(command, args);
}

void Bluetooth_On_Off(const char* status)
{
    std::string command;
    std::vector<std::string> args;
    command = "bluetoothctl";
    args = {"power", status} ;
    execvp_Command(command, args);
}


void Bluetooth_Show()
{
    std::string command;
    std::vector<std::string> args;
    command = "bluetoothctl";
    args = {"show"} ;
    execvp_Command(command, args);
}



void Bluetooth_Menu()
{
    while(1)
    {
        int Option_Num;

        std::cout <<"\nBluetooth Control Program"
        <<"\n-------------------\n" 
        <<"1. Display Bluetooth Status\n"
        <<"2. Turn Bluetooth On\n"
        <<"3. Turn Bluetooth Off\n"
        <<"4. Connect to Bluetooth Device\n"
        <<"5. Back to Main Menu"<< std::endl;
        std::cout <<  "\nPlease Select Option: ";
        std::cin >> Option_Num;
        std::cout <<  "\n";

        switch (Option_Num)
        {
            case(1):
                Bluetooth_Show();
                break;
            case(2):
                Bluetooth_On_Off("on");
                break;
            case(3):
                Bluetooth_On_Off("off");
                break;
            case(4):
                Bluetooth_On_Off("on");
                Bluetooth_list();
                std::cout <<  "\nHere is a List of Nearby Bluetooth Devices With There MAC Address (if You Device is Not Listed Please Try Again)\n";
                Connect_to_Device();
                break;
            case(5):
                Main_Menu();
                break;
            
            default:
                std::cout <<"\nInvalid Input Please Try Again\n";
                break;


        }

    }
    
};