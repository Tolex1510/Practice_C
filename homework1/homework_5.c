#include <stdio.h>
#include <math.h>

int main() {
    double calculated;
    double actual;
    printf("Type calculated speed: ");
    scanf("%lf", &calculated);
    printf("Type actual speed: ");
    scanf("%lf", &actual);
    if (fabs(calculated - actual) >= 0.1) {
        printf("Unstable");
    }
    else {
        printf("Stable");
    }
}