//BRESH CIRCLE FLOWER

#include<GL/glut.h>
#include<bits/stdc++.h>

using namespace std;
float flag;
float u,v,rad;
void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
}
void displaypoint(float x ,float y)
{
	glColor3f(0.0,0.0,0.0);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

void octant(int xc,int yc,int x,int y)
{
	displaypoint(xc+x,yc+y);
	displaypoint(xc+x,yc-y);
	displaypoint(xc-x,yc+y);
	displaypoint(xc-x,yc-y);
	
	displaypoint(xc+y,yc+x);
	displaypoint(xc+y,yc-x);
	displaypoint(xc-y,yc+x);
	displaypoint(xc-y,yc-x);
	
}

void circle(float xc,float yc,int r)
{
	int x=0;
	int y=r;
	
	float d=3-2*r;
	
	while(x<y)
	{	octant(xc,yc,x,y);
		if(d>=0)
		{
			d=d+4*(x-y)+10;
			y--;
		}
		else
		{
			d=d+4*x+6;
		}
		
		x++;
	}
	glFlush();
}

void pattern(int x,int y,int r)
{
	circle(x+r,y,r);
	circle(x+r*cos(90),y+r*sin(90),r);
	circle(x+r*cos(90),y-r*sin(90),r);
	circle(x-r*cos(90),y+r*sin(90),r);
	circle(x-r*cos(90),y-r*sin(90),r);
	circle(x-r,y,r);
	circle(x,y,r);
	circle(x,y,2*r);
	
	glFlush();
}
void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
		if(flag)
		{
			pattern(u,v,rad);
			glFlush();
		}
		flag=0;
	
}
void mymouse(int button,int state ,int x,int y)
{
	if(state==GLUT_DOWN && flag==0)
	{
		u=x;
		v=480-y;
		flag=1;
	}
}
int main(int argc,char**argv)
{
	cout<<"Enter the radius of smallest circle"<<endl;
	cin>>rad;
	cout<<"Click on window to set center of pattern"<<endl;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Pattern");
	init();
	
	glutDisplayFunc(render);
	glutMouseFunc(mymouse);
	
	glutMainLoop();
	return 0;
}