#include "build.hpp"

int buildCode(string fileName){
    string buildFileName = "build_" + fileName;
    ofstream buildFile(buildFileName);
    // Simply copy for now
    ifstream codeFile(fileName);
    buildFile << codeFile.rdbuf(); 
    buildFile.close();
    cout << "Generated build file: " << buildFileName << endl;
    return 0;   
}
