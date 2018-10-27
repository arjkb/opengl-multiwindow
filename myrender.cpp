#include <glm/glm.hpp>
#include <stdio.h>
#include "GL/glew.h"
#include "GL/freeglut.h"

using namespace std;

GLint win1, win2;

void keyboard(unsigned char key, int x, int y)  {
    const GLfloat RED[] = {1.0, 0.0, 0.0};
    const GLfloat GREEN[] = {0.0, 1.0, 0.0};
    const GLfloat BLUE[] = {0.0, 0.0, 1.0};

    printf("pressed key '%c'\n", key);
    
    switch (key)
    {
        case 'x':
        case 'X':   printf("at %c\n", key);
                    glColor3fv(GREEN); break;
        default:    break;
    }
    glutPostRedisplay();
}

void drawSquare(const GLfloat SIDE)    {
    glBegin(GL_POLYGON);
        glVertex3f(-SIDE,SIDE,0);
        glVertex3f(-SIDE,-SIDE,0);
        glVertex3f(SIDE,-SIDE,0);
        glVertex3f(SIDE,SIDE,0);
    glEnd();
}

void display(void)  {
    const GLfloat RED[] = {1.0, 0.0, 0.0};
    const GLfloat BLUE[] = {0.0, 0.0, 1.0};
    
    printf(" current window = %d\n", glutGetWindow());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if(glutGetWindow() == win1) {
        glColor3fv(RED);
        drawSquare(0.5);
    } else if(glutGetWindow() == win2)  {
        glColor3fv(BLUE);
        drawSquare(0.5);
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

    glutKeyboardFunc(keyboard);

    printf(" win1 = %d, win2 = %d\n", win1, win2);

    glutMainLoop();

    return 0;
}
