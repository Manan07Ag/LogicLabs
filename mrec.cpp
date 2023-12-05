#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Window dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Rectangle position
float rectX = 0.0f;
float rectY = 0.0f;
float rectTargetX = 0.0f;
float rectTargetY = 0.0f;
float rectSpeed = 0.005f; // Adjust this value to control the movement speed

// Boundary limits
const float minX = -0.9f;
const float maxX = 0.9f;
const float minY = -0.9f;
const float maxY = 0.9f;

bool isMoving = false; // Indicates whether the rectangle is currently moving

// Function to draw the rectangle
void drawRectangle() {
    glBegin(GL_QUADS);
    glVertex2f(rectX - 0.1f, rectY - 0.1f); // Bottom-left vertex
    glVertex2f(rectX + 0.1f, rectY - 0.1f); // Bottom-right vertex
    glVertex2f(rectX + 0.1f, rectY + 0.1f); // Top-right vertex
    glVertex2f(rectX - 0.1f, rectY + 0.1f); // Top-left vertex
    glEnd();
}

// Function to handle keyboard input
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            rectTargetY += 0.1f;
            break;
        case 'a':
            rectTargetX -= 0.1f;
            break;
        case 's':
            rectTargetY -= 0.1f;
            break;
        case 'd':
            rectTargetX += 0.1f;
            break;
        case 27: // ESC key
            exit(0);
            break;
    }

    // Clamp target position to boundary limits
    rectTargetX = std::max(minX, std::min(maxX, rectTargetX));
    rectTargetY = std::max(minY, std::min(maxY, rectTargetY));

    // Start or stop the movement
    isMoving = true;
    glutPostRedisplay();
}

// Function to update the rectangle's position smoothly
void update() {
    // Calculate the direction vector
    float dx = rectTargetX - rectX;
    float dy = rectTargetY - rectY;

    // Calculate the distance to the target position
    float distance = sqrt(dx * dx + dy * dy);

    if (isMoving) {
        // If the distance is greater than the desired speed, move towards the target
        if (distance > rectSpeed) {
            float ratio = rectSpeed / distance;
            rectX += dx * ratio;
            rectY += dy * ratio;
        } else {
            // If the distance is smaller than the speed, snap to the target position
            rectX = rectTargetX;
            rectY = rectTargetY;
            isMoving = false; // Stop the movement
        }
    }
}

// Function to render the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color

    // Update the rectangle's position smoothly
    update();

    // Draw the rectangle
    glLoadIdentity();
    drawRectangle();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Bounded Smooth Rectangle Movement");

    glutDisplayFunc(display);
    glutIdleFunc(display); // Register the idle function
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
