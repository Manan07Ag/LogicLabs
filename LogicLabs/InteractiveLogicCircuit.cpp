#include <GL/glut.h>
#include <cmath>
#include "ShapeRenderer.h"

class InteractiveLogicCircuit {
public:
    InteractiveLogicCircuit() : windowWidth(400), windowHeight(400), dragging(0), rectX(0.0), rectY(-0.9), rectWidth(0.1), boxInSpace(false) {
        instance = this;
    }

    void run(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(windowWidth, windowHeight);
        glutCreateWindow("Interactive Logic Circuit");

        glutDisplayFunc(displayCallback);
        glutReshapeFunc(reshapeCallback);
        glutMouseFunc(mouseCallback);
        glutMotionFunc(motionCallback);

        glutMainLoop();
    }

private:
    int windowWidth;
    int windowHeight;
    int dragging;
    float rectX;
    float rectY;
    float rectWidth;
    bool boxInSpace;

    static InteractiveLogicCircuit* instance;

    static void displayCallback() {
        instance->display();
    }

    static void reshapeCallback(int width, int height) {
        instance->reshape(width, height);
    }

    static void mouseCallback(int button, int state, int x, int y) {
        instance->mouse(button, state, x, y);
    }

    static void motionCallback(int x, int y) {
        instance->motion(x, y);
    }

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0, 1.0, 1.0);
        glLineWidth(2.0);

        // Draw the static line in the middle
        glBegin(GL_LINES);
        glVertex2f(-0.5, 0.0);
        glVertex2f(-0.25, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(0.25, 0.0);
        glVertex2f(0.5, 0.0);
        glEnd();

        float squareSize = 0.24;
        glBegin(GL_LINE_LOOP); 
        glVertex2f(-squareSize, squareSize);
        glVertex2f(squareSize, squareSize);
        glVertex2f(squareSize, -squareSize);
        glVertex2f(-squareSize, -squareSize);
        glEnd();


        // Set color for the circle
        glColor3f(1.0, 1.0, 1.0);

        // Draw the movable shape (scaled down)
        glPushMatrix();
        glTranslatef(rectX, rectY, 0.0f);
        glScalef(0.5f, 0.5f, 0.5f); // Scale down the shape
        ShapeRenderer::NotG();
        glPopMatrix();

        // Check if the shape is in a specific area to change its color
        boxInSpace = rectX >= -0.25 && rectX <= 0.25 && rectY >= -0.1 && rectY <= 0.1;
        if (boxInSpace) {
            glColor3f(1.0, 1.0, 0.0); // Change color if in space
        }

        // // Draw the static circle
        float circleRadius = 0.05;
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < 360; i++) {
            float angle = i * M_PI / 180;
            float x = 0.7 + circleRadius * cos(angle);
            float y = 0.0 + circleRadius * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();

        glFlush();
    }

    void reshape(int width, int height) {
        windowWidth = width;
        windowHeight = height;

        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
    }

    void mouse(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            float mouseX = (float)x / windowWidth * 2.0 - 1.0;
            float mouseY = 1.0 - (float)y / windowHeight * 2.0;

            // Adjust hitbox for the scaled-down shape
            float hitboxSize = rectWidth * 2.0f; // Scale down the hitbox size
            if (mouseY >= rectY - hitboxSize && mouseY <= rectY + hitboxSize &&
                mouseX >= rectX - hitboxSize && mouseX <= rectX + hitboxSize) {
                dragging = 1;
            }
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            dragging = 0;
        }
    }

    void motion(int x, int y) {
        if (dragging) {
            rectX = (float)x / windowWidth * 2.0 - 1.0;
            rectY = 1.0 - (float)y / windowHeight * 2.0;
            glutPostRedisplay();
        }
    }
};

InteractiveLogicCircuit* InteractiveLogicCircuit::instance = nullptr;

int main(int argc, char** argv) {
    InteractiveLogicCircuit app;
    app.run(argc, argv);
    return 0;
}
