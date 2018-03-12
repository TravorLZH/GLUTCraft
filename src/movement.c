#include <math.h>
#include <glutcraft/movement.h>

void moveForward(camera_t* camera,float step){
	float yaw=camera->yaw;
	float stepx=-step*sin(yaw*M_PI/180.0f);
	float stepz=-step*cos(yaw*M_PI/180.0f);
	camera->x+=stepx;
	camera->z+=stepz;
}

void moveSide(camera_t* camera,float step){
	float yaw=camera->yaw-90.0f;
	float stepx=-step*sin(yaw*M_PI/180.0f);
	float stepz=-step*cos(yaw*M_PI/180.0f);
	camera->x+=stepx;
	camera->z+=stepz;
}
