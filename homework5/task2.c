#include <stdio.h>
#include <string.h>
#include <ctype.h>


void remove_space(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

void vowel_to_star(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            str[i] = '*';
        }
    }
}

void invert(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = tolower(str[i]);
            }
            else {
                str[i] = toupper(str[i]);
            }
        }
    }
}

typedef struct {
    char name[10];
    void (*func)();
} Command;

int main() {
    Command commands[] = {
        {"spaceless", remove_space},
        {"vowel", vowel_to_star},
        {"invert", invert}
    };
    char str[100], command[20];
    while (1) {
        printf("Введите команду (spaceless, vowel, invert, exit): ");
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) {
            break;
        }
        printf("Введите строку: ");
        scanf(" %99[^\n]", str);

        int found = 0;
        for (int i = 0; commands[i].name; i++) {
            if (strcmp(commands[i].name, command) == 0) {
                commands[i].func(str);
                printf("Результат: %s\n", str);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Неизвестная команда!\n");
        }
    }
    return 0;
}