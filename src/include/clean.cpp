#include "clean.hpp"
int cleanProject() {
    system("rm -r testcases/");
    system("mkdir testcases");
    system("rm build_*");
    cout << "Project cleaned successfully" << endl;
    return 0;
}