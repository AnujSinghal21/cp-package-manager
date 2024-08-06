#ifndef UTIL_HPP
#define UTIL_HPP    

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <limits.h>
using namespace std;

string getProgramFilesPath();
string getCurrentWorkingDirectory();
vector<string> splitString(string s, char delim);

#endif