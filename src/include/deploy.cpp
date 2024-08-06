#include "deploy.hpp"

int submitCode(string fileName){
    string scriptPath = getProgramFilesPath() + "/src/scripts/submit.py";
    string scriptCommand = "python3 \"" + scriptPath + "\" \"" + fileName + "\"";
    return system(scriptCommand.c_str());
}