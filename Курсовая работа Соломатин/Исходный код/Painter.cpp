#include"Painter.h"

void Painter::DrawTank(int x, int y, int p, bool enemy)
{
	int size = 20;
	glBegin(GL_POINTS);
	if (enemy == false)
		glColor3d(0, 0.5, 0);
	else
		glColor3d(0.55, 0.55, 0.55);

	switch (p)
	{
	case 1:
	{
		for (int i = 0; i <= size / 2 - 6; i = i + 2)
		{
			glVertex2f(x - size / 2, y + i);
			glVertex2f(x + size / 2, y + i);
			glVertex2f(x + 1 - size / 2, y + i);
			glVertex2f(x - 1 + size / 2, y + i);
			glVertex2f(x + 2 - size / 2, y + i);
			glVertex2f(x - 2 + size / 2, y + i);
		}
		for (int i = 0; i <= size / 2; i = i + 2)
		{
			glVertex2f(x - size / 2, y - i);
			glVertex2f(x + size / 2, y - i);
			glVertex2f(x + 1 - size / 2, y - i);
			glVertex2f(x - 1 + size / 2, y - i);
			glVertex2f(x + 2 - size / 2, y - i);
			glVertex2f(x - 2 + size / 2, y - i);
		}
		//Крышки гусениц
		for (int i = 0; i <= size / 2; ++i)
		{
			glVertex2f(x + 3 - size / 2, y - i);
			glVertex2f(x - 3 + size / 2, y - i);
		}
		for (int i = 0; i <= size / 2 - 6; ++i)
		{
			glVertex2f(x + 3 - size / 2, y + i);
			glVertex2f(x - 3 + size / 2, y + i);
		}
		//Траки
		for (int i = 2; i <= size - 8; ++i)
		{
			glVertex2f(x + 4 - size / 2, y - size / 2 + i);
			glVertex2f(x - 4 + size / 2, y - size / 2 + i);
			glVertex2f(x + 5 - size / 2, y - size / 2 + i);
			glVertex2f(x - 5 + size / 2, y - size / 2 + i);
		}
		//Корпус танка
		for (int i = 3; i <= size - 7; ++i)
		{
			for (int j = 6; j <= size - 6; j++)
				glVertex2f(x - j + size / 2, y + i - size / 2);
		}
		for (int i = 1; i <= size / 2; ++i)
			glVertex2f(x, y + i);
	}break;
	case 2:
	{
		for (int i = 0; i <= size / 2 - 6; i = i + 2)
		{
			glVertex2f(x + i, y - size / 2);
			glVertex2f(x + i, y + size / 2);
			glVertex2f(x + i, y + 1 - size / 2);
			glVertex2f(x + i, y - 1 + size / 2);
			glVertex2f(x + i, y + 2 - size / 2);
			glVertex2f(x + i, y - 2 + size / 2);
		}
		for (int i = 0; i <= size / 2; i = i + 2)
		{
			glVertex2f(x - i, y - size / 2);
			glVertex2f(x - i, y + size / 2);
			glVertex2f(x - i, y + 1 - size / 2);
			glVertex2f(x - i, y - 1 + size / 2);
			glVertex2f(x - i, y + 2 - size / 2);
			glVertex2f(x - i, y - 2 + size / 2);
		}
		//Крышки гусениц
		for (int i = 0; i <= size / 2; ++i)
		{
			glVertex2f(x - i, y + 3 - size / 2);
			glVertex2f(x - i, y - 3 + size / 2);
		}
		for (int i = 0; i <= size / 2 - 6; ++i)
		{
			glVertex2f(x + i, y + 3 - size / 2);
			glVertex2f(x + i, y - 3 + size / 2);
		}
		//Траки
		for (int i = 2; i <= size - 8; ++i)
		{
			glVertex2f(x - size / 2 + i, y + 4 - size / 2);
			glVertex2f(x - size / 2 + i, y - 4 + size / 2);
			glVertex2f(x - size / 2 + i, y + 5 - size / 2);
			glVertex2f(x - size / 2 + i, y - 5 + size / 2);
		}
		//Корпус танка
		for (int i = 3; i <= size - 7; ++i)
		{
			for (int j = 6; j <= size - 6; j++)
				glVertex2f(x + i - size / 2, y - j + size / 2);
		}
		for (int i = 1; i <= size / 2; ++i)
			glVertex2f(x + i, y);
	}break;
	case 3:
	{
		for (int i = 0; i <= size / 2 - 6; i = i + 2)
		{
			glVertex2f(x - i, y - size / 2);
			glVertex2f(x - i, y + size / 2);
			glVertex2f(x - i, y + 1 - size / 2);
			glVertex2f(x - i, y - 1 + size / 2);
			glVertex2f(x - i, y + 2 - size / 2);
			glVertex2f(x - i, y - 2 + size / 2);
		}
		for (int i = 0; i <= size / 2; i = i + 2)
		{
			glVertex2f(x + i, y - size / 2);
			glVertex2f(x + i, y + size / 2);
			glVertex2f(x + i, y + 1 - size / 2);
			glVertex2f(x + i, y - 1 + size / 2);
			glVertex2f(x + i, y + 2 - size / 2);
			glVertex2f(x + i, y - 2 + size / 2);
		}
		//Крышки гусениц
		for (int i = 0; i <= size / 2; ++i)
		{
			glVertex2f(x + i, y + 3 - size / 2);
			glVertex2f(x + i, y - 3 + size / 2);
		}
		for (int i = 0; i <= size / 2 - 6; ++i)
		{
			glVertex2f(x - i, y + 3 - size / 2);
			glVertex2f(x - i, y - 3 + size / 2);
		}
		//Траки
		for (int i = 2; i <= size - 8; ++i)
		{
			glVertex2f(x + size / 2 - i, y + 4 - size / 2);
			glVertex2f(x + size / 2 - i, y - 4 + size / 2);
			glVertex2f(x + size / 2 - i, y + 5 - size / 2);
			glVertex2f(x + size / 2 - i, y - 5 + size / 2);
		}
		//Корпус танка
		for (int i = 3; i <= size - 7; ++i)
		{
			for (int j = 6; j <= size - 6; j++)
				glVertex2f(x - i + size / 2, y + j - size / 2);
		}
		for (int i = 1; i <= size / 2; ++i)
			glVertex2f(x - i, y);
	}break;
	case 4:
	{
		for (int i = 0; i <= size / 2 - 6; i = i + 2)
		{
			glVertex2f(x - size / 2, y - i);
			glVertex2f(x + size / 2, y - i);
			glVertex2f(x + 1 - size / 2, y - i);
			glVertex2f(x - 1 + size / 2, y - i);
			glVertex2f(x + 2 - size / 2, y - i);
			glVertex2f(x - 2 + size / 2, y - i);
		}
		for (int i = 0; i <= size / 2; i = i + 2)
		{
			glVertex2f(x - size / 2, y + i);
			glVertex2f(x + size / 2, y + i);
			glVertex2f(x + 1 - size / 2, y + i);
			glVertex2f(x - 1 + size / 2, y + i);
			glVertex2f(x + 2 - size / 2, y + i);
			glVertex2f(x - 2 + size / 2, y + i);
		}
		//Крышки гусениц
		for (int i = 0; i <= size / 2; ++i)
		{
			glVertex2f(x + 3 - size / 2, y + i);
			glVertex2f(x - 3 + size / 2, y + i);
		}
		for (int i = 0; i <= size / 2 - 6; ++i)
		{
			glVertex2f(x + 3 - size / 2, y - i);
			glVertex2f(x - 3 + size / 2, y - i);
		}
		//Траки
		for (int i = 2; i <= size - 8; ++i)
		{
			glVertex2f(x + 4 - size / 2, y + size / 2 - i);
			glVertex2f(x - 4 + size / 2, y + size / 2 - i);
			glVertex2f(x + 5 - size / 2, y + size / 2 - i);
			glVertex2f(x - 5 + size / 2, y + size / 2 - i);
		}
		//Корпус танка
		for (int i = 3; i <= size - 7; ++i)
		{
			for (int j = 6; j <= size - 6; j++)
				glVertex2f(x + j - size / 2, y - i + size / 2);
		}
		for (int i = 1; i <= size / 2; ++i)
			glVertex2f(x, y - i);
	}break;
	}
	glEnd();
}

void Painter::DrawBullet(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3d(0, 0, 0);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x - 1, y);
	glVertex2f(x, y + 1);
	glVertex2f(x, y - 1);
	glEnd();
}

void Painter::DrawWall(int x, int y, int p)
{
	
	switch (p)
	{	
		//Непробиваемая стена
	case 1:	
	{
		glBegin(GL_QUADS);
		glColor3d(1, 1, 1);
		glVertex2f(x - 15, y + 15);
		glVertex2f(x - 15, y - 15);
		glVertex2f(x + 15, y - 15);
		glVertex2f(x + 15, y + 15);
		glEnd();
		break;
	}
		//Кирпичная пробиваемая стена
	case 2:
	{
		glBegin(GL_QUADS);// 0.95, 0.91, 0.788
		glColor3d(1, 0.15, 0.05);
		glVertex2f(x - 15, y + 15);
		glVertex2f(x - 15, y - 15);
		glVertex2f(x + 15, y - 15);
		glVertex2f(x + 15, y + 15);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.95, 0.95, 0.8);
		glVertex2f(x - 9, y + 15);
		glVertex2f(x - 9, y - 15);
		glVertex2f(x - 11, y - 15);
		glVertex2f(x - 11, y + 15);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.95, 0.95, 0.8);
		glVertex2f(x - 9 + 10, y + 15);
		glVertex2f(x - 9 + 10, y - 15);
		glVertex2f(x - 11 + 10, y - 15);
		glVertex2f(x - 11 + 10, y + 15);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.95, 0.95, 0.8);
		glVertex2f(x - 9 + 20, y + 15);
		glVertex2f(x - 9 + 20, y - 15);
		glVertex2f(x - 11 + 20, y - 15);
		glVertex2f(x - 11 + 20, y + 15);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.95, 0.95, 0.8);
		glVertex2f(x - 15, y - 11 + 10);
		glVertex2f(x - 15, y - 9 + 10);
		glVertex2f(x + 15, y - 9 + 10);
		glVertex2f(x + 15, y - 11 + 10);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.95, 0.95, 0.8);
		glVertex2f(x - 15, y - 11 + 20);
		glVertex2f(x - 15, y - 9 + 20);
		glVertex2f(x + 15, y - 9 + 20);
		glVertex2f(x + 15, y - 11 + 20);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.95, 0.95, 0.8);
		glVertex2f(x - 15, y - 11);
		glVertex2f(x - 15, y - 9);
		glVertex2f(x + 15, y - 9);
		glVertex2f(x + 15, y - 11);
		glEnd();
		break;
	}
		//Вода
	case 3:
	{
		glBegin(GL_QUADS);
		glColor3d(0, 0.5, 1);
		glVertex2f(x - 15, y + 15);
		glVertex2f(x - 15, y - 15);
		glVertex2f(x + 15, y - 15);
		glVertex2f(x + 15, y + 15);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.5, 0.775, 1);
		glVertex2f(x - 12, y -10);
		glVertex2f(x - 12, y - 12);
		glVertex2f(x +1, y - 12);
		glVertex2f(x - 5, y -10);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.5, 0.775, 1);
		glVertex2f(x - 12+15, y - 10+4);
		glVertex2f(x - 12+15, y - 12+4);
		glVertex2f(x + 2+15, y - 12+4);
		glVertex2f(x - 5+15, y - 10+4);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.5, 0.775, 1);
		glVertex2f(x - 12 + 10, y - 10 + 10);
		glVertex2f(x - 12 + 10, y - 12 + 10);
		glVertex2f(x -5 + 10, y - 12 + 10);
		glVertex2f(x +2 + 10, y - 10 + 10);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.5, 0.775, 1);
		glVertex2f(x - 14 + 2, y - 10 + 6);
		glVertex2f(x - 14 + 2, y - 12 + 6);
		glVertex2f(x - 7 + 2, y - 12 + 6);
		glVertex2f(x + 2, y - 10 + 6);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.5, 0.775, 1);
		glVertex2f(x - 6 + 8, y - 10 + 20);
		glVertex2f(x - 6 + 8, y - 12 + 20);
		glVertex2f(x + 6 + 8, y - 12 + 20);
		glVertex2f(x + 2 + 8, y - 10 + 20);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.5, 0.775, 1);
		glVertex2f(x - 14 + 5, y - 10 + 15);
		glVertex2f(x - 14 + 8, y - 12 + 15);
		glVertex2f(x + 8, y - 12 + 15);
		glVertex2f(x + 4+8, y - 10 + 15);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.5, 0.775, 1);
		glVertex2f(x - 14, y - 10 + 22);
		glVertex2f(x - 13, y - 12 + 22);
		glVertex2f(x + 1, y - 12 + 22);
		glVertex2f(x -1, y - 10 + 21);
		glEnd();
	}
	}
}

void Painter::DrawField()
{
	glBegin(GL_LINES);
	glColor3d(1, 1, 1);
	glVertex3d(50, 50, 0);
	glVertex3d(50, 650, 0);
	glVertex3d(650, 50, 0);
	glVertex3d(650, 650, 0);
	glVertex3d(50, 50, 0);
	glVertex3d(650, 50, 0);
	glVertex3d(50, 650, 0);
	glVertex3d(650, 650, 0);
	glEnd();	
	glBegin(GL_QUADS);
	glColor3d(0.85, 0.85, 0);
	glVertex2f(51, 649);
	glVertex2f(51, 51);
	glVertex2f(649, 51);
	glVertex2f(649, 649);
	glEnd();
}

void Painter::drawText(const char *text, int length, int x, int y)
{
	glColor3d(1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 700, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i<length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
	delete[] matrix;
}