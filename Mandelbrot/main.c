// Orshak Ivan, 28.12.15

#include "compl.h"
#include <glut.h>

#define H 600
#define W 600

unsigned char Frame[H][W][3];

void Display(void)
{
	COMPL Z;
	double n, x0, x1, y0, y1;
	int xs, ys;

	x0 = y0 = -2;
	x1 = y1 = 2;

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	for (ys = 0; ys < H; ys++)
		for (xs = 0; xs < W; xs++)
		{
			Z = CompSet(xs * (x1 - x0) / W + x0, ys * (y1 - y0) / H + y0);
			n = Iter(Z);

			Frame[ys][xs][0] = n * 2;
			Frame[ys][xs][1] = n * 15;
			Frame[ys][xs][2] = n * 30;
		}

	glDrawPixels(W, H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

	glFinish();

	glutSwapBuffers();

	glutPostRedisplay();
}

void Keyboard(unsigned char Key, int x, int y)
{
	if (Key == 27)
		exit(0);
	else if (Key == 'f')
		glutFullScreen();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(380, 80);
	glutInitWindowSize(600, 600);

	glutCreateWindow("Main");

	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);

	glutMainLoop();

	return 0;
}