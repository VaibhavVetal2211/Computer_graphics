//STAIRCASE

#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

int flag=0; // Flag to toggle drawing on mouse click
float u,v;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
    glColor3f(0.0, 0.0, 0.0);
}

void displaypoint(float x, float y)
{
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

void breshline(float x1,float y1,float x2,float y2)
{
	float x,y,p,pinc1,pinc2,dx,dy;
	dx=x2-x1;
	dy=y2-y1;
	x=x1;
	y=y1;
	float xinc=1;
	float yinc=1;
	
	if(dx<0)
		dx=-dx;
	if(dy<0)
		dy=-dy;
	if(x2<x1)
		xinc=-1;
	if(y2<y1)
		yinc=-1;
	displaypoint(x,y);
	
	if(dx>dy)
	{
		p=2*dy-dx;
		pinc1=2*(dy-dx);
		pinc2=2*dy;
		
		for(int i=0;i<dx;i++)
		{
			if(p>=0)
			{
				y=y+yinc;
				p=p+pinc1;
			}
			else
			{
				p=p+pinc2;
			}
			
			x=x+xinc;
			displaypoint(x,y);
		}
	}
	else		//dy>dx
	{
		p=2*dx-dy;
		pinc1=2*(dx-dy);
		pinc2=2*dx;
		for(int i=0 ;i<dy;i++)
		{
			if(p>=0)
			{
				x=x+xinc;
				p=p+pinc1;
			}
			else
			{
				p=p+pinc2;
			}
			y=y+yinc;
			displaypoint(x,y);
		}
	}
	glFlush();
}





void dda(float x1, float y1, float x2, float y2)
{
    float dx, dy, x, y, step, xinc, yinc;

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    step = max(abs(dx), abs(dy));

    xinc = dx / step;
    yinc = dy / step;

    for (int i = 0; i <= step; i++)
    {
        displaypoint(x, y);
        x = x + xinc;
        y = y + yinc;
    }
    glFlush();
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (flag)
    {
        // Draw staircase starting from the clicked point
       dda(u,v,u,v+20);
       dda(u,v+20,u+20,v+20);
       dda(u+20,v+20,u+20,v+40);
       dda(u+20,v+40,u+40,v+40);
       dda(u+40,v+40,u+40,v+60);
       dda(u+40,v+60,u+60,v+60);
       dda(u+60,v+60,u+60,v+80);
       dda(u+60,v+80,u+80,v+80);
       dda(u+80,v+80,u+80,v+100);
       dda(u+80,v+100,u+100,v+100);
       dda(u+100,v+100,u+100,v+120);
       dda(u+100,v+120,u+120,v+120);
       dda(u+120,v+120,u+120,v);
       dda(u+120,v,u,v);
     
    }

    glFlush();
}

void mymouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        u=x;
        v=480-y;
        flag=1;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("staircase");
    init();
    glutDisplayFunc(render);

    // Register the mouse click callback function
    glutMouseFunc(mymouse);

    glutMainLoop();
}