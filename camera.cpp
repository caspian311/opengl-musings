
#include <stdio.h>
#include <GL/glu.h>

void update_camera()
{
   int eyeX = 10;
   int eyeY = 10;
   int eyeZ = 10;
   int centerX = 0;
   int centerY = 0;
   int centerZ = 0;
   int upX = 0;
   int upY = 1;
   int upZ = 0;


//   glMatrixMode(GL_PROJECTION);
//   glLoadIdentity();
//   gluPerspective(50.0, 1.0, 3.0, 7.0);
//   glMatrixMode(GL_MODELVIEW);
//   glLoadIdentity();

   gluLookAt(
         eyeX, eyeY, eyeZ,
         centerX, centerY, centerZ,
         upX, upY, upZ
      );
}

void resizing(int width, int height)
{
   // const float ar = (float) width / (float) height;

//   glViewport(0, 0, width, height);
   /*
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity() ;
   */
 //  update_camera();
}
