#include <iostream>
#include <GL/glut.h>
#include <string>
#include <functional>
#include <vector>
#include "Tutorials.h"

// Forward declaration
void drawText(float x, float y, const std::string& text);

class Button {
public:
    Button(float x1, float y1, float x2, float y2, const std::string& text, std::function<void()> callback)
        : x1(x1), y1(y1), x2(x2), y2(y2), text(text), onClick(std::move(callback)) {}

    void draw() const {
        // Set the button color
        glColor3f(colorR, colorG, colorB);
        // Draw the button as a quadrilateral
        glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
        glEnd();

        // Draw the button text
        glColor3f(0.0f, 0.0f, 0.0f); // Black color for text
        drawText((x1 + x2) / 2, (y1 + y2) / 2, text);
    }

    bool isClicked(float mouseX, float mouseY) const {
        return mouseX >= x1 && mouseX <= x2 && mouseY >= y1 && mouseY <= y2;
    }

    void performAction() const {
        if (onClick) {
            onClick();
        }
    }

private:
    float x1, y1, x2, y2;
    float colorR = 0.7f, colorG = 0.0f, colorB = 0.0f; // Default button color is red
    std::string text;
    std::function<void()> onClick;
};

class Application {
public:
    Application() : playButton(-0.2f, 0.3f, 0.2f, 0.5f, "Play", [this]() { onPlayClicked(); }),
                    exitButton(-0.2f, 0.1f, 0.2f, 0.3f, "Exit", [this]() { onExitClicked(); }) {
        mainWindow = glutCreateWindow("OpenGL Buttons Example");

        // Set up the display and mouse callback functions
        glutDisplayFunc(displayCallback);
        glutMouseFunc(mouseCallback);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        // Assign the instance to the static member
        instance = this; 
    }

    void run() {
        glutMainLoop();
    }

    static void displayCallback() {
        instance->render();
    }

    static void mouseCallback(int button, int state, int x, int y) {
        instance->mouseEvent(button, state, x, y);
    }

private:
    int mainWindow;
    Button playButton;
    Button exitButton;
    static Application* instance;

    void render() {
        glClear(GL_COLOR_BUFFER_BIT);

        if (!isPlayClicked) {
            playButton.draw();
            exitButton.draw();
        }

        glutSwapBuffers();
    }

    void mouseEvent(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            float mouseX = static_cast<float>(x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH) / 2);
            float mouseY = static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);

            if (playButton.isClicked(mouseX, mouseY)) {
                playButton.performAction();
            } else if (exitButton.isClicked(mouseX, mouseY)) {
                exitButton.performAction();
            }
        }
    }

   void onPlayClicked() {
    isPlayClicked = true;
    std::cout << "Play clicked" << std::endl;

    // Call the function to initialize and show tutorials
    showTutorials();
}

    void onExitClicked() {
        std::exit(0); // Exit the application
    }

    bool isPlayClicked = false;
};

// Define static instance pointer
Application* Application::instance = nullptr;

// Utility function for drawing text
void drawText(float x, float y, const std::string& text) {
    glRasterPos2f(x, y);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    
    // Create the application instance
    static Application app;
    
    app.run(); // This will enter the GLUT event processing loop

    return 0;
}
