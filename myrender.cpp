#include <glm/glm.hpp>
#include <stdio.h>
#include "GL/glew.h"
#include "GL/freeglut.h"

using namespace std;

void display(void)  {
    const GLfloat RED[] = {1.0, 0.0, 0.0};
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3fv(RED);
    glVertex3f(-0.5,0.5,0);
    glVertex3f(-0.5,-0.5,0);
    glVertex3f(0.5,-0.5,0);
    glVertex3f(0.5,0.5,0);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[]) {
    printf("hello, world!\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("window 1");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
