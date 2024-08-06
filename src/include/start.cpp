#include "start.hpp"


int startSolving(string problem) {
    string fileName = "code.cpp";
    string url = "https://codeforces.com/problemset/problem/33/A";
    if (problem.substr(0, 8) == "https://") {
        url = problem;
        fileName = getFileNameFromLink(problem);
    } else {
        vector<string> extension = splitString(problem, '.');
        if (extension[extension.size()-1] != "cpp" ){
            fileName = problem + ".cpp";
        }else{
            fileName = problem;
        }
    }
    if (fileAlreadyExists(fileName)) {
        cout << "File already exists" << endl;
        return 1;
    }

    ofstream file(fileName);
    ifstream my_template("lib/template.cpp");
    file << "// Question: " << url << endl;
    file << my_template.rdbuf();

    return 0;
}