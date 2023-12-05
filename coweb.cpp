#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846;

// Quadratic Bezier Curve function
void drawBezierCurve(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_LINE_STRIP);
    for (float t = 0.0; t <= 1.0; t += 0.25) {
        float xt = (1 - t) * (1 - t) * x1 + 2 * (1 - t) * t * x2 + t * t * x3;
        float yt = (1 - t) * (1 - t) * y1 + 2 * (1 - t) * t * y2 + t * t * y3;
        glVertex2f(xt, yt);
    }
    glEnd();
}

void drawSpiderWeb() {
    glClear(GL_COLOR_BUFFER_BIT);

    float centerX = 0.0f;
    float centerY = 0.0f;
    int numPoints = 9; // Number of radial lines
    int numRings = 8;  // Number of concentric circles
    float maxRadius = 0.9f;

    // Draw radial lines
    for (int i = 0; i < numPoints; ++i) {
        float angle = 2.0 * PI * i / numPoints;
        float x = centerX + maxRadius * cos(angle);
        float y = centerY + maxRadius * sin(angle);

        glBegin(GL_LINES);
        glVertex2f(centerX, centerY);
        glVertex2f(x, y);
        glEnd();
    }

    // Draw concentric curved circles using Bezier curves
    for (int j = 1; j <= numRings; ++j) {
        float currentRadius = (maxRadius / numRings) * j;

        for (int i = 0; i < numPoints; ++i) {
            float startAngle = 2.0 * PI * i / numPoints;
            float endAngle = 2.0 * PI * (i + 1) / numPoints;

            float x1 = centerX + currentRadius * cos(startAngle);
            float y1 = centerY + currentRadius * sin(startAngle);

            float x3 = centerX + currentRadius * cos(endAngle);
            float y3 = centerY + currentRadius * sin(endAngle);

            // Control point slightly inside the circle to make the curves "pulled in"
            float controlRadius = currentRadius * 0.8;
            float x2 = centerX + controlRadius * cos((startAngle + endAngle) / 2);
            float y2 = centerY + controlRadius * sin((startAngle + endAngle) / 2);

            drawBezierCurve(x1, y1, x2, y2, x3, y3);
        }
    }

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Spider's Web using GLUT");
    
    glutDisplayFunc(drawSpiderWeb);
    
    glutMainLoop();
    return 0;
}
