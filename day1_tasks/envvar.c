#include <stdio.h>
#include <stdlib.h>

int main() {
    // Retrieve the value of a specific environment variable (e.g., PATH)
    char *path = getenv("PATH");
    if (path == NULL) {
        fprintf(stderr, "Error: PATH environment variable not found\n");
    } else {
        printf("Value of PATH: %s\n", path);
    }

    // Set a new environment variable
    const char *new_var_name = "MY_VARIABLE";
    const char *new_var_value = "/path/to/some/directory";
    if (setenv(new_var_name, new_var_value, 1) == -1) {
        perror("Error setting new environment variable");
        exit(EXIT_FAILURE);
    } else {
        printf("New environment variable set: %s=%s\n", new_var_name, new_var_value);
    }

    // Retrieve the value of the newly set environment variable
    char *new_var = getenv(new_var_name);
    if (new_var == NULL) {
        fprintf(stderr, "Error: New environment variable not found\n");
    } else {
        printf("Value of %s: %s\n", new_var_name, new_var);
    }

    return 0;
}
