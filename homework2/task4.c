#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    char position[20];
    float salary;
} Employee;

int main() {
    int number;
    scanf("%d", &number);
    Employee* employees = (Employee*) malloc(number * sizeof(Employee));
    
    for (int i = 0; i < number; i++) {
        scanf("%s %s %f", &employees[i].name, &employees[i].position, &employees[i].salary);
    }

    for (int i = 0; i < number; i++) {
        printf("Name: %s\nPosition: %s\nSalary: %.2f\n\n", employees[i].name, employees[i].position, employees[i].salary);
    }
    free(employees);
    return 0;
}
