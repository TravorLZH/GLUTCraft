#include <glutcraft.h>
#include <glutcraft/debugscreen.h>
#include <glutcraft/dimconv.h>
#include <glutcraft/movement.h>
#include <GL/glut.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define FPS 20
#define GRAVITY	0.02f	// Gravity

mouse_t mouse;
camera_t camera;
window_t window;
bool dbgScreen=0;

int FOV = 70;

void centerCursor(void) {
	int centerX=getWindowX(0);
	int centerY=getWindowY(0);
	if(mouse.x!=centerX || mouse.y!=centerY){
		mouse.x=centerX;
		mouse.y=centerY;
		glutWarpPointer(mouse.x,mouse.y);
	}
}

void coordinatePerspective(void) {
	camera.yaw = (float)(((int)camera.yaw) % 360);
	camera.pitch = camera.pitch >= 90.0f ? camera.pitch=90.0f : camera.pitch;
	camera.pitch = camera.pitch <= -90.0f ? camera.pitch=-90.0f : camera.pitch;
	glRotatef(-camera.pitch, 1.0f, 0.0f, 0.0f);
	glRotatef(-camera.yaw, 0.0f, 1.0f, 0.0f);
	glTranslatef(-camera.x, -camera.y, -camera.z);
}

void drawLevel(void) {
	glColor3f(0.0f,1.0f,0.0f);
	glutWireTeapot(0.5);
}

void display(void) {
	glPushMatrix();
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	if(dbgScreen){
		showDebugText(mouse,window,camera);
	}
	coordinatePerspective();
	drawLevel();
	glFlush();
	glPopMatrix();
}

void frameFunc(int arg) {
	glutPostRedisplay();
	if(mouse.grab==1){
		centerCursor();
	}
	glutTimerFunc(1000 / FPS, &frameFunc, 0);
}
void keyFunc(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	case 'w':case 'W':	// Go forward
		moveForward(&camera,0.05f);
		break;
	case 's':case 'S':	// Go backward
		moveForward(&camera,-0.05f);
		break;
	case 'a':case 'A':	// Go left
		camera.x -= 0.05f;
		break;
	case 'd':case 'D':	// Go right
		camera.x += 0.05f;
		break;
	case 'j':	// Go down
		camera.y += 0.05f;
		break;
	case 'k':	// Go up
		camera.y -= 0.05f;
		break;
	case 'm':	// Toggle mouse grab
		mouse.grab=mouse.grab? 0:1;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	window.width=w;
	window.height=h;
	setWindowSize(w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, ((float)w)/((float)h), 0, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		camera.yaw+=1.0f;
		break;
	case GLUT_KEY_RIGHT:
		camera.yaw-=1.0f;
		break;
	case GLUT_KEY_UP:
		camera.pitch+=1.0f;
		break;
	case GLUT_KEY_DOWN:
		camera.pitch-=1.0f;
		break;
	case GLUT_KEY_F3:
		dbgScreen=dbgScreen?0:1;
		break;
	}
	glutPostRedisplay();
}

void motionFunc(int x, int y) {
	mouse.x = x;
	mouse.y = y;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	memset(&mouse, 0, sizeof(mouse));
	memset(&camera, 0, sizeof(camera));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("GLUT Craft");
	glutReshapeFunc(&reshape);
	glutDisplayFunc(&display);
	glutSpecialFunc(&specialKeys);
	glutPassiveMotionFunc(&motionFunc);
	glutKeyboardFunc(&keyFunc);
	glutTimerFunc(1000 / FPS, &frameFunc, 0);
	glutMainLoop();
	return 0;
}
