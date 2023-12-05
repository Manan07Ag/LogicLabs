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

        glPushMatrix();
        glTranslatef(-width/2.0, 0.0, 0.0); // Adjusted for cell centering
        glRotatef(rotationAngle, 0.0, 0.0, 1.0);

        // Use fixed world coordinates for the shapes
        glBegin(GL_LINE_STRIP);
        for (int i = 110; i <= 250; i++) 
        {
            float angle = i * M_PI / 180.0;
            float x = width/2.0 * cos(angle);
            float y = height/2.0 * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();

        glPopMatrix();

        // The lines for the OR gate
        glBegin(GL_LINES);
        glVertex2f(-0.5 * width, 0.05 * height);
        glVertex2f(-0.02 * width, 0.05 * height);

        glVertex2f(-0.5 * width, -0.05 * height);
        glVertex2f(-0.02 * width, -0.05 * height);

        glVertex2f(0.6 * width, 0.0);
        glVertex2f(0.9 * width, 0.0);
        glEnd();

        // Rotate the first straight line
        rotateLine(0.62 * width, 0.2 * height, -0.28 * width, 0.15 * height, lineRotationAngle1);
        // Rotate the second straight line
        rotateLine(0.62 * width, -0.2 * height, -0.28 * width, -0.15 * height, lineRotationAngle2);
    }

private:
    void rotateLine(float x1, float y1, float x2, float y2, float angle) const {
        glPushMatrix();
        float centerX = (x1 + x2) / 2.0;
        float centerY = (y1 + y2) / 2.0;
        glTranslatef(centerX, centerY, 0.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        glVertex2f(x1 - centerX, y1 - centerY);
        glVertex2f(x2 - centerX, y2 - centerY);
        glEnd();
        glPopMatrix();
    }

    float width;
    float height;
    static constexpr float rotationAngle = 180.0;
    static constexpr float lineRotationAngle1 = -25.0;
    static constexpr float lineRotationAngle2 = 25.0;
};

class NOTGate {
public:
    NOTGate(float width, float height)
        : width(width), height(height) {}

    void draw() const {
        glColor3f(1.0f, 1.0f, 1.0f);

        // Push the current matrix onto the stack
        glPushMatrix();

        // Apply the rotation transformation
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        // Draw a white triangle with only the outlines visible
        glBegin(GL_LINE_LOOP);  // Use GL_LINE_LOOP to draw only the outline
        glVertex2f(-width/2.0f, -height/2.0f);  // Bottom vertex
        glVertex2f(width/2.0f, -height/2.0f);   // Right vertex
        glVertex2f(0.0f, height/2.0f);    // Top vertex
        glEnd();

        // Pop the matrix from the stack to restore the original transformation
        glPopMatrix();

        // Draw two horizontal lines parallel to each other to the left of the triangle
        glBegin(GL_LINES);
        glVertex2f(-width, height/4.0f);  // Top line, start
        glVertex2f(-width/2.0f, height/4.0f);  // Top line, end
        glVertex2f(-width, -height/4.0f); // Bottom line, start
        glVertex2f(-width/2.0f, -height/4.0f); // Bottom line, end
        glEnd();

        // Draw a line attached to the right side of the triangle
        glBegin(GL_LINES);
        glVertex2f(0.0f, 0.0f);  // Start point (right vertex of the triangle)
        glVertex2f(width/10.0f, 0.0f);  // End point (desired location)
        glEnd();

        // Draw a small circle to the right of the triangle
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; ++i) {
            float angle = static_cast<float>(i) * 3.14159265f / 180.0f;
            float x = 0.05f * std::cos(angle);
            float y = 0.05f * std::sin(angle);
            glVertex2f(width/5.0f + x, y);
        }
        glEnd();
    }

private:
    float width;
    float height;
    static constexpr float angle = -90.0f;
};

int nandXPos = 6; // Fix the location of NAND gate at position 6,5
int nandYPos = 5; // Fix the location of NAND gate at position 6,5
int orXPos = 3;
int orYPos = 3;
int notXPos = 3;
int notYPos = 7;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Grid grid(GRID_SIZE);
    grid.draw();

    // Draw NAND Gate in its cell
    glPushMatrix();
    float nandTranslateX = -1.0f + nandXPos * grid.cellWidth() + grid.cellWidth() / 2.0f;
    float nandTranslateY = 1.0f - nandYPos * grid.cellHeight() - grid.cellHeight() / 2.0f;
    glTranslatef(nandTranslateX, nandTranslateY, 0.0f);
    NANDGate nandGate(grid.cellWidth(), grid.cellHeight());
    nandGate.draw();
    glPopMatrix();

    // Draw OR Gate in its cell
    glPushMatrix();
    float orTranslateX = -1.0f + orXPos * grid.cellWidth() + grid.cellWidth() / 2.0f;
    float orTranslateY = 1.0f - orYPos * grid.cellHeight() - grid.cellHeight() / 2.0f;
    glTranslatef(orTranslateX, orTranslateY, 0.0f);
    ORGate orGate(grid.cellWidth(), grid.cellHeight());
    orGate.draw();
    glPopMatrix();

    // Draw NOT Gate in its cell
    glPushMatrix();
    float notTranslateX = -1.0f + notXPos * grid.cellWidth() + grid.cellWidth() / 2.0f;
    float notTranslateY = 1.0f - notYPos * grid.cellHeight() - grid.cellHeight() / 2.0f;
    glTranslatef(notTranslateX, notTranslateY, 0.0f);
    NOTGate notGate(grid.cellWidth(), grid.cellHeight());
    notGate.draw();
    glPopMatrix();

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
