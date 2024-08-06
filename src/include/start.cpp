#include "start.hpp"


int startSolving(string problem) {
    string fileName = "code.cpp";
    string url = "https://codeforces.com/problemset/problem/33/A";
    if (problem.substr(0, 8) == "https://") {
        url = problem;
        vector<string> parts = splitString(url, '/');
        if (parts.size() < 6) {
            cout << "Invalid URL" << endl;
            return 1;
        }
        if (parts[3] == "problemset") {
            fileName = "P" + parts[5] + parts[6] + ".cpp";
        } else {
            fileName = "C" + parts[4] + parts[6] + ".cpp";
        }
    } else {
        vector<string> extension = splitString(problem, '.');
        if (extension[extension.size()-1] != "cpp" ){
            fileName = problem + ".cpp";
        }else{
            fileName = problem;
        }
    }
    ofstream file(fileName);
    ifstream my_template("lib/template.cpp");
    file << "// Question: " << url << endl;
    file << my_template.rdbuf();

    return 0;
}