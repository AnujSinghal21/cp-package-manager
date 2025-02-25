#include "run.hpp"

int runCode(string fileName){
    if (fileName.substr(fileName.find_last_of(".") + 1) != "cpp"){
        fileName += ".cpp";
    }
    if (fileName.substr(0, 6) != "build_"){
        fileName = "build_" + fileName;
    }
    string command = "g++ " + fileName + " -o " + fileName + ".out";
    system(command.c_str());
    command = "./" + fileName + ".out";
    system(command.c_str());
    return 0;
}
