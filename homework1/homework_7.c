#include <stdio.h>

int main() {
    float frequency;
    printf("Type frequency: ");
    scanf("%f", &frequency);
    if (frequency >= 2.5 && frequency <= 3.5) {
        printf("Stable");
    }
    else {
        printf("Unstable");
    }
}