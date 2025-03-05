#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SHIPS 100
#define MAX_LENGTH 50

int main() {
    char spaceships[MAX_SHIPS][MAX_LENGTH];
    int count;

    printf("Введите количество кораблей: ");
    scanf("%d", &count);

    if (count > MAX_SHIPS) {
        count = MAX_SHIPS;
    }

    for (int i = 0; i < count; i++) {
        printf("Введите название корабля %d: ", i + 1);
        scanf("%s", spaceships[i]);
    }
    for (int i = 0; i < count; i++) {
        if (tolower(spaceships[i][0]) == 's' && tolower(spaceships[i][1]) == 's') {
            printf("Первый корабль: %s", spaceships[i]);
            return 0;
        }
    }
    printf("Ничего нет\n");
}