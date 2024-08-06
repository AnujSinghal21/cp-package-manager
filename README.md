# cp-package-manager (CPM)
A library with an integrated tool to help in competitive programming.

## Installation

### Browser extension
Go to `manage extensions` tab on Chrome/Edge and switch on developer mode.

Then, choose the `load unpacked` option and select the `CPM_CF_Extension` folder inside `src` folder to add the extension.

### CF server
- Make sure `python3` is installed on your system.
- Install `flask` and `flask-cors` packages.

### CPM
- You need to be on a UNIX system (WSL also works) to use this program.
- Make sure you have `g++` installed on your system.
- After cloning the repository, go to the `src` folder and run `make` command to build the project.
- Then add the path to the repository's `bin` folder to environment's PATH variable. 
- Run `cpm -h` in a terminal to verify installation.

## Usage
`cpm --help` or `cpm -h`: Prints the usage documentation of program.

`cpm init <projectName>`: Creates the project folder and imports library to it.

`cpm cfserver`: Start the server to work with the CPM_CF_Extension to parse testcases from codeforces.com (Need CPM_CF_Extension to work).
Run this from a project folder and let the server run while you are coding and stop it after use.

`cpm start <fileName/link>`: Creates a new file and copies the template to it.

`cpm build <fileName>`: Creates a build file by adding code of all the used library functions and templates in given file.

`cpm install <fileName> <package>`: Imports the code of given package (library function) into given file for modifications.

`cpm run <fileName> [-b]`: Run the given file's corresponding build file (-b to build again) interactively through terminal.

`cpm test <fileName> [-b]`: Run the given file's corresponding build file (-b to build again) on the predefined testcases in `testcases/` folder.

`cpm deploy <fileName> [-b]`: Submits the file to codeforces and optionally build the file again before submission (needs CPM_CF_Extension to be installed in default browser).

`cpm publish [-r]`: Described in development section.

`cpm update`: Download updated version of library as well as program from GitHub repository.

## Development

If you want to help in extending the library or the functionality of the program, please use the `cpm publish -r` command to push your changes.
If you are a contributor you can directly push the changes, otherwise you will need to create a pull request.

Few things to note:
- Refer to `contribute.md` in lib folder for instructions regarding conventions about adding a library.
- If you just want to customize the library for personal use, feel free to fork the repo and use it.