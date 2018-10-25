#include <glm/glm.hpp>
#include <stdio.h>
#include "GL/glew.h"
#include "GL/freeglut.h"

using namespace std;

GLint win1, win2;

void drawSquare(const GLfloat SIDE, const GLfloat COLOR[])    {
    glBegin(GL_POLYGON);
        glColor3fv(COLOR);
        glVertex3f(-SIDE,SIDE,0);
        glVertex3f(-SIDE,-SIDE,0);
        glVertex3f(SIDE,-SIDE,0);
        glVertex3f(SIDE,SIDE,0);
    glEnd();
}

void display(void)  {
    const GLfloat RED[] = {1.0, 0.0, 0.0};
    
    printf(" current window = %d\n", glutGetWindow());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if(glutGetWindow() == win1) {
        drawSquare(0.5, RED);
    } else if(glutGetWindow() == win2)  {
        drawSquare(0.5, RED);
    }
    
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[]) {
    printf("hello, world!\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(50, 50);
    win1 = glutCreateWindow("window 1");
    glutDisplayFunc(display);

    glutInitWindowPosition(500, 50);
    win2 = glutCreateWindow("window 2");
    glutDisplayFunc(display);

    printf(" win1 = %d, win2 = %d\n", win1, win2);

    glutMainLoop();

    return 0;
}
