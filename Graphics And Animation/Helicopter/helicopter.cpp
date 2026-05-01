
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<bits/stdc++.h>



float degreeX = 0;
float degreeY = 0;
float degreeZ = 0;

float angle = 0;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
void cube()
{
    glBegin(GL_QUADS);

//red front
    glColor3f(1,0,0);
    glVertex3f(0.0,1.0,0.0);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,0.0);

    //yellow left

    glColor3f(1,1,0);
    glVertex3f(0.0,1.0,1.0);
    glVertex3f(0.0,1.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,1.0);

    //blue back
    glColor3d(0,0,1);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(0.0,1.0,1.0);
    glVertex3f(0.0,0.0,1.0);
    glVertex3f(1.0,0.0,1.0);

//green right

    glColor3f(0,1,0);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,0.0,1.0);
    glVertex3f(1.0,0.0,0.0);



    //cyan bottom

    glColor3f(1,0,1);
    glVertex3f(1.0,0.0,1.0);
    glVertex3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.0,0.0,0.0);

    //violet top

   glColor3f(0,1,1);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(0.0,1.0,0.0);
    glVertex3f(0.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glEnd();


}




void fanBody(){
   glPushMatrix();
    glColor3f(1,.3,.3);
    glTranslated(-0,0,-4);
    glScalef(3,1.5,1.5);
    cube();
    glPopMatrix();

}
void fanBody2(){
   glPushMatrix();
    glColor3f(1,.3,.3);
    glTranslated(3,0,-4);
    glScalef(2,1,1.5);
    cube();
    glPopMatrix();

}
void circle(double r, double g, double b)
{
    glColor3f(r,g,b);

    glBegin(GL_POLYGON);

    for(int i =0; i<=360; i++)
    {
        double theta = 2*3.1416 * i/360;

        glVertex3f(cos(theta), sin(theta), 0);
    }

    glEnd();

}



void wings(GLdouble rot)
{
    glPushMatrix();
    glTranslated(0,0,0);
    glRotated(rot, 0,1,0);
    glRotated(angle, 0,1,0);

    glScalef(2,0.1, .2);
    cube();

    glPopMatrix();
}

void wings2(GLdouble rot)
{
    glPushMatrix();
    glTranslated(0,0,0);
    glRotated(rot, 0,0,1);
    glRotated(angle, 0,0,1);

    glScalef(.7,0.1, .2);
    cube();

    glPopMatrix();
}




void fan()
{
    glPushMatrix();

    glTranslated(1.5,1.5,-3.5);

glPushMatrix();
           glScalef(0.2, 1.7, 0.2);
          cube();
glPopMatrix();

       glTranslated(0.1, 1.7,0);


         wings(0);
         wings(90);
         wings(180);
         wings(270);

glPopMatrix();


}

void fan2()
{
    glPushMatrix();

    glTranslated(4.8,0,-4);

glPushMatrix();
           glScalef(0.2, 1.5, 0.2);
          cube();
glPopMatrix();

       glTranslated(0.1, 1.5,0);


         wings2(0);
         wings2(90);
         wings2(180);
         wings2(270);

glPopMatrix();


}

void spin()
{
    angle += 0.01;
    if(angle> 360)
        angle -=360;
        glutPostRedisplay();

}



static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
        glTranslated(0,0,-10);

          glTranslated(-3,-0.5,-6);

        glRotated(degreeX,1,0,0);
        glRotated(degreeY,0,1,0);
        glRotated(degreeZ,0,0,1);

        glTranslated(3,0.5,6);
      fan();
      fan2() ;
      fanBody();
      fanBody2();




    glPopMatrix();

    glutSwapBuffers();
}




static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case 'a':
            degreeX+=2.5;
            break;

        case 'b':
            degreeX-=2.5;
            break;

        case 'c':
            degreeY+=2.5;
            break;

        case 'd':
            degreeY-=2.5;
            break;

        case 'e':
            degreeZ+=2.5;
            break;

        case 'f':
            degreeZ-=2.5;
            break;


    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("lab 1");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(spin);


    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);



    glutMainLoop();

    return EXIT_SUCCESS;
}


