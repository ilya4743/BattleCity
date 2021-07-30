#include"Game.h"
#include <GL\glut.h>

Game G1;

void renderScene(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	if (G1.state == 0)
	{
		G1.OtherGameObjects();
		G1.Player();
		G1.Bots();
		G1.Bullets();
	}
	if (G1.state == 1)
		G1.GameOver();
	if (G1.state == 2)
	{
		G1.OtherGameObjects();
		G1.Player();
		G1.Bullets();
	}
	glutSwapBuffers();
}

void Timer(int)
{
	renderScene();
	glutTimerFunc(15, Timer, 1);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);	// ������������� GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//������������� ������� ������ RGB � ������� �����
	glutInitWindowPosition(G1.ScreenSizeX/2- G1.WindowSizeX/2, G1.ScreenSizeY/2- G1.WindowSizeY/2); //������������� ������� ����
	glutInitWindowSize(G1.WindowSizeX, G1.WindowSizeY);//������������� ������ ����
	glClearColor(0, 0, 0, 1.0);						//����� �������� ������� ������ ������ �����
	glutCreateWindow("�������");					//�������� ���� "�������"
	glMatrixMode(GL_PROJECTION);					//������� � ���, ��� ������� ��������� � �������.
	glLoadIdentity();								//��������� ������� �������
	glOrtho(0, 800, 0, 700, -1, 1);					//��������� ������������� ��������
	glutDisplayFunc(renderScene);              		//����������� �������� �������
	glutKeyboardFunc(&Controls::KeyboardDown);		//����������� ������� ������ �� �����
	glutKeyboardUpFunc(&Controls::KeyboardUp);		//����������� ������� ������ �� �����
	glutSpecialFunc(&Controls::KeyboardSpecialDown);//����������� ������� ���� ������
	glutSpecialUpFunc(&Controls::KeyboardSpecialUp);//����������� ������� ���� ������
	Timer(0);										//������������� ������
	glutMainLoop();		// �������� ���� GLUT
	return 0;
}