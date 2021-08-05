#include<bits/stdc++.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;
int pntX1, pntY1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
vector<int> mntX;
vector<int> mntY;
int transX, transY;
double scaleX, scaleY;
double angle, angleRad;
char reflectionAxis, shearingAxis;
int shearingX, shearingY;

double round(double d)
{
    return floor(d + 0.5);
}

void ddrawPolygon()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(pntX[i], pntY[i]);
        //  cout<<mntX[i]<<" "<<mntY[i]<<endl;
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(mntX[i], mntY[i]);
    }
    glEnd();
}


void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);


    // drawPolygon();
    ddrawPolygon();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    cout << "\n\nFor Polygon:\n" << endl;

    cout << "Enter no of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter co-ordinates for vertex  " << i + 1 << " : ";
        cin >> pntX1 >> pntY1;
        pntX.push_back(pntX1);
        pntY.push_back(pntY1);
        mntX.push_back(pntX1);
        mntY.push_back(pntY1);
    }
    while(1)
    {
        cout << "Enter your choice:\n\n" << endl;

        cout << "1. Translation" << endl;
        cout << "2. Scaling" << endl;
        cout << "3. Rotation" << endl;
        cout << "4. Mirror Reflection" << endl;
        cout << "5. Shearing" << endl;
        cout << "6. Exit" << endl;

        cin >> choice;



        if (choice == 1)
        {
            cout << "Enter the translation factor for X and Y: ";
            cin >> transX >> transY;
            for (int i = 0; i < edges; i++)
            {
                //glVertex2i(pntX[i] + x, pntY[i] + y);
                mntX[i]=mntX[i]+transX;
                mntY[i]=mntY[i]+transY;
            }


        }
        else if (choice == 2)
        {
            cout << "Enter the scaling factor for X and Y: ";
            cin >> scaleX >> scaleY;
            for (int i = 0; i < edges; i++)
            {
                //glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
                mntX[i]=round(mntX[i] * scaleX);
                mntY[i]=round(mntY[i] * scaleY);
            }

        }
        else if (choice == 3)
        {
            cout << "Enter the angle for rotation: ";
            cin >> angle;
            angleRad = angle * 3.1416 / 180;
            for (int i = 0; i < edges; i++)
            {
    //glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
                mntX[i]=round((mntX[i] * cos(angleRad)) - (mntY[i] * sin(angleRad)));
                mntY[i]=round((mntX[i] * sin(angleRad)) + (mntY[i] * cos(angleRad)));
            }
        }
        else if (choice == 4)
        {
            cout << "Enter reflection axis ( x or y ): ";
            cin >> reflectionAxis;
            if (reflectionAxis == 'x' || reflectionAxis == 'X')
            {
                for (int i = 0; i < edges; i++)
                {
                    //glVertex2i(round(pntX[i]), round(pntY[i] * -1));
                    mntX[i]=round(mntX[i]);
                    mntY[i]=round(mntY[i] * -1);
                }
            }
            else if (reflectionAxis == 'y' || reflectionAxis == 'Y')
            {
                for (int i = 0; i < edges; i++)
                {
                    //glVertex2i(round(pntX[i] * -1), round(pntY[i]));
                    mntX[i]=round(mntX[i] * -1);
                    mntY[i]=round(mntY[i]);
                }
            }

        }
        else if (choice == 5)
        {
            cout << "Enter shearing axis ( x or y ): ";
            cin >> shearingAxis;
            if (shearingAxis == 'x' || shearingAxis == 'X')
            {
                cout << "Enter the shearing factor for X: ";
                cin >> shearingX;
            }
            else
            {
                cout << "Enter the shearing factor for Y: ";
                cin >> shearingY;
            }
            if (shearingAxis == 'x' || shearingAxis == 'X')
            {
                //glVertex2i(pntX[0], pntY[0]);
                mntX[0]=mntX[0];
                mntY[0]=mntY[0];

                //glVertex2i(pntX[1] + shearingX, pntY[1]);
                //glVertex2i(pntX[2] + shearingX, pntY[2]);
                mntX[1]=mntX[1] + shearingX;
                mntY[1]=mntY[1];
                mntX[2]=mntX[2] + shearingX;
                mntY[2]=mntY[2];
                //glVertex2i(pntX[3], pntY[3]);
                mntX[3]=mntX[3];
                mntY[3]=mntY[3];
            }
            else if (shearingAxis == 'y' || shearingAxis == 'Y')
            {
                //glVertex2i(pntX[0], pntY[0]);
                //glVertex2i(pntX[1], pntY[1]);
                mntX[0]=mntX[0];
                mntY[0]=mntY[0];
                mntX[1]=mntX[1];
                mntY[1]=mntY[1];

                //glVertex2i(pntX[2], pntY[2] + shearingY);
                mntX[2]=mntX[2];
                mntY[2]=mntY[2] + shearingY;
                glVertex2i(pntX[3], pntY[3] + shearingY);
                mntX[3]=mntX[3];
                mntY[3]=mntY[3] + shearingY;
            }
        }
        else if(choice==6)
        {
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutInitWindowSize(640, 480);
            glutInitWindowPosition(0, 0);
            glutCreateWindow("Extended Basic Transformations");

            glutDisplayFunc(myDisplay);
            myInit();
            glutMainLoop();



           
        }
       
    }

}
