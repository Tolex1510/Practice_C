#include <stdio.h>

typedef enum {
    Gasoline, Deisel, Electric
} Engine;

typedef struct {
    char brand[25];
    char model[25];
    int year;
    Engine engine;
} Vehicle;

int main() {
    int number;
    scanf("%d", &number);
    Vehicle vehicles[number];
    for (int i = 0; i < number; i++) {
        scanf("%s %s %d %d", &vehicles[i].brand, &vehicles[i].model, &vehicles[i].year, &vehicles[i].engine);
    }

    for (int i = 0; i < number; i++) {
        printf("Vehicle: %s %s\nYear: %d\nEngine Type: %s\n\n", vehicles[i].brand, vehicles[i].model, vehicles[i].year, 
                vehicles[i].engine == 0 ? "Gasoline" : vehicles[i].engine == 1 ? "Diesel" : "Electric");
    }

    return 0;
}