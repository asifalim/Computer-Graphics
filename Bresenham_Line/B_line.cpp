#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
GLfloat dx, dy;
GLfloat X1, x2, Y1, y2;
void display()
{
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) with corners at
    * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    */
    //glEnd();
    glColor3f (0.0, 0.0, 1.0);
    GLfloat p=(2 * dy) - dx;
    glBegin(GL_POINTS);
    for(GLfloat i = X1, j = Y1; i < x2; i++)
    {
        glVertex3f (i / 100, j / 100, 0.0);
        if(p >=0 )j++, p = p + (2 * dy) - (2 * dx);
        else if(p < 0)p = p + (2 * dy);
    }
    glEnd();

    /* don't wait!
    * start processing buffered OpenGL routines
    */
    glFlush ();
}
void init (void)
{
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{

    printf("Enter first point: ");
    cin >> X1 >> Y1;
    printf("Enter second point: ");
    cin >> x2 >> y2;
    dx = x2 - X1;
    dy = y2 - Y1;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
