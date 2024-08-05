#include "util.hpp"
#include "cfserver.hpp"

int startCfServer() {
    const string programPath = getProgramFilesPath();
    const string scriptPath = programPath + "/src/server/app.py";
    const string command = "python3 \"" + scriptPath + "\"";
    system(command.c_str());
    return 0;
}
