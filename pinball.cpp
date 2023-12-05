#include <GL/glut.h>

// Ball properties
float ballX = 0.0f;
float ballY = 0.0f;
float ballRadius = 0.05f;
float ballSpeedX = 0.02f;
float ballSpeedY = 0.02f;

// Bar properties
float barX = 0.0f;
float barWidth = 0.4f;
float barHeight = 0.02f;

// Window dimensions
int windowWidth = 800;
int windowHeight = 600;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawBall() {
    glLoadIdentity();
    glTranslatef(ballX, ballY, 0.0);
    glColor3f(1.0, 0.0, 0.0); // Red ball
    glBegin(GL_TRIANGLE_FAN);
    for (float angle = 0.0; angle <= 2.0 * 3.141592; angle += 0.01) {
        float x = ballRadius * cos(angle);
        float y = ballRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawBar() {
    glLoadIdentity();
    glTranslatef(barX, -0.9, 0.0);
    glColor3f(0.0, 0.0, 1.0); // Blue bar
    glBegin(GL_QUADS);
    glVertex2f(-barWidth / 2, 0.0);
    glVertex2f(barWidth / 2, 0.0);
    glVertex2f(barWidth / 2, barHeight);
    glVertex2f(-barWidth / 2, barHeight);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Update ball position
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    // Ball collisions with walls
    if (ballX + ballRadius > 1.0 || ballX - ballRadius < -1.0) {
        ballSpeedX = -ballSpeedX;
    }
    if (ballY + ballRadius > 1.0 || ballY - ballRadius < -1.0) {
        ballSpeedY = -ballSpeedY;
    }

    // Ball collision with bar
    if (ballY - ballRadius < -0.9 && ballX >= barX - barWidth / 2 && ballX <= barX + barWidth / 2) {
        ballSpeedY = -ballSpeedY;
    }

    drawBall();
    drawBar();

    glutSwapBuffers();
}

void mouseMotion(int x, int y) {
    // Convert mouse coordinates to OpenGL coordinates
    barX = (x / static_cast<float>(windowWidth) * 2.0) - 1.0;

    // Ensure the bar stays within the window boundaries
    if (barX - barWidth / 2 < -1.0) {
        barX = -1.0 + barWidth / 2;
    }
    else if (barX + barWidth / 2 > 1.0) {
        barX = 1.0 - barWidth / 2;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Ball and Bar");

    init();

    glutDisplayFunc(display);
    glutPassiveMotionFunc(mouseMotion);

    glutMainLoop();

    return 0;
}
