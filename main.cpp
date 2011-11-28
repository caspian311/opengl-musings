#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>

#include "camera.h"
#include "maze.h"
#include "lighting.h"

static void resize(int width, int height)
{
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0f, (float) width / (float) height, 0.01f, 200.0f);
}

static void display(void)
{
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

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
         printf("quit...\n");
         exit(0);
         break;
      case 'a':
         printf("turning left...\n");

         turn_left();
         break;
      case 'd':
         printf("turning right...\n");

         turn_right();
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

   glClearColor(0, 0, 0, 0);
   //glEnable(GL_CULL_FACE);
   //glCullFace(GL_BACK);

   //glEnable(GL_DEPTH_TEST);
   //glDepthFunc(GL_LESS);

   setup_lighting();

   glutMainLoop();

   return EXIT_SUCCESS;
}

