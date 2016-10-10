#include <GLUT/glut.h>
#include <math.h>
#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>

const int W = 1000;
const int H = 1000;

void setupView_(int w, int h){
	glOrtho(0, w, h, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void restoreView_(){
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}

void display(void) {
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT );

//	glBegin(GL_LINE_LOOP);
//	glBegin(GL_LINES);
//	glBegin(GL_LINE_STRIP);
	setupView_(W, H);
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3d(0.0, 0.0, 0.0);
	glVertex2i(10, 10);
	glEnd();

	glFlush();
}

int main (int argc, char *argv[]) { 
	glutInit(&argc, argv);
	glutInitWindowSize(W , H);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glViewport(0, 0, 400, 400);
	glutMainLoop();                 // イベント待ち
	return 0;
}

