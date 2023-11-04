#include <stdio.h>
#include <string.h>

int main() {
    // Replace this with your C code as a string
    const char* c_code = "my name is harini \n my regno - 192224032 \n";

    int spaceCount = 0;
    int newlineCount = 0;

    for (int i = 0; c_code[i] != '\0'; i++) {
        if (c_code[i] == ' ' || c_code[i] == '\t') {
            spaceCount++;
        } else if (c_code[i] == '\n') {
            newlineCount++;
        }
    }

    printf("White spaces: %d\n", spaceCount);
    printf("Newline characters: %d\n", newlineCount);

    return 0;
}

