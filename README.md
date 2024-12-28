# Zxch OS CLI

Welcome to Zxch OS, a simple command-line interface operating system built for educational purposes. This project is designed to showcase various functionalities such as user authentication, file operations, browsing, math solving, and system information management.

## Features

- **User Setup & Login**: Setup a username and password, or use a setup key to log in.
- **File Operations**: Write to and read from files.
- **Browse**: Use the `w3m` browser to search the web or visit links.
- **Math Solver**: Solve basic mathematical expressions.
- **System Info**: View user information and system details.
- **Time & Settings**: Display current time and system settings.

## Prerequisites

- **C Compiler** (e.g., GCC)
- **w3m** (for browsing functionality)

## How to Build

To compile Zxch OS, use the following command:

```bash
gcc -o zxch zxch.c
```

After building, you can run Zxch OS by executing:

./zxch

Usage

Upon running the program, the CLI will prompt for input. Here's a quick overview of the commands:

$ setup zxch: Begin the setup process. You can create a user account or login using a setup key.

$ setup zxch login: Log in with your username and password or setup key.

$ file: Access file operations to read or write files.

$ browse <link/query>: Open a URL or search query using the w3m browser.

$ math <expression>: Solve a math expression, e.g., $ math 5 + 3.

$ info: Display user information such as username, password status, and setup key.

$ help: Show a list of available commands.

$ time: Display the current time and date.

$ settings: Show or modify settings, such as the setup key or password.


Example

1. Setting up the system:

$ setup zxch
Enter a username: john_doe
Set a password (leave empty for no password): mypassword
Setup complete. Your setup key: ABC123456789DEF
You can log in using '$ setup zxch login'.


2. Logging in:

$ setup zxch login
Enter username: john_doe
Enter password: mypassword
Login successful. Welcome, john_doe!


3. Executing a command:

$ file
File Operations:
1. Write a file
2. Read a file
Choose an option (1/2): 1
Enter file name: test.txt
Enter content: Hello, world!
File written successfully.


4. Browsing:

$ browse https://www.example.com
Launching w3m with query: https://www.example.com


5. Solving math expressions:

$ math 5 + 3
Result: 8



## License

Zxch OS is licensed under the Zxch CL 

This is an educational project designed to demonstrate basic concepts in programming and operating system functionality.

## Disclaimer

This project is for educational purposes only. It is not intended for use in production environments and should not be considered a full-fledged operating system.
