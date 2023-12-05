#include <GL/glut.h>
#include <cstring>

int windowWidth = 800;
int windowHeight = 600;

bool displayDescriptionAND = true;
bool displayDescriptionOR = false;
bool displayDescriptionNAND = false;
bool displayDescriptionNOR = false;
bool displayDescriptionXOR = false;
bool displayDescriptionNOT = false;

void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);

    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (displayDescriptionAND) {
        
        glColor3f(1.0, 1.0, 1.0);

        float x = -0.9;
        float y = 0.7;

        const char* description = "An AND gate is an electrical circuit that combines two signals,\n"
        "so that the output is on if both signals are present. \n"
        "The output of the AND gate is connected to a base driver\n"
        "which is coupled to the bases of transistors, and alternately\n"
        "switches the transistors at opposite corners of the inverter.\n"
        "                                                            \n"
        "  A    B     Y   \n"
        "  0    0     0   \n"
        "  0    1     0   \n"
        "  1    0     0   \n"
        "  1    1     1   ";

        const char* line = description;
        while (*line) {
            const char* endLine = strchr(line, '\n');
            if (endLine) {
                int lineLength = endLine - line;
                char lineBuffer[256];
                strncpy(lineBuffer, line, lineLength);
                lineBuffer[lineLength] = '\0';
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, lineBuffer);
                y -= 0.1;
                line = endLine + 1;
            } else {
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, line);
                break;
            }
        }
    } else if (displayDescriptionOR) {
        
        glColor3f(1.0, 1.0, 1.0);

        float x = -0.9;
        float y = 0.7;

        const char* description = "An OR gate is an electrical circuit that combines \n"
        "two input signals, and it produces an output that is on if at least\n"
        "one of the input signals is present. The output of the OR gate is  \n"
        "connected to a base driver, which is coupled to the bases of transistors, and \n"
        "alternately switches the transistors at opposite corners of the inverter.\n"
        "\n"
        "  A    B     Y  \n"
        "  0    0     0   \n"
        "  0    1     1   \n"
        "  1    0     1   \n"
        "  1    1     1   ";

        const char* line = description;
        while (*line) {
            const char* endLine = strchr(line, '\n');
            if (endLine) {
                int lineLength = endLine - line;
                char lineBuffer[256];
                strncpy(lineBuffer, line, lineLength);
                lineBuffer[lineLength] = '\0';
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, lineBuffer);
                y -= 0.1;
                line = endLine + 1;
            } else {
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, line);
                break;
            }
        }
    } else if (displayDescriptionNAND) {
        
        glColor3f(1.0, 1.0, 1.0);

        float x = -0.9;
        float y = 0.7;

        const char* description = "A NAND gate is an electrical circuit that combines two input\n"
        "signals, and it generates an output that is on unless both input signals\n" 
        "are present. The output of the NAND gate is connected to a base driver,\n" 
        "which is coupled to the bases of transistors, and alternately switches\n" 
        "the transistors at opposite corners of the inverter.\n"
        "\n"
        "  A    B     Y  \n"
        "  0    0     1   \n"
        "  0    1     1   \n"
        "  1    0     1   \n"
        "  1    1     0   ";

        const char* line = description;
        while (*line) {
            const char* endLine = strchr(line, '\n');
            if (endLine) {
                int lineLength = endLine - line;
                char lineBuffer[256];
                strncpy(lineBuffer, line, lineLength);
                lineBuffer[lineLength] = '\0';
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, lineBuffer);
                y -= 0.1;
                line = endLine + 1;
            } else {
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, line);
                break;
            }
        }
    } else if (displayDescriptionNOR) {

        glColor3f(1.0, 1.0, 1.0);

        float x = -0.9;
        float y = 0.7;

        const char* description = "A NOR gate is an electrical circuit that combines two\n"
        "input signals, and it produces an output that is on only if neither\n"
        "of the input signals is present. The output of the NOR gate is connected \n"
        "to a base driver, which is coupled to the bases of transistors, \n"
        "and alternately switches the transistors at opposite corners of the inverter.\n"
        "\n"
        "  A    B     Y  \n"
        "  0    0     1   \n"
        "  0    1     0   \n"
        "  1    0     0   \n"
        "  1    1     0   ";

        const char* line = description;
        while (*line) {
            const char* endLine = strchr(line, '\n');
            if (endLine) {
                int lineLength = endLine - line;
                char lineBuffer[256];
                strncpy(lineBuffer, line, lineLength);
                lineBuffer[lineLength] = '\0';
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, lineBuffer);
                y -= 0.1;
                line = endLine + 1;
            } else {
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, line);
                break;
            }
        }
    } else if (displayDescriptionXOR) {
        
        glColor3f(1.0, 1.0, 1.0);

        float x = -0.9;
        float y = 0.7;

        const char* description = "An XOR gate is an electrical circuit that combines two  \n"
        "input signals, and it generates an output that is on when the number of \n"
        "input signals that are on is odd. The output of the XOR gate is \n"
        "connected to a base driver, which is coupled to the bases of transistors, \n"
        "and alternately switches the transistors at opposite corners of the inverter.\n"
        "\n"
        "  A    B     Y  \n"
        "  0    0     0   \n"
        "  0    1     1   \n"
        "  1    0     1   \n"
        "  1    1     0   ";

        const char* line = description;
        while (*line) {
            const char* endLine = strchr(line, '\n');
            if (endLine) {
                int lineLength = endLine - line;
                char lineBuffer[256];
                strncpy(lineBuffer, line, lineLength);
                lineBuffer[lineLength] = '\0';
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, lineBuffer);
                y -= 0.1;
                line = endLine + 1;
            } else {
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, line);
                break;
            }
        }
    } else if (displayDescriptionNOT) {
        // Display the description of the NOT gate
        glColor3f(1.0, 1.0, 1.0);

        float x = -0.9;
        float y = 0.7;

        const char* description = "A NOT gate, also known as an inverter, is an electrical \n"
        "circuit that takes a single input signal and produces an output \n"
        "that is the opposite of the input signal. The output of the NOT gate \n"
        "is connected to a base driver, which is coupled to the bases of transistors,\n" 
        "and alternately switches the transistors at opposite corners of the inverter.\n"
        "\n"
        "  A    Y  \n"
        "  0    1   \n"
        "  1    0   \n";

        const char* line = description;
        while (*line) {
            const char* endLine = strchr(line, '\n');
            if (endLine) {
                int lineLength = endLine - line;
                char lineBuffer[256];
                strncpy(lineBuffer, line, lineLength);
                lineBuffer[lineLength] = '\0';
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, lineBuffer);
                y -= 0.1;
                line = endLine + 1;
            } else {
                renderBitmapString(x, y, GLUT_BITMAP_9_BY_15, line);
                break;
            }
        }
    }

    // Render navigation buttons here (Next and Previous)
    // (Similar to the "display" function in the previous code)

    glColor3f(0.8, 0.0, 0.0); 
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);  // Bottom left corner
    glVertex2f(-0.75, -1.0);  // Bottom right corner
    glVertex2f(-0.75, -0.8);  // Top right corner
    glVertex2f(-1.0, -0.8);  // Top left corner
    glEnd();

    // Render the "Previous" text on the button
    glColor3f(1.0, 1.0, 1.0); 
    renderBitmapString(-0.95, -0.91, GLUT_BITMAP_9_BY_15, "Back");

    // Render the "Next" button at the bottom right corner
    glColor3f(0.0, 0.8, 0.0); 
    glBegin(GL_QUADS);
    glVertex2f(0.8, -0.8);  // Bottom right corner
    glVertex2f(1.0, -0.8);  // Bottom left corner
    glVertex2f(1.0, -1.0);  // Top left corner
    glVertex2f(0.8, -1.0);  // Top right corner
    glEnd();

    // Render the "Next" text on the button
    glColor3f(1.0, 1.0, 1.0); // White color for the text
    renderBitmapString(0.87, -0.91, GLUT_BITMAP_9_BY_15, "Next");

    glFlush();
}

void reshape(int w, int h) {
    windowWidth = w;
    windowHeight = h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'N' || key == 'n') {
        if (displayDescriptionAND) {
            displayDescriptionAND = false;
            displayDescriptionOR = true;
        } else if (displayDescriptionOR) {
            displayDescriptionOR = false;
            displayDescriptionNAND = true;
        } else if (displayDescriptionNAND) {
            displayDescriptionNAND = false;
            displayDescriptionNOR = true;
        } else if (displayDescriptionNOR) {
            displayDescriptionNOR = false;
            displayDescriptionXOR = true;
        } else if (displayDescriptionXOR) {
            displayDescriptionXOR = false;
            displayDescriptionNOT = true;
        } else if (displayDescriptionNOT) {
            displayDescriptionNOT = false;
            displayDescriptionAND = true;
        }
        glutPostRedisplay();
    } else if (key == 'B' || key == 'b') {
        if (displayDescriptionAND) {
            displayDescriptionAND = false;
            displayDescriptionNOR = false;
        } else if (displayDescriptionOR) {
            displayDescriptionOR = false;
            displayDescriptionAND = true;
        } else if (displayDescriptionNAND) {
            displayDescriptionNAND = false;
            displayDescriptionOR = true;
        } else if (displayDescriptionNOR) {
            displayDescriptionNOR = false;
            displayDescriptionNAND = true;
        } else if (displayDescriptionXOR) {
            displayDescriptionXOR = false;
            displayDescriptionNOR = true;
        } else if (displayDescriptionNOT) {
            displayDescriptionNOT = false;
            displayDescriptionXOR = true;
        }
        glutPostRedisplay();
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Logic Gate Description");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
