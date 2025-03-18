#include <stdio.h>
#include <string.h>
#include <ctype.h>


void to_upper(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lower(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

void reverse(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

typedef struct {
    char name[10];
    void (*func)();
} Command;

int main() {
    Command commands[] = {
        {"upper", to_upper},
        {"lower", to_lower},
        {"reverse", reverse}
    };
    char str[100], command[20];
    while (1) {
        printf("Введите команду (upper, lower, reverse, exit): ");
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