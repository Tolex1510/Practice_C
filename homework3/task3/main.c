#include <stdio.h>
#include "ship.h"


int main() {
    float speed, time;
    printf("Type speed: ");
    scanf("%f", &speed);
    printf("Type time: ");
    scanf("%f", &time);
    float distance = calculate_distance(speed, time);
    printf("Distance: %.2f\n", distance);
    int fuel_level;
    printf("Type fuel level: ");
    scanf("%d", &fuel_level);
    if (check_fuel(fuel_level)) {
        printf("Good level\n");
    }
    else {
        printf("Bad level\n");
    }
    return 0;
}