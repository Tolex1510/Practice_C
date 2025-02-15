#include <stdio.h>

int main() {
    int date;
    printf("Type date: ");
    scanf("%d", &date);
    if (date > 20250210) {
        printf("In the future");
    }
    else {
        printf("Not in the future");
    }
}