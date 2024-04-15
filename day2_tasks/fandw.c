#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char* commands[] = {"ls", "echo Hello", "pwd", "date"};
    int num_commands = sizeof(commands) / sizeof(commands[0]);
    
    // Loop to fork child processes
    for (int i = 0; i < num_commands; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            // Error occurred
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            printf("Child process %d executing command: %s\n", getpid(), commands[i]);
            system(commands[i]);
            exit(EXIT_SUCCESS);
        }
    }
    
    // Parent process waits for all child processes to complete
    for (int i = 0; i < num_commands; i++) {
        int status;
        pid_t pid = wait(&status);
        if (pid > 0) {
            if (WIFEXITED(status)) {
                printf("Child process %d exited with status %d\n", pid, WEXITSTATUS(status));
            } else {
                printf("Child process %d terminated abnormally\n", pid);
            }
        } else {
            perror("wait");
        }
    }
    
    return 0;
}
