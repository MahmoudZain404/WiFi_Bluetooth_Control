#ifndef Main_Menu_H
#define MAIN_MENU_H

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>

extern void Main_Menu();

void execvp_Command(const std::string &command, const std::vector<std::string> &args);


#endif