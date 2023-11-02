#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    int result;

    // Live code: This block will be executed
    if (x > y) {
        result = x + y;
    }

    // Dead code: This block will never be executed
    if (y > x) {
        result = y - x;
    }

    printf("Result: %d\n", result);

    return 0;
}

