#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    char stop[] = "*#";
    scanf("%s", message);

    size_t start_pos = strspn(message, stop);
    size_t stop_pos = strlen(message) - strcspn(message + start_pos, stop);
    size_t len = stop_pos - start_pos;
    printf("%d %d", start_pos, stop_pos);
    char *clear_message = strndup(message + start_pos, len);
    printf("Сообщение: %s\nДлина сообщения: %d", clear_message, len);
}