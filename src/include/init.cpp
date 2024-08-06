#include "init.hpp"

int initializeProject(string projectName) {
    string mkdirCommand = "mkdir \"" + projectName + "\"";
    int result = 0;
    result = system(mkdirCommand.c_str());
    if (result != 0) {
        return 1;
    }

    chdir(projectName.c_str());
    mkdirCommand = "mkdir testcases";
    result = system(mkdirCommand.c_str());
    string copyLibCommand = "cp -r \"" + getProgramFilesPath() + "/lib\" .";
    result = system(copyLibCommand.c_str());
    cout << "Project " << projectName << " created successfully" << endl;
    cout << "cd into the project directory to start working" << endl;
    return 0;
}