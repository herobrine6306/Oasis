#include <iostream>
#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Function to load game assets
void loadGameAssets() {
    // Load your floor.obj and player.obj here
    std::cout << "Loading game assets..." << std::endl;
}

// Function to handle joystick input
void handleJoystickInput(SDL_Joystick* joystick) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_JOYAXISMOTION) {
            if (event.jaxis.axis == 0) {
                // Handle horizontal joystick movement
                std::cout << "Horizontal movement: " << event.jaxis.value << std::endl;
            }
            else if (event.jaxis.axis == 1) {
                // Handle vertical joystick movement
                std::cout << "Vertical movement: " << event.jaxis.value << std::endl;
            }
        }
    }
}

void startGame() {
    loadGameAssets();
    
    // Initialize SDL for joystick support
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Joystick* joystick = SDL_JoystickOpen(0);
    if (joystick == nullptr) {
        std::cerr << "Failed to open joystick: " << SDL_GetError() << std::endl;
        return;
    }

    bool running = true;
    while (running) {
        handleJoystickInput(joystick);

        // Additional game loop logic here

        // For demo purposes, break after one loop
        running = false;
    }

    SDL_JoystickClose(joystick);
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    startGame();
    return 0;
}
