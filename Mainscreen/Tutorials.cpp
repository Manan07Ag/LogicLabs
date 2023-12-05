#include <GL/glut.h>
#include <cstring>
#include "Tutorials.h"
#include <iostream> 



class LogicGateDescription {
public:
     LogicGateDescription()
        : windowWidth(800), windowHeight(600), displayDescriptionAND(true),
          displayDescriptionOR(false), displayDescriptionNAND(false),
          displayDescriptionNOR(false), displayDescriptionXOR(false),
          displayDescriptionNOT(false) {
        instance = this; // Set instance pointer to this object
    }

    void initialize() {
    // Set up the display and keyboard callbacks here
    glutDisplayFunc(displayWrapper);
    glutReshapeFunc(reshapeWrapper);
    glutKeyboardFunc(keyboardWrapper);
     glutMouseFunc(mouseWrapper); 

    // Initial OpenGL setup if needed, like glClearColor, etc.
    initOpenGL();

    // Do not call glutMainLoop(); it is already running
}
    void initOpenGL() {
        glClearColor(0.0, 0.0, 0.0, 1.0);
    }

    // This function replaces the global display function
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
    glutSwapBuffers();
    }

    // Wrappers for GLUT callbacks
    static void displayWrapper() {
        std::cout << "Tutorial display function called." << std::endl;
        instance->display();
        
    }

    static void reshapeWrapper(int width, int height) {
        instance->reshape(width, height);
    }

    static void keyboardWrapper(unsigned char key, int x, int y) {
        instance->keyboard(key, x, y);
    }

    static void mouseWrapper(int button, int state, int x, int y) {
    instance->mouse(button, state, x, y);
}


// Convert pixel coordinates to OpenGL coordinates
float getOpenGLX(int x) {
    return (2.0f * x) / windowWidth - 1.0f;
}

float getOpenGLY(int y) {
    return 1.0f - (2.0f * y) / windowHeight;
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float mouseX = getOpenGLX(x);
        float mouseY = getOpenGLY(y);

        // Check if the "Next" button is clicked
        if (mouseX >= 0.8f && mouseX <= 1.0f && mouseY <= -0.8f && mouseY >= -1.0f) {
            // Next button logic
            nextDescription();
        }

        // Check if the "Back" button is clicked
        if (mouseX >= -1.0f && mouseX <= -0.75f && mouseY <= -0.8f && mouseY >= -1.0f) {
            // Back button logic
            previousDescription();
        }
    }
}

    // More functions...

private:
    int windowWidth, windowHeight;
    bool displayDescriptionAND;
    bool displayDescriptionOR;
    bool displayDescriptionNAND;
    bool displayDescriptionNOR;
    bool displayDescriptionXOR;
    bool displayDescriptionNOT;
    static LogicGateDescription* instance;
        // Button bounds for "Next" button
    // Button bounds for "Next" button
float nextButtonX = 0.8f; // X position
float nextButtonY = -1.0f; // Y position
float nextButtonWidth = 0.2f; // Width (1.0 - 0.8)
float nextButtonHeight = 0.2f; // Height (-0.8 - (-1.0))

// Button bounds for "Back" button
float backButtonX = -1.0f; // X position
float backButtonY = -1.0f; // Y position
float backButtonWidth = 0.25f; // Width (-0.75 - (-1.0))
float backButtonHeight = 0.2f; // Height (-0.8 - (-1.0))


    void renderBitmapString(float x, float y, void* font, const char* string) {
        glRasterPos2f(x, y);
        while (*string) {
            glutBitmapCharacter(font, *string);
            string++;
        }
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

void nextDescription() {
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
    }

void previousDescription() {
        if (displayDescriptionAND) {
            displayDescriptionAND = false;
            displayDescriptionNOR = true;
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

    void keyboard(unsigned char key, int x, int y) {
        if (key == 'n' || key == 'N') {
            nextDescription(); // Call the new method
        } else if (key == 'b' || key == 'B') {
            previousDescription(); // Call the new method
        }
    }

    // More private methods...
};
LogicGateDescription* LogicGateDescription::instance = nullptr;

void showTutorials() {
    std::cout << "Showing Tutorials..." << std::endl;
    static LogicGateDescription tutorials;
    tutorials.initialize(); // Set callbacks but don't call glutMainLoop

    // Force redraw. Note: This should be called if the main loop is running and window context is correct
    glutPostRedisplay();
}


