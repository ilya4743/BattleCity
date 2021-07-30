#pragma once
#include <GL\glut.h>
class Painter
{
public:
	static void DrawTank(int x, int y, int p, bool enemy);
	static void DrawBullet(int x, int y);
	static void DrawWall(int x, int y,int p);
	static void DrawField();
	static void drawText(const char *text, int length, int x, int y);
};