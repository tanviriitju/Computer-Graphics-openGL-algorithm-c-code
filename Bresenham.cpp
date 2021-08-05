#include<iostream>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;
float x,y,r;
void Cirpot(int x,int y,float xx,float yx)
{
    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f((x+xx)/1000,(y+yx)/1000);
    glVertex2f((x+yx)/1000,(y+xx)/1000);
    glVertex2f((x+yx)/1000,(y-xx)/1000);
    glVertex2f((x+xx)/1000,(y-yx)/1000);
    glVertex2f((x-xx)/1000,(y-yx)/1000);
    glVertex2f((x-yx)/1000,(y-xx)/1000);
    glVertex2f((x-yx)/1000,(y+xx)/1000);
    glVertex2f((x-xx)/1000,(y+yx)/1000);
    glEnd();
}

void Bresenham()
{
    float d,xx,yx;
    xx=0;
    yx=r;
    d=3-2*r;
    while(xx<=yx)
    {
        Cirpot(x,y,xx,yx);
        if(d<0)
            d+=4*xx+6;
        else
        {
            d+=4*(xx-yx)+10;
            yx--;
        }
        xx++;
    }
}


void myInit()
{
    glEnable(GL_DEPTH_TEST);
    gluOrtho2D(0,1600,0,800);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}
void display(void)
{

    Bresenham();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv); //Initialize glut
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);

    cout<<"Please enter the dot coordinates and radius:"<<endl;
    cin>>x>>y>>r;
    //Set the mode of the window-depth buffer, single buffer, color model
    glutInitWindowPosition(200,200); //Set the position of the window
    glutInitWindowSize(400,400); //Set the size of the window
    glutCreateWindow("Bresenham Circle"); //Create window and assign title

  //  glMatrixMode( GL_PROJECTION );
    glutDisplayFunc(display);//Call display to transfer the drawing to the window. The prototype of this function is glutDisplayFunc(void)
    glutMainLoop(); //Enter the loop and wait
}
