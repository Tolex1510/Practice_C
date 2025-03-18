#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int countVowels(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int compareLength(const void *a, const void *b) {
    char **str1 = (char **) a;
    char **str2 = (char **) b;
    return strlen(*str1) - strlen(*str2);
}

int compareAlphabet(const void *a, const void *b) {
    char **str1 = (char **) a;
    char **str2 = (char **) b;
    return strcasecmp(*str1, *str2);
}

int compareVowels(const void *a, const void *b) {
    char **str1 = (char **) a;
    char **str2 = (char **) b;
    return countVowels(*str1) - countVowels(*str2);
}

int main() {
    int number;
    printf("Количество строк: ");
    scanf("%d", &number);
    getchar();

    char **strings = malloc(number * sizeof(char *));
    for (int i = 0; i < number; i++) {
        strings[i] = malloc(100 * sizeof(char));
        printf("Введите строку %d: ", i + 1);
        fgets(strings[i], 100, stdin);
        strings[i][strcspn(strings[i], "\n")] = 0;
    }

    printf("Выберите режим сортировки:\n");
    printf("1. По алфавиту\n");
    printf("2. По длине строки\n");
    printf("3. По количеству гласных букв\n");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        qsort(strings, number, sizeof(char *), compareAlphabet);
        break;
    case 2:
        qsort(strings, number, sizeof(char *), compareLength);
        break;
    case 3:
        qsort(strings, number, sizeof(char *), compareVowels);
        break;
    default:
        printf("Недопустимый ввод \n");
        return 1;
    }

    printf("Отсортированный массив: \n");
    for (int i = 0; i < number; i++) {
        printf("%s\n", strings[i]);
    }

    for (int i = 0; i < number; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}