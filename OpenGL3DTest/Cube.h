#pragma once

#include <stdio.h>
#include <Windows.h>
#include <GL\freeglut.h>

#include "Vector.h"

class Cube
{
public:
	Cube();
	Cube(MyVector, float );

	void drawCube();

private:
	MyVector center; //���S�_�̍��W
	MyVector ver[8]; //�W�̒��_
};


Cube::Cube() {
	MyVector res = MyVector(0, 0, 0);
	Cube(res, 1.0f);
}

Cube::Cube(MyVector center, float length) {
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

	for (int i = 0; i < 8; i++) {
		ver[i] = MyVector(cube[i * 3] * length, cube[i * 3 + 1] * length, cube[i * 3 + 2] * length
		);
		//printf_s("%f,%f,%f\n", cube[i * 3] * length, cube[i * 3 + 1] * length, cube[i * 3 + 2] * length);
	}
	//for (int i = 0; i < 8; i++)
	//	printf("%f,%f,%f\n", ver[i].getX(), ver[i].getY(), ver[i].getZ());

}

void Cube::drawCube()
{
	// Todo: �����̃G���[�𒼂�
	for (int i = 0; i < 8; i++)
		printf("%f,%f,%f\n", ver[i].getX(), ver[i].getY(), ver[i].getZ());

	float vertexes[24];
	for (int i = 0; i < 8; i++) {
		vertexes[i * 3] = ver[i].getX();
		vertexes[i * 3 + 1] = ver[i].getY();
		vertexes[i * 3 + 2] = ver[i].getZ();
	}

	//for(int i=0;i<24;i++)
	//	printf_s("%f\n",vertexes[i]);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertexes);

	//glBegin(GL_LINE_STRIP);
	//{
	//	for (int i = 0; i < 4; i++) {
	//		glArrayElement(i);
	//	}
	//	glArrayElement(0);
	//}
	//glEnd();

	//glBegin(GL_LINES);
	//{
	//	for (int i = 0; i < 4; i++) {
	//		glArrayElement(i);
	//		glArrayElement(i + 4);
	//	}
	//}
	//glEnd();

	//glBegin(GL_LINE_STRIP);
	//{
	//	for (int i = 4; i < 8; i++) {
	//		glArrayElement(i);
	//	}
	//	glArrayElement(4);
	//}
	//glEnd();

	glPointSize(5);
	glBegin(GL_POINTS);
	{
		for (int i = 0; i < 8; i++)
			glArrayElement(i);
	}
	glEnd();
	//glFlush();
}
