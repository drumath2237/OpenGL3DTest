// OpenGL3DTest.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include <GL\freeglut.h>

#define TRANSLATING 1
#define SCALING 2
#define ROTATING 3

int transState = 0;

float colors[] = {
	1,0,0,
	1,0,0,
	1,0,0,
	1,0,0,

	0,0,1,
	0,0,1,
	0,0,1,
	0,0,1,
};

float cube[] = {
	0.5, 0.5, -0.5,
	0.5, -0.5, -0.5,
	-0.5, -0.5, -0.5,
	-0.5, 0.5, -0.5,

	0.5, 0.5, 0.5,
	0.5, -0.5, 0.5,
	-0.5, -0.5, 0.5,
	-0.5, 0.5, 0.5
};

void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, cube);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glBegin(GL_LINE_STRIP);
	{
		for (int i = 0; i < 4; i++) {
			glArrayElement(i);
		}
		glArrayElement(0);
	}
	glEnd();

	glBegin(GL_LINES);
	{
		for (int i = 0; i < 4; i++) {
			glArrayElement(i);
			glArrayElement(i + 4);
		}
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	{
		for (int i = 4; i < 8; i++) {
			glArrayElement(i);
		}
		glArrayElement(4);
	}
	glEnd();

	glPointSize(5);
	glBegin(GL_POINTS);
	{
		for (int i = 0; i < 8; i++)
			glArrayElement(i);
	}
	glEnd();

	glFlush();
}

void mouse(int button, int state, int x, int y) {
	//glRotatef(5.0, 0, 1, 0);
}

void key(unsigned char key, int x, int y) {
	if (key == 'g')
		transState = TRANSLATING;
	else if (key == 's')
		transState = SCALING;
	else if (key == 'r')
		transState = ROTATING;
	else
		transState = 0;

	printf_s("state is %d\n", transState);
}

void motion(int x, int y) {
	printf_s("motion: (%d, %d)\n", x, y);
}

void passive(int x, int y) {
	printf_s("passive: (%d, %d)\n", x, y);
}

void anim(int value) {
	glRotatef(5.0, 0, 1, 0);
	glutPostRedisplay();
	glutTimerFunc(100, anim, 0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutCreateWindow("3D Test!");

	glRotatef(15.0, 1, 0, 0);
	glRotatef(10.0, 0, 1, 0);

	glutDisplayFunc(disp);
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	glutMotionFunc(motion);
	glutPassiveMotionFunc(passive);
	glutTimerFunc(100, anim, 0);
	
	glutMainLoop();
    return 0;
}