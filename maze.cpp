#include <GL/glut.h>

void draw_maze()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3d(1, 0, 0);

   glPushMatrix();
      glTranslated(-10,1,10);
      glutSolidSphere(1,16,16);
   glPopMatrix();

   glPushMatrix();
      glTranslated(10,1,10);
      glutSolidSphere(1,16,16);
   glPopMatrix();

   glPushMatrix();
      glTranslated(10,1,-10);
      glutSolidSphere(1,16,16);
   glPopMatrix();

   glPushMatrix();
      glTranslated(-10,1,-10);
      glutSolidSphere(1,16,16);
   glPopMatrix();

   glColor3d(0.5, 0.5, 0.5);
   glPushMatrix();
      glBegin(GL_TRIANGLES);
         glVertex3f(-10.0f, 0.0f,  10.0f); // 1
         glVertex3f( 10.0f, 0.0f,  10.0f); // 2
         glVertex3f( 10.0f, 0.0f, -10.0f); // 3

         glVertex3f(-10.0f, 0.0f,  10.0f); // 1
         glVertex3f( 10.0f, 0.0f, -10.0f); // 3
         glVertex3f(-10.0f, 0.0f, -10.0f); // 4
      glEnd();
   glPopMatrix();
}
