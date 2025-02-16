#include <stdio.h>

typedef union {
    int number;
    char letter;
} Grade;

int main() {
    int type;
    scanf("%d", &type);
    Grade grade[type];
    if (type == 1) {
        scanf("%d", &grade[type].number);
        printf("Grade: %d\n", grade[type].number);
    }
    else if (type == 2) {
        scanf(" %c", &grade[type].letter);
        printf("Grade: %c\n", grade[type].letter);
    }

    return 0;
}