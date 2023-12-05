#include <GL/glut.h>
#include <cmath>
#include <iostream>

class GraphicsApp {
public:
    static void run(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(800, 600);
        glutCreateWindow("Translating Triangle in Movable Scene");

        glutReshapeFunc(reshape);
        glutDisplayFunc(display);
        glutMouseFunc(mouseClick);
        glutMotionFunc(mouseDrag);

        glViewport(0, 0, 800, 600);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        glutMainLoop();
    }

private:
    static GLfloat angle;
    static GLfloat sceneX;
    static GLfloat sceneY;
    static GLfloat triangleX;
    static GLfloat triangleY;
    static bool isDragging;
    static GLfloat initialMouseX;
    static GLfloat initialMouseY;
    static GLfloat stepSize;

    static void reshape(int width, int height) {
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        if (width >= height) {
            double aspect = static_cast<double>(width) / static_cast<double>(height);
            glOrtho(-aspect, aspect, -1.0, 1.0, -1.0, 1.0);
        } else {
            double aspect = static_cast<double>(height) / static_cast<double>(width);
            glOrtho(-1.0, 1.0, -aspect, aspect, -1.0, 1.0);
        }

        glMatrixMode(GL_MODELVIEW);
    }

    static void display() {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 1.0f);

        glPushMatrix();
        glTranslatef(sceneX, sceneY, 0.0f);

        glPushMatrix();
        glTranslatef(triangleX, triangleY, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        glTranslatef(-triangleX, -triangleY, 0.0f);

        glBegin(GL_LINE_LOOP);
        glVertex2f(triangleX - 0.2f, triangleY - 0.2f);
        glVertex2f(triangleX + 0.2f, triangleY - 0.2f);
        glVertex2f(triangleX, triangleY + 0.2f);
        glEnd();
        glPopMatrix();

        glBegin(GL_LINES);
        glVertex2f(-0.4f, 0.1f);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(-0.4f, -0.1f);
        glVertex2f(-0.2f, -0.1f);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(0.3f, 0.0f);
        glVertex2f(0.4f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; ++i) {
            float angle = static_cast<float>(i) * 3.14159265f / 180.0f;
            float x = 0.05f * std::cos(angle);
            float y = 0.05f * std::sin(angle);
            glVertex2f(0.25f + x, y);
        }
        glEnd();

        glLineStipple(1, 0x00FF);
        glEnable(GL_LINE_STIPPLE);
        glBegin(GL_LINE_LOOP);
        glVertex2f(-0.4f, -0.3f);
        glVertex2f(0.4f, -0.3f);
        glVertex2f(0.4f, 0.3f);
        glVertex2f(-0.4f, 0.3f);
        glEnd();
        glDisable(GL_LINE_STIPPLE);

        glPopMatrix();
        glFlush();
    }

    static void mouseClick(int button, int state, int mouseX, int mouseY) {
        if (button == GLUT_LEFT_BUTTON) {
            if (state == GLUT_DOWN) {
                isDragging = true;
                initialMouseX = mouseX;
                initialMouseY = mouseY;
            } else if (state == GLUT_UP) {
                isDragging = false;
            }
        }
    }

    static void mouseDrag(int mouseX, int mouseY) {
        if (isDragging) {
            int deltaX = mouseX - initialMouseX;
            int deltaY = mouseY - initialMouseY;
            sceneX += deltaX * stepSize;
            sceneY -= deltaY * stepSize;

            const float minX = -1.0f;
            const float minY = -1.0f;
            const float maxX = 1.0f;
            const float maxY = 1.0f;

            sceneX = std::max(minX, std::min(maxX, sceneX));
            sceneY = std::max(minY, std::min(maxY, sceneY));

            initialMouseX = mouseX;
            initialMouseY = mouseY;
            glutPostRedisplay();
        }
    }
};

GLfloat GraphicsApp::angle = -90.0f;
GLfloat GraphicsApp::sceneX = 0.0f;
GLfloat GraphicsApp::sceneY = 0.0f;
GLfloat GraphicsApp::triangleX = 0.0f;
GLfloat GraphicsApp::triangleY = 0.0f;
bool GraphicsApp::isDragging = false;
GLfloat GraphicsApp::initialMouseX;
GLfloat GraphicsApp::initialMouseY;
GLfloat GraphicsApp::stepSize = 0.005f;

int main(int argc, char** argv) {
    GraphicsApp::run(argc, argv);
    return 0;
}
