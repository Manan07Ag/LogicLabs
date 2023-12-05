#include <GL/glut.h>

const int width = 800; // Width of the window
const int height = 600; // Height of the window
const int gridSize = 20; // Size of each grid cell

void drawGrid() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the grid
    glBegin(GL_QUADS);
    for (int x = 0; x < width; x += gridSize) {
        for (int y = 0; y < height; y += gridSize) {
            if ((x / gridSize + y / gridSize) % 2 == 0) {
                glColor3f(1.0f, 0.0f, 0.0f); // Red
            } else {
                glColor3f(0.0f, 0.0f, 1.0f); // Blue
            }
            glVertex2i(x, y);
            glVertex2i(x + gridSize, y);
            glVertex2i(x + gridSize, y + gridSize);
            glVertex2i(x, y + gridSize);
        }
    }
    glEnd();

    glFlush();
}

void display() {
    drawGrid();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Color Grid in OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
