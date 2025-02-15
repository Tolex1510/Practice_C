#include <stdio.h>

int main() {
    float oxygen;
    printf("Type oxygen reserves: ");
    scanf("%f", &oxygen);
    if (oxygen < 15) {
        printf("Turn on the emergency system");
    }
    else {
        printf("Normal");
    }
}