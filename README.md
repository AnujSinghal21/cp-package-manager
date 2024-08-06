# cp-package-manager (CPM)
A library with an integrated tool to help in competitive programming.

## Installation

## Usage
`cpm --help` or `cpm -h`: Prints the usage documentation of program.

`cpm init <projectName>`: Creates the project folder and imports library to it.

`cpm cfserver`: Start the server to work with the CPM_CF_Extension to parse testcases from codeforces.com (Need CPM_CF_Extension to work).

`cpm start <fileName/link>`: Creates a new file and copies the template to it.

`cpm run <fileName> [-b]`: Run the given file's corresponding build file (-b to build again) interactively through terminal.

`cpm test <fileName> [-b]`: Run the given file's corresponding build file (-b to build again) on the predefined testcases in `testcases/` folder.

`cpm deploy <fileName> [-b]`: Submits the file to codeforces and optionally build the file again before submission (needs CPM_CF_Extension to be installed in default browser).

## Development
