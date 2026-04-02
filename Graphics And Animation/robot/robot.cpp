
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;
float degreeX = 0;
float degreeY = 0;
float degreeZ = 0;

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

void robot(){

   //body
    glPushMatrix();
    glTranslated(-1.5, -2, -7);
    glScaled(3.0, 4.0, 1.0);
    cube();
    glPopMatrix();

    //head
    glPushMatrix();
    glTranslated(-0.75, 2, -7);
    glScaled(1.5, 1.5, 1);

    cube();
    glPopMatrix();

    //right hand
     glPushMatrix();
    glTranslated(1.5,0.5, -7);
    glScaled(0.5, 3.5 , 0.5);
    cube();
    glPopMatrix();

    //left hand
    glPushMatrix();
    glTranslated(-2, 0.5, -7);
    glScaled(0.5, 3.5 , 0.5);
    cube();
    glPopMatrix();


   //right leg
     glPushMatrix();
    glTranslated(1,-6, -7);
    glScaled(0.5, 4 , 0.5);
    cube();
    glPopMatrix();

    //left leg
    glPushMatrix();
    glTranslated(-1.5, -6, -7);
    glScaled(0.5, 4 , 0.5);
    cube();
    glPopMatrix();


}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);


    glPushMatrix();
        glTranslated(0,0,-7);

        glTranslated(-3,-0.5,-6);
        glRotated(degreeX,0.5,0,0);
        glRotated(degreeY,0,.5,0);
        glRotated(degreeZ,0,0,.5);
        glScalef(1,1,1);

        glTranslated(3,0.5,6);
         robot();


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

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
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

    glutCreateWindow("2023100000130");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);



    glutMainLoop();

    return EXIT_SUCCESS;
}


