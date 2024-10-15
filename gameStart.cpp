#include <iostream>
#include <GL/glut.h> // Include the OpenGL header
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> loadOBJ(const char* path) {
    std::ifstream file(path);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

void loadGameAssets() {
    // Load your player.obj and floor.obj here
    auto playerLines = loadOBJ("player.obj");
    auto floorLines = loadOBJ("floor.obj");

    // Process the loaded data as needed
    // For simplicity, we are just printing the first line
    std::cout << "Loaded player asset: " << playerLines[0] << std::endl;
    std::cout << "Loaded floor asset: " << floorLines[0] << std::endl;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Add code to draw player and floor
    // Here, you would typically render your 3D models

    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.333, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Game");
    init();
    loadGameAssets();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
