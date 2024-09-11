#include <iostream>
#include <stdlib.h>
#include "../CPPHeaders/BLUETOOTH.hpp"
#include "../CPPHeaders/WIFI.hpp"
#include "../CPPHeaders/Main_Menu.hpp"




extern void Main_Menu()
{
    while(1)
    {
        int Option_Num;
        std::cout <<  "\nMain Menu\n--------------------\n1- Wifi Control" << "\n" <<  "2- Bluetooth Control" << "\n" << "3- Exit" << std::endl;
        std::cout <<  "\nPlease Select Option: ";
        std::cin >> Option_Num;
        std::cout <<  "\n";
        switch (Option_Num)
        {
            case (1):
                Wifi_Menu();
                break;

            case (2):
                Bluetooth_Menu();
                break;
            case (3):
                exit(0);
            default:
                std::cout <<"\nInvalid Input Please Try Again\n";
                break;
        }
    }

}
 
 void execvp_Command(const std::string &command, const std::vector<std::string> &args) {
     pid_t pid = fork();  // Create a new process

    if (pid == -1) {
        // Fork failed
        perror("fork failed");
        return;
    } else if (pid == 0) {
        // Child process
        std::vector<char*> c_args;
        c_args.push_back(strdup(command.c_str()));

        // Convert args to C-style strings
        for (const std::string& arg : args) {
            c_args.push_back(strdup(arg.c_str()));
        }
        c_args.push_back(nullptr);

        // Execute the command in the child process
        if (execvp(command.c_str(), c_args.data()) == -1) {
            perror("execvp failed");
        }

        // Free memory (this will only be reached if execvp fails)
        for (char* arg : c_args) {
            free(arg);
        }

        _exit(EXIT_FAILURE);  // Exit the child process if execvp fails
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);  // Wait for the child process to complete

        /*if (WIFEXITED(status)) {
            std::cout << "Child process exited with status: " << WEXITSTATUS(status) << std::endl;
        }*/
    }
}

