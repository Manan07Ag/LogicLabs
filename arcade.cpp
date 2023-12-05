#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Include the algorithm header for std::max and std::min
#include <iostream>
#include <sstream>

// Initial window dimensions
const int INITIAL_OUTER_WIDTH = 800;
const int INITIAL_OUTER_HEIGHT = 600;
int OUTER_WIDTH = INITIAL_OUTER_WIDTH;
int OUTER_HEIGHT = INITIAL_OUTER_HEIGHT;
int INNER_WIDTH = OUTER_WIDTH;
int INNER_HEIGHT = OUTER_HEIGHT;
const int BORDER_REDUCTION_INTERVAL = 3000; // 3 seconds
const int BORDER_REDUCTION_AMOUNT = 10;     // 0.1 cm in pixels (adjust as needed)

// Box dimensions
const GLfloat BOX_SIZE = 0.1f;

// Initial positions of the boxes
GLfloat controlledBoxX = 0.0f;
GLfloat controlledBoxY = 0.0f;
GLfloat movingBoxX = 0.0f;
GLfloat movingBoxY = 0.0f;
GLfloat movingBoxSpeedX = 0.02f;
GLfloat movingBoxSpeedY = 0.03f;

bool shouldStop = false;
bool gameover = false;
bool collisionOccurred = false;
bool redBoxAtRest = true;
unsigned int startTime = 0;
unsigned int elapsedTime = 0;
unsigned int timerStartTime = 0;
float reductionSpeed = 1.0f;
unsigned int borderReductionTime = 0;

// Function to update the moving box's position
void updateMovingBox(int value) {
    if (!shouldStop) {
        // Update the moving box's position
        movingBoxX += movingBoxSpeedX;
        movingBoxY += movingBoxSpeedY;

        // Bounce the moving box off the screen boundaries
        if (movingBoxX + BOX_SIZE > 1.0f || movingBoxX < -1.0f) {
            movingBoxSpeedX *= -1;
        }
        if (movingBoxY + BOX_SIZE > 1.0f || movingBoxY < -1.0f) {
            movingBoxSpeedY *= -1;
        }

        glutPostRedisplay();

        // Check for collision if the red box is not at rest
        if (!redBoxAtRest && !gameover && controlledBoxX < movingBoxX + BOX_SIZE &&
            controlledBoxX + BOX_SIZE > movingBoxX && controlledBoxY < movingBoxY + BOX_SIZE &&
            controlledBoxY + BOX_SIZE > movingBoxY) {
            gameover = true;
            elapsedTime = glutGet(GLUT_ELAPSED_TIME) - startTime; // Stop the timer
            collisionOccurred = true;
        }

        // Gradually decrease the inner window size when the game is not over
        if (!gameover && elapsedTime >= 5 && INNER_WIDTH > 200 && INNER_HEIGHT > 150) {
            INNER_WIDTH = std::max(200, INNER_WIDTH - static_cast<int>(reductionSpeed));
            INNER_HEIGHT = std::max(150, INNER_HEIGHT - static_cast<int>(reductionSpeed));
        }

        // Slow down the reduction speed every 3 seconds
        unsigned int currentTime = glutGet(GLUT_ELAPSED_TIME);
        unsigned int timerElapsedTime = currentTime - timerStartTime;
        if (timerElapsedTime >= BORDER_REDUCTION_INTERVAL) {
            reductionSpeed += 1.0f; // Adjust this value as needed
            timerStartTime = currentTime;
        }

        // Decrease the border size by 0.1 cm every 3 seconds and then stop
        if (currentTime - borderReductionTime >= BORDER_REDUCTION_INTERVAL && OUTER_WIDTH > 200 && OUTER_HEIGHT > 150) {
            OUTER_WIDTH = std::max(200, OUTER_WIDTH - BORDER_REDUCTION_AMOUNT);
            OUTER_HEIGHT = std::max(150, OUTER_HEIGHT - BORDER_REDUCTION_AMOUNT);
            borderReductionTime = currentTime;
        }
    }
    glutTimerFunc(16, updateMovingBox, 0); // 16ms delay (about 60 FPS)
}

// Function to handle keyboard input
void keyboard(unsigned char key, int x, int y) {
    if (gameover) return;

    switch (key) {
        case 'w':
        case 'W':
            controlledBoxY += 0.05f;
            redBoxAtRest = false;
            break;
        case 's':
        case 'S':
            controlledBoxY -= 0.05f;
            redBoxAtRest = false;
            break;
        case 'a':
        case 'A':
            controlledBoxX -= 0.05f;
            redBoxAtRest = false;
            break;
        case 'd':
        case 'D':
            controlledBoxX += 0.05f;
            redBoxAtRest = false;
            break;
        case 27: // 27 is the ASCII code for the Escape key
            shouldStop = true;
            break;
    }

    // Keep the controlled box within the screen boundaries
    controlledBoxX = std::max(-1.0f, std::min(controlledBoxX, 1.0f - BOX_SIZE));
    controlledBoxY = std::max(-1.0f, std::min(controlledBoxY, 1.0f - BOX_SIZE));

    glutPostRedisplay(); // Request a redraw
}

// Function to draw the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the viewport to the inner window dimensions
    glViewport((OUTER_WIDTH - INNER_WIDTH) / 2, (OUTER_HEIGHT - INNER_HEIGHT) / 2, INNER_WIDTH, INNER_HEIGHT);

    // Set up projection matrix to match viewport size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    // Draw the controlled box (Red)
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(controlledBoxX, controlledBoxY);
    glVertex2f(controlledBoxX + BOX_SIZE, controlledBoxY);
    glVertex2f(controlledBoxX + BOX_SIZE, controlledBoxY + BOX_SIZE);
    glVertex2f(controlledBoxX, controlledBoxY + BOX_SIZE);
    glEnd();

    // Draw the moving box (Blue)
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(movingBoxX, movingBoxY);
    glVertex2f(movingBoxX + BOX_SIZE, movingBoxY);
    glVertex2f(movingBoxX + BOX_SIZE, movingBoxY + BOX_SIZE);
    glVertex2f(movingBoxX, movingBoxY + BOX_SIZE);
    glEnd();

    // Display "Game Over" in the middle of the screen when the game is over
    if (gameover) {
        glColor3f(1.0f, 1.0f, 1.0f); // White color
        glRasterPos2f(-0.15f, 0.0f); // Position of the text
        std::string gameOverText = "Game Over!";
        for (char c : gameOverText) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }

        // Display elapsed time in seconds
        glRasterPos2f(-0.2f, -0.2f); // Position of the text
        std::stringstream timerText;
        timerText << "Time: " << elapsedTime / 1000 << "s";
        for (char c : timerText.str()) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
    }

    // Display the timer on the top left when no collision has occurred
    if (!collisionOccurred && !gameover) {
        glColor3f(1.0f, 1.0f, 1.0f); // White color
        glViewport(0, 0, OUTER_WIDTH, OUTER_HEIGHT); // Reset viewport to outer window dimensions
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, OUTER_WIDTH, 0, OUTER_HEIGHT, -1, 1);
        glRasterPos2f(10, OUTER_HEIGHT - 20); // Position of the text
        unsigned int currentTime = glutGet(GLUT_ELAPSED_TIME);
        elapsedTime = (currentTime - startTime) / 1000; // Convert to seconds
        std::stringstream timerText;
        timerText << "Time: " << elapsedTime << "s";
        for (char c : timerText.str()) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    // Handle window resizing (outer window remains constant)
    glViewport(0, 0, w, h);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(OUTER_WIDTH, OUTER_HEIGHT);
    glutCreateWindow("Controlled and Moving Boxes");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    // Seed for random number generation
    std::srand(std::time(0));

    // Start updating the moving box's position
    glutTimerFunc(0, updateMovingBox, 0);

    startTime = glutGet(GLUT_ELAPSED_TIME); // Start the timer
    timerStartTime = startTime; // Initialize timer start time
    borderReductionTime = startTime; // Initialize border reduction timer

    glutMainLoop();

    return 0;
}
