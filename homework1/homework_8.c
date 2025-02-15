#include <stdio.h>

int main() {
    int cargo;
    printf("Type cargo: ");
    scanf("%d", &cargo);
    if (cargo % 4 == 0) {
        printf("Yes, %d kg in cells", cargo / 4);
    }
    else {
        printf("No");
    }
}