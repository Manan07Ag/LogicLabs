#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

// Window dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Boundary coordinates
const GLfloat BOUNDARY_LEFT = -0.9f;
const GLfloat BOUNDARY_RIGHT = 0.9f;
const GLfloat BOUNDARY_TOP = 0.9f;
const GLfloat BOUNDARY_BOTTOM = -0.9f;

// Initial rectangle position
GLfloat rectX = 0.0f;
GLfloat rectY = 0.0f;
const GLfloat RECTANGLE_SIZE = 0.1f;

// Second rectangle position and speed
GLfloat rect2X = 0.0f;
GLfloat rect2Y = 0.0f;
GLfloat rect2SpeedX = 0.02f;
GLfloat rect2SpeedY = 0.03f;

bool shouldStop = false;
bool gameover = false;

// Function to update the second rectangle's position
void updateSecondRectangle(int value) {
    // Update the second rectangle's position
    rect2X += rect2SpeedX;
    rect2Y += rect2SpeedY;

    // Bounce the second rectangle off the boundaries
    if (rect2X + RECTANGLE_SIZE > BOUNDARY_RIGHT || rect2X < BOUNDARY_LEFT) {
        rect2SpeedX *= -1;
    }
    if (rect2Y + RECTANGLE_SIZE > BOUNDARY_TOP || rect2Y < BOUNDARY_BOTTOM) {
        rect2SpeedY *= -1;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateSecondRectangle, 0); // 16ms delay (about 60 FPS)
}

// Function to handle keyboard input
void keyboard(unsigned char key, int x, int y) {
    if (gameover) return;

    switch (key) {
        case 'w':
        case 'W':
            rectY += 0.05f;
            break;
        case 's':
        case 'S':
            rectY -= 0.05f;
            break;
        case 'a':
        case 'A':
            rectX -= 0.05f;
            break;
        case 'd':
        case 'D':
            rectX += 0.05f;
            break;
        case 27: // 27 is the ASCII code for the Escape key
            shouldStop = true;
            break;
    }

    // Keep the first rectangle within the boundaries
    rectX = std::max(BOUNDARY_LEFT, std::min(rectX, BOUNDARY_RIGHT - RECTANGLE_SIZE));
    rectY = std::max(BOUNDARY_BOTTOM, std::min(rectY, BOUNDARY_TOP - RECTANGLE_SIZE));

    glutPostRedisplay(); // Request a redraw

    // Check for collision
    if (rectX < rect2X + RECTANGLE_SIZE && rectX + RECTANGLE_SIZE > rect2X &&
        rectY < rect2Y + RECTANGLE_SIZE && rectY + RECTANGLE_SIZE > rect2Y) {
        gameover = true;
    }
}

// Function to draw the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the first rectangle
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(rectX, rectY);
    glVertex2f(rectX + RECTANGLE_SIZE, rectY);
    glVertex2f(rectX + RECTANGLE_SIZE, rectY + RECTANGLE_SIZE);
    glVertex2f(rectX, rectY + RECTANGLE_SIZE);
    glEnd();

    // Draw the second rectangle
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(rect2X, rect2Y);
    glVertex2f(rect2X + RECTANGLE_SIZE, rect2Y);
    glVertex2f(rect2X + RECTANGLE_SIZE, rect2Y + RECTANGLE_SIZE);
    glVertex2f(rect2X, rect2Y + RECTANGLE_SIZE);
    glEnd();

    // Check for collision and display "Game Over"
    if (gameover) {
        glColor3f(1.0f, 1.0f, 1.0f); // White color
        glRasterPos2f(-0.2f, 0.0f); // Position of the text
        std::string gameoverText = "Game Over!";
        for (char c : gameoverText) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
    }

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Bouncing Rectangles");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    // Seed for random number generation
    std::srand(std::time(0));

    // Start updating the second rectangle's position
    glutTimerFunc(0, updateSecondRectangle, 0);

    glutMainLoop();

    return 0;
}
