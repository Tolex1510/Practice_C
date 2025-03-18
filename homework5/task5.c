#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Когда будете проверять, то заметите, 
что все работает, кроме команды write.
Если не сложно, можете объяснить почему*/

typedef struct {
    char *command;
    void (*func) (char **);
} Command;


char *allocatedMemory = NULL;
int allocatedSize = 0;

void allocMemory(char **args) {
    if (allocatedMemory != NULL) {
        printf("Память уже выделена\n");
        return;
    }
    if (args[1] == NULL) {
        printf("Укажите размер для выделения памяти \n");
        return;
    }

    allocatedSize = atoi(args[1]);
    allocatedMemory = malloc(allocatedSize);
    if (allocatedMemory == NULL) {
        printf("Ошибка выделения памяти \n");
        return;
    }

    printf("Выделено %d байт памяти \n", allocatedSize);
}

void freeMemory(char **args) {
    if (allocatedMemory == NULL) {
        printf("Память не выделена \n");
        return;
    }

    free(allocatedMemory);
    allocatedMemory = NULL;
    allocatedSize = 0;

    printf("Память освобождена \n");
}

void writeText(char **args) {
    if (allocatedMemory == NULL) {
        printf("Память не выделена \n");
        return;
    }

    char *text = args[1];
    for (int i = 2; args[i] != NULL; i++) {
        text = realloc(text, strlen(text) + strlen(args[i]) + 2);
        strcat(text, " ");
        strcat(text, args[i]);
    }

    if (strlen(text) > allocatedSize - 1) {
        printf("Текст не поместится в выделенную память \n");
        free(text);
        return;
    }

    strcpy(allocatedMemory, text);
    free(text);

    printf("Текст записан в память \n");
}

void printData(char **args) {
    if (allocatedMemory == NULL) {
        printf("Память не выделена \n");
        return;
    }

    printf("Данные: %s\n", allocatedMemory);
}

void exitProgram(char **args) {
    if (allocatedMemory != NULL) {
        free(allocatedMemory);
    }
    exit(0);
}

int main() {
    Command commands[] = {
        {"alloc", allocMemory},
        {"free", freeMemory},
        {"write", writeText},
        {"print", printData},
        {"exit", exitProgram},
        {NULL, NULL}
    };

    while (1) {
        printf("Введите команду: ");
        char input[256];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        char *args[256];
        int argCount = 0;
        char *token = strtok(input, " ");
        while (token != NULL && argCount < 256 - 1) {
            args[argCount++] = token;
            token = strtok(NULL, " ");
        }
        args[argCount] = NULL;

        for (int i = 0; commands[i].command != NULL; i++) {
            if (strcmp(args[0], commands[i].command) == 0) {
                commands[i].func(args);
                break;
            }
        }

        if (commands[argCount].command == NULL) {
            printf("Недопустимая команда \n");
        }
    }
    return 0;
}