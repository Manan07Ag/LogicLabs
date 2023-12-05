#include <GL/glut.h>
#include <cmath>

GLfloat triangleAngle = 0.0f;  
GLfloat squareSize = 0.5f;      
GLfloat linePosition = -1.0f;  
GLfloat lineSpeed = 0.0025f;    
bool zoomingIn = true;          
bool lineMovingForward = true;  

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.50f, 0.0f);  
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}
void drawSquare() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.50f); 
    glVertex2f(-squareSize, -squareSize);
    glVertex2f(squareSize, -squareSize);
    glVertex2f(squareSize, squareSize);
    glVertex2f(-squareSize, squareSize);
    glEnd();
}
void drawLine() {
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);  
    glVertex2f(-1.0f, linePosition);
    glVertex2f(1.0f, linePosition);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH) / 3, glutGet(GLUT_WINDOW_HEIGHT));
    glPushMatrix();
    glTranslatef(-0.33f, 0.0f, -1.0f); 
    glRotatef(triangleAngle, 0.0f, 0.0f, 1.0f); 
    drawTriangle();
    glPopMatrix();
    glViewport(glutGet(GLUT_WINDOW_WIDTH) / 3, 0, glutGet(GLUT_WINDOW_WIDTH) / 3, glutGet(GLUT_WINDOW_HEIGHT));
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -1.0f); 
    drawSquare();
    glPopMatrix();
    glViewport(2 * glutGet(GLUT_WINDOW_WIDTH) / 3, 0, glutGet(GLUT_WINDOW_WIDTH) / 3, glutGet(GLUT_WINDOW_HEIGHT));
    glPushMatrix();
    glTranslatef(0.33f, 0.0f, -1.0f); 
    drawLine();
    glPopMatrix();
    glutSwapBuffers();
}
void idle()
 {
    triangleAngle += 0.5f;  
    if (triangleAngle > 360.0f)
        triangleAngle -= 360.0f;

    if (zoomingIn)
     {
        squareSize += 0.001f; 
        if (squareSize >= 0.5f)
            zoomingIn = false;
    } 
    else 
    {
        squareSize -= 0.001f;  
        if (squareSize <= 0.1f)
            zoomingIn = true;
    }

    if (lineMovingForward) 
    {
        linePosition += lineSpeed; 
        if (linePosition > 1.0f)
            lineMovingForward = false;
    } 
    else 
    {
        linePosition -= lineSpeed;  
        if (linePosition < -1.0f)
            lineMovingForward = true;
    }

    glutPostRedisplay();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Three Animations");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutMainLoop();

    return 0;
}