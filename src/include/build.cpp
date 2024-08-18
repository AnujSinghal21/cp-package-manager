#include "build.hpp"
#include <deque>
#include <set>
int F_INTERACTIVE = 0;
int F_MULTIPLE_TESTS = 0;
int F_USE_LL = 0;
int F_BUILD_SIMPLE = 0;

void setFlags(vector<string> & lines){
    for (string line : lines){
        string actualLine = line.substr(0, line.find("//"));
        if (actualLine.find("#define INTERACTIVE") != string::npos){
            F_INTERACTIVE = 1;
        }
        if (actualLine.find("#define MULTIPLE_TESTS") != string::npos){
            F_MULTIPLE_TESTS = 1;
        }
        if (actualLine.find("#define USE_LL") != string::npos){
            F_USE_LL = 1;
        }
        if (actualLine.find("#define BUILD_SIMPLE") != string::npos){
            F_BUILD_SIMPLE = 1;
        }
    }
}

vector<string> getIdentifiers(string& line){
    vector<string> identifiers;
    set<char> delimiters = {' ', '(', ')', '{', '}', ';', ',', '=', '+', '-', '*', '/', '%', '<', '>', '&', '|', '^', '~', '!', '?', ':', '[', ']', '.', '#', '\r', '\n', '\t'};
    string actualLine = line.substr(0, line.find("//"));
    string identifier = "";
    for (char c : actualLine){
        if (delimiters.find(c) != delimiters.end()){
            if (identifier != ""){
                identifiers.push_back(identifier);
                identifier = "";
            }
        }else{
            identifier += c;
        }
    }
    if (identifier != ""){
        identifiers.push_back(identifier);
    }
    return identifiers;
}

void extractTokens(vector<string> &lines, set<string> &usedTokens, set<string> &definedTokens){
    for (string line : lines){
        int isDefine = 0;
        if (line.find("#define") != string::npos){
            isDefine = 1;
        }
        string actualLine = line.substr(0, line.find("//"));
        vector<string> tokensInLine = getIdentifiers(actualLine);
        for (string token : tokensInLine){
            usedTokens.insert(token);
            if (isDefine){
                definedTokens.insert(token);
            }
        }
    }
}

vector<string> getLibraryCodeToInclude(set<string> &usedTokens, set<string> &definedTokens){
    map<string, LibInfo> libInfoMap = readLibraries();
    set<string> librariesToInclude;
    for (string token : usedTokens){
        string defToken = libInfoMap[token].define;
        if (defToken == ""){
            continue;
        }
        if (definedTokens.find(defToken) != definedTokens.end()){
            continue;
        }
        if (libInfoMap[token].libFileName != ""){
            librariesToInclude.insert(defToken);
            for (string dependency : libInfoMap[defToken].dependencies){
                if (definedTokens.find(dependency) != definedTokens.end()){
                    continue;
                }
                librariesToInclude.insert(dependency);
            }
        }
    }
    if (librariesToInclude.size() != 0){
        cout << "Including libraries: ";
        for (auto l: librariesToInclude){
            cout << l << ", ";
        }
        cout << endl;
    }
    vector<string> codeToInclude;
    for (string libName : librariesToInclude){
        LibInfo libInfo = libInfoMap[libName];
        vector<string> code = libInfo.getCode();
        for (string codeLine : code){
            codeToInclude.push_back(codeLine);
        }
    }
    return codeToInclude;
}

int buildCode(string fileName){
    if (fileName.substr(fileName.find_last_of(".") + 1) != "cpp"){
        fileName += ".cpp";
    }
    string buildFileName = "build_" + fileName;
    ofstream buildFile(buildFileName);
    ifstream codeFile(fileName);
    vector<string> lines;
    deque<string> finalLines;
    for (string line; getline(codeFile, line);){
        lines.push_back(line);
    }
    if (lines.size() <= 1){
        cout << "Error: Empty file" << endl;
        return 1;
    }

    // extract the flags and tokens
    setFlags(lines);
    set<string> usedTokens, definedTokens;
    if (!F_BUILD_SIMPLE){
        extractTokens(lines, usedTokens, definedTokens);
    }

    int ignore = 0;
    string metaLine = "";
    for (string line : lines){
        // remove local includes and defines
        if (line.find("#ifdef LOCAL") != string::npos){
            ignore = 1;
        }else if (line.find("#endif") != string::npos){
            ignore = 0;
            continue;
        }
        if (ignore){
            continue;
        }
        if (line.find("// Question:") != string::npos){
            metaLine = line;
            continue;
        }

        finalLines.push_back(line);
    }
    if (!F_BUILD_SIMPLE){
        vector<string> libraryCode = getLibraryCodeToInclude(usedTokens, definedTokens);
        for (int i = libraryCode.size() - 1; i >= 0; i--){
            finalLines.push_front(libraryCode[i]);
        }
    }
    if (F_USE_LL){
        finalLines.push_front("#define int long long");
    }
    finalLines.push_front("using namespace std;");
    finalLines.push_front("#include <bits/stdc++.h>");
    finalLines.push_front(metaLine);

    finalLines.push_back("signed main(){"); 
    if (!F_INTERACTIVE){
        finalLines.push_back("    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);");
    }
    finalLines.push_back("    init();");
    if (F_MULTIPLE_TESTS){
        finalLines.push_back("    int testcases = 1;");
        finalLines.push_back("    cin >> testcases;");
        finalLines.push_back("    for(int i = 0; i < testcases; i++){");
        finalLines.push_back("        solve(i);");
        finalLines.push_back("    }");
    }else{
        finalLines.push_back("    int testcases = 1;");
        finalLines.push_back("    for(int i = 0; i < testcases; i++){");
        finalLines.push_back("        solve(i);");
        finalLines.push_back("    }");
    }
    finalLines.push_back("    return 0;");
    finalLines.push_back("}");
    finalLines.push_back("");

    for (string line : finalLines){
        buildFile << line << endl;
    }
    buildFile.close();
    cout << "Generated build file: " << buildFileName << endl;
    return 0;   
}
