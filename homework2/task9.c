#include <stdio.h>

typedef enum {
    Sunny, Cloudy, Rainy
} State;

typedef struct {
    float temp;
    float humidity;
    State state;
} Weather;

int main() {
    Weather weather;
    scanf("%f %f %d", &weather.temp, &weather.humidity, &weather.state);

    printf("Temperature: %.1f°C\nHumidity: %.1f%\nCondition: %s\n", weather.temp, weather.humidity, weather.state == 0 ? "Sunny" : weather.state == 1 ? "Cloudly" : "Rainy");
    return 0;
}