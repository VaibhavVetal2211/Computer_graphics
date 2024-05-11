//LINE CLIPPING
#include<GL/glut.h>
#include<bits/stdc++.h>

int xmin=50;
int xmax=200;
int ymin=50;
int ymax=200;

float u1,v1,u2,v2;
float flag=0;
struct code
{
	int t,b,r,l;
};

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glPointSize(2);
}

void draw_window()
{
	glColor3f(1.0,0.5,0.0);
		glBegin(GL_LINE_LOOP);
			glVertex2f(xmin,ymin);
			glVertex2f(xmax,ymin);
			glVertex2f(xmax,ymax);
			glVertex2f(xmin,ymax);
		glEnd();
		glFlush();	
}
code get_code(float x,float y)
{
	code c={0,0,0,0};
				//intersecting points
	if(x<xmin)
		c.l=1;
	
	if(x>xmax)
		c.r=1;
	
	if(y<ymin)
		c.b=1;
		
	if(y>ymax)
		c.t=1;
		
	return c;					

}

void cohen()
{
	code c ,c1,c2;
	float x,y;
	int flag;
	
	float m = (v2-v1)/(u2-u1);
	
	c1=get_code(u1,v1);
	c2=get_code(u2,v2);
	
	while(1)
	{
		//line completely inside
		
		if(c1.l==0 && c2.l ==0 && c1.r==0 && c2.r==0 && c1.t==0 && c2.t==0 && c1.b==0 && c2.b==0)
		{
				
				break;
		}
		
		else if( (c1.l && c2.l) || (c1.r&&c2.r) || (c1.t&&c2.t) || (c1.b && c2.b) !=0 )
		{	
			u1=v1=u2=v2=0;
			break;
		}
		
		else
		{
			if(c1.l==1 || c2.l==1)
			{
				if(c1.l==1)
					flag=0;
					
				if(c2.l==1)
					flag=1;
				
				x=xmin;
				y=m*(xmin-u1)+v1;
						
			}
			
			else if(c1.r==1 || c2.r==1)
			{
				if(c1.r==1)
					flag=0;
				if(c2.r==1)
					flag=1;
					
				x=xmax;
				y=m*(xmax-u1)+v1;		
			}
			
			else if(c1.t==1 || c2.t==1)
			{
				if(c1.t==1)
					flag=0;
				if(c2.t==1)
					flag=1;
				y=ymax;
				x=(ymax-v1)/m +u1 ;	
			}
			else if(c1.b==1 || c2.b==1)
			{
				if(c1.b==1)
					flag=0;
				if(c2.b==1)
					flag=1;
				
				y=ymin;
				x=(ymin-v1)/m + u1 ;		
					
			}
			
			c = get_code(x,y);
			if(flag==0)
			{
				u1=x;
				v1=y;
				c1=c;
			}
			else if(flag==1)
			{
				u2=x;
				v2=y;
				c2=c;
			}
		}
	}
	// draw window
		draw_window();
		
	// draw cohen line again
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(u1,v1);
		glVertex2f(u2,v2);
	glEnd();
	glFlush();	
	
}
void mymouse(int button,int state,int x,int y)
{
	glColor3f(0.0,0.0,0.0);
	if(state==GLUT_DOWN && flag==0)
	{
		u1=x;
		v1=480-y;
		flag=1;
	}
	else if(state==GLUT_DOWN && flag==1)
	{
		u2=x;
		v2=480-y;
		flag=2;
		glBegin(GL_LINES);
		glVertex2f(u1,v1);
		glVertex2f(u2,v2);
		glEnd();
		glFlush();
	}
	
	
}

void mykeyboard(char unsigned key , int x,int y)
{
	if(key=='c')
	{
		init();
		cohen();
	}
	if(key=='r')
	{
		init();
		draw_window();
		flag=0;
	}
}
int main(int argc , char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("just looking like wow");
	
	gluOrtho2D(0,640,0,480);
	init();
	glFlush();
	glutDisplayFunc(draw_window);
	glutMouseFunc(mymouse);
	glutKeyboardFunc(mykeyboard);
	glutMainLoop();
	
}