#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <limits.h>
#include "include/util.hpp"
#include "include/cfserver.hpp"
#include "include/init.hpp"
#include "include/start.hpp"
#include "include/deploy.hpp"
#include "include/run.hpp"
#include "include/test.hpp"
#include "include/build.hpp"
using namespace std;

int print_doc(){
    cout << "Usage: cpm [command] [options]" << endl;
    cout << "Commands:" << endl;
    cout << "  init <project_name>     Create a new project" << endl;
    cout << "  cfserver                Start the codeforces server" << endl;
    cout << "  build <filename>        Build the file" << endl;
    cout << "  install <filename> <package_name>  Install the library file" << endl;
    cout << "  run <filename> [-b]     Run the file" << endl;
    cout << "  test <filename> [-b]    Run the file on test cases" << endl;
    cout << "  start <filename/link>   Create new file by name/codeforces link" << endl;
    cout << "  deploy <filename> [-b]  Submit the file" << endl;
    cout << "  publish                 Publish the library" << endl;    
    cout << "  update                  Update the local copy of library from github" << endl;
    cout << "  --help, -h              Display this help message" << endl;
    return 0;
}

int main(int argc, char *argv[]) {
    vector<string> args(argv, argv + argc);
    if (argc == 1){
        return print_doc();
    } else if (argc == 2 && (args[1] == "--help" || args[1] == "-h")){
        return print_doc();
    } else if (argc == 3 && args[1] == "init"){
        // use arg[2] as the project name
        return initializeProject(args[2]);
    } else if (argc == 2 && args[1] == "cfserver"){
        // start the server
        return startCfServer();
    } else if (argc == 3 && args[1] == "build"){
        // build the file in arg[2]
        return buildCode(args[2]);
    } else if (argc >= 3 && args[1] == "run"){
        if (argc == 4 && (args[3] == "-b" || args[3] == "--build")){
            // build the file in arg[2] before running
            buildCode(args[2]);
        }
        // run the file in arg[2]
        return runCode(args[2]);
    }else if (argc >= 3 && args[1] == "test") {
        if (argc == 4 && (args[3] == "-b" || args[3] == "--build")){
            // build the file in arg[2] before running
            buildCode(args[2]);
        }
        // run the file in arg[2] on test cases file
        return testCode(args[2]);
    } else if (argc == 4 && args[1] == "install"){
        //install the package arg[3] in the arg[2] file
        return 0;
    } else if (argc == 3 && args[1] == "start") {
        // if a filename is given then create a new file with that name
        // else if cf problem link is given then create a new file with the problem name and fetch test cases
        return startSolving(args[2]);
    } else if (argc >= 3 && args[1] == "deploy") {
        if (argc == 4 && (args[3] == "-b" || args[3] == "--build")){
            // build the file in arg[2] before submitting
        }
        // submit the file in arg[2] if it is a codeforces problem
        return submitCode(args[2]);
    } else if (argc >= 2 && args[1] == "publish") {
        // publish the library locally
        if (argc == 3 && (args[2] == "-r" || args[2] == "--remote")) {
            // publish the library on remote repository 
        }
        return 0;
    } else if (argc == 2 && args[1] == "update") {
        // update the library from remote repository
        return 0;
    }

    cout << "Invalid usage. Please refer to below usage instructions:" << endl;
    print_doc();
    return 0;
}