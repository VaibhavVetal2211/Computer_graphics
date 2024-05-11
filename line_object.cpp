// DOTTED LINE SQUARE OBJECT

#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
struct point
{
	float x,y;	
};

point P,Q,A1,A2,B1,B2,B3,B4,C1,C2,C3,C4;
int flag=0;

void polygon_points()
{
	A1.x=P.x;
	A1.y=Q.y;
	A2.x=Q.x;
	A2.y=P.y;
	
	B1.x=(A1.x+P.x)/2;
	B1.y=(A1.y+P.y)/2;
	B2.x=(A1.x+Q.x)/2;
	B2.y=(A1.y+Q.y)/2;
	B3.x=(Q.x+A2.x)/2;
	B3.y=(Q.y+A2.y)/2;	
	B4.x=(P.x+A2.x)/2;
	B4.y=(P.y+A2.y)/2;
	
	C1.x=(B1.x+B2.x)/2;
	C1.y=(B1.y+B2.y)/2;
	C2.x=(B2.x+B3.x)/2;
	C2.y=(B2.y+B3.y)/2;
	C3.x=(B3.x+B4.x)/2;
	C3.y=(B3.y+B4.y)/2;
	C4.x=(B4.x+B1.x)/2;
	C4.y=(B4.y+B1.y)/2;
	
}
void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
	
}
void displaypoint(float x,float y)
{	
	glPointSize(2);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
	glFlush();	
}
void breshline(float x1,float y1,float x2,float y2)
{
	float x,y,dx,dy,p,pinc1,pinc2,xinc,yinc;
	
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;
	
	if(dx<0)
		dx=-dx;
	if(dy<0)
		dy=-dy;
		
	xinc=yinc=1;
	
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
		
		for(int i=0;i<(int)dx;i++)
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
		if(i%11==3 || i%11==4 || i%11==5||i%11==6||i%11==7||i%11==8||i%11==9||i%11==10)
			displaypoint(x,y);
		}
		
		
				
	}
	else
	{
		p=2*dx-dy;
		pinc1=2*(dx-dy);
		pinc2=2*dx;
		
	for(int i=0;i<(int)dy;i++)
	{
			if(p>=0)
		{
			x=x+xinc;
			p=p+pinc1;
		}
		else
		p=p+pinc2;
		
		y=y+yinc;
		
		if(i%11==3 || i%11==4 || i%11==5||i%11==6||i%11==7||i%11==8||i%11==9||i%11==10)
			displaypoint(x,y);
	}
	}			
		glFlush();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
if(flag==2)
{
	breshline(A1.x, A1.y, Q.x, Q.y);
    breshline(Q.x, Q.y, A2.x, A2.y);
    breshline(A2.x, A2.y, P.x, P.y);
    breshline(P.x, P.y, A1.x, A1.y);

    breshline(B1.x, B1.y, B2.x, B2.y);
    breshline(B2.x, B2.y, B3.x, B3.y);
    breshline(B3.x, B3.y, B4.x, B4.y);
    breshline(B4.x, B4.y, B1.x, B1.y);

    breshline(C1.x, C1.y, C2.x, C2.y);
    breshline(C2.x, C2.y, C3.x, C3.y);
    breshline(C3.x, C3.y, C4.x, C4.y);
    breshline(C4.x, C4.y, C1.x, C1.y);
    flag=0;
}
glFlush();
}

void mymouse(int button,int state,int x,int y)
{
	if(state==GLUT_DOWN && flag==0)
	{
		P.x=x;
		P.y=480-y;
		flag=1;
	}
	else if(state==GLUT_DOWN && flag==1)
	{
		Q.x=x;
		Q.y=480-y;
		flag=2;
		polygon_points();
		glutDisplayFunc(render);
		glFlush();
	}

}
int main(int argc,char**argv)
{
//	cout<<"Enter the coordinates of P"<<endl;
//	cin>>P.x;
//	cin>>P.y;
//	cout<<"Enter the coordinates of Q"<<endl;
//	cin>>Q.x;
//	cin>>Q.y;
	//polygon_points();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Kar Hawa");
	
	init();
	
	glutDisplayFunc(render);
	glutMouseFunc(mymouse);
	
	glutMainLoop();
	return 0;
}