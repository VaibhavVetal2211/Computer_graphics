//KOCH CURVE

#include<GL/glut.h>
#include<bits/stdc++.h>
#define RADIAN 3.14/180
void init(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1400,0,900);
	glColor3f(1.0,1.0,1.0);
	
}

void koch(float xa,float ya,float xb,float yb,int n)
{
	float xc,yc,xd,yd,midx,midy;
	
	xc=(2*xa+xb)/3;
	yc=(2*ya+yb)/3;
	xd=(2*xb+xa)/3;
	yd=(2*yb+ya)/3;
	
	midx= xc+(xd-xc)*cos(RADIAN*60) + (yd-yc)*sin(RADIAN*60);
	midy= yc-(xd-xc)*sin(RADIAN*60) + (yd-yc)*cos(RADIAN*60);
	
	if(n>0)
	{
		koch(xa,ya,xc,yc,n-1);
		koch(xc,yc,midx,midy,n-1);
		koch(midx,midy,xd,yd,n-1);
		koch(xd,yd,xb,yb,n-1);
	}
	else
	{
	
			glVertex2f(xa,ya);
			glVertex2f(xc,yc);
			
			glVertex2f(xc,yc);
			glVertex2f(midx,midy);
			
			glVertex2f(midx,midy);
			glVertex2f(xd,yd);
			
			glVertex2f(xd,yd);	
			glVertex2f(xb,yb);
	}
	glFlush();
}

void draw(int n)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		koch(600,100,800,400,n);
		koch(800,400,400,400,n);
		koch(400,400,600,100,n);
	glEnd();
	glFlush();	
}

void render()
{
	draw(7);
	glFlush();
}

int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1400,900);
	glutInitWindowPosition(0,0);
	glutCreateWindow("KOCH");
	
	init();
	
	glutDisplayFunc(render);
	glutMainLoop();
	return 0;
}