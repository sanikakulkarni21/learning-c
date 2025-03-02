#include <stdio.h>

int main() {
    FILE *file;
    char buffer[256];  // Buffer to store the content

    // Open the file in read mode
    file = fopen("example.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Move the file pointer to the 10th byte from the beginning of the file
    fseek(file, 10, SEEK_SET);

    // Read and print the content from the 10th byte
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Content from the 10th byte: %s", buffer);
    } else {
        printf("Error or end of file reached.\n");
    }

    // Close the file
    fclose(file);

    return 0;
}
