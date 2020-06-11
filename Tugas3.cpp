#include <GL/freeglut.h>
#include <iostream>

void inis()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(11.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(3.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void tamp()
{
	float a1x = 50.0, a1y = 50.0, b1x = 150.0, b1y = 200.0,
		a2x = 50.0, a2y = 200.0, b2x = 150.0, b2y = 50.0,
		a3x = 100.0, a3y = 50.0, b3x = 200.0, b3y = 200.0,
		a4x = 100.0, a4y = 200.0, b4x = 200.0, b4y = 50.0,
		m1,m2,m3,m4,c1,c2,c3,c4, qx,i , ab,j , lm,k ,op,l;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(50.0, 50.0);
	glVertex2f(50.0, 200.0);
	glVertex2f(200.0, 200.0);
	glVertex2f(200.0,50.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 102/255);//kuning
		glVertex2f(a1x, a1y);
		glVertex2f(b1x, b1y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);//biru
	glVertex2f(a2x, a2y);
	glVertex2f(b2x, b2y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(51 / 255, 1.0, 51 / 255);//hijau
	glVertex2f(a3x, a3y);
	glVertex2f(b3x, b3y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(102 / 255, 0.0, 0.0);//coklat
	glVertex2f(a4x, a4y);
	glVertex2f(b4x, b4y);
	glEnd();
	//rumus perpotongan
	m1 = (b1y - a1y) / (b1x - a1x);
	m2 = (b2y - a2y) / (b2x - a2x);
	m3 = (b3y - a3y) / (b3x - a3x);
	m4 = (b4y - a4y) / (b4x - a4x);
	c1 = a1y - (m1 * a1x);
	c2 = a2y - (m2 * a2x);
	c3 = a3y - (m3 * a3x);
	c4 = a4y - (m4 * a4x);
	//titik potong
	qx = (c2 - c1) / (m1 - m2);
	i = (m1 * qx) + c1;
	ab = (c4 - c1) / (m1 - m4);
	j = (m1 * ab) + c1;
	lm = (c3 - c2) / (m2 - m3);
	k = (m3 * lm) + c3;
	op = (c4 - c3) / (m3 - m4);
	l = (m3 * op) + c3;
	//Tampilan titik potong
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(qx, i);
	glVertex2f(ab, j);
	glVertex2f(lm, k);
	glVertex2f(op, l);
	glEnd();

	glFlush();
}
int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tugas 3 Perpotongan Garis");
	glutDisplayFunc(tamp);
	inis();
	glutMainLoop();
	return 0;
}