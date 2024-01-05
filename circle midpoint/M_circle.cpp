#include<bits/stdc++.h>
using namespace std;
#include <GL/gl.h>
#include<GL/glut.h>
#include<math.h>
int r;
void putpixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void Midpoint_circle(int r)
{

    int x = 0, y = r, p = 1-r;
    while (x <= y)
    {

        putpixel(x, y);
        putpixel(y, x);
        putpixel(-x, y);
        putpixel(y, -x);
        putpixel(x, -y);
        putpixel(-y, x);
        putpixel(-x, -y);
        putpixel(-y, -x);

        if (p < 0)
        {
            p += 2*x + 3;
        }
        else
        {
            p += 2*x - 2*y + 5;
            y--;
        }
        x++;
    }
}
void display()
{
    glClearColor(0.0, 0.0, 0.3, 0.0);
    glColor3f(0.5, 0.3, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    glFlush();
    Midpoint_circle(r);
}
void myinit()
{
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)500, 0.0, (GLdouble)500);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char** argv)
{
    printf("Enter radius: ");
    cin >> r;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Midpoint-Circle");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
