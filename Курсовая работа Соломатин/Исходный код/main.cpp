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
	glutInit(&argc, argv);	// Инициализация GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//устанавливаем палитру цветов RGB и двойной буфер
	glutInitWindowPosition(G1.ScreenSizeX/2- G1.WindowSizeX/2, G1.ScreenSizeY/2- G1.WindowSizeY/2); //устанавливаем позицию окна
	glutInitWindowSize(G1.WindowSizeX, G1.WindowSizeY);//Устанавливает размер окна
	glClearColor(0, 0, 0, 1.0);						//задаём значение очистки цветом буфера цвета
	glutCreateWindow("Танчики");					//создание окна "Танчики"
	glMatrixMode(GL_PROJECTION);					//говорит о том, что команды относятся к проекту.
	glLoadIdentity();								//считывает текущую матрицу
	glOrtho(0, 800, 0, 700, -1, 1);					//установка ортогональной проекции
	glutDisplayFunc(renderScene);              		//регистрация обратных вызовов
	glutKeyboardFunc(&Controls::KeyboardDown);		//регистрация нажатий кнопок на клаве
	glutKeyboardUpFunc(&Controls::KeyboardUp);		//регистрация отжатий кнопок на клаве
	glutSpecialFunc(&Controls::KeyboardSpecialDown);//регистрация нажатий спец кнопок
	glutSpecialUpFunc(&Controls::KeyboardSpecialUp);//регистрация отжатий спец кнопок
	Timer(0);										//устанавливаем таймер
	glutMainLoop();		// Основной цикл GLUT
	return 0;
}