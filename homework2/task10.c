#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[20];
    int credits;
    char professor[50];
} Course;

int main() {
    int number;
    scanf("%d", &number);
    Course* courses = (Course*) malloc(number * sizeof(Course));

    for (int i = 0; i < number; i++) {
        scanf("%s %d %s", &courses[i].title, &courses[i].credits, &courses[i].professor);
    }

    for (int i = 0; i < number; i++) {
        printf("Course: %s\nCredits: %d\nProfessor: %s\n\n", courses[i].title, courses[i].credits, courses[i].professor);
    }
    free(courses);
    return 0;
}
