#include <windows.h>
#pragma once
#ifdef __cplusplus
extern "C" {
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
#ifdef __cplusplus
}
#endif
