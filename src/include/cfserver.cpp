#include "util.hpp"

int startCfServer() {
    string programPath = getProgramFilesPath();
    string scriptPath = programPath + "/src/server/app.py";

    string command = "python3 \"" + scriptPath + "\"";
    int result = std::system(command.c_str());

    return 0;
}
