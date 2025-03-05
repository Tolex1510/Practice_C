#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[25];
    Date date;
    char description[100];
} Event;

int main() {
    int number;
    scanf("%d", &number);
    Event* events = (Event*) malloc(number * sizeof(Event));
    for (int i = 0; i < number; i++) {
        scanf("%s %d %d %d %s", &events[i].name, &events[i].date.day, &events[i].date.month, &events[i].date.year, &events[i].description);
    }

    for (int i = 0; i < number; i++) {
        printf("Event: %s\nDate: %d/%d/%d\nDescription: %s\n\n", events[i].name, events[i].date.day, events[i].date.month, events[i].date.year, events[i].description);
    }
    free(events);
    return 0;
}
