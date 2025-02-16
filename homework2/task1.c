#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char Name[20];
    int Age;
    double GPA;
} Student;

int main() {
    int counter;
    printf("Counter: ");
    scanf("%d", &counter);
    Student* students = (Student*) malloc(counter*sizeof(Student));
    for (int i = 0; i < counter; i++) {
        scanf("%s %d %lf", &students[i].Name, &students[i].Age, &students[i].GPA);
    }

    for (int i = 0; i < counter; i++) {
        printf("Name: %s\n", students[i].Name);
        printf("Age: %d\n", students[i].Age);
        printf("GPA: %lf\n", students[i].GPA);
    }
    return 0;
}