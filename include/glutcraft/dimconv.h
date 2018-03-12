#include <glutcraft.h>
#ifndef __GLUTCRAFT_DIMCONV_H_
#define __GLUTCRAFT_DIMCONV_H_
#ifdef __cplusplus
extern "C"{
#endif
extern void setWindowSize(int width,int height);
extern float getScreenX(int windowx);
extern float getScreenY(int windowy);
extern int getWindowX(float screenx);
extern int getWindowY(float screeny);
extern int getWindowDistance(int dimension,float screenDistance);
extern float getScreenDistance(int dimension,int windowDistance);
#ifdef __cplusplus
}
#endif
#endif
