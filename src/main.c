#pragma once
#include <utils.h>
#include <GL/glut.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define CX(x)	((((float)x)/150)-1.0f)
#define CY(y)	((((float)-y)/150)+1.0f)
#define WX(x)	((int)((x+1.0f)*150.0f))
#define WY(y)	((int)((y-1.0f)*150.0f))
#define FPS 20
#define FOO 30
#define PI 3.1415926535f
#define POOP distance*tan(60.0f)
#define BAR(x) (x*PI/180)
#define g	0.02f

mouse_t mouse;
camera_t camera;

int FOV = 70;

void printStuff(LPVOID param) {
	system("cls");
	printf("======MOUSE======\n");
	printf("X:\t%f (%d)\n", mouse.coordx, mouse.x);
	printf("Y:\t%f (%d)\n", mouse.coordy, mouse.y);
	printf("=====CAMERA======\n");
	printf("X: %f, Y: %f, Z: %f\n", camera.x, camera.y, camera.z);
	printf("Pitch: %f, Yaw: %f\n", camera.pitch, camera.yaw);
}

void keepCursor() {
	mouse.x = mouse.x > 300 ? 300 : mouse.x;
	mouse.x = mouse.x < 0 ? 0 : mouse.x;
	mouse.y = mouse.y > 300 ? 300 : mouse.y;
	mouse.y = mouse.y < 0 ? 0 : mouse.y;
	mouse.coordx = CX(mouse.x);
	mouse.coordy = CY(mouse.y);
	glutWarpPointer(mouse.x, mouse.y);
}

void coordinatePerspective() {
	camera.yaw = (float)(((int)camera.yaw) % 360);
	camera.pitch = camera.pitch >= 90.0f ? camera.pitch=90.0f : camera.pitch;
	camera.pitch = camera.pitch <= -90.0f ? camera.pitch=-90.0f : camera.pitch;
	glRotatef(-camera.pitch, 1.0f, 0.0f, 0.0f);
	glRotatef(-camera.yaw, 0.0f, 1.0f, 0.0f);
	glTranslatef(-camera.x, -camera.y, -camera.z);
}
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 0, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawLevel() {
	glutWireCube(0.5);
}

void display(void) {
	glPushMatrix();
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	coordinatePerspective();
	drawLevel();
	glFlush();
	glPopMatrix();
}

void frameFunc(int arg) {
	keepCursor();
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, &frameFunc, 0);
}
void keyFunc(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	case 'w':case 'W':
		camera.z -= 0.05f;
		break;
	case 's':case 'S':
		camera.z += 0.05f;
		break;
	case 'a':case 'A':
		camera.x -= 0.05f;
		break;
	case 'd':case 'D':
		camera.x += 0.05f;
		break;
	case 'j':
		camera.y += 0.05f;
		break;
	case 'k':
		camera.y -= 0.05f;
		break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, h-300, 300, 300);
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
	}
	glutPostRedisplay();
}

void motionFunc(int x, int y) {
	mouse.x = x;
	mouse.y = y;
	mouse.coordx = CX(x);
	mouse.coordy = CY(y);
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	memset(&mouse, 0, sizeof(mouse));
	memset(&camera, 0, sizeof(camera));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(300, 300);
	glutCreateWindow("GLUT Craft");
	glutReshapeFunc(&reshape);
	glutDisplayFunc(&display);
	init();
	glutSpecialFunc(&specialKeys);
	glutPassiveMotionFunc(&motionFunc);
	glutKeyboardFunc(&keyFunc);
	glutIdleFunc(&printStuff);
	glutTimerFunc(1000 / FPS, &frameFunc, 0);
	glutMainLoop();
	return 0;
}
