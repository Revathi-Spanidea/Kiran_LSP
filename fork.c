#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid; // Process ID

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Error occurred
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID=%d\n", getpid());
        printf("Child's parent process: PPID=%d\n", getppid());
    } else {
        // Parent process
        printf("Parent process: PID=%d\n", getpid());
        printf("Parent's parent process: PPID=%d\n", getppid());
    }

    return 0;
}

