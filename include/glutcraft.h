#ifndef	__GLUTCRAFT_H_
#define	__GLUTCRAFT_H_
typedef struct _mouse {
	char grab;
	int x;
	int y;
}mouse_t;
typedef struct _window{
	int width;
	int height;
}window_t;
typedef struct _camera {
	float pitch;
	float yaw;
	float x;
	float y;
	float z;
}camera_t;
#endif
