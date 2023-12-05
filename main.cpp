#include <iostream>
#include <GL/glut.h>
#include <cstring>

int windowWidth = 800;
int windowHeight = 600;
int mainWindow;
bool isPlayClicked = false;

bool displayDescriptionAND = false;
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

void displayLogicGateDescription() {
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
    }else if (displayDescriptionOR) {
        
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

    }  else if (displayDescriptionNOR) {

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

void displayPlayButton() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw "Play" button
    glColor3f(0.0f, 0.7f, 0.0f); // Green color
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, 0.3f);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(-0.2f, 0.5f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for text
    renderBitmapString(-0.05f, 0.4f, GLUT_BITMAP_HELVETICA_18, "Play");

    // Draw "Exit" button
    glColor3f(0.7f, 0.0f, 0.0f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(-0.2f, 0.3f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for text
    renderBitmapString(-0.08f, 0.2f, GLUT_BITMAP_HELVETICA_18, "Exit");

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float mouseX = (float)(x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH) / 2);
        float mouseY = (float)(glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);

        if (isPlayClicked) {
            // Handle logic gate description window
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
    }else if (displayDescriptionOR) {
        
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

    }  else if (displayDescriptionNOR) {

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


    glutSwapBuffers();
    } else if (mouseX >= -0.2f && mouseX <= 0.2f && mouseY >= 0.3f && mouseY <= 0.5f) {
            isPlayClicked = true;
            glutDestroyWindow(mainWindow);

            // Create a new window to display logic gate descriptions
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
            glutInitWindowSize(windowWidth, windowHeight);
            mainWindow = glutCreateWindow("Logic Gate Description");

            // Set the display function for the new window
            glutDisplayFunc(displayLogicGateDescription);
        } else if (mouseX >= -0.2f && mouseX <= 0.2f && mouseY >= 0.1f && mouseY <= 0.3f) {
            exit(0); // Close the program
        }
    }
}

void keyboard(unsigned char key, int x, int y) {
    if (isPlayClicked) {
        // Handle keyboard input for navigation between gate descriptions
        switch (key) {
            case 'N':
            case 'n':
                if (displayDescriptionAND) {
                    displayDescriptionAND = false;
                    displayDescriptionOR = true;
                } else if (displayDescriptionOR) {
                    displayDescriptionOR = false;
                    displayDescriptionNAND = true;
                } else if (displayDescriptionNAND) {
                    displayDescriptionNAND = false;
                    displayDescriptionNOR = true;
                } 
                // Handle other cases for different gates

                glutPostRedisplay(); // Trigger redrawing
                break;
            case 'B':
            case 'b':
                if (displayDescriptionAND) {
                    displayDescriptionAND = false;
                    displayDescriptionNOT = true;
                } else if (displayDescriptionOR) {
                    displayDescriptionOR = false;
                    displayDescriptionAND = true;
                } else if (displayDescriptionNAND) {
                    displayDescriptionNAND = false;
                    displayDescriptionOR = true;
                }
                // Handle other cases for going back

                glutPostRedisplay(); // Trigger redrawing
                break;
            // Add more cases for other navigation keys if needed
        }
    }
}


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Default background color
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    mainWindow = glutCreateWindow("OpenGL Buttons Example");

    glutDisplayFunc(displayPlayButton);
    glutMouseFunc(mouse); // Set the mouse click callback

    init();

    glutMainLoop();

    return 0;
}
