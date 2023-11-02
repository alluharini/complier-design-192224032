#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;

    // Common subexpression
    int common = a + b;

    int result1 = common * 2;  // Reuses the common subexpression
    int result2 = common - 1;  // Reuses the common subexpression

    printf("Common Subexpression: %d\n", common);
    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);

    return 0;
}

