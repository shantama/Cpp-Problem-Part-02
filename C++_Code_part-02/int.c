#include <SDL.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define HEART_SIZE 100

// Function to draw a heart shape
void drawHeart(SDL_Renderer *renderer, int x, int y, int size) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderDrawLine(renderer, x, y, x + size / 2, y - size);
    SDL_RenderDrawLine(renderer, x + size / 2, y - size, x + size, y);
    double radius = size / 2.0;
    double centerX1 = x + size / 4.0;
    double centerY1 = y - size / 4.0;
    double centerX2 = x + 3 * size / 4.0;
    double centerY2 = y - size / 4.0;
    double numPoints = 100;
    for (double i = 0; i < numPoints; i++) {
        double angle = i * 2 * M_PI / numPoints;
        double x1 = centerX1 - radius * cos(angle);
        double y1 = centerY1 - radius * sin(angle);
        double x2 = centerX2 - radius * cos(angle);
        double y2 = centerY2 - radius * sin(angle);
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}

int main(int argc, char *argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window and renderer
    SDL_Window *window = SDL_CreateWindow("Vibrating Red Heart", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear the screen to black
        SDL_RenderClear(renderer);

        // Draw the vibrating heart at different positions
        int x = WINDOW_WIDTH / 2 + (int)(20 * sin(SDL_GetTicks() / 100.0));
        int y = WINDOW_HEIGHT / 2 + (int)(20 * cos(SDL_GetTicks() / 100.0));
        drawHeart(renderer, x, y, HEART_SIZE);

        SDL_RenderPresent(renderer);
    }

    // Cleanup and quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

