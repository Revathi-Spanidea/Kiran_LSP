#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    char *filename = "examfile.txt";
    mode_t mode = S_IRUSR;

    
    int fd = open(filename, O_CREAT | O_WRONLY, mode);
    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
    
   if (chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) == -1) {
        perror("Error while changing permissions");
        exit(EXIT_FAILURE);
    }

    printf("File permissions changed successfully.\n");

    return 0;
}
