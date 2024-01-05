#include<bits/stdc++.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

// Set up the window size
int width = 800;
int height = 600;
#define M_PI 3.1416

// Function to draw the arc using the polynomial method
void drawArc(float centerX, float centerY, float radius, float startAngle, float endAngle, int numSegments)
{
    glBegin(GL_LINE_STRIP);

    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = startAngle + (endAngle - startAngle) * static_cast<float>(i) / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

// Function to display the scene
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2d(0, 300);
    glVertex2d(800, 300);
    glVertex2d(400, 0);
    glVertex2d(400, 600);
    glEnd();
    glColor3f(1.0, 1.0, 1.0); // Set color to white


    // Draw an arc from 45 to 135 degrees with radius 100
    drawArc(width / 2.0, height / 2.0, 100.0, M_PI / 180, M_PI / 4.0, 100);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Arc Drawing using Polynomial Method");
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to black
    gluOrtho2D(0, width, 0, height);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
