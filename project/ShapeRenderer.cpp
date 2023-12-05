// ShapeRenderer.cpp
#include "ShapeRenderer.h"
#include <GL/glut.h>
#include <cmath>

void ShapeRenderer::NotG() {
    // Drawing the triangle
    glPushMatrix();
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.0f, 0.2f);
    glEnd();
    glPopMatrix();

    // Drawing lines
    glBegin(GL_LINES);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(-0.4f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glEnd();

    // Drawing another line
    glBegin(GL_LINES);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glEnd();

    // Drawing a circle
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; ++i) {
        float angle = static_cast<float>(i) * 3.14159265f / 180.0f;
        float x = 0.05f * std::cos(angle);
        float y = 0.05f * std::sin(angle);
        glVertex2f(0.25f + x, y);
    }
    glEnd();

    // Drawing a stippled rectangle
    glLineStipple(1, 0x00FF);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(-0.4f, 0.3f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}
