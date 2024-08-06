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
        return 0;
    } else if (argc >= 3 && args[1] == "run"){
        if (argc == 4 && (args[3] == "-b" || args[3] == "--build")){
            // build the file in arg[2] before running
        }
        // run the file in arg[2]
        return 0;
    }else if (argc >= 3 && args[1] == "test") {
        int f_build = 0;
        int f_interactive = 0;
        int f_invalid = 1;
        if (argc == 4){
            if (args[3] == "-b" || args[3] == "--build"){
                f_build = 1;
                f_invalid = 0;
            } else if (args[3] == "-i" || args[3] == "--interactive"){
                f_interactive = 1;
                f_invalid = 0;
            }
        } else if (argc == 5){
            if ((args[3] == "-b" || args[3] == "--build") && (args[4] == "-i" || args[4] == "--interactive")){
                f_build = 1;
                f_interactive = 1;
                f_invalid = 0;
            }else if ((args[3] == "-i" || args[3] == "--interactive") && (args[4] == "-b" || args[4] == "--build")){
                f_build = 1;
                f_interactive = 1;
                f_invalid = 0;
            }
        }
        if (!f_invalid){
            if (f_build){
                // build the file in arg[2] before running
            }
            if (f_interactive){
                // run the file in arg[2] on interactive test cases
            } else {
                // run the file in arg[2] on test cases file
            }
            return 0;
        }
        // run the file in arg[2] on test cases file
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