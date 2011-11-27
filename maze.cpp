#include <GL/glut.h>

void draw_maze()
{
   glPushMatrix();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   glColor3d(1,0,0);

   glBegin(GL_TRIANGLES);
      glVertex3f(-10.0f, 0.0f,  10.0f);
      glVertex3f( 10.0f, 0.0f,  10.0f);
      glVertex3f( 10.0f, 0.0f, -10.0f);
      glVertex3f(-10.0f, 0.0f, -10.0f);
   glEnd();
   glPopMatrix();
}
