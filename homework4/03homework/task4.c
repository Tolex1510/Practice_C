#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char code[] = "launch-2025";
    char input[50];
    scanf("%s", &input);
    char lower_input[50];
    for (int i = 0; i < strlen(input); i++) {
        lower_input[i] = tolower(input[i]);
    }
    if (strcmp(lower_input, code) == 0) {
        printf("Код принят");
    }
    else {
        printf("Ошибка: неверный код!");
    }
}