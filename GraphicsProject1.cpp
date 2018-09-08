#include <iostream>
#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
int CNG=0;
int a=0,r=1,c=0,c1=0,c2=0,k=0,l=95,m=78,n=103,l1=95,m1=78,n1=103,l2=95,m2=78,n2=103,bfr=141,bfg=165,bfb=186,l3=39,m3=48,n3=150,l4=197,m4=16,n4=26;
int t=20;
float _move = 0.0f,_mover = 0.0f,_move1 = 0.0f,_move2 = 0.0f,_movep=0.0f,_moveCNG=0.0f;
float x4=-0.9f,y4=-0.35f,x5=-0.6f,y5=0.1,x7=-1.5f,y7=0.1,x=-0.9f,x2=-0.9;
float _angle1 = 30.0f;

void myDisplay(void);
void myInit (void);

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void sky(){
//water

//sky
glBegin(GL_QUADS);
glColor3f(0.000, 0.749, 1.000);
glVertex2f(-2.0,1.0);
glVertex2f(1.0,1.0);

glColor3f(0.8, 1.000, 1.000);
glVertex2f(1.0, -0.2);
glVertex2f(-2.0, -0.2);

glEnd();
}


void afternoon(){
 static GLfloat  ambient[] = { 0.0f,  0.0f,  0.0f, 1.0f };
 static GLfloat  diffuse[] = { 0.3f,  0.3f,  0.3f, 1.0f };
 static GLfloat specular[] = { 1.0f,  1.0f,  1.0f, 1.0f };
 static GLfloat  specref[] = { 1.0f,  1.0f,  1.0f, 1.0f };
 static GLfloat position[] = {10.0f, 10.0f, 10.0f, 1.0f };
 short shininess = 128;

 GLfloat density = 0.005; //set the density to 0.3 which is acctually quite thick

 GLfloat fogColor[4] = {0.7, 0.7, 0.8, 1.0}; //set the for color to grey

 glDisable(GL_LIGHTING);
 glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
 glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
 glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
 glLightfv(GL_LIGHT0, GL_POSITION, position);
 glEnable(GL_LIGHT0);

 //light1

 GLfloat light1_dir[] = {0.7f, 0.7f, 0.0f, 0.0f};
 GLfloat light1_ambient_col[] = {0.1f, 0.0f, 0.0f, 1.0f};
 GLfloat light1_diffuse_col[] = {0.8f, 0.3f, 0.5f, 1.0f};
 GLfloat light1_specular_col[] = {0.8f, 0.8f, 0.8f, 1.0f};


 glLightfv(GL_LIGHT1, GL_POSITION, light1_dir);
 glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient_col);
 glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse_col);
 glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular_col);
 glEnable(GL_LIGHT1);


 //light2
 GLfloat light2_pos[] = {0.0f, 5.0f, 0.0f, 1.0f};
 GLfloat light2_ambient_col[] = {0.1f, 0.0f, 0.0f, 1.0f};
 GLfloat light2_diffuse_col[] = {1.0f, 1.0f, 1.0f, 1.0f};
 GLfloat light2_specular_col[] = {0.8f, 0.8f, 0.8f, 1.0f};

 glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient_col);
 glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse_col);
 glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular_col);

 glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
 //glLightModelf(GL_LIGHT_MODEL_TWO_SIDE,1);
 glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);

 glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION,  1.0f);		// Default is 1.0f
 glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION,    0.0f);		// Default is 0.0f
 glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0f);		// Default is 0.0f

 GLfloat light2_spotlight_dir[] = { 0.0f, 0.0f, -1.0f, 0.0f };
 glLightfv( GL_LIGHT2, GL_SPOT_DIRECTION, light2_spotlight_dir );

 glLightf( GL_LIGHT2, GL_SPOT_EXPONENT, 0.0f );
 glLightf( GL_LIGHT2, GL_SPOT_CUTOFF, 40.0f );
 //glEnable(GL_LIGHT2);

 //light3

 GLfloat light3_dir[] = {0.0f, 0.7f, 0.7f, 0.0f};
 GLfloat light3_ambient_col[] = {0.1f, 0.0f, 0.0f, 1.0f};
 GLfloat light3_diffuse_col[] = {0.2f, 0.3f, 0.7f, 1.0f};
 GLfloat light3_specular_col[] = {0.8f, 0.8f, 0.8f, 1.0f};

 glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
 glLightfv(GL_LIGHT3, GL_POSITION, light3_dir);
 glLightfv(GL_LIGHT3, GL_AMBIENT, light3_ambient_col);
 glLightfv(GL_LIGHT3, GL_DIFFUSE, light3_diffuse_col);
 glLightfv(GL_LIGHT3, GL_SPECULAR, light3_specular_col);
 glEnable(GL_LIGHT3);
 //fog
 glEnable (GL_FOG); //enable the fog

 glFogi (GL_FOG_MODE, GL_LINEAR); //set the fog mode to GL_EXP2

 //glFogi (GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2

 glFogfv (GL_FOG_COLOR, fogColor);

 glFogf (GL_FOG_DENSITY, density);

 glHint (GL_FOG_HINT, GL_NICEST);

 glFogf(GL_FOG_START, 100.0f);             // Fog Start Depth
 glFogf(GL_FOG_END, 160.0f);               // Fog End Depth

 glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
 glEnable(GL_COLOR_MATERIAL);

 glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
 glMateriali(GL_FRONT, GL_SHININESS, shininess);

 glEnable(GL_NORMALIZE);
}


void baseman(){
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.45,0.14,0);
    //body
	glPushMatrix();
	glColor3ub(255,255,255);
	//glColor3f(0.686, 0.933, 0.933);
	glScalef(0.6, 0.7, 0);
	glTranslatef(-0.05,-0.35,0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.05,0.0f);
	glVertex3f(0.0,0.3,0.0f);
	glVertex3f(0.1,0.3,0.0f);
	glVertex3f(0.1,0.05,0.0f);
	glEnd();
	glPopMatrix();

	//left hand
	glPushMatrix();
	glColor3f(0.118, 0.565, 1.000);
	glScalef(0.6, 0.7, 0);
	glTranslatef(-0.07,-0.27,0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0f);
	glVertex3f(0.0,0.2,0.0f);
	glVertex3f(0.02,0.2,0.0f);
	glVertex3f(0.02,0.0,0.0f);
	glEnd();
	glPopMatrix();

	//right hand
	glPushMatrix();
	glColor3f(0.118, 0.565, 1.000);
	glScalef(0.6, 0.7, 0);
	glTranslatef(0.05,-0.27,0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0f);
	glVertex3f(0.0,0.2,0.0f);
	glVertex3f(0.02,0.2,0.0f);
	glVertex3f(0.02,0.0,0.0f);
	glEnd();
	glPopMatrix();

	//left leg
	glPushMatrix();
	glColor3ub(0,0,0);
	//glColor3f(0.412, 0.412, 0.412);
	glScalef(0.6, 0.7, 0);
	glTranslatef(-0.05,-0.55,0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0f);
	glVertex3f(0.0,0.25,0.0f);
	glVertex3f(0.035,0.25,0.0f);
	glVertex3f(0.035,0.0,0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0,0,0);
	glScalef(0.6, 0.7, 0);
	glTranslatef(-0.04,-0.55,0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0f);
	glVertex3f(0.0,0.05,0.0f);
	glVertex3f(-0.05,0.0,0.0f);
	glEnd();
	glPopMatrix();

	//right leg
	glPushMatrix();
	glColor3ub(0,0,0);
	glScalef(0.6, 0.7, 0);
	glTranslatef(0.015,-0.55,0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.25,0.0f);
	glVertex3f(0.0,0.0,0.0f);
	glVertex3f(0.035,0.0,0.0f);
	glVertex3f(0.035,0.25,0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0,0,0);
	glScalef(0.6, 0.7, 0);
	glTranslatef(0.04,-0.55,0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.05,0.0f);
	glVertex3f(0.0,0.0,0.0f);
	glVertex3f(0.05,0.0,0.0f);
	glEnd();
	glPopMatrix();


    //head
    glPushMatrix(); //Save the current state of transformations
    glScalef(0.7,1,1);
    glColor3f(1.000, 0.871, 0.678);
    glScalef(0.6, 0.7, 0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
	glPopMatrix();

	//hair
	glPushMatrix(); //Save the current state of transformations
    glScalef(0.7,1,1);
    glColor3f(0.0, 0.0, 0.0);
    glScalef(0.6, 0.7, 0);
	glBegin(GL_POLYGON);
	for(int i=0;i<45;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/90;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
	glPopMatrix();

    //left eye

    for(float i=0.05f;i>-0.06f;i-=0.1f){
    glPushMatrix(); //Save the current state of transformations
    glScalef(0.6,1,1);
    glColor3f(0,0,0);
    glScalef(0.6, 0.7, 0);
    glTranslatef(i,-0.02,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.015;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
	glPopMatrix();
    }


    glPushMatrix(); //Save the current state of transformations
    glScalef(0.6,1,1);
    glColor3f(0,0,0);
    glScalef(0.6, 0.7, 0);
    glTranslatef(0.0,-0.055,0);
	glBegin(GL_LINES);
	for(int i=0;i<60;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/25;
		float r=0.025;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
	glPopMatrix();

     glPushMatrix(); //Save the current state of transformations
    glScalef(0.6,1,1);
    glColor3f(1.000, 0.871, 0.678);
    glScalef(0.6, 0.7, 0);
    glTranslatef(0.0,-0.055,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<60;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/120;
		float r=0.027;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
	glPopMatrix();
}


void Sun(void){

    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.6,0.86,0);
    glScalef(0.8,1.6,1);
    glBegin(GL_POLYGON);
    glColor3ub(255, 190, 94);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.08;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
	glPopMatrix();
}

void DrawCNG(void){
    //Drawing CarBody
    float x0=-0.6f,y0=0.1f,x11=-0.6f,xcng=1.0f;
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
//x5=-0.6f,y5=0.1,x7=-0.6f,y7=0.1,
    //horn
    glPushMatrix();
    glTranslatef(_moveCNG, 0.0f, 0.0f);
    glColor3ub(228, 239, 23);
	glBegin(GL_POLYGON);
        glVertex3f(x0+0.23-xcng, -y0+0.08-0.18, 0.0f );
        glVertex3f(x0+0.23-xcng, -y0+0.06-0.18, 0.0f );
        glVertex3f(x0+0.26-xcng, -y0+0.04-0.18, 0.0f );
        glVertex3f(x0+0.26-xcng, -y0+0.10-0.18, 0.0f );
    glEnd();
    glPushMatrix();
    //CNG ceiling
    glPushMatrix();
    //glTranslatef(_moveCNG, 0.0f, 0.0f);
    glColor3ub(228, 239, 23);
	glBegin(GL_POLYGON);
        glVertex3f(x0+0.18-xcng, -y0+0.2, 0.0f);
        glVertex3f(x0-0.03-xcng, -y0+0.2, 0.0f);
        glVertex3f(x0-0.03-xcng, -y0+0.1, 0.0f );
        glVertex3f(x0+0.22-xcng, -y0+0.1, 0.0f );
    glEnd();
    glPushMatrix();
    //glTranslatef(_moveCNG, 0.0f, 0.0f);
    glColor3ub(228, 239, 23);
    glBegin(GL_POLYGON);

        glVertex3f(x0+0.22-xcng, -y0+0.1, 0.0f );
        glVertex3f(x0-0.03-xcng, -y0+0.1, 0.0f );
        glVertex3f(x0-0.03-xcng, -y0, 0.0f );
        glVertex3f(x0+0.24-xcng, -y0, 0.0f );

    glEnd();
    //body of the CNG
    glPushMatrix();
    //glTranslatef(_moveCNG, 0.0f, 0.0f);
    glColor3ub(92, 224, 35);
    glBegin(GL_POLYGON);
        glVertex3f(x0+0.24-xcng, -y0, 0.0f );
        glVertex3f(x0-0.03-xcng, -y0, 0.0f );
        glVertex3f(x0-0.03-xcng, -y0-0.2, 0.0f );
        glVertex3f(x0+0.24-xcng, -y0-0.2, 0.0f );

    glEnd();
    //divider
    glPushMatrix();
    //glTranslatef(_moveCNG, 0.0f, 0.0f);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(x0+0.24-xcng, -y0, 0.0f );
        glVertex3f(x0-0.03-xcng, -y0, 0.0f );
        glVertex3f(x0-0.03-xcng, -y0-0.02, 0.0f );
        glVertex3f(x0+0.24-xcng, -y0-0.02, 0.0f );

    glEnd();
	glPopMatrix();

    //Drawing CNG Windows

    glColor3ub(255,255,255);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
	glTranslatef(_moveCNG, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x11-0.015-xcng, -y0+0.18, 0.0f);
        glVertex3f(x11-0.015-xcng, -y0+0.01, 0.0f);
        glVertex3f(x11+0.08+0.01-xcng, -y0+0.01, 0.0f);
        glVertex3f(x11+0.08+0.01-xcng, -y0+0.18, 0.0f);
    glEnd();
    glPopMatrix();
     glColor3ub(255,255,255);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
//x5=-0.6f,y5=0.1,
    glPushMatrix();
	glTranslatef(_moveCNG, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x11+0.12f-xcng, -y7+0.18, 0.0f);
        glVertex3f(x11+0.12f-xcng, -y7+0.01, 0.0f);
        glVertex3f(x11+0.24-0.020f-xcng, -y7+0.01, 0.0f);
        glVertex3f(x11+0.18f-xcng, -y7+0.18, 0.0f);

    glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.55-0.05+0.01-xcng, -0.29, 0.0);
	glTranslatef(_moveCNG, 0.0f, 0.0f);
     glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();

    glTranslatef(-0.55+0.15-0.05+0.04-xcng, -0.29, 0.0);
	glTranslatef(_moveCNG, 0.0f, 0.0f);
     glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();


}

void plane(void){
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    //pakha up
    glPushMatrix();
    glTranslatef(_movep,0.30,0);
    glColor3f(1,0,0);
    glScalef(0.05,0.2,1);
    glTranslatef(14.2,3.0,0);
    glBegin(GL_POLYGON);
    glVertex3f(1,0,0.0f);
    glVertex3f(1.6,0.5,0.0f);
    glVertex3f(1.3,0.5,0.0f);
    glVertex3f(0.3,0,0.0f);
    glEnd();
    glPopMatrix();


    //blue
    glPushMatrix();
    glTranslatef(_movep,0.30,0);
    glColor3f(0,0,1);
    glScalef(0.05,0.15,1);
    glTranslatef(16.2,4.2,0);
    glBegin(GL_POLYGON);
    glVertex3f(1,0,0.0f);
    glVertex3f(1,0.5,0.0f);
    glVertex3f(0.7,0.5,0.0f);
    glVertex3f(0.4,0,0.0f);
    glEnd();
    glPopMatrix();
    //red
    glPushMatrix();
    glTranslatef(_movep,0.30,0);
    glColor3f(1,0,0);
    glScalef(0.05,0.15,1);
    glTranslatef(16.3,4.2,0);
    glBegin(GL_POLYGON);
    glVertex3f(1,0,0.0f);
    glVertex3f(1,0.5,0.0f);
    glVertex3f(0.7,0.5,0.0f);
    glVertex3f(0.5,0,0.0f);
    glEnd();
    glPopMatrix();
    //square base
	glPushMatrix();
	glTranslatef(_movep,0.30,0);
	glTranslatef(-0.13,0.6,0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.98,0.05,0.0f);
    glVertex3f(0.83,0.05,0.0f);
    glVertex3f(0.83,0.0,0.0f);
    glVertex3f(0.99,0.0,0.0f);
    glVertex3f(1,0.1,0.0f);
    glVertex3f(0.99,0.1,0.0f);

    glEnd();
	glPopMatrix();

	//window
	float h=0.72;
	float g=0.6;
    for(int j=0;j<6;j++){
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(_movep,0.30,0);
	glTranslatef(h,0.63,0);
    glScalef(g,1,1);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.01;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y ,0.0f);
	}
	glEnd();
	glPopMatrix();
	h+=0.02;
	}
    //front window
    glPushMatrix();
    glTranslatef(_movep,0.30,0);
    glScalef(0.1,0.5,1);
    glTranslatef(8,0.02,0);
    glScalef(0.6,0.7,1);
    glTranslatef(-2.73,1.75,0);

    glBegin(GL_POLYGON);
    glVertex3f(1,0,0.0f);
    glVertex3f(1,0.05,0.0f);
    glVertex3f(0.6,0.0,0.0f);
    glEnd();
    glPopMatrix();

    //pakha down
    glPushMatrix();
    glTranslatef(_movep,0.31,0);
    glColor3f(0,0,1);
    glScalef(0.05,0.2,1);
    glTranslatef(14.5,3.03,0);
    glBegin(GL_POLYGON);
    glVertex3f(1,0,0.0f);
    glVertex3f(1.6,-0.3,0.0f);
    glVertex3f(1.3,-0.3,0.0f);
    glVertex3f(0.3,0,0.0f);
    glEnd();
    glPopMatrix();
    glPopMatrix();

}

void DrawBackground(void){
    //glColor3ub(57,132,57
    glColor3ub(0,206,0);

	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-1.0f, -0.2-0.08f, 0.0f);
        glVertex3f(1.0f, -0.2-0.08f, 0.0f);
        glVertex3f(1.0f, 0.0f, 0.0f);


    glEnd();
    glPopMatrix();
     glPushMatrix();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0f, 0.0-0.6f, 0.0f);
        glVertex3f(-1.0f, -0.2-0.08-0.8f, 0.0f);
        glVertex3f(1.0f, -0.2-0.08-0.8f, 0.0f);
        glVertex3f(1.0f, 0.0-0.6f, 0.0f);


    glEnd();
    glPopMatrix();
}
void DrawBuilding(void){
        //draw building
        //glColor3d(1,0,0);
        //float x4=-0.9,y4=-0.2
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        float b=0.0f;
        for(int i=0;i<2;i++){
        glPushMatrix();
        glColor3ub(bfr,bfg,bfb);
        glTranslatef(b, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex3f((x4), -y4+0.4, 0.0f);
            glVertex3f((x4), y4+0.2, 0.0f);
            glVertex3f(x4+0.25, y4+0.2, 0.0f);
            glVertex3f((x4+0.25), -y4+0.4, 0.0f);
        glEnd();
        glPopMatrix();
        b+=0.3;

        }
        for(float i=0.0f;i<1.0;i+=0.9){
        glPushMatrix();
        glTranslatef(i, 0.0f, 0.0f);
        glColor3ub(155,0,0);
        glBegin(GL_POLYGON);
            glVertex3f((x4+0.6), -y4+0.4-0.2, 0.0f);
            glVertex3f((x4+0.6), y4+0.2, 0.0f);
            glVertex3f(x4+0.25+0.6, y4+0.2, 0.0f);
            glVertex3f((x4+0.25+0.6), -y4+0.4-0.2, 0.0f);
        glEnd();
        glPopMatrix();
        }

        //Side of the building
        for(float i=0;i<0.40;i+=0.3){
        glColor3ub(bfr-30,bfg-50,bfb-70);
        glLoadIdentity(); //Reset the drawing perspective
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(i, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex3f((x4+0.25), -y4+0.4, 0.0f);
            glVertex3f(x4+0.25, y4+0.2, 0.0f);
            glVertex3f(x4+0.28, y4+0.28, 0.0f);
            glVertex3f((x4+0.28), -y4+0.48, 0.0f);

        glEnd();
        glPopMatrix();
        }
        for(float i=0.0f;i<1.0;i+=0.9){
        glPushMatrix();
        glTranslated(i,0.0f,0.0f);
        glColor3ub(155-34,0,0);
        glBegin(GL_POLYGON);
            glVertex3f((x4+0.25+0.6), -y4+0.4-0.2, 0.0f);
            glVertex3f(x4+0.25+0.6, y4+0.2, 0.0f);
            glVertex3f(x4+0.28+0.6, y4+0.28, 0.0f);
            glVertex3f((x4+0.28+0.6), -y4+0.48-0.2, 0.0f);

        glEnd();
        glPopMatrix();
        }
        //Building rooftop
        for(float i=0;i<0.40;i+=0.3){
        glColor3ub(158,185,209);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(i, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex3f((x4+0.28), -y4+0.48, 0.0f);
            glVertex3f((x4+0.03), -y4+0.48, 0.0f);
            glVertex3f((x4), -y4+0.4, 0.0f);
            glVertex3f((x4+0.25), -y4+0.4, 0.0f);

        glEnd();
        glPopMatrix();
        }
        for(float i=0.0f;i<1.0;i+=0.9){
        glPushMatrix();
        glTranslated(i,0.0f,0.0f);
        glColor3ub(150+37,0,0);
        glBegin(GL_POLYGON);
            glVertex3f((x4+0.28+0.6), -y4+0.48-0.2, 0.0f);
            glVertex3f((x4+0.03+0.6), -y4+0.48-0.2, 0.0f);
            glVertex3f((x4+0.6), -y4+0.4-0.2, 0.0f);
            glVertex3f((x4+0.25+0.6), -y4+0.4-0.2, 0.0f);

        glEnd();
        glPopMatrix();
        }
        //Window
        float x11=-0.9f,y11=0.35f;
    //float g=0.6;
    for(int j=0;j<27;j++){
    if(j!=0 && j%3==0 && j!=9 && j!=18){
        if(j<9){
        y11-=0.20f;
        //x11=-0.9f;
        x11=-0.9f;
        }
        if(j>9 && j<18){
        y11-=0.20f;
        //x11=-0.9f;
        x11=-0.6f;
        }
        if(j>18){
        y11-=0.20f;
        //x11=-0.9f;
        x11=-0.3f;
        }
    }
    if(j!=0 && j%9==0){

        y11=0.35;
        x11=-0.6;
    }

	glColor3ub(14, 144, 214);
	glPushMatrix(); //Save the current state of transformations
	//glTranslatef(p,q,0);
    //glScalef(g,1,1);

	glBegin(GL_POLYGON);
        glVertex3f((x11+0.015), y11+0.35, 0.0f);
        glVertex3f((x11+0.015), y11+0.23, 0.0f);
        glVertex3f(x11+0.075, y11+0.23, 0.0f);
        glVertex3f((x11+0.075), y11+0.35, 0.0f);

    glEnd();

	glPopMatrix();
	x11+=0.08f;

	//q+=0.2f;
	}
	float y22=0.16f;
	for(int i=0;i<6;i++){
        if(i!=0 && i%3==0){
                y22-=0.20f;
                //x11=-0.9f;
                x11=-0.06f;
        }
        glColor3ub(14, 144, 214);
        glPushMatrix(); //Save the current state of transformations


	glBegin(GL_POLYGON);
        glVertex3f((x11+0.015+0.66), y22+0.35, 0.0f);
        glVertex3f((x11+0.015+0.66), y22+0.23, 0.0f);
        glVertex3f(x11+0.075+0.66, y22+0.23, 0.0f);
        glVertex3f((x11+0.075+0.66), y22+0.35, 0.0f);

    glEnd();

	glPopMatrix();
	x11+=0.08f;
	}
        //Door
        for(float i=0.0;i<0.7;i+=0.3){


        glColor3ub(255,255,255);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(i, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex3f((x4+0.06), y4+0.48, 0.0f);
            glVertex3f((x4+0.06), y4+0.2, 0.0f);
            glVertex3f(x4+0.17, y4+0.2, 0.0f);
            glVertex3f((x4+0.17), y4+0.48, 0.0f);
        glEnd();
        glPopMatrix();

        glColor3ub(220,220,220);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(i, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex3f((x4+0.07), y4+0.46, 0.0f);
            glVertex3f((x4+0.07), y4+0.2, 0.0f);
            glVertex3f(x4+0.16, y4+0.2, 0.0f);
            glVertex3f((x4+0.16), y4+0.46, 0.0f);
        glEnd();
        glPopMatrix();
    }
    glColor3ub(255,255,255);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        //glTranslatef(i, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex3f((x4+0.06+1.5), y4+0.48, 0.0f);
            glVertex3f((x4+0.06+1.5), y4+0.2, 0.0f);
            glVertex3f(x4+0.17+1.5, y4+0.2, 0.0f);
            glVertex3f((x4+0.17+1.5), y4+0.48, 0.0f);
        glEnd();
        glPopMatrix();

        glColor3ub(220,220,220);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        //glTranslatef(i, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex3f((x4+0.07+1.5), y4+0.46, 0.0f);
            glVertex3f((x4+0.07+1.5), y4+0.2, 0.0f);
            glVertex3f(x4+0.16+1.5, y4+0.2, 0.0f);
            glVertex3f((x4+0.16+1.5), y4+0.46, 0.0f);
        glEnd();
        glPopMatrix();
}
void DrawRoad(void){
    //Draw Road
    glColor3ub(45,51,45);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0f, -0.2-0.05f, 0.0f);
        glVertex3f(-1.0f, -0.7+0.05f, 0.0f);
        glVertex3f(1.0f, -0.7f+0.05, 0.0f);
        glVertex3f(1.0f, -0.2-0.05f, 0.0f);


   glEnd();
    glPopMatrix();
    //Sides
    float rsx=1.0f,rsy=-0.18;

    for(int i=0;i<2;i++){
    glColor3ub(103,103,103);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glBegin(GL_POLYGON);
        glVertex3f(-rsx, rsy-0.05, 0.0f);
        glVertex3f(-rsx, rsy-0.1f, 0.0f);
        glVertex3f(rsx, rsy-0.1f, 0.0f);
        glVertex3f(rsx, rsy-0.05, 0.0f);


   glEnd();
    glPopMatrix();
    rsy-=0.37;
    //rsy-=0.42;
    }
    glColor3ub (219, 193, 17);
            glLoadIdentity(); //Reset the drawing perspective
            glMatrixMode(GL_MODELVIEW);
            //glTranslatef(0.2, 0.0, 0.0);
            float w1=0.0f,sy=-0.23;
            float sx=-0.9f;
            for(int l=0;l<10;l++){

            glPushMatrix();
            glTranslatef(w1, 0.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex3f(sx+0.01f, sy, 0.0f);
            glVertex3f(sx-0.05f, sy-0.048, 0.0f);
            glVertex3f(sx+0.2f, sy-0.048, 0.0f);
            glVertex3f(sx+0.26f, sy, 0.0f);

            glEnd();
            glPopMatrix();


            w1+=0.2;
            sx+=0.26;

            }
            float w2=0.0f,sy2=-0.6;
            float sx2=-0.9f;
            for(int l=0;l<10;l++){

            glPushMatrix();
            glTranslatef(w2, 0.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex3f(sx2+0.01f, sy2, 0.0f);
            glVertex3f(sx2-0.05f, sy2-0.048, 0.0f);
            glVertex3f(sx2+0.2f, sy2-0.048, 0.0f);
            glVertex3f(sx2+0.26f, sy2, 0.0f);

            glEnd();
            glPopMatrix();


            w2+=0.2;
            sx2+=0.26;

            }
        //draw lanes x=-0.9
            glColor3ub (255, 255, 255);
            glLoadIdentity(); //Reset the drawing perspective
            glMatrixMode(GL_MODELVIEW);
            //glTranslatef(0.2, 0.0, 0.0);
            float w=0.0f;
            float xl=-0.9f;
            for(int l=0;l<5;l++){
            glPushMatrix();
            glTranslatef(w, 0.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex3f(xl+0.01f, -0.41f, 0.0f);
            glVertex3f(xl-0.05f, -0.45f, 0.0f);
            glVertex3f(xl+0.2f, -0.45f, 0.0f);
            glVertex3f(xl+0.26f, -0.41f, 0.0f);

            glEnd();
            glPopMatrix();
            w+=0.2;
            xl+=0.26;
            }

}
void DrawTrees(void){

    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);

     for(float o=0.15;o<0.3;o+=0.05){
    glPushMatrix();

    glTranslatef(o+0.03, 0.56, 0.0);
    glColor3ub(0,159,80);
     //glColor3ub(0,153,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.06;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();
    }
    for(float o=0.15;o<0.34;o+=0.05){
    glPushMatrix();

    glTranslatef(o, 0.48, 0.0);
    glColor3ub(0,153,77);
     //glColor3ub(0,153,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.06;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();
    }

    glColor3ub(155,78,0);
        glLoadIdentity(); //Reset the drawing perspective
        glMatrixMode(GL_MODELVIEW);

        glPushMatrix();
        glBegin(GL_POLYGON);
        glVertex3f(0.2f, 0.22f, 0.0f);
        glVertex3f(0.19f, -0.1f, 0.0f);
        glVertex3f(0.3f, -0.1f, 0.0f);
        glVertex3f(0.29f, 0.22f, 0.0f);
        glVertex3f(0.3f, 0.42f, 0.0f);
        glVertex3f(0.16f, 0.42f, 0.0f);
        glEnd();
        glPopMatrix();

    for(float o=0.1;o<0.35;o+=0.06){
    glPushMatrix();

    glTranslatef(o, 0.4, 0.0);
    glColor3ub(0,145,72);
     //glColor3ub(0,153,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.07;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();
    }

}
void DrawSignal(void){
    //traffic control
        glColor3ub(0,0,0);
        glLoadIdentity(); //Reset the drawing perspective
        glMatrixMode(GL_MODELVIEW);

        glPushMatrix();
        glBegin(GL_POLYGON);
        glVertex3f(0.5f, -0.15f, 0.0f);
        glVertex3f(0.55f, -0.15f, 0.0f);
        glVertex3f(0.55f, 0.3f, 0.0f);
        glVertex3f(0.5f, 0.3f, 0.0f);
        glEnd();
        glPopMatrix();
        glColor3ub(0,0,0);
        glLoadIdentity(); //Reset the drawing perspective
        glMatrixMode(GL_MODELVIEW);

        glPushMatrix();
        glBegin(GL_POLYGON);
        glVertex3f(0.57f, 0.2f, 0.0f);
        glVertex3f(0.57f, 0.45f, 0.0f);
        glVertex3f(0.48f, 0.45f, 0.0f);
        glVertex3f(0.48f, 0.2f, 0.0f);
        glEnd();
        glPopMatrix();

        //Signal Lights
        glPushMatrix();
       //Red Light
	glTranslatef(0.525, 0.40, 0.0);
    glColor3ub(l,m,n);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.03;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.525, 0.32, 0.0);
	glColor3ub(l1,m1,n1);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.03;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.525, 0.24, 0.0);
	glColor3ub(l2,m2,n2);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.03;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();
}
void DrawCar(void){
    //float x0=-0.6f,y0=0.1f;
    //Drawing CarBody
    glColor3ub(l4,m4,n4);

	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
//x5=-0.6f,y5=0.1,x7=-0.6f,y7=0.1,
    glPushMatrix();
	glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x7-0.03, -y7, 0.0f);
        glVertex3f(x7+0.27, -y7, 0.0f);
        glVertex3f(x7+0.2, y7-0.07, 0.0f);
        glVertex3f(x7+0.05, y7-0.07, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(x7-0.03, -y5, 0.0f);
        glVertex3f(x7-0.07, -y5, 0.0f);
        glVertex3f(x7-0.07, -y5-0.18, 0.0f);
        glVertex3f(x7+0.35, -y5-0.18, 0.0f);
        glVertex3f(x7+0.35, -y5, 0.0f);
    glEnd();
    glPopMatrix();

    //Drawing Car Windows
    glColor3ub(255,255,255);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
	glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x5+0.05+0.005-0.9, y5-y5, 0.0f);
        glVertex3f(x5+0.05+0.005-0.9, -y5+0.01f, 0.0f);
        glVertex3f(x5+0.05+0.005+0.08-0.9, -y5+0.01f, 0.0f);
        glVertex3f(x5+0.05+0.005+0.08-0.9, y5-y5, 0.0f);
    glEnd();
    glPopMatrix();
    glColor3ub(255,255,255);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
//x5=-0.6f,y5=0.1,
    glPushMatrix();
	glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x5+0.05+0.005+0.1f-0.9, y5-y5, 0.0f);
        glVertex3f(x5+0.05+0.005+0.1f-0.9, -0.1f+0.01f, 0.0f);
        glVertex3f(x5+0.27-0.020f-0.9, -y5+0.01f, 0.0f);
        glVertex3f(x5+0.2-0.005f-0.9, y5-y5, 0.0f);

    glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.55-0.9, -0.29, 0.0);
	glTranslatef(_move, 0.0f, 0.0f);
    glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();

    glTranslatef(-0.55+0.17-0.9, -0.29, 0.0);
	glTranslatef(_move, 0.0f, 0.0f);
    glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();
}
void DrawCar1(void){
    //Drawing CarBody
    glColor3ub(l3,m3,n3);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
//x5=-0.6f,y5=0.1,x7=-0.6f,
    float yc2=0.03f;
    glPushMatrix();
	glTranslatef(_move1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x7-0.03, -y7-0.2, 0.0f);
        glVertex3f(x7+0.27, -y7-0.2, 0.0f);
        glVertex3f(x7+0.2, y7-0.07-0.2, 0.0f);
        glVertex3f(x7+0.05, y7-0.07-0.2, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(x7-0.03, -y5-0.2, 0.0f);
        glVertex3f(x7-0.07, -y5-0.2, 0.0f);
        glVertex3f(x7-0.07, -y5-0.18-0.2+yc2, 0.0f);
        glVertex3f(x7+0.35, -y5-0.18-0.2+yc2, 0.0f);
        glVertex3f(x7+0.35, -y5-0.2, 0.0f);
    glEnd();
    glPopMatrix();

    //Drawing Car Windows
    glColor3ub(255,255,255);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
	glTranslatef(_move1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x5+0.05+0.005-0.9, y5-y5-0.2, 0.0f);
        glVertex3f(x5+0.05+0.005-0.9, -y5+0.01f-0.2, 0.0f);
        glVertex3f(x5+0.05+0.005+0.08-0.9, -y5+0.01f-0.2, 0.0f);
        glVertex3f(x5+0.05+0.005+0.08-0.9, y5-y5-0.2, 0.0f);
    glEnd();
    glPopMatrix();

    glColor3ub(255,255,255);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
//x5=-0.6f,y5=0.1,
    glPushMatrix();
	glTranslatef(_move1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x5+0.05+0.005+0.1f-0.9, y5-y5-0.2, 0.0f);
        glVertex3f(x5+0.05+0.005+0.1f-0.9, -0.1f+0.01f-0.2, 0.0f);
        glVertex3f(x5+0.27-0.020f-0.9, -y5+0.01f-0.2, 0.0f);
        glVertex3f(x5+0.2-0.005f-0.9, y5-y5-0.2, 0.0f);

    glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.55-0.9, -0.29-0.2+yc2, 0.0);
	glTranslatef(_move1, 0.0f, 0.0f);
    glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();

    glTranslatef(-0.55+0.17-0.9, -0.29-0.2+yc2, 0.0);
	glTranslatef(_move1, 0.0f, 0.0f);
    glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();

}

void DrawCar2(void){

    //Drawing CarBody
    glColor3ub(39,48,150);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    //x5=-0.6f,y5=0.1,x7=-0.6f,y7=0.1,
    glPushMatrix();
	glTranslatef(_move2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x7-0.03-0.5, -y7-0.2, 0.0f);
        glVertex3f(x7+0.27-0.5, -y7-0.2, 0.0f);
        glVertex3f(x7+0.2-0.5, y7-0.07-0.2, 0.0f);
        glVertex3f(x7+0.05-0.5, y7-0.07-0.2, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(x7-0.03-0.5, -y5-0.2, 0.0f);
        glVertex3f(x7-0.07-0.5, -y5-0.2, 0.0f);
        glVertex3f(x7-0.07-0.5, -y5-0.18-0.2, 0.0f);
        glVertex3f(x7+0.35-0.5, -y5-0.18-0.2, 0.0f);
        glVertex3f(x7+0.35-0.5, -y5-0.2, 0.0f);
    glEnd();
    glPopMatrix();

    //Drawing Car Windows
    glColor3ub(255,255,255);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
	glTranslatef(_move2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x5+0.05+0.005-0.5-0.9, y5-y5-0.2, 0.0f);
        glVertex3f(x5+0.05+0.005-0.5-0.9, -y5+0.01f-0.2, 0.0f);
        glVertex3f(x5+0.05+0.005+0.08-0.5-0.9, -y5+0.01f-0.2, 0.0f);
        glVertex3f(x5+0.05+0.005+0.08-0.5-0.9, y5-y5-0.2, 0.0f);
    glEnd();
    glPopMatrix();

    glColor3ub(255,255,255);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
//x5=-0.6f,y5=0.1,
    glPushMatrix();
	glTranslatef(_move2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(x5+0.05+0.005+0.1f-0.5-0.9, y5-y5-0.2, 0.0f);
        glVertex3f(x5+0.05+0.005+0.1f-0.5-0.9, -0.1f+0.01f-0.2, 0.0f);
        glVertex3f(x5+0.27-0.020f-0.5-0.9, -y5+0.01f-0.2, 0.0f);
        glVertex3f(x5+0.2-0.005f-0.5-0.9, y5-y5-0.2, 0.0f);

    glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.55-0.5-0.9, -0.29-0.2, 0.0);
	glTranslatef(_move2, 0.0f, 0.0f);
     glColor3ub(0,0,0);
	glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();

    glTranslatef(-0.55+0.17-0.5-0.9, -0.29-0.2, 0.0);
	glTranslatef(_move2, 0.0f, 0.0f);
     glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,0.0f );
	}
	glEnd();
    glPopMatrix();
}


void DrawRain(void){

    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.3f, _mover, 0.0f);

    float x9=-0.9f;
    float y9= 1.0f;
    for(int j=0;j<220;j++){
        if(j%9==0 && j!=0){
                x9+=0.1;
                y9= 1.0f;
        }
        glColor3ub (255, 255, 255);

        glBegin(GL_LINES);
        glVertex3f(x9,y9,0.0f);
        glVertex3f(x9-0.02, y9-0.1f,0.0f);

        y9-=0.2f;
        glEnd();
    }
    glPopMatrix();

}
void smallT(void){



    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    for(float f=0.0;f<1.0;f+=0.3){
       // glPushMatrix();
        glTranslatef(f,-0.01,0.0);
    glPushMatrix();
    glTranslatef(-0.91+0.01,-0.61,0);
    glScalef(0.8,1,1);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.271, 0.075);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.03;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

    //tree
    glPushMatrix();
    glTranslatef(0,-0.02,0);
    glPushMatrix();
    glTranslatef(-0.9,-0.52,0);
    glScalef(0.6,1,1);
    glBegin(GL_POLYGON);
    glColor3f(0.000, 1.000, 0.000);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

    //flower
	glPushMatrix();
    glTranslatef(-0.9,-0.53,0);
    glScalef(0.8,1,1);
    glBegin(GL_POLYGON);
    glColor3f(0.000, 1.000, 0.000);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.04;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(-0.88,-0.56,0);
    glScalef(0.8,1,1);
    glBegin(GL_POLYGON);
    glColor3f(0.000, 1.000, 0.000);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.04;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(-0.92,-0.56,0);
    glScalef(0.8,1,1);
    glBegin(GL_POLYGON);
    glColor3f(0.000, 1.000, 0.000);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.04;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPopMatrix();
}
}

void darksky(){
//water

//sky
glBegin(GL_QUADS);
glColor3f(0.412, 0.412, 0.412);
glVertex2f(-1.0,1.0);
glVertex2f(1.0,1.0);

glColor3f(0.8, 1.000, 1.000);
glVertex2f(1.0, -0.05);
glVertex2f(-1.0, -0.05);
glEnd();



}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

   /* switch(a){
        case 1:
            afternoon();
          glEnable(GL_LIGHTING);
            break;
    }*/
    sky();

    if(r==0){
        darksky();
    }
        DrawBackground();

        DrawBuilding();

        DrawRoad();
        DrawTrees();
        DrawSignal();
        baseman();
        DrawCNG();
        DrawCar();
        DrawCar1();
        DrawCar2();

        if(r==0){
            DrawRain();
        }
        else if(r==1){
            Sun();
        }
        plane();
        //smallT();
        if(a==1){
     afternoon();
      glEnable(GL_LIGHTING);
    }
        //man();

    glutSwapBuffers();
}


void update(int value) {
    _mover-=0.01;

    if(_mover < -0.1){
        _mover = 0.0;
    }

    if(l!=243 || _move<0.70+0.9 || _move>0.76+0.9){
        _move += .02;
    }

    if(_move>1.9+0.9){
        _move=0.02;
        l4+=100;
        m4+=100;
        n4+=100;
    }

	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(t, update, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update1(int value) {
    if(l!=243 || _move1<0.68+0.9 || _move1>0.76+0.9){
    _move1 += .02;
    }

    if(_move1>1.9+0.9){
        _move1=0.02;
        l3+=100;
        m3+=100;
        n3+=100;
    }

   // printf("%f", _move1);
    //printf(" ");
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(30, update1, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update2(int value) {
    if(l!=243 || _move2<0.72+0.9 || _move2>1.2+0.9){
    _move2 += 0.02;
    }

	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(30, update2, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update3(int value) {

    _movep -= 0.005;

    glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(30, update3, 0); //Notify GLUT to call update again in 25 milliseconds
}
void updateCNG(int value){


        if(l!=243 || _moveCNG<1.8 || _moveCNG>1.86){
            _moveCNG +=0.02;

        }

    glutPostRedisplay();
    glutTimerFunc(30,updateCNG,0);
}
//void specialKeys(int key, int x, int y) {
void specialKeys(unsigned char key, int x, int y) {
    float fraction = 0.1f;
    switch (key) {
        //case GLUT_KEY_RIGHT:
        case 'n':
            a=1;
        break;
        case 's':
            r=1;
            a=0;
        break;
        case 'Y':
         // x4+=0.5f;
         //Yellow
            if(l2==0 || l==243){
            l1=227;
            m1=227;
            n1=2;
          }
        break;
        //case GLUT_KEY_LEFT:
        case 'r':
         // x4-=0.5f;
            r=0;
            a=0;
        break;
        //case GLUT_KEY_UP:
        case 'R':
          //upVy+=0.1f;
          //Yellow
          l1=95;
            m1=78;
            n1=103;
            //Green
            l2=95;
            m2=78;
            n2=103;
            //Red
           l=243;
           m=54;
           n=58;
          //c=1;
          break;
        //case GLUT_KEY_DOWN:
        case 'G':
          c=0;
          //Yellow
           l1=95;
            m1=78;
            n1=103;
            //Red
            l=95;
            m=78;
            n=103;
            //Green
          l2=0;
          m2=179;
          n2=89;
          c=0;
          c1=0;
          c2=0;
          k=0;
        break;

    }
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (1200, 600);
	glutInitWindowPosition (50, 50);
	glutCreateWindow("Transformation");
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(specialKeys);
    //glutSpecialFunc(specialKeys);
	glutTimerFunc(t, update, 0); //Add a timer
	glutTimerFunc(30, update1, 0);
	glutTimerFunc(30, update2, 0);
	glutTimerFunc(30, update3, 0);
	glutTimerFunc(30,updateCNG, 0);
	myInit ();
	glutMainLoop();

}

void myInit (void)
{
glClearColor(0.0, 0.8, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(6.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1200.0, 0.0, 600.0);
}








