#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc > 3) {
        fprintf(stderr, "Error: More than 3 arguments have been passed. Usage: %s arg1 arg2 arg3\n", argv[0]);


        return EXIT_FAILURE;
    }
   

    char *source_path = argv[1];
    char *destination_path = argv[2];

    int source_fd = open("/home/kiransai/source.txt", O_RDONLY | O_WRONLY | O_CREAT, S_IRUSR);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }




    
    int destination_fd = open("/home/kiransai/destination.txt", O_WRONLY | O_CREAT  , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (destination_fd == -1) {


        perror("Error opening destination file");
        
        exit(EXIT_FAILURE);
    }

   
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (bytes_read == -1) {
        perror("Error reading from source file");
        close(source_fd);
        
        exit(EXIT_FAILURE);
        }
        bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
           close(source_fd);
            close(destination_fd);
            exit(EXIT_FAILURE);
        }
    }

    
    if (close(source_fd) == -1) {
        perror("Error closing source file");
        exit(EXIT_FAILURE);
    }
    if (close(destination_fd) == -1) {
        perror("Error closing destination file");
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully.\n");

    return 0;
}

