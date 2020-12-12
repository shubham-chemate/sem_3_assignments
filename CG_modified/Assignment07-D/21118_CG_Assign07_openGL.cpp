#include <GL/glut.h>
#include "math.h"
#include "iostream"

using namespace std;

#define PI 3.14159265f

float xc = 0, yc = 0; //coordinates of the center of the ball

float ballRadius = 0.08; //radius of the ball relative to window size

//This is the function defined to draw the ball
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(xc, yc, 0.0); //translates the center
    //drawing the ball
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(0, 0, 255);
    int num = 100;
    float angle;
    for (int i = 0; i <= num; i++)
    {
        angle = i * 2 * PI / num;
        glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
    }
    glEnd();
    glFlush();
    glutSwapBuffers();
}

//Function Overloading
/* the keyPress function with the parameter list as 3 integers is defined for moving the ball
 and the next keyPress is defined for closing the window*/

void keyPress(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        yc += 0.02;
        if (yc > 1)
        {
            yc = -1.0;
        }
        cout << "UP" << endl;
        glutPostRedisplay();
    }
    //down key
    else if (key == GLUT_KEY_DOWN)
    {
        yc -= 0.02;
        if (yc < -1)
        {
            yc = 1;
        }
        cout << "Down" << endl;
        glutPostRedisplay();
    }
    //left key
    else if (key == GLUT_KEY_LEFT)
    {
        xc -= 0.02;
        if (xc < -1)
        {
            xc = 1;
        }
        cout << "Left" << endl;
        glutPostRedisplay();
    }
    //right key
    else if (key == GLUT_KEY_RIGHT)
    {
        xc += 0.02;
        if (xc > 1)
        {
            xc = -1;
        }
        cout << "Right" << endl;
        glutPostRedisplay();
    }
}

void keyPress(unsigned char key, int x, int y)
{
    if (key == 27)
    {
        cout << "Closing the program" << endl;
        exit(0);
    }
}

int main(int argc, char** argv)
{
    cout << "Simple Ball Game!!" << endl;
    cout << "Game Controls: \n";
    cout << "\t=> Move up             - UP Arrow Key" << endl;
    cout << "\t=> Move down           - DOWN Arrow Key" << endl;
    cout << "\t=> Move left           - LEFT Arrow Key" << endl;
    cout << "\t=> Move right          - RIGHT Arrow Key" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(600, 50);
    glutCreateWindow("Ball Movement using Keys");
    glutDisplayFunc(display); //callback function
    glClearColor(0.0, 0, 0.0, 0);
    glutKeyboardFunc(keyPress); //callback function
    glutSpecialFunc(keyPress); //callback function
    glutMainLoop();
    return 0;
}