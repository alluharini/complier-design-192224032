#include <stdio.h>
#include <string.h>

int main() {
    char com[30];
    printf("Enter Text : ");
    gets(com);

    if (com[0] == '/' && (com[1] == '/' || com[1] == '*')) {
        if (com[1] == '/')
            printf("It is a Comment line.");
        else {
            int i;
            for (i = 2; i <= 30; i++) {
                if (com[i] == '*' && com[i + 1] == '/') {
                    printf("It is a Comment line.");
                    return 0;
                }
            }
            printf("It is Not a Comment line.");
        }
    } else {
        printf("It is Not a Comment line.");
    }

    return 0;
}
