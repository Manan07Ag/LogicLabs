#include <GL/glut.h>
#include <SOIL/SOIL.h> // SOIL header
#include <iostream>

GLuint sphereTextureID; // Texture ID for the sphere
GLuint pandaTextureID;  // Texture ID for the panda

// Rotation angles
float angleX = 0.0f;
float angleY = 0.0f;

void loadTextures() {
    // Load texture for the sphere
    sphereTextureID = SOIL_load_OGL_texture(
        "sphere_texture.jpg", // Replace with your sphere texture file path
        SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y
    );

    if (!sphereTextureID) {
        std::cerr << "Failed to load sphere texture" << std::endl;
        return;
    }

    // Load texture for the panda
    pandaTextureID = SOIL_load_OGL_texture(
        "panda_texture.jpg", // Replace with your panda texture file path
        SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y
    );

    if (!pandaTextureID) {
        std::cerr << "Failed to load panda texture" << std::endl;
        return;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Position the camera
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Apply rotations
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    // Enable texture mapping for the sphere
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sphereTextureID);

    // Draw the textured sphere
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glutSolidSphere(1.0, 50, 50);

    // Disable texture mapping for the sphere
    glDisable(GL_TEXTURE_2D);

    // Enable texture mapping for the panda
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, pandaTextureID);

    // Draw a quad (or any shape) around the sphere to display the panda texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.2, -1.2, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1.2, -1.2, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.2, 1.2, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.2, 1.2, 0.0);
    glEnd();

    // Disable texture mapping for the panda
    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}

void idle() {
    // Update rotation angles
    angleX += 0.5f;
    angleY += 0.5f;

    // Redraw the scene
    glutPostRedisplay();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotating Sphere with Panda Texture");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    loadTextures(); // Load the textures

    glutMainLoop();

    return 0;
}
