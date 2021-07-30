#pragma once
#include "BoxCollider.h"
#include <fstream>

class Bullet :public Point
{
protected:
	int speed;	
	int p;		//����������� �������� 1-�����, 2-�����, 3-�����, 4-����
	bool enemy;	//��������� ���� ��� ���
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

	void MoveBullet();	//�������� ����

	friend istream &operator >> (istream &in, Bullet &c); //���� �� �����
};

class Wall :public Point
{
private:
	int type;	//��� ����� 1-����������, 2-���������, 3-���� 
public:
	BoxCollider WallCollider;

	Wall();
	Wall(int xn, int yn, int t, BoxCollider bc);
	Wall(const Wall &a);

	int GetType() { return type; }
	void SetType(int t) { type = t; }

	friend istream &operator >> (istream &in, Wall &c); //���� �� �����
};