#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char buffer[256];  // Buffer to store the line read from the file

    // Open the file in read mode
    file = fopen("example.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read each line from the file and print it to the console
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Print the line read from the file
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}
