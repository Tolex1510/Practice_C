#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    int number;
    scanf("%d", &number);
    Student students[number];

    for (int i = 0; i < number; i++) {
        scanf("%s %d %f", &students[i].name, &students[i].age, &students[i].gpa);
    }

    for (int i = 0; i < number; i++) {
        Student* student = &students[i];
        printf("Name: %s\nAge: %d\nGPA: %.1f\n\n", student->name, student->age, student->gpa);
    }

    return 0;
}