#include <glm/glm.hpp>
#include <stdio.h>
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
        
        void setColor(GLfloat color[3])  {
            this->color = color;
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
        case 'X':   printf("at %c\n", key);
                    glColor3fv(COLOR_GREEN); break;
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

    if(glutGetWindow() == win1) {
        // glColor3fv(COLOR_RED);
        drawSquare(0.5);
    } else if(glutGetWindow() == win2)  {
        // glColor3fv(COLOR_BLUE);
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

    // glColor3fv(COLOR_RED);

    printf(" win1 = %d, win2 = %d\n", win1, win2);

    glutMainLoop();

    return 0;
}
