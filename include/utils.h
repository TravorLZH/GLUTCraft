#include <windows.h>
#ifndef __TRAVOR_UTILS_H_
#define __TRAVOR_UTILS_H_
typedef struct _mouse {
	int x;
	int y;
	float coordx;
	float coordy;
}mouse_t;
typedef struct _camera {
	float pitch;
	float yaw;
	float x;
	float y;
	float z;
}camera_t;
#endif
