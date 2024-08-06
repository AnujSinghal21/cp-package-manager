#include "test.hpp"
#include <dirent.h>
#include <algorithm>

vector<string> getFiles(string path) {
    DIR *dir;
    struct dirent *ent;
    vector<string> files;
    if ((dir = opendir(path.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            string fileName = ent->d_name;
            if (fileName != "." && fileName != "..") {
                files.push_back(fileName);
            }
        }
        closedir(dir);
    } else {
        return files;
    }
    return files;
}

struct testcase {
    string input;
    string output;
};

vector<testcase> getTestCases(vector<string>& filenames, string text) {
    vector<testcase> testcases;
    for (const auto& filename : filenames) {
        if (filename.find(text) != string::npos) {
            testcase t;
            if (filename.find("input_") == 0) {
                t.input = filename;
                string outputFile = "output_" + filename.substr(6); 
                auto it = find(filenames.begin(), filenames.end(), outputFile);
                if (it != filenames.end()) {
                    t.output = *it;
                }
                testcases.push_back(t);
            }
        }
    }
    return testcases;
}


int testCode(string fileName) {
    // find test cases;
    string question = splitString(fileName, '.')[0];
    if (question.substr(0, 6) == "build_") {
        question = question.substr(6);
    }
    vector<string> files = getFiles("./testcases");
    vector<testcase> testcases = getTestCases(files, question);
    if (testcases.size() == 0) {
        cout << "No test cases found for " << fileName << endl;
        return 0;
    }
    // Compile the code
    if (fileName.substr(0, 6) != "build_") {
        fileName = "build_" + fileName;
    }
    string buildCommand = "g++ " + fileName + " -o " + fileName + ".out";
    int result = system(buildCommand.c_str());
    if (result != 0) {
        return 1;
    }
    cout << "Running " << testcases.size() << " testcase(s) for " << fileName << endl;
    int passed = 0;
    for (int i = 0; i < testcases.size(); i++) {
        testcase t = testcases[i];
        string command = "./" + fileName + ".out < testcases/" + t.input + " > temp_output.txt";
        system(command.c_str());
        command = "diff -w temp_output.txt testcases/" + t.output + " > /dev/null";
        result = system(command.c_str());
        if (result != 0) {
            cout << "\033[31mTest case " << (i+1) << " failed\033[0m" << endl;
            cout << "\033[36mInput: " << t.input << endl;
            ifstream inputFile("testcases/" + t.input);
            cout << inputFile.rdbuf() << "\033[0m";
            cout << "\033[35mExpected Output: " << t.output << endl;
            ifstream expectedOutput("testcases/" + t.output);
            cout << expectedOutput.rdbuf() << "\033[0m";
            ifstream actualOutput("temp_output.txt");
            cout << "\033[32mYour Output: " << endl;
            cout << actualOutput.rdbuf() << "\033[0m";
        } else {
            passed++;
            cout << "\033[32mTest case " << (i+1) << " passed\033[0m" << endl;
        }
    }
    if (passed == testcases.size()) {
        cout << "\033[32mAll test cases passed\033[0m" << endl;
    }

    return 0;
}