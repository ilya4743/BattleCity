#include"Control.h"
#include<windows.h>
#include"Game.h"

extern Game G1;

Controls::Controls()
{
	keyPressedUp = 0;
	keyPressedDown = 0;
	keyPressedRight = 0;
	keyPressedLeft = 0;
	keyPressedFire = 0;
}

void Controls::KeyboardSpecialDown(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		SetKeyPressedUp(G1.keyboard, false);
		SetKeyPressedDown(G1.keyboard, false);
		SetKeyPressedRight(G1.keyboard, false);
		SetKeyPressedLeft(G1.keyboard, true);
		break;
	case GLUT_KEY_UP:
		SetKeyPressedUp(G1.keyboard, true);
		SetKeyPressedDown(G1.keyboard, false);
		SetKeyPressedRight(G1.keyboard, false);
		SetKeyPressedLeft(G1.keyboard, false);
		break;
	case GLUT_KEY_RIGHT:
		SetKeyPressedUp(G1.keyboard, false);
		SetKeyPressedDown(G1.keyboard, false);
		SetKeyPressedRight(G1.keyboard, true);
		SetKeyPressedLeft(G1.keyboard, false);
		break;
	case GLUT_KEY_DOWN:
		SetKeyPressedUp(G1.keyboard, false);
		SetKeyPressedDown(G1.keyboard, true);
		SetKeyPressedRight(G1.keyboard, false);
		SetKeyPressedLeft(G1.keyboard, false);
		break;
	}
}

void Controls::KeyboardDown(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'w':
		SetKeyPressedUp(G1.keyboard, true);
		SetKeyPressedDown(G1.keyboard, false);
		SetKeyPressedRight(G1.keyboard, false);
		SetKeyPressedLeft(G1.keyboard, false);
		break;
	case 'd':
		SetKeyPressedUp(G1.keyboard, false);
		SetKeyPressedDown(G1.keyboard, false);
		SetKeyPressedRight(G1.keyboard, true);
		SetKeyPressedLeft(G1.keyboard, false);
		break;
	case 'a':
		SetKeyPressedUp(G1.keyboard, false);
		SetKeyPressedDown(G1.keyboard, false);
		SetKeyPressedRight(G1.keyboard, false);
		SetKeyPressedLeft(G1.keyboard, true);
		break;
	case 's':
		SetKeyPressedUp(G1.keyboard, false);
		SetKeyPressedDown(G1.keyboard, true);
		SetKeyPressedRight(G1.keyboard, false);
		SetKeyPressedLeft(G1.keyboard, false);
		break;
	case 'l':
		SetKeyPressedFire(G1.keyboard, true);
		break;
	case 'r':
		G1.Restart();
		break;
	case 27:
		exit(0);
		break;
	}
}

void Controls::KeyboardSpecialUp(int k, int x, int y)
{
	switch (k)
	{	
	case GLUT_KEY_LEFT:
		SetKeyPressedLeft(G1.keyboard, false);
	break;
	case GLUT_KEY_UP:
		SetKeyPressedUp(G1.keyboard, false);
		break;
	case GLUT_KEY_RIGHT:
		SetKeyPressedRight(G1.keyboard, false);
		break;
	case GLUT_KEY_DOWN:
		SetKeyPressedDown(G1.keyboard, false);
		break;
	}
}

void Controls::KeyboardUp(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'w':
		SetKeyPressedUp(G1.keyboard, false);
		break;

	case 'd':
		SetKeyPressedRight(G1.keyboard, false);
		break;

	case 'a':
		SetKeyPressedLeft(G1.keyboard, false);
		break;

	case 's':
		SetKeyPressedDown(G1.keyboard, false);
		break;

	case 'l':
		SetKeyPressedFire(G1.keyboard, false);
		break;

	case 27:
		exit(0);
		break;
	}
}