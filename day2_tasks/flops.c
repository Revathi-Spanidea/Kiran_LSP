#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    // Creating a directory
    const char* dir_name = "test_directory";
    if (mkdir(dir_name, 0777) == -1) {
        perror("mkdir");
        exit(EXIT_FAILURE);
    }
    printf("Directory '%s' created successfully.\n", dir_name);

    // Listing directory contents
    printf("Contents of directory '%s':\n", dir_name);
    DIR *dir = opendir(dir_name);
    if (dir) {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            printf("%s\n", entry->d_name);
        }
        closedir(dir);
    } else {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Creating a file in the directory
    const char* file_name = "test_file.txt";
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "This is a test file.\n");
    fclose(file);
    printf("File '%s' created successfully.\n", file_name);

    // Deleting the file
    if (unlink(file_name) == -1) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }
    printf("File '%s' deleted successfully.\n", file_name);

    // Deleting the directory
    if (rmdir(dir_name) == -1) {
        perror("rmdir");
        exit(EXIT_FAILURE);
    }
    printf("Directory '%s' deleted successfully.\n", dir_name);

    return 0;
}
