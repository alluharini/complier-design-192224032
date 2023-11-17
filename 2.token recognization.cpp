#include <stdio.h>
#include <string.h> // Include the string.h header
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter a C expression: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \t\n");

    while (token != NULL) {
        if (isalpha(token[0]) || token[0] == '_') {
            printf("Identifier: %s\n", token);
        } else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            printf("Constant: %s\n", token);
        } else if (strchr("+-*/=<>", token[0])) {
            printf("Operator: %s\n", token);
        }

        token = strtok(NULL, " \t\n");
    }

    return 0;
}

