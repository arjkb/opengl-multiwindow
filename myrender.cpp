#include <glm/glm.hpp>
#include <stdio.h>
#include <iostream>
#include "GL/glew.h"
#include "GL/freeglut.h"

using namespace std;

GLint win1, win2;

const GLfloat COLOR_RED[] = {1.0, 0.0, 0.0};
const GLfloat COLOR_GREEN[] = {0.0, 1.0, 0.0};
const GLfloat COLOR_BLUE[] = {0.0, 0.0, 1.0};

class Window
{
    private:
        GLfloat *color;
        int id;
    public:
        // Window(/* args */);
        // ~Window();
        void setID(const int ID)  {
            this->id = ID;
        }

        int getID(void) {
            return this->id;
        } 
        
        void setColor(const GLfloat color[3])  {
            this->color = (GLfloat *) color;
        }

        GLfloat* getColor(void)  {
            return this->color;
        }
} window1, window2;

// Window::myrender(/* args */)
// {
// }

// Window::~myrender()
// {
// }


void keyboard(unsigned char key, int x, int y)  {
    printf("pressed key '%c'\n", key);
    switch (key)
    {
        case 'x':   
        case 'X':   printf("gui\n");
                    window1.setColor(COLOR_GREEN);
                    window2.setColor(COLOR_RED);
                    break;
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
    printf(" current window = %d\n", glutGetWindow());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // iterate through window objects, and apply its properties
    for(int window = 1; window <= 2; window++)  {   
        glutSetWindow(window);
        if(glutGetWindow() == window1.getID()) {
            // glColor3fv(COLOR_RED);
            printf("window1!\n");
            glColor3fv(window1.getColor());
            drawSquare(0.5);
        } else if(glutGetWindow() == window2.getID())  {
            printf("window2!\n");
            glColor3fv(window2.getColor());
            drawSquare(0.5);
        }
        glFlush();
        glutSwapBuffers();
    }
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
    window1.setID(win1);
    window2.setID(win2);

    window1.setColor(COLOR_RED);
    window2.setColor(COLOR_BLUE);
    printf("main\n");

    glutDisplayFunc(display);

    

    glutKeyboardFunc(keyboard);

    // glColor3fv(COLOR_RED);

    printf(" win1 = %d, win2 = %d\n", win1, win2);

    glutMainLoop();

    return 0;
}
