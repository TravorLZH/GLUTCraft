#include <assert.h>
#include <glutcraft/dimconv.h>

float width=0;
float height=0;

void setWindowSize(int w,int h){
	width=(float)w;
	height=(float)h;
}

float getScreenX(int x){
	assert(width!=0.0f);
	return (((float)x)/(width/2))-1.0f;
}

float getScreenY(int y){
	assert(height!=0.0f);
	return (((float)-y)/(height/2))+1.0f;
}

int getWindowX(float x){
	assert(width!=0.0f);
	return (int)((x+1.0f)*width/2);
}

int getWindowY(float y){
	assert(height!=0.0f);
	return (int)(-(y-1.0f)*height/2);
}
