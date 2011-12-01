#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

#include "maze_builder.h"

void display_maze();
void draw_horizontal_wall(int i, int j);
void draw_vertical_wall(int i, int j);
void draw_wall();
void draw_sphere(int i, int j);
void draw_floor();

void draw_maze()
{
   build_maze();

   display_maze();
}

void display_maze()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   for (int i=0; i<10; i++)
   {
      for (int j=0; j<10; j++)
      {
         char element = maze_data[i][j];
         switch (element)
         {
            case '-':
               draw_horizontal_wall(i, j);
               break;
            case '|':
               draw_vertical_wall(i, j);
               break;
            case 's':
               draw_sphere(i, j);
               break;
         }
      }
   }

   draw_floor();
}

void draw_horizontal_wall(int i, int j)
{
   glColor3d(0.5, 0.5, 0.5);
   glPushMatrix();
      glTranslated((float)i, 1.0f, (float)j);
      glRotated(90, 0.0f, 0.0f, 1.0f);
      draw_wall();
   glPopMatrix();
}

void draw_vertical_wall(int i, int j)
{
   glColor3d(0.5, 0.5, 0.5);
   glPushMatrix();
      glTranslated((float)i, 1.0f, (float)j);
      glRotated(90, 1.0f, 0.0f, 0.0f);
      draw_wall();
   glPopMatrix();
}

void draw_wall()
{
   glBegin(GL_TRIANGLES);
      glVertex3f(-0.5f, 0.5f,  0.5f); // 1
      glVertex3f( 0.5f, 0.5f,  0.5f); // 2
      glVertex3f( 0.5f, 0.5f, -0.5f); // 3

      glVertex3f(-0.5f, 0.5f,  0.5f); // 1
      glVertex3f( 0.5f, 0.5f, -0.5f); // 3
      glVertex3f(-0.5f, 0.5f, -0.5f); // 4
   glEnd();
}

void draw_sphere(int i, int j)
{
   glColor3d(1, 0, 0);
   glPushMatrix();
      glTranslated((float)i, 1, (float)j);
      glutSolidSphere(0.5, 16, 16);
   glPopMatrix();
}

void draw_floor()
{
   glColor3d(0.5, 0.6, 0.9);
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
