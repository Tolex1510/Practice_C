#include <stdio.h>

typedef union {
    int int_num;
    float float_num;
    char string[50];
} Data;

int main() {
    int number;
    scanf("%d", &number);
    Data data;
    if (number == 1) {
        scanf("%d", &data.int_num);
        printf("Integer: %d\n", data.int_num);
    }
    else if (number == 2) {
        scanf("%f", &data.float_num);
        printf("Float: %.2f\n", data.float_num);
    }
    else if (number == 3) {
        scanf("%s", &data.string);
        printf("String: %s\n", data.string);
    }

    return 0;
}