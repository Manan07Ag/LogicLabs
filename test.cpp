#include <GL/glut.h>
#include <cmath>
#include <iostream>

const int GRID_SIZE = 10; // 10x10 grid

class Grid {
public:
    Grid(int size) : size(size) {}

    void draw() const {
        glColor3f(0.5f, 0.5f, 0.5f); // Set grid color to grey

        for (int i = 0; i <= size; ++i) {
            float x = -1.0f + i * cellWidth();
            float y = -1.0f + i * cellHeight();

            // Draw vertical line
            glBegin(GL_LINES);
            glVertex2f(x, -1.0f);
            glVertex2f(x, 1.0f);
            glEnd();

            // Draw horizontal line
            glBegin(GL_LINES);
            glVertex2f(-1.0f, y);
            glVertex2f(1.0f, y);
            glEnd();
        }
    }

    float cellWidth() const { return 2.0f / size; }
    float cellHeight() const { return 2.0f / size; }

private:
    int size;
};

class NANDGate {
public:
    NANDGate(float width, float height)
        : width(width), height(height) {}

    void draw() const {
        glColor3f(1.0f, 1.0f, 1.0f);

        // Rectangle
        glBegin(GL_LINE_LOOP);
        glVertex2f(-width/2.0f, -height/2.0f);
        glVertex2f(width/2.0f, -height/2.0f);
        glVertex2f(width/2.0f, height/2.0f);
        glVertex2f(-width/2.0f, height/2.0f);
        glEnd();

        // Lines to the left
        glBegin(GL_LINES);
        glVertex2f(-width, height/4.0f);
        glVertex2f(-width/2.0f, height/4.0f);
        glVertex2f(-width, -height/4.0f);
        glVertex2f(-width/2.0f, -height/4.0f);
        glEnd();

        // Semi-circle
        glBegin(GL_LINE_LOOP);
        for (int i = 270; i <= 450; ++i) {
            float angle = static_cast<float>(i) * M_PI / 180.0;
            float x = width/2.0f * cos(angle);
            float y = height/2.0f * sin(angle);
            glVertex2f(width/2.0f + x, y);
        }
        glEnd();

        // Line attached to the right side
        glBegin(GL_LINES);
        glVertex2f(width, 0.0f);
        glVertex2f(width + width/10.0f, 0.0f);
        glEnd();
    }

    float getWidth() const {
        return width;
    }

    float getHeight() const {
        return height;
    }

private:
    float width;
    float height;
};

class ORGate {
public:
    ORGate(float width, float height)
        : width(width), height(height) {}

    void draw() const {
        glColor3f(1.0f, 1.0f, 1.0f);

        // Draw the main body of the OR gate
        glBegin(GL_POLYGON);
        glVertex2f(-width / 2.0f, 0.0f); // Left point
        glVertex2f(0.0f, height / 2.0f); // Top point
        glVertex2f(width / 2.0f, 0.0f); // Right point
        glVertex2f(0.0f, -height / 2.0f); // Bottom point
        glEnd();

        // Draw the input lines
        glBegin(GL_LINES);
        glVertex2f(-width / 2.0f, 0.05 * height);
        glVertex2f(-0.15 * width, 0.05 * height);

        glVertex2f(-width / 2.0f, -0.05 * height);
        glVertex2f(-0.15 * width, -0.05 * height);
        glEnd();

        // Draw the output line
        glBegin(GL_LINES);
        glVertex2f(0.15 * width, 0.0f);
        glVertex2f(width / 2.0f, 0.0f);
        glEnd();
    }

    float getWidth() const {
        return width;
    }

    float getHeight() const {
        return height;
    }

private:
    float width;  // Width of the OR gate
    float height; // Height of the OR gate
};


// Define coordinates for gate positions and connections
int nandXPos = 6;
int nandYPos = 5;
int orXPos = 3;
int orYPos = 3;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Grid grid(GRID_SIZE);
    grid.draw();

    // Draw NAND Gate in its cell
    float nandGateWidth = 0.2; // Set the NAND gate width
    float nandGateHeight = 0.2; // Set the NAND gate height
    glPushMatrix();
    float nandTranslateX = -1.0f + nandXPos * grid.cellWidth() + grid.cellWidth() / 2.0f;
    float nandTranslateY = 1.0f - nandYPos * grid.cellHeight() - grid.cellHeight() / 2.0f;
    glTranslatef(nandTranslateX, nandTranslateY, 0.0f);
    NANDGate nandGate(nandGateWidth, nandGateHeight);
    nandGate.draw();
    glPopMatrix();

    // Draw OR Gate in its cell
    float orGateWidth = 0.2; // Set the OR gate width
    float orGateHeight = 0.2; // Set the OR gate height
    glPushMatrix();
    float orTranslateX = -1.0f + orXPos * grid.cellWidth() + grid.cellWidth() / 2.0f;
    float orTranslateY = 1.0f - orYPos * grid.cellHeight() - grid.cellHeight() / 2.0f;
    glTranslatef(orTranslateX, orTranslateY, 0.0f);
    ORGate orGate(orGateWidth, orGateHeight);
    orGate.draw();
    glPopMatrix();

    // Draw the connection line between NAND and OR gates
    float nandOutputX = nandTranslateX + nandGateWidth / 2.0f;
    float nandOutputY = nandTranslateY;
    float orInputX = orTranslateX - orGateWidth / 2.0f;
    float orInputY = orTranslateY;
    
    glColor3f(1.0f, 1.0f, 1.0f); // Set the line color to white
    glBegin(GL_LINES);
    glVertex2f(nandOutputX, nandOutputY);
    glVertex2f(orInputX, orInputY);
    glEnd();

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = static_cast<float>(width) / static_cast<float>(height);
    if (width >= height) {
        glOrtho(-aspect, aspect, -1.0, 1.0, -1.0, 1.0);
    } else {
        glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Gates");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
