#include "util.hpp"

string getProgramFilesPath() {
    char buffer[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
        string::size_type pos = string(buffer).find_last_of("/");
        string path = string(buffer).substr(0, pos);
        pos = path.find_last_of("/");
        return path.substr(0, pos);
    }
    return "";
}

string getCurrentWorkingDirectory() {
    char buffer[PATH_MAX];
    if (getcwd(buffer, sizeof(buffer)) != nullptr) {
        return string(buffer);
    } else {
        perror("getcwd() error");
        return "";
    }
}

vector<string> splitString(string s, char delim) {
    vector<string> parts;
    string part = "";
    for (char c : s) {
        if (c == delim) {
            parts.push_back(part);
            part = "";
        } else {
            part += c;
        }
    }
    parts.push_back(part);
    return parts;
}

string getFileNameFromLink(string url){
    string fileName = "code.cpp";
    vector<string> parts = splitString(url, '/');
    if (parts.size() < 6) {
        return fileName;
    }
    if (parts[3] == "problemset") {
        fileName = "P" + parts[5] + parts[6] + ".cpp";
    } else {
        fileName = "C" + parts[4] + parts[6] + ".cpp";
    }
    return fileName;
}

bool fileAlreadyExists(string filePath) {
    // Check if the file exists
    std::ifstream infile(filePath);
    if (infile.good()) {
        // File already exists
        infile.close();
        return true;
    }
    return false;
}

string cleanSpaces(string s){
    string result = "";
    for (char c : s){
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r'){
            result += c;
        }
    }
    return result;
}

map<string, LibInfo> readLibraries() {
    ifstream confFile("lib/config.csv");
    string line;
    map<string, LibInfo> libInfoMap;
    int line0 = 0;
    while (getline(confFile, line)) {
        if (line0 == 0) {
            line0 = 1;
            continue;
        }
        vector<string> parts = splitString(line, ',');
        for (int i = 0; i < parts.size(); i++) {
            parts[i] = cleanSpaces(parts[i]);
        }
        string libName = parts[0];
        string libFileName = parts[1];
        string define = parts[2];
        vector<string> dependencies;
        for (int i = 3; i < parts.size(); i++) {
            dependencies.push_back(parts[i]);
        }
        libInfoMap[libName] = LibInfo(libName, libFileName, define, dependencies);
        libInfoMap[define] = LibInfo(libName, libFileName, define, dependencies);
    }
    return libInfoMap;
}
