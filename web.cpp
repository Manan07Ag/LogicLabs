#include <stdio.h>
#include <GL/glut.h>

int x = 250; 
int y = 100;

void drawRedShoe(void)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(245, 30);
	glVertex2i(170, 30);
	glVertex2i(170, 60);
	glVertex2i(180, 60);
	glVertex2i(180, 70);
	glVertex2i(245, 70);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(280, 30);
	glVertex2i(355, 30);
	glVertex2i(355, 60);
	glVertex2i(345, 60);
	glVertex2i(345, 70);
	glVertex2i(280, 70);
	glEnd();
}

void drawBluePant(void)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(180, 170);
	glVertex2i(180, 70);
	glVertex2i(245, 70);
	glVertex2i(245, 135);
	glVertex2i(280, 135);
	glVertex2i(280, 170);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(280, 70);
	glVertex2i(280, 170);
	glVertex2i(345, 170);
	glVertex2i(345, 70);
	glEnd();
}

void drawLeftHand(void)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(180, 168);
	glVertex2i(130, 168);
	glVertex2i(130, 210);
	glVertex2i(180, 210);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(130, 210);
	glVertex2i(180, 210);
	glVertex2i(180, 285);
	glVertex2i(130, 270);
	glEnd();
}

void drawRightHand(void)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(345, 165);
	glVertex2i(390, 165);
	glVertex2i(390, 210);
	glVertex2i(345, 210);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(390, 210);
	glVertex2i(345, 210);
	glVertex2i(345, 285);
	glVertex2i(395, 270);
	glEnd();
}

void drawBody(void)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(220, 300);
	glVertex2i(310, 300);
	glVertex2i(345, 285);
	glVertex2i(345, 170);
	glVertex2i(180, 170);
	glVertex2i(180, 285);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(180, 200);
	glVertex2i(220, 200);
	glVertex2i(220, 250);
	glVertex2i(180, 250);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(345, 200);
	glVertex2i(305, 200);
	glVertex2i(305, 250);
	glVertex2i(345, 250);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(265, 300);
	glVertex2i(265, 250);

	glVertex2i(220, 300);
	glVertex2i(265, 260);
	glVertex2i(310, 300);
	glVertex2i(265, 260);

	glVertex2i(305, 255);
	glVertex2i(225, 255);

	glVertex2i(275, 250);
	glVertex2i(275, 230);

	glVertex2i(255, 250);
	glVertex2i(255, 230);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(235, 270);
	glVertex2i(295, 270);
	glVertex2i(295, 250);
	glVertex2i(235, 250);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(230, 210);
	glVertex2i(250, 210);
	glVertex2i(250, 220);
	glVertex2i(230, 220);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(275, 210);
	glVertex2i(295, 210);
	glVertex2i(295, 220);
	glVertex2i(275, 220);
	glEnd();
}

void drawEye(void)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(200, 330);
	glVertex2i(200, 380);
	glVertex2i(245, 345);
	glVertex2i(245, 330);
	glVertex2i(200, 330);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(200, 330);
	glVertex2i(200, 380);
	glVertex2i(245, 345);
	glVertex2i(245, 330);
	glVertex2i(200, 330);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(285, 330);
	glVertex2i(330, 330);
	glVertex2i(330, 380);
	glVertex2i(285, 345);
	glVertex2i(285, 330);
	glEnd();


	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(285, 330);
	glVertex2i(330, 330);
	glVertex2i(330, 380);
	glVertex2i(285, 345);
	glVertex2i(285, 330);
	glEnd();
}

void drawHead(void)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(220, 300);
	glVertex2i(310, 300);
	glVertex2i(355, 330);
	glVertex2i(355, 390);
	glVertex2i(315, 410);
	glVertex2i(225, 410);
	glVertex2i(175, 390);
	glVertex2i(175, 330);
	glVertex2i(220, 300);
	glEnd();


	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(220, 300);
	glVertex2i(310, 300);
	glVertex2i(355, 330);
	glVertex2i(355, 390);
	glVertex2i(315, 410);
	glVertex2i(225, 410);
	glVertex2i(175, 390);
	glVertex2i(175, 330);
	glVertex2i(220, 300);
	glEnd();
}

void drawShapeLines(void)
{
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex2i(170, 60);
	glVertex2i(170, 30);
	glVertex2i(245, 30);
	glVertex2i(245, 135);
	glVertex2i(280, 135);
	glVertex2i(280, 30);
	glVertex2i(355, 30);
	glVertex2i(355, 60);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);

	glVertex2i(280, 70);
	glVertex2i(345, 70);

	glVertex2i(245, 70);
	glVertex2i(180, 70);

	glVertex2i(345, 60);
	glVertex2i(345, 285);

	glVertex2i(180, 60);
	glVertex2i(180, 285);

	// Hand Left
	glVertex2i(180, 165);
	glVertex2i(135, 165);

	glVertex2i(130, 168);
	glVertex2i(130, 270);

	glVertex2i(130, 270);
	glVertex2i(220, 300);

	// Hand Right
	glVertex2i(345, 165);
	glVertex2i(390, 165);

	glVertex2i(395, 168);
	glVertex2i(395, 270);

	glVertex2i(395, 270);
	glVertex2i(310, 300);

	//Sholder
	glVertex2i(220, 300);
	glVertex2i(310, 300);
	glEnd();
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(GLfloat(10.0));
	
	drawRedShoe();
	drawBluePant();
	drawLeftHand();
	drawRightHand();
	drawBody();
	drawHead();
	drawEye();
	drawShapeLines();
	glFlush();
}


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(520, 575);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Draw the attached Image: Spider Man");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}