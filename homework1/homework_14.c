#include <stdio.h>

int main() {
    int weight;
    printf("Type weight: ");
    scanf("%d", &weight);
    printf("Weight on Moon is %.2f", weight / 6.0);
}