
#include <math.h>
#include <stdio.h>
#include <GL/glu.h>

void update();

const float ROTATION_SPEED = 5.0f;

int screen_width, screen_height;

int eyeX =  0;
int eyeY =  5;
int eyeZ =  10;
int centerX = 0;
int centerY = 0;
int centerZ = 0;
int upX = 0;
int upY = 1;
int upZ = 0;

float rotation_angle = 0;

void update_camera()
{
   gluLookAt(
         eyeX, eyeY, eyeZ,
         centerX, centerY, centerZ,
         upX, upY, upZ
      );
   printf("gluLookAt: (%d, %d, %d), (%d, %d, %d), (%d, %d, %d)\n",
         eyeX, eyeY, eyeZ,
         centerX, centerY, centerZ,
         upX, upY, upZ);
}

void turn_left()
{
   rotation_angle -= ROTATION_SPEED;
   update();
}

void turn_right()
{
   rotation_angle += ROTATION_SPEED;
   update();
}

void update()
{
   centerX = 10 * cos(rotation_angle);
   centerZ = 10 * sin(rotation_angle);

   update_camera();
}

