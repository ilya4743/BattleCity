#pragma once
#include "BoxCollider.h"
#include <fstream>

class Bullet :public Point
{
protected:
	int speed;	
	int p;		//направление движения 1-вверх, 2-право, 3-влево, 4-вниз
	bool enemy;	//вражеская пуля или нет
public:
	BoxCollider Collider;

	Bullet();
	Bullet(int xn, int yn, int s, int pn, BoxCollider bc, bool en);
	Bullet(const Bullet &a);

	int GetSpeed() { return speed; }
	void SetSpeed(int s) { speed = s; }
	int GetP() { return p; }
	void SetP(int pn) { p = pn; }
	bool GetEnemy() { return enemy; }
	void SetEnemy(bool en) { enemy = en; }

	void MoveBullet();	//движение пули

	friend istream &operator >> (istream &in, Bullet &c); //ввод из файла
};

class Wall :public Point
{
private:
	int type;	//тип стены 1-непробивая, 2-кирпичная, 3-вода 
public:
	BoxCollider WallCollider;

	Wall();
	Wall(int xn, int yn, int t, BoxCollider bc);
	Wall(const Wall &a);

	int GetType() { return type; }
	void SetType(int t) { type = t; }

	friend istream &operator >> (istream &in, Wall &c); //ввод из файла
};