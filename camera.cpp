
#include <math.h>
#include <stdio.h>
#include <GL/glu.h>

#include "globals.h"

const float ROTATION_SPEED = 1.0f;
const float MOVEMENT_SPEED = 1.0f;

int screen_width, screen_height;

float eyeX =  0;
float eyeY =  1;
float eyeZ =  10;
float centerX = 0;
float centerY = 1;
float centerZ = 0;
float upX = 0;
float upY = 1;
float upZ = 0;

float rotation_angle = -90.0f;

void log();

void update_camera()
{
   gluLookAt(
         eyeX, eyeY, eyeZ,
         centerX, centerY, centerZ,
         upX, upY, upZ
      );

   if (DEBUGGING)
   {
      log();
   }
}

void turn_left()
{
   rotation_angle -= ROTATION_SPEED;

   float angle_in_rads = rotation_angle * (PI / 180);
   centerX = (MOVEMENT_SPEED * cos(angle_in_rads)) + eyeX;
   centerZ = (MOVEMENT_SPEED * sin(angle_in_rads)) + eyeZ;

   update_camera();
}

void turn_right()
{
   rotation_angle += ROTATION_SPEED;

   float angle_in_rads = rotation_angle * (PI / 180);
   centerX = (MOVEMENT_SPEED * cos(angle_in_rads)) + eyeX;
   centerZ = (MOVEMENT_SPEED * sin(angle_in_rads)) + eyeZ;

   update_camera();
}

void move_forward()
{
   eyeX = centerX;
   eyeZ = centerZ;

   float angle_in_rads = rotation_angle * (PI / 180);
   centerX = (MOVEMENT_SPEED * cos(angle_in_rads)) + eyeX;
   centerZ = (MOVEMENT_SPEED * sin(angle_in_rads)) + eyeZ;

   update_camera();
}

void move_backward()
{
   centerX = eyeX;
   centerZ = eyeZ;

   float angle_in_rads = (rotation_angle + 180) * (PI / 180);
   eyeX = (MOVEMENT_SPEED * cos(angle_in_rads)) + eyeX;
   eyeZ = (MOVEMENT_SPEED * sin(angle_in_rads)) + eyeZ;

   update_camera();
}

void strafe_left()
{
   float angle_in_rads = (rotation_angle + 90) * (PI / 180);
   eyeX = (MOVEMENT_SPEED * cos(angle_in_rads)) + eyeX;
   eyeZ = (MOVEMENT_SPEED * sin(angle_in_rads)) + eyeZ;
}

void strafe_right()
{
   float angle_in_rads = (rotation_angle - 90) * (PI / 180);
   eyeX = (MOVEMENT_SPEED * cos(angle_in_rads)) + eyeX;
   eyeZ = (MOVEMENT_SPEED * sin(angle_in_rads)) + eyeZ;
}

void log()
{
      printf("gluLookAt: (%f, %f, %f), (%f, %f, %f), (%f, %f, %f)\n", 
         eyeX, eyeY, eyeZ,
         centerX, centerY, centerZ,
         upX, upY, upZ);
}
