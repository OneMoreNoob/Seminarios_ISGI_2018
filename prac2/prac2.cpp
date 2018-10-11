/**
*  prac2.cpp
*
*  Plantilla basica de una aplicacion en OpenGL
*
*  @author:   rvivo@upv.es
*  @version:  v1.0 Oct,2018
*  @require:  freeglut
*
**/

#define PROYECTO "ISGI::P2::Estrella de David"

#include <iostream>
#include "gl/freeglut.h"
#include <cmath>

static GLuint estrella;

using namespace std;

void init()
{
	estrella = glGenLists(1);
	glNewList(estrella, GL_COMPILE);

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < 4; i++) {
		double angle = (1 + (i * 4) % 12) * PI / 6;
		glVertex3f(1.0 * cos(angle), 1.0 * sin(angle), 0.0);
		glVertex3f(0.7 * cos(angle), 0.7 * sin(angle), 0.0);
	}
		glVertex3f(0.5*cos(0 * 2 * 3.1415926 / 5), 0.5*sin(0 * 2 * 3.1415926 / 5), 0.0);
		glVertex3f(0.5*cos(1 * 2 * 3.1415926 / 5), 0.5*sin(1 * 2 * 3.1415926 / 5), 0.0);
		glVertex3f(0.5*cos(2 * 2 * 3.1415926 / 5), 0.5*sin(2 * 2 * 3.1415926 / 5), 0.0);
		glVertex3f(0.5*cos(3 * 2 * 3.1415926 / 5), 0.5*sin(3 * 2 * 3.1415926 / 5), 0.0);
	glEnd();

	glEndList();

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0);
	
	glPolygonMode(GL_FRONT, GL_LINE);
	glPointSize(10.0);
	glColor3f(0.0,0.0,0.3);
	glCallList(estrella);

	glFlush();
}

void reshape(GLint w, GLint h)
{

}

void main(int argc, char** argv)
{
	// Initializations
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow(PROYECTO);
	init();
	cout << PROYECTO << " en marcha" << endl;
	// Callbacks
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	// Event loop
	glutMainLoop();
}
