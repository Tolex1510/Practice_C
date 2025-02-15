#include <stdio.h>

int main() {
    int amount;
    printf("Type amount of astronauts: ");
    scanf("%d", &amount);
    if (amount % 2 == 0) {
        if (amount % 4 == 0) {
            printf("Type: 4, amount: %d", amount / 4);
            return 0;
        }
        else {
            printf("Type: 2, amount: %d", amount / 2);
            return 0;
        }
    }
    else if (amount % 3 == 0) {
        printf("Type: 3, amount: %d", amount / 3);
        return 0;
    }
    else {
        if ((amount - 1) % 4 == 0) {
            printf("Type: 4, amount: %d", (amount-1) / 4);
            return 0;
        }
        else {
            printf("Type: 2, amount: %d", (amount - 1) / 2);
            return 0;
        }
    }
}