#ifndef __TRAVOR_UTILS_H_
#define __TRAVOR_UTILS_H_
#ifdef __cplusplus
extern "C"{
#endif
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
extern int toxz(float*,float*,float);
#ifdef __cplusplus
}
#endif
#endif
