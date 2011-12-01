#include <iostream>
#include <fstream>
#include <string>

#include "maze_builder.h"

char maze_data[10][10];
bool has_read_file = false;

void process_line(std::string line, int line_number);

void build_maze()
{
   if (!has_read_file)
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
}

void process_line(std::string line, int line_number)
{
   for (int i=0; i<line.length(); i++)
   {
      maze_data[line_number][i] = line[i];
   }  
}


