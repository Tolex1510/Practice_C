#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char old[200];
    scanf(" %[^\n]", old);
    char*new = strdup(old);
    printf("Оригинал: %s\nКопия: %s ", old, new);
    free(new);
}