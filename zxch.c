#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Define constants
#define MAX_USERNAME 100
#define MAX_PASSWORD 100
#define MAX_BUFFER 1024

// Global variables for user information
char username[MAX_USERNAME];
char password[MAX_PASSWORD];
char setup_key[16];
int is_logged_in = 0;

// Function declarations
void generate_setup_key();
void setup_user();
void login();
void execute_command(const char* command);
void file_operations();
void browse(const char* query);
void math_solver(const char* expression);
void show_info();
void show_help();
void show_time();
void show_settings();
void export_password(const char* new_password);

// Entry point
int main() {
    char input[MAX_BUFFER];
    printf("Welcome to Zxch OS CLI. Type '$ setup zxch' to get started.\n");

    while (1) {
        printf("\n$ ");
        fgets(input, MAX_BUFFER, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if (strncmp(input, "$ setup zxch", 12) == 0) {
            if (strstr(input, "login")) {
                login();
            } else {
                setup_user();
            }
        } else if (is_logged_in) {
            execute_command(input);
        } else {
            printf("You must log in first. Type '$ setup zxch login'.\n");
        }
    }

    return 0;
}

void generate_setup_key() {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < 15; i++) {
        setup_key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    setup_key[15] = '\0';
}

void setup_user() {
    printf("Setting up Zxch OS...\n");
    printf("Enter a username: ");
    fgets(username, MAX_USERNAME, stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove newline character

    printf("Set a password (leave empty for no password): ");
    fgets(password, MAX_PASSWORD, stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove newline character

    generate_setup_key();
    printf("Setup complete. Your setup key: %s\n", setup_key);
    printf("You can log in using '$ setup zxch login'.\n");
}

void login() {
    char input_username[MAX_USERNAME];
    char input_password[MAX_PASSWORD];
    char input_key[16];

    printf("Enter username: ");
    fgets(input_username, MAX_USERNAME, stdin);
    input_username[strcspn(input_username, "\n")] = '\0'; // Remove newline character

    if (strcmp(input_username, username) != 0) {
        printf("Invalid username.\n");
        return;
    }

    if (strlen(password) > 0) {
        printf("Enter password: ");
        fgets(input_password, MAX_PASSWORD, stdin);
        input_password[strcspn(input_password, "\n")] = '\0';

        if (strcmp(input_password, password) != 0) {
            printf("Incorrect password.\n");
            return;
        }
    } else {
        printf("Enter setup key: ");
        fgets(input_key, 16, stdin);
        input_key[strcspn(input_key, "\n")] = '\0';

        if (strcmp(input_key, setup_key) != 0) {
            printf("Incorrect setup key.\n");
            return;
        }
    }

    is_logged_in = 1;
    printf("Login successful. Welcome, %s!\n", username);
}

void execute_command(const char* command) {
    if (strcmp(command, "$ file") == 0) {
        file_operations();
    } else if (strncmp(command, "$ browse ", 9) == 0) {
        browse(command + 9);
    } else if (strncmp(command, "$ math ", 7) == 0) {
        math_solver(command + 7);
    } else if (strcmp(command, "$ info") == 0) {
        show_info();
    } else if (strcmp(command, "$ help") == 0) {
        show_help();
    } else if (strcmp(command, "$ time") == 0) {
        show_time();
    } else if (strcmp(command, "$ settings") == 0) {
        show_settings();
    } else if (strncmp(command, "$ export password=", 18) == 0) {
        export_password(command + 18);
    } else {
        printf("Unknown command. Type '$ help' for a list of commands.\n");
    }
}

void file_operations() {
    char choice[MAX_BUFFER];
    char filename[MAX_BUFFER];
    char content[MAX_BUFFER];

    printf("File Operations:\n");
    printf("1. Write a file\n");
    printf("2. Read a file\n");
    printf("Choose an option (1/2): ");
    fgets(choice, MAX_BUFFER, stdin);
    choice[strcspn(choice, "\n")] = '\0';

    if (strcmp(choice, "1") == 0) {
        printf("Enter file name: ");
        fgets(filename, MAX_BUFFER, stdin);
        filename[strcspn(filename, "\n")] = '\0';

        printf("Enter content: ");
        fgets(content, MAX_BUFFER, stdin);
        content[strcspn(content, "\n")] = '\0';

        FILE* file = fopen(filename, "w");
        if (file) {
            fprintf(file, "%s", content);
            fclose(file);
            printf("File written successfully.\n");
        } else {
            printf("Error writing file.\n");
        }
    } else if (strcmp(choice, "2") == 0) {
        printf("Enter file name: ");
        fgets(filename, MAX_BUFFER, stdin);
        filename[strcspn(filename, "\n")] = '\0';

        FILE* file = fopen(filename, "r");
        if (file) {
            printf("File content:\n");
            while (fgets(content, MAX_BUFFER, file)) {
                printf("%s", content);
            }
            fclose(file);
        } else {
            printf("Error reading file.\n");
        }
    } else {
        printf("Invalid option.\n");
    }
}

void browse(const char* query) {
    char command[MAX_BUFFER];

    if (strstr(query, "http://") || strstr(query, "https://")) {
        snprintf(command, sizeof(command), "w3m '%s'", query);
    } else {
        snprintf(command, sizeof(command), "w3m 'https://www.google.com/search?q=%s'", query);
    }

    printf("Launching w3m with query: %s\n", query);

    int result = system(command);
    if (result != 0) {
        printf("Error: Unable to execute w3m. Make sure it is installed on your system.\n");
    }
}

void math_solver(const char* expression) {
    int num1, num2;
    char operator;

    if (sscanf(expression, "%d %c %d", &num1, &operator, &num2) == 3) {
        switch (operator) {
            case '+': printf("Result: %d\n", num1 + num2); break;
            case '-': printf("Result: %d\n", num1 - num2); break;
            case '*': printf("Result: %d\n", num1 * num2); break;
            case '/': 
                if (num2 != 0) printf("Result: %d\n", num1 / num2);
                else printf("Error: Division by zero.\n");
                break;
            default: printf("Invalid operator.\n");
        }
    } else {
        printf("Invalid math expression.\n");
    }
}

void show_info() {
    printf("User Info:\n");
    printf("Username: %s\n", username);
    printf("Password: %s\n", strlen(password) > 0 ? "Set" : "Not Set");
    printf("Setup Key: %s\n", setup_key);
}

void show_help() {
    printf("Commands:\n");
    printf("$ file - File operations (write/read files)\n");
    printf("$ browse <link/query> - Browse something (requires w3m)\n");
    printf("$ math <expression> - Solve math expressions\n");
    printf("$ info - Show user and system info\n");
    printf("$ help - Show this help message\n");
    printf("$ time - Show current time and date\n");
    printf("$ settings - Show and change settings\n");
}

void show_time() {
    time_t now = time(NULL);
    printf("Current time: %s", ctime(&now));
}

void show_settings() {
    printf("Settings:\n");
    printf("$ export password=<new password>\n");
    printf("$ setup key - Display setup key\n");
}

void export_password(const char* new_password) {
    strncpy(password, new_password, MAX_PASSWORD - 1);
    password[MAX_PASSWORD - 1] = '\0';
    printf("Password updated successfully.\n");
}
