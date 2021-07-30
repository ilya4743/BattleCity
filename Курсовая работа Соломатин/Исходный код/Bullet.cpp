#include "Bullet.h"

//Методы класса Bullet
Bullet::Bullet() :Point()
{
	speed = 0;
	p = 0;
	enemy = false;
}

Bullet::Bullet(int xn, int yn, int s, int pn, BoxCollider bc, bool en) :Point(xn, yn)
{
	speed = s;
	p = pn;
	Collider = bc;
	enemy = en;
}

Bullet::Bullet(const Bullet &a) :Point(a)
{
	speed = a.speed;
	p = a.p;
	Collider = a.Collider;
	enemy = a.enemy;
}

void Bullet::MoveBullet()
{
	switch (p)
	{
	case 1:
		this->y = this->y + speed;
		break;
	case 2:
		this->x = this->x + speed;
		break;
	case 3:
		this->x = this->x - speed;
		break;
	case 4:
		this->y = this->y - speed;
		break;
	}
	Collider.SetBoxCollider(Point(this->x - 2, this->y - 2), Point(this->x + 2, this->y + 2));
}

istream &operator >> (istream &in, Bullet &c)
{
	in >> (Point)c >> c.Collider >> c.speed >> c.p >> c.enemy;
	return in;
}

//Методы класса Wall
Wall::Wall() :Point()
{
	type = 0;
}

Wall::Wall(int xn, int yn,int t, BoxCollider bc) :Point(xn, yn)
{
	type = t;
	WallCollider = bc;
}

Wall::Wall(const Wall &a):Point(a)
{
	type = a.type;
	WallCollider = a.WallCollider;
}

istream &operator >> (istream &in, Wall &c)
{
	in >> c.x >> c.y;
	in >> c.WallCollider >> c.type;
	return in;
}