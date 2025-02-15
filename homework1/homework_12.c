#include <stdio.h>

int main() {
    int angle;
    printf("Type angle: ");
    scanf("%d", &angle);
    if (angle >= -180 && angle <= 180) {
        printf("In range");
    }
    else {
        printf("Not in range");
    }
}