#include "GL/glut.h"
#include "iostream"
#include "math.h"

using namespace std;

//defining a matrix for the operations to be performed
float TransM[4][4];

//coordinates of the original cube
float original[8][3] =
{
    {10, 10, -40}, {50, 10, -40}, {50, 50, -40}, {10, 50, -40},
    {0, 0, 0}, {40, 0, 0}, {40, 40, 0}, {0, 40, 0}
};


float output[8][3];

float tx, ty, tz, sx, sy, sz, angle; //transforming factors

int ch, rc;

void makeIdentity(float m[4][4]) //setting the transformation matrix to identity matrix
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m[i][j] = (i == j);
        }
    }
}

void translate(float tx, float ty, float tz)
{
    for (int i = 0; i < 8; i++)
    {
        output[i][0] = original[i][0] + tx; //adding tx to x coordinate of the vertex
        output[i][1] = original[i][1] + ty; //adding ty to y coordinate of the vertex
        output[i][2] = original[i][2] + tz; //adding tx to z coordinate of the vertex
    }
}

void scale(float sx, float sy, float sz)
{
    TransM[0][0] = sx;
    TransM[1][1] = sy;
    TransM[2][2] = sz;
}

void rotateX(float a)
{
    a = a * 3.142 / 180;
    TransM[1][1] = cos(a);
    TransM[1][2] = -sin(a);
    TransM[2][1] = sin(a);
    TransM[2][2] = cos(a);
}

void rotateY(float a)
{
    a = a * 3.142 / 180;
    TransM[0][0] = cos(a);
    TransM[0][2] = -sin(a);
    TransM[2][0] = sin(a);
    TransM[2][2] = cos(a);
}

void rotateZ(float a)
{
    a = a * 3.142 / 180;
    TransM[0][0] = cos(a);
    TransM[0][1] = -sin(a);
    TransM[1][0] = sin(a);
    TransM[1][1] = cos(a);
}

void Multiplication()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            output[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                output[i][j] = output[i][j] + original[i][k] * TransM[k][j];
            }
        }
    }
}

void displayCube(float a[8][3])
{
    glBegin(GL_QUADS);
    glColor3f(255, 255, 0); //behind
    glVertex3fv(a[0]);
    glVertex3fv(a[1]);
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);

    glColor3f(0, 255, 255);  //bottom
    glVertex3fv(a[0]);
    glVertex3fv(a[1]);
    glVertex3fv(a[5]);
    glVertex3fv(a[4]);

    glColor3f(255, 0, 255); //left
    glVertex3fv(a[0]);
    glVertex3fv(a[4]);
    glVertex3fv(a[7]);
    glVertex3fv(a[3]);

    glColor3f(0, 0, 255); //right
    glVertex3fv(a[1]);
    glVertex3fv(a[2]);
    glVertex3fv(a[6]);
    glVertex3fv(a[5]);

    glColor3f(255, 0, 0); //up
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);
    glVertex3fv(a[7]);
    glVertex3fv(a[6]);

    glColor3f(0, 255, 0);
    glVertex3fv(a[4]);
    glVertex3fv(a[5]);
    glVertex3fv(a[6]);
    glVertex3fv(a[7]);
    glEnd();
}

void initGL() //constructor to set the camera perspective
{
    glClearColor(0, 0, 0, 0); //set background color to white
    glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex2s(-1000, 0);
    glVertex2s(1000, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2s(0, -1000);
    glVertex2s(0, 1000);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    displayCube(original);
    makeIdentity(TransM);
    switch (ch)
    {
    case 1:
        translate(tx, ty, tz);
        break;
    case 2:
        scale(sx, sy, sz);
        Multiplication();
        break;
    case 3:
        switch (rc)
        {
        case 1:
            rotateX(angle);
            break;
        case 2:
            rotateY(angle);
            break;
        case 3:
            rotateZ(angle);
            break;
        default:
            break;
        }
        Multiplication();
        break;
    }
    displayCube(output);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    cout << "Choose Transformation to be performed: \n\t 1. Translation \n\t 2. Scaling \n\t 3. Rotation \n\t 4. Exit \n: ";
    cin >> ch;
    if (ch == 1)
    {
        cout << "Enter tx  ty  tz =  ";
        cin >> tx >> ty >> tz;
    }

    else if (ch == 2)
    {
        cout << "Enter Sx  Sy  Sz =  ";
        cin >> sx >> sy >> sz;
    }

    else if (ch == 3)
    {
        cout << endl;
        cout << "Choose Axis For Rotation: \n\t 1. Parallel to X-axis."
             << "(y& z) \n\t 2. Parallel to Y-axis.(x& z) \n\t 3. Parallel to Z-axis."
             << "(x& y) \n: ";
        cin >> rc;

        if (rc == 1)
        {
            cout << "Enter Rotation angle =  ";
            cin >> angle;
        }

        else if (rc == 2)
        {
            cout << "Enter Rotation angle =  ";
            cin >> angle;
        }

        else if (rc == 3)
        {
            cout << "Enter Rotation angle =  ";
            cin >> angle;
        }

        else
        {
            cout << "Wrong Choice...!!!" << endl;
        }
    }
    else if (ch == 4)
    {
        return 0;
    }
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1300, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("3D Transformations on Cube");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}