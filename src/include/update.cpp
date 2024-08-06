#include "update.hpp"

int publishUpdatedLib(string commitMessage, bool remote){
    cout << "Publishing the local library..." << endl;
    string projectPath = getProgramFilesPath();
    string libPath = projectPath + "/lib";
    string newLib = "lib";
    system(("rm -r \"" + libPath + "\"").c_str());
    system(("cp -r \"" + newLib + "\" \"" + projectPath + "\"").c_str());
    if(remote){
        cout << "Publishing the updated library to the remote repository..." << endl;
        chdir(projectPath.c_str());
        system("git add .");
        system(("git commit -m \"" + commitMessage + "\"").c_str());
        system("git push origin main");
    }
    return 0;
}

int pullUpdatedLib(){
    cout << "Pulling the updated library from the remote repository..." << endl;
    string cwd = getCurrentWorkingDirectory();
    string projectPath = getProgramFilesPath();
    chdir(projectPath.c_str());
    system("git pull");
    chdir(cwd.c_str());
    system("rm -r lib");
    system(("cp -r \"" + projectPath + "/lib\" .").c_str());
    cout << "Library updated successfully" << endl;
    return 0;
}