#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

struct pixel{
	float r,g,b;
};

pixel bc,fc;

void init(){ 
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0,500,0,500);
}

void dda(float xa,float ya,float xb,float yb){
	float dx=xb-xa;
	float dy=yb-ya;
	float step=0;
	if(abs(dx)>abs(dy)){
		step=abs(dx);
	}
	else{
		step=abs(dy);
	}
	float xinc=dx/step;
	float yinc=dy/step;
	float x=xa;float y=ya;
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	for(int i=0;i<step;i++){
		x+=xinc;
		y+=yinc;
		glVertex2f(x,y);
	}
	glEnd();
	glFlush();
}

void boundaryFill(float x,float y){
	pixel p;
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,&p);
	if((p.r!=bc.r || p.g!=bc.g || p.b!=bc.b)&& (p.r!=fc.r || p.g!=fc.g || p.b!=fc.b)){
		glBegin(GL_POINTS);
		glColor3f(fc.r,fc.g,fc.b);
		glVertex2f(x,y);
		glEnd();
		glFlush();
		boundaryFill(x+1,y);
		boundaryFill(x-1,y);
		boundaryFill(x,y+1);
		boundaryFill(x,y-1);
	}
	
}
void render(){
	dda(100.0,100.0,200.0,100.0);
	dda(170.0,75.0,200.0,100.0);
	dda(330.0,75.0,170.0,75.0);
	dda(300.0,100.0,400.0,100.0);
	dda(300.0,100.0,330.0,75.0);
	dda(400.0,100.0,400.0,400.0);
	dda(400.0,400.0,100.0,400.0);
	dda(100.0,100.0,100.0,400.0);
	dda(150.0,125.0,150.0,375.0);
	dda(350.0,375.0,350.0,125.0);
	dda(150.0,375.0,350.0,375.0);
	dda(150.0,125.0,350.0,125.0);
	
	//mountains
	
	dda(150.0,125.0,200.0,300.0);
	dda(200.0,300.0,250.0,125.0);
	dda(300.0,300.0,250.0,125.0);
	dda(300.0,300.0,350.0,125.0);
	
	//set boundary color
	bc.r=0.0;bc.g=0.0;bc.b=0.0;
	fc.r=1.0;fc.g=0.0;fc.b=0.0;
	boundaryFill(250.0,100.0);
	
	fc.r=0.0;fc.g=1.0;fc.b=0.0;
	boundaryFill(200.0,250.0);
	boundaryFill(300.0,250.0);
	
	
}


int main(int argc,char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("jay bhai ki filling");
	init();
	glutDisplayFunc(render);
	glutMainLoop();
}
