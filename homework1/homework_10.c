#include <stdio.h>

int main() {
    int degree;
    printf("Type temperature: ");
    scanf("%d", &degree);
    if (degree >= -150 && degree <= 120) {
        printf("Normal temperature");
    }
    else {
        printf("Not normal temperature");
    }
}