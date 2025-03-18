#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char expression[100];
    printf("Введите выражение: ");
    fgets(expression, sizeof(expression), stdin);

    expression[strcspn(expression, "\n")] = 0;

    char *token = strtok(expression, " ");
    char operand1[20];
    strcpy(operand1, token);

    token = strtok(NULL, " ");
    char operator = *token;

    token = strtok(NULL, " ");
    char operand2[20];
    strcpy(operand2, token);

    double num1 = atof(operand1);
    double num2 = atof(operand2);

    printf("Operand 1: %f\n", num1);
    printf("Operator: %c\n", operator);
    printf("Operand 2: %f\n", num2);

    double result;

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("На 0 делить нельзя");
                return 1;
            }
            else {
                result = num1 / num2;
                break;
            }
        default:
            printf("Неизвестный оператор");
            return 1;
    }
    printf("Результат: %f\n", result);
    return 1;
}