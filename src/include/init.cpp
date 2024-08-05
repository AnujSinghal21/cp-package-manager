#include "init.hpp"

int initializeProject(string projectName) {
    string mkdirCommand = "mkdir \"" + projectName + "\"";
    int result = 0;
    result = system(mkdirCommand.c_str());
    if (result != 0) {
        return 1;
    }   
    cout << "Project " << projectName << " created successfully" << endl;
    cout << "cd into the project directory to start working" << endl;
    return 0;
}