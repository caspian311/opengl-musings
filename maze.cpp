#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <string>

bool has_read_file = false;
char maze[10][10];

void build_maze();
void process_line(std::string line, int line_number);
void display_maze();

void draw_maze()
{
   if (!has_read_file)
   {
      build_maze();
   }

   display_maze();
}

void display_maze()
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

void build_maze()
{
   std::string line;
   std::ifstream maze_file ("data.txt");
   if (maze_file.is_open())
   {
      int line_number =0;
      while (maze_file.good()) 
      {
         std::getline(maze_file, line);
         process_line(line, line_number);
         line_number++;
      }
   }
   has_read_file = true;
}

void process_line(std::string line, int line_number)
{
   for (int i=0; i<line.length; i++)
   {
      maze[line_number][i] = line[i];
   }  
}


