#pragma once

class Controls
{
public:
	bool keyPressedUp;		
	bool keyPressedDown;
	bool keyPressedRight;
	bool keyPressedLeft;
	bool keyPressedFire;

	Controls();

	static void KeyboardDown(unsigned char k, int x, int y);
	static void	KeyboardUp(unsigned char k, int x, int y);
	static void	KeyboardSpecialUp(int k, int x, int y);
	static void KeyboardSpecialDown(int key, int, int);

	static void SetKeyPressedUp(Controls &k, bool s) { k.keyPressedUp = s; }
	static void SetKeyPressedDown(Controls &k, bool s) { k.keyPressedDown = s; }
	static void SetKeyPressedRight(Controls &k, bool s) { k.keyPressedRight = s; }
	static void SetKeyPressedLeft(Controls &k, bool s) { k.keyPressedLeft = s; }
	static void SetKeyPressedFire(Controls &k, bool s) { k.keyPressedFire = s; }
};