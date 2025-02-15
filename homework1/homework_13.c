#include <stdio.h>

int main() {
    int cosmonauts;
    printf("Type amount of cosmonauts: ");
    scanf("%d", &cosmonauts);
    if (cosmonauts % 2 == 0) {
        printf("Yes");
    }
    else {
        printf("No");
    }
}