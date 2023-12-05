#include <GL/freeglut.h>

float rotation_angle = 0.0f;
const float increment = 5.0f; // rotation increment in degrees

void setAlternateColor(int step) {
    switch (step % 3) {
        case 0:
            glColor3f(0.0f, 1.0f, 1.0f); // Blue
            break;
        case 1:
            glColor3f(1.0f, 0.30f, 0.71f); // Pink
            break;
        case 2:
            glColor3f(1.0f, 1.0f, 0.0f); // Yellow
            break;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Define a longer rectangle with the center at the origin
    float rectangle[4][2] = {
        {-0.05f, -0.7f},
        {0.05f, -0.7f},
        {0.05f, 0.7f},
        {-0.05f, 0.7f}
    };

    int step = 0;
    for (rotation_angle = 0.0f; rotation_angle <= 360.0f; rotation_angle += increment) {
        glPushMatrix();
        
        // Set the color for the current rectangle
        setAlternateColor(step);
        
        // Rotate the rectangle
        glRotatef(rotation_angle, 0.0f, 0.0f, 1.0f);
        
        // Translate the rectangle outwards to create the "orbiting" effect
        glTranslatef(0.5f, 0.0f, 0.0f); // Here, 0.5f is the radius of the orbit
        
        glBegin(GL_QUADS);
        for (int i = 0; i < 4; i++) {
            glVertex2f(rectangle[i][0], rectangle[i][1]);
        }
        glEnd();
        
        glPopMatrix();
        step++;
    }

    // Swap the buffers to display the rendered image
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Orbiting Rectangle Captures with Alternate Colors");
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}
