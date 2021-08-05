#include <windows.h>
#include<bits/stdc++.h>
#include <gl/Gl.h>
#include <gl/glut.h>
#include<vector>
//#include <stdio.h>
using namespace std;
int screenheight = 900;
int screenwidth = 900;
bool flag = true;
//int X1,Y1,X2,Y2 ;
vector<int>vx;
vector<int>vy;
vector<int>cx;
vector<int>cy;
int nn;
int xmin, ymin, xmax, ymax, sz;

void DrawRect(int x0, int y0, int x1, int y1)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRecti(x0,y0,x1,y1);
    glFlush();
}

void DrawLineSegment(int x0, int y0, int x1, int y1)
{
    glColor3d(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(x0,y0);
    glVertex2i(x1,y1);
    glEnd();
    glFlush();
}
typedef int OutCode;
const int INSIDE = 0; // 0000
const int BOTTOM = 1; // 0001
const int RIGHT = 2; // 0010
const int TOP = 4; // 0100
const int LEFT = 8; // 1000

OutCode ComputeOutCode(int x, int y)
{
    OutCode code;
    code = INSIDE;
    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    else if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;
    return(code);
}
void lineclip(int x0,int y0,int x1,int y1)
{
    OutCode code0,code1;
    int midx,midy;
    if(abs(x0-x1)==1 && abs(y0-y1)==1)
        return;
    code0=ComputeOutCode(x0,y0);
    code1=ComputeOutCode(x1,y1);
//cout<<code0<<"  "<<code1<<endl;
    if( !(code0 | code1) )
    {
        DrawLineSegment(x0,y0,x1,y1);
        return;
    }

    else if(code0 & code1)
        return ;

    midx=(x0+x1)/2;
    midy=(y0+y1)/2;

    lineclip(midx,midy,x1,y1);
    lineclip(x0,y0,midx,midy);
}

void myDisplay()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    DrawRect(xmin,ymin,xmax,ymax);
for (int i=0;i<nn;i++)
    DrawLineSegment(vx[i],vy[i],cx[i],cy[i]);
    glFlush();
}

void myKey(unsigned char key,int x,int y)
{
    glClear(GL_COLOR_BUFFER_BIT);

        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,0,0);
        DrawRect(xmin,ymin,xmax,ymax);
        glColor3f(0.0,0.0,0.0);
        glFlush();
        for(int i=0;i<nn;i++)
        {
            lineclip(vx[i],vy[i],cx[i],cy[i]);
        }


}

int main( int argc, char ** argv )
{
    glutInit( &argc, argv );
    printf("Please enter the lower corner and upper corner of window:\n");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
    int n;
    cout<<"enter number of line"<<endl;
    cin>>nn;
     int k,l,m,e;
    for(int i=0;i<nn;i++)
    {

        cin>>k>>l>>m>>e;
        vx.push_back(k);
        vy.push_back(l);
         cx.push_back(m);
        cy.push_back(e);

    }
   // printf("Please enter the two points of line:\n");
   // scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
    glutInitWindowPosition( 0, 0 );
    glutInitWindowSize( 900, 700 );
    glutCreateWindow( "1997" );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0, 900, 0, 900 );
    glViewport(0, 0, 900, 900);
    glutDisplayFunc( myDisplay );
    glutKeyboardFunc(myKey);
    glutMainLoop();
    return( 0 );
}
