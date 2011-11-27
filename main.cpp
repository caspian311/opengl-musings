#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>

#include "camera.h"
#include "maze.h"
#include "lighting.h"

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

static void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   draw_maze();
   update_camera();

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
   }

   glutPostRedisplay();
}

static void idle(void)
{
   glutPostRedisplay();
}


int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitWindowSize(640,480);
   glutInitWindowPosition(10,10);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

   glutCreateWindow("Maze");

   glutReshapeFunc(resize);
   glutDisplayFunc(display);
   glutKeyboardFunc(key);
   glutIdleFunc(idle);

   glClearColor(1,1,1,1);
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);

   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LESS);

   setup_lighting();

   glutMainLoop();

   return EXIT_SUCCESS;
}

