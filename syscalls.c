#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include <fcntl.h>

int main() {
    int fd; // File descriptor

    // Open a new file for writing, creating if it doesn't exist
    fd = open("example.txt", O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write some text to the file
    char *text = "Hello, world!\n";
    if (write(fd, text, strlen(text)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    printf("File '' created and written successfully.\n");

    return 0;
}

