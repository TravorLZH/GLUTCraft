#include <stdio.h>
#include <assert.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <glutcraft/debugscreen.h>
#include <glutcraft/dimconv.h>

#define	LINE_HEIGHT	18

static void printStringAt(const char *str,int x,int y){
	assert(x>=0);
	assert(y>=0);
	glRasterPos2i(x,y);
	int i;
	int len=strlen(str);
	for(i=0;i<len;i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
	}
}

void showDebugText(mouse_t mouse,window_t window,camera_t camera){
	char buf[BUFSIZ];
	int i=0;
	glColor3f(1.0f,1.0f,1.0f);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0,window.width,0,window.height);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	sprintf(buf,"Mouse XY: %d (%f) / %d (%f)%s",mouse.x,getScreenX(mouse.x),mouse.y,getScreenY(mouse.y),mouse.grab? " (grabbed)":"\0");
	printStringAt(buf,0,window.height-LINE_HEIGHT);
	memset(buf,0,BUFSIZ);	// Clear buff
	sprintf(buf,"Window Resolution: %d x %d",window.width,window.height);
	printStringAt(buf,0,window.height-LINE_HEIGHT*2);
	memset(buf,0,BUFSIZ);
	sprintf(buf,"Camera XYZ: %f / %f / %f, Yaw: %f, Pitch: %f",camera.x,camera.y,camera.z,camera.yaw,camera.pitch);
	printStringAt(buf,0,window.height-LINE_HEIGHT*3);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
