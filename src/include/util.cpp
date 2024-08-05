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
