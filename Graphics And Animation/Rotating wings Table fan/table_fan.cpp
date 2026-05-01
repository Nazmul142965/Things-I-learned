
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



// ---------------- CUBE ----------------
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


// ---------------- TABLE ----------------
void table()
{
//Top
    glPushMatrix();
    glColor3f(1,.3,.3);
    glTranslated(-3,-.5,-6);
    glScalef(6,.5,4);
    cube();
    glPopMatrix();

//left corner
     glPushMatrix();
    glColor3f(1,.3,.3);
    glTranslated(-3,-6,-6);
    glScalef(.5,6,.5);
    cube();
    glPopMatrix();

    //right corner
    glPushMatrix();
    glColor3f(1,.3,.3);
    glTranslated(2.5,-6,-6);
    glScalef(.5,6,.5);
    cube();
    glPopMatrix();




    //left corner
     glPushMatrix();
    glColor3f(1,.3,.3);
    glTranslated(-3,-6,-3);
    glScalef(.5,6,.5);
    cube();
    glPopMatrix();

    //right corner
    glPushMatrix();
    glColor3f(1,.3,.3);
    glTranslated(2.5,-6,-3);
    glScalef(.5,6,.5);
    cube();
    glPopMatrix();


}

// ---------------- CIRCLE ---------------


void circle(double r, double g, double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);

    for(int i = 0; i<=360; i++)
    {
        double theta = 2*3.1416* i/360;
        glVertex3f(cos(theta), sin(theta), 0);

    }
    glEnd();
}




void wings (GLdouble rot)
{
    glPushMatrix();
   glTranslated(0,0,0);
    glRotated(rot,0,0,1);
    glRotatef(angle, 0,0,1);


    glScalef(2,.3,0.05);
    cube();
    glPopMatrix();

}



void fan()
{
    glPushMatrix();

    glTranslated(0,0,-4);

     glPushMatrix();
     glScalef(0.2,2,0.2);
     cube();
     glPopMatrix();

         // fan circle
    glTranslated(0.1,2,0);
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    circle(0,0,1);
    glPopMatrix();


    wings(0);
    wings(120);
    wings(240);

glPopMatrix();



}


void spin()
{
    angle += 0.05;
    if(angle>360)
        angle -= 360;
    glutPostRedisplay();
}




static void display(void)
{
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslated(0,0,-7);

        glTranslated(-3, -0.5, -6);

       // Step 2: rotate
      glRotated(degreeX,1,0,0);
      glRotated(degreeY,0,1,0);
      glRotated(degreeZ,0,0,1);

    // Step 3: move back
    glTranslated(3, 0.5, 6);

    table();
    fan();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
 switch (key)
    {
        case 27: exit(0);

        case 'a': degreeX+=5; break;
        case 'b': degreeX-=5; break;

        case 'c': degreeY+=5; break;
        case 'd': degreeY-=5; break;

        case 'e': degreeZ+=5; break;
        case 'f': degreeZ-=5; break;
    }
    glutPostRedisplay();
}





/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Table fan");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(spin);

    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);


    glutMainLoop();

    return EXIT_SUCCESS;
}



