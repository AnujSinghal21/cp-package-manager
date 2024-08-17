#include "install.hpp"


int installLibCode(string fileName, string libName){
    map<string, LibInfo> libInfoMap = readLibraries();
    LibInfo libInfo = libInfoMap[libName];
    if (libInfo.libName == ""){
        cout << "Library not found" << endl;
        return 1;
    }
    vector<string> code = libInfo.getCode();
    if (fileName.substr(fileName.find_last_of(".") + 1) != "cpp"){
        fileName += ".cpp";
    }

    ifstream codeFile(fileName);
    vector<string> lines, finalLines;
    for (string line; getline(codeFile, line);){
        lines.push_back(line);
    }
    if (lines.size() <= 1){
        cout << "Error: Empty file" << endl;
        return 1;
    }

    int added = 0;
    string metaLine = "";
    for (string line : lines){
        if (line.find("#ifdef LOCAL") != string::npos){
            finalLines.push_back(line);
            finalLines.push_back("#define "+libInfo.define);
            added = 1;
        }else if (line.find("#endif") != string::npos){
            finalLines.push_back(line);
            for (string codeLine : code){
                finalLines.push_back(codeLine);
            }
            added = 2;
        }else{
            finalLines.push_back(line);
        }
    }
    if (added != 2){
        finalLines.clear();
        finalLines.push_back(lines[0]);
        finalLines.push_back(lines[1]);
        finalLines.push_back(lines[2]);
        for (string codeLine : code){
            finalLines.push_back(codeLine);
        }
        for (int i = 3; i < lines.size(); i++){
            finalLines.push_back(lines[i]);
        }
    }

    ofstream buildFile(fileName);
    for (string line : finalLines){
        buildFile << line << endl;
    }
    buildFile.close();
    return 0;
}

