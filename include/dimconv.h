#ifndef __TRAVOR_DIMCONV_H_
#define __TRAVOR_DIMCONV_H_
#ifdef __cplusplus
extern "C"{
#endif
extern void setWindowSize(int width,int height);
extern float getScreenX(int windowx);
extern float getScreenY(int windowy);
extern int getWindowX(int screenx);
extern int getWindowY(int screeny);
#ifdef __cplusplus
}
#endif
#endif
