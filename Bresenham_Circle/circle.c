#include<stdio.h>
#include <GL/gl.h>
#include<GL/glut.h>
#include<math.h>

int first=0;
int xi,yi,xf,yf;
void putpixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}
double round(double n)
{
    return (n>=0)?(int)(n+0.5):(int)(n-0.5);
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
    glClearColor(0.4,0.7,0.2,1.0);
    glColor3f(0.5,0.3,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    glFlush();
}
void mouse(int btn,int state,int y,int x)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        xi=0;
        yi=y;
        Bresenham_circle(yi);
    }
}
void myinit()
{
    glViewport(0,0,500,500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)500,0.0,(GLdouble)500);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char** argv)
{
    /*glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Bresenham-Circle");
    myinit();*/
    //glutDisplayFunc(display);
    //myinit();
    //glutMouseFunc(mouse);
    //glutMainLoop();
    return 0;
  }
