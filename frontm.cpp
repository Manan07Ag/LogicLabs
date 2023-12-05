#include <iostream>
#include <GL/glut.h>
#include <cstdlib> // For the exit function

bool isPlayClicked = false; // Flag to track if "Play" button is clicked
int mainWindow; // Store the main window ID

void drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void display() {
    switch(scenid){
    case 0:startMenue();break;
    case 1:tutora

    }
    glClear(GL_COLOR_BUFFER_BIT);

    if (!isPlayClicked) {
        // Draw "Play" button
        glColor3f(0.0f, 0.7f, 0.0f); // Green color
        glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.3f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(0.2f, 0.5f);
        glVertex2f(-0.2f, 0.5f);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f); // Black color for text
        drawText(-0.05f, 0.4f, "Play");

        // Draw "Exit" button
        glColor3f(0.7f, 0.0f, 0.0f); // Red color
        glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(0.2f, 0.1f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.2f, 0.3f);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f); // Black color for text
        drawText(-0.08f, 0.2f, "Exit");
    }

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convert mouse coordinates to OpenGL coordinates
        float mouseX = (float)(x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH) / 2);
        float mouseY = (float)(glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);

        // Check if the mouse click is inside the "Play" button
        if (!isPlayClicked && mouseX >= -0.2f && mouseX <= 0.2f && mouseY >= 0.3f && mouseY <= 0.5f) {
            isPlayClicked = true;
            glutDestroyWindow(mainWindow); // Close the main window

            // Create a new window with a blue background
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
            glutInitWindowSize(800, 600);
            glutInitWindowPosition(100, 100);
            mainWindow = glutCreateWindow("OpenGL Blue Screen");
            glClearColor(0.0, 0.0, 1.0, 1.0); // Blue background color

            // Set the display function for the new window
            glutDisplayFunc(display);
        }

        // Check if the mouse click is inside the "Exit" button
        if (!isPlayClicked && mouseX >= -0.2f && mouseX <= 0.2f && mouseY >= 0.1f && mouseY <= 0.3f) {
            exit(0); // Close the program
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    mainWindow = glutCreateWindow("OpenGL Buttons Example");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); // Set the mouse click callback

    glClearColor(1.0, 1.0, 1.0, 1.0); // Default background color

    glutMainLoop();

    return 0;
}
