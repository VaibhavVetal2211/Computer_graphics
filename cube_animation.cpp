//ANIMATION CODE 



#include<GL/glut.h>
GLfloat angle = 0.0;
GLfloat translateX = 0.0;
void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,1.0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(translateX, 0.0, -5.0); // Translate along the x-axis
	glRotatef(angle,1.0,1.0,1.0);
	
	glBegin(GL_QUADS);
		glColor3f(1.0,0.0,0.0);
	glVertex3f(1,-1,-1);
		glVertex3f(1,1,-1);
		glVertex3f(1,1,1);
		glVertex3f(1,-1,1);
		
		glColor3f(0.0,1.0,0.0);
		glVertex3f(-1,1,-1);
		glVertex3f(-1,1,1);
		glVertex3f(1,1,1);
		glVertex3f(1,1,-1);
		
		glColor3f(0.0,0.0,1.0);
		glVertex3f(-1,-1,1);
		glVertex3f(1,-1,1);
		glVertex3f(1,1,1);
		glVertex3f(-1,1,1);
		
		glColor3f(1.0,1.0,1.0);
		glVertex3f(-1,-1,-1);
		glVertex3f(-1,-1,1);
		glVertex3f(-1,1,1);
		glVertex3f(-1,1,-1);
		
		glColor3f(1.0,1.0,0.0);
		glVertex3f(-1,-1,-1);
		glVertex3f(1,-1,-1);
		glVertex3f(1,-1,1);
		glVertex3f(-1,-1,1);
		
		glColor3f(1.0,0.0,1.0);
		glVertex3f(-1,-1,-1);
		glVertex3f(-1,1,-1);
		glVertex3f(1,1,-1);
		glVertex3f(1,-1,-1);
		
		glEnd();
		glutSwapBuffers();
		
}

void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei(h)));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(GLfloat)w/(GLfloat)h,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}

void idle()
{
	angle+=0.5;
	
	if(angle>360)
		angle-=360;
	
	 // Update translation along the x-axis
    translateX += 0.001; // Adjust the speed of translation as needed

    // If the cube moves out of the window, reset its position
    if (translateX > 5.0)
        translateX = -5.0;
        
	glutPostRedisplay();	
}
int main(int argc ,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Animation");
	init();
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}