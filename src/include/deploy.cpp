#include "deploy.hpp"

int submitCode(string fileName){
    if (fileName.substr(fileName.find_last_of(".") + 1) != "cpp"){
        fileName += ".cpp";
    }
    if (fileName.substr(0, 6) != "build_"){
        fileName = "build_" + fileName;
    }

    string scriptPath = getProgramFilesPath() + "/src/scripts/submit.py";
    string scriptCommand = "python3 \"" + scriptPath + "\" \"" + fileName + "\"";
    return system(scriptCommand.c_str());
}