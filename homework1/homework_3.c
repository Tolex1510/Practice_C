#include <stdio.h>

int main() {
    char mark;
    printf("Type mark: ");
    scanf("%c", &mark);
    if (mark >= 'A' && mark <= 'Z') {
        printf("Yes");
    }
    else {
        printf("No");
    }
}