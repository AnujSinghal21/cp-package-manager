#include "update.hpp"

int publishUpdatedLib(string commitMessage, bool remote){
    cout << "Updating the local library..." << endl;
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
        system("git push origin master");
    }
    return 0;
}