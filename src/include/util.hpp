#ifndef UTIL_HPP
#define UTIL_HPP    

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <limits.h>
#include <map>
using namespace std;

class LibInfo{
    public:
    string libName;
    string libFileName;
    string define;
    vector<string> dependencies;
    LibInfo(){
        this->libName = "";
        this->libFileName = "";
        this->define = "";
        this->dependencies = {};
    }
    LibInfo(string libName, string libFileName, string define, vector<string> dependencies){
        this->libName = libName;
        this->libFileName = libFileName;
        this->define = define;
        this->dependencies = dependencies;
    }
    vector<string> getCode(){
        string libFileName = "lib/" + this->libFileName;
        ifstream file(libFileName);
        string line;
        vector<string> code;
        int i = 0;
        while (getline(file, line)){
            if (i < 2){
                i++;
                continue;
            }
            code.push_back(line);
        }
        return code;
    }
};

string getProgramFilesPath();
string getCurrentWorkingDirectory();
vector<string> splitString(string s, char delim);
string getFileNameFromLink(string url);
bool fileAlreadyExists(string filePath);
map<string, LibInfo> readLibraries();

#endif