#include <stdio.h>

int main() {
    int mass;
    scanf("%d", &mass);
    if (mass < 60 || mass > 90) {
        printf("No, you can't");
    } 
    else {
        printf("Yes, you can");
    }
}
