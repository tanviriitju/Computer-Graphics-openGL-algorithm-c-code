#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
//variable declaration for user’s prompted input
int X1,X2,Y1,Y2;
float u1=0,u2=1;
//variable declaration for window
int xmin,ymin,xmax,ymax;
//datatype changing to double from int
double p[4],q[4];

void init()
{
 glClearColor(1.0,1.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-500,500,-500,500);
}
//clipping the window acc to the point
void clip(int x1,int y1,int x2,int y2)
{
 int dx=x2-x1,dy=y2-y1,i;
 double t;
 p[0]=-dx;q[0]=x1-xmin;
 p[1]=dx;q[1]=xmax-x1;
 p[2]=-dy;q[2]=y1-ymin;
 p[3]=dy;q[3]=ymax-y1;
 //determining where the line is located acc to the window by calculating the p and q value
 for(i=0;i<4;i++)
 {

 if(p[i]==0 && q[i]<0)
 return;
 if(p[i]<0)
 {
 t=(q[i])/(p[i]);
 if(t>u1 && t<u2)
 {u1=t;}
 }
 else if(p[i]>0)
 {
 t=(q[i])/(p[i]);
 if(t>u1 && t<u2)
 {u2=t;}
 }
 }
 if(u1<u2)
 {
 x1=x1+u1*(x2-x1);
 y1=y1+u1*(y2-y1);
 x2=x1+u2*(x2-x1);
 y2=y1+u2*(y2-y1);
 glBegin(GL_LINES);
 glVertex2i(x1,y1);
 glVertex2i(x2,y2);
 glEnd();
 glFlush();
 }
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0,0.0,0.0);

 glBegin(GL_LINES);
 glVertex2i(X1,Y1);
 glVertex2i(X2,Y2);
 glEnd();
 glFlush();
}
//clipping the line acc to window
void myKey(unsigned char key,int x,int y)
{
glClear(GL_COLOR_BUFFER_BIT);
 if(key=='c')
 {
 glClear(GL_COLOR_BUFFER_BIT);
 glFlush();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
 glVertex2i(xmin,ymin);
 glVertex2i(xmin,ymax);
 glVertex2i(xmin,ymax);
 glVertex2i(xmax,ymax);
 glVertex2i(xmax,ymax);
 glVertex2i(xmax,ymin);
 glVertex2i(xmin,ymin);
 glVertex2i(xmax,ymin);
 glEnd();
 glFlush();
 clip(::X1,Y1,X2,Y2);
 }
}
int main(int argc,char ** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 //prompting for user input
 printf("Please enter lower corner of the window:\n");
 scanf("%d %d", &xmin, &ymin);
 printf("Please enter upper corner of the window:\n");
 scanf("%d %d", &xmax, &ymax);
 printf("Please enter first point:\n");
 scanf("%d %d", &X1, &Y1);
 printf("Please enter second point:\n");
 scanf("%d %d", &X2, &Y2);
 glutInitWindowSize(640,600);
 glutInitWindowPosition(0,0);
 glutCreateWindow("Clip");
 glutDisplayFunc(display);
 glutKeyboardFunc(myKey);
 init();
 glutMainLoop();
 return 0;
}
