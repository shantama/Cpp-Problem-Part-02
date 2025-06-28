
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function

#define HEART_SCALE 5
#define VIBRATION_AMPLITUDE 0.1

void drawHeart(double time) {
    for (double y = 1.5; y > -1.5; y -= 0.1) {
        for (double x = -1.5; x < 1.5; x += 0.05) {
            double a = x * x + y * y - 1;
            char character = (a * a * a - x * x * y * y * y <= 0.0) ? '*' : ' ';

            // Add a time-dependent vibration
            double vibration = VIBRATION_AMPLITUDE * sin(time);

            printf("%c",character);
            usleep(10000); // Sleep for a short time to slow down the animation
        }
        putchar('\n');
    }
}

int main() {
    double time = 0.0;

    while (1) {
        // Clear the console screen (system-dependent)
        system("cls"); // Use "cls" for Windows

        drawHeart(time);

        // Increment time for animation
        time += 0.1;

        // Sleep for a short time to control the animation speed
        usleep(10000); // Adjust this value to control the animation speed
    }

    return 0;
}
