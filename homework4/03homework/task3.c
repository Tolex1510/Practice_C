#include <stdio.h>
#include <string.h>

int main() {
    char crew[] = "Гагарин;Титов;Армстронг;Коллинз;Олдрин";

    printf("Список комонавтов:\n");
    char *token = strtok(crew, ";");
    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, ";");
    }
    return 0;
}