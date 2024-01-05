#include<bits/stdc++.h>
using namespace std;
#include <GL/gl.h>
#include<GL/glut.h>
#include<math.h>

int first=0;
int xi,yi,xf,yf;
int r;
void putpixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}
double round(double n)
{
    return (n >= 0)?(int)(n + 0.5):(int)(n - 0.5);
}
void Bresenham_circle(int r)
{
    int x=0, y = r,d = 3 - 2 * r;

    while(x <= y)
    {
        //Here Transform each x,y coordinates by 250 pixels
        putpixel(250 + x, 250 + y);
        putpixel(250 + y, 250 + x);
        putpixel(250 - x, 250 + y);
        putpixel(250 - x, 250 - y);
        putpixel(250 - y, 250 + x);
        putpixel(250 - y, 250 - x);
        putpixel(250 + y, 250 - x);
        putpixel(250 + x, 250 - y);
        if(d < 0)
            d=d + (4 * x) + 6;
        else
        {
            d=d + (4 * (x - y)) + 10;
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
    Bresenham_circle(r);
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
    cout << "Enter radius : " ;
    cin >> r;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Bresenham-Circle");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
  }
