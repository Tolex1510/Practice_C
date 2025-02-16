#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int amount;
    double price;
} Item;

int main() {
    int number;
    scanf("%d", &number);
    Item* items = (Item*) malloc(number * sizeof(Item));
    for (int i = 0; i < number; i++) {
        scanf("%s %d %lf", &items[i].name, &items[i].amount, &items[i].price);
    }
    for (int i = 0; i < number; i++) {
        printf("Item: %s\nQuantity: %d\nPrice: %.2lf\n\n", items[i].name, items[i].amount, items[i].price);
    }

    return 0;
}