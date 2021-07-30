#define _CRT_SECURE_NO_WARNINGS
#include<thread>
#include"Tank.h"

using namespace std;

//Методы класса Tank
Tank::Tank() :Bullet()
{
	hp = 0;
	enemy = false;
	attack = false;
}

Tank::Tank(int xn, int yn, int hpn, int s, int pn, bool en, bool at, BoxCollider bc) :Bullet(xn, yn, s, pn, bc, en)
{
	hp = hpn;
	attack = at;
}

Tank::Tank(const Tank &a) :Bullet(a)
{
	hp = a.hp;
	attack = a.attack;
}

void ShootСooldown(int Cooldown, vector<Bullet> &b, Tank &a)
{
	b.insert(b.end(), Bullet());
	a.SetAttack(true);
	switch (a.GetP())
	{
	case 1:
		b.back().SetX(a.GetX());
		b.back().SetY(a.GetY()+11);
		break;
	case 2:
		b.back().SetX(a.GetX()+11);
		b.back().SetY(a.GetY());
		break;
	case 3:
		b.back().SetX(a.GetX()-11);
		b.back().SetY(a.GetY());
		break;
	case 4:
		b.back().SetX(a.GetX());
		b.back().SetY(a.GetY()-11);
		break;
	}
	b.back().SetP(a.GetP());
	b.back().SetSpeed(5);
	if (a.GetEnemy() == true)
		b.back().SetEnemy(true);
	else
		b.back().SetEnemy(false);
	b.back().Collider.SetBoxCollider(Point(a.GetX() - 2, a.GetY() - 2), Point(a.GetX() + 2, a.GetY() + 2));
	Sleep(Cooldown);
	a.SetAttack(false);
}

void Tank::Shoot(int Cooldown, vector<Bullet> &b, Tank &a)
{
	thread Coold(ShootСooldown, Cooldown, ref(b), ref(a));
	Coold.detach();
}

void Tank::FindTarget(Tank pl, Tank &ii)
{
	thread v(FT, pl, ref(ii));
	v.detach();
}

void Tank::ChangeCol()
{
	switch (p)
	{
	case 1:
		Collider.SetBoxCollider(Point(x - 10, y - 10), Point(x + 10, y + 11));
		break;
	case 2:
		Collider.SetBoxCollider(Point(x - 10, y - 10), Point(x + 11, y + 10));
		break;
	case 3:
		Collider.SetBoxCollider(Point(x - 11, y - 10), Point(x + 10, y + 10));
		break;
	case 4:
		Collider.SetBoxCollider(Point(x - 10, y - 11), Point(x + 10, y + 10));
		break;
	}
}

bool Tank::CheckMoveAi(vector<Wall> &w, vector<Tank> &a, Tank &t)
{
	bool b = false;
	for (int j = 0; j < w.size(); j++)	   //есть ли столкновение со стеной
	{
		b = Collider&&w[j].WallCollider;
		if (b == true) break;
	}
	if (b == false) b=Collider&&t.Collider;	// столкновение с игроком
	if (b == false)
	{
		for (int i = 0; i < a.size(); i++) //есть ли столкновение с ботов с ботами
		{
			b = (Collider&&a[i].Collider) && ((y != a[i].GetY()) || (x != a[i].GetX()));
			if (b == true) break;
		}
	}	
	if (b == false)				//произошёл ли вылет за границы игрового поля
	
		switch (p)
		{
		case 1:
			b = (y >= 650 - 12);
			break;
		case 2:
			b = (x >= 650 - 12);
			break;
		case 3:
			b = (x <= 50 + 12);
			break;
		case 4:
			b = (y <= 50 + 12);
			break;

		}	
	return b;
}

bool Tank::CheckMove(vector<Wall> &w, vector<Tank> &a)
{
	bool b = false;
	for (int j = 0; j < w.size(); j++)	   //есть ли столкновение со стеной
	{
		b = Collider&&w[j].WallCollider;
		if (b == true) break;
	}
	if (b == false)
	{
		for (int i = 0; i < a.size(); i++) //есть ли столкновение с ботов с ботами
		{
			b = (Collider&&a[i].Collider);
			if (b == true) break;
		}
	}
	if (b == false)						//произошёл ли вылет за границы игрового поля

		switch (p)
		{
		case 1:
			b = (y >= 650 - 12);
			break;
		case 2:
			b = (x >= 650 - 12);
			break;
		case 3:
			b = (x <= 50 + 12);
			break;
		case 4:
			b = (y <= 50 + 12);
			break;

		}
	return b;
}

void Tank::MoveUp(vector<Wall> &w, vector<Tank> &a)
{
	short int s = 0;
	p = 1;
	Collider.SetBoxCollider(Point(x - 10, y - 10), Point(x + 10, y + 11));
	while (CheckMove(w, a) == false && s != speed)
	{
		s++;
		y = y + 1;
		ChangeCol();
	}
	if (CheckMove(w, a) != false && this->enemy == true)
		p = 1 + rand() % 4;
	ChangeCol();
}

void Tank::MoveRight(vector<Wall> &w, vector<Tank> &a)
{
	short int s = 0;
	p = 2;
	Collider.SetBoxCollider(Point(x - 10, y - 10), Point(x + 11, y + 10));
	while (CheckMove(w, a) == false && s != speed)
	{
		s++;
		x = x + 1;
		ChangeCol();
	}
	if (CheckMove(w, a) != false && this->enemy == true)
		p = 1 + rand() % 4;
	ChangeCol();
}

void Tank::MoveLeft(vector<Wall> &w, vector<Tank> &a)
{
	short int s = 0;
	p = 3;
	Collider.SetBoxCollider(Point(x - 11, y - 10), Point(x + 10, y + 10));
	while (CheckMove(w, a) == false && s != speed)
	{
		s++;
		x = x - 1;
		ChangeCol();
	}
	if (CheckMove(w, a) != false && this->enemy == true)
		p = 1 + rand() % 4;
	ChangeCol();
}

void Tank::MoveDown(vector<Wall> &w, vector<Tank> &a)
{
	short int s = 0;
	p = 4;
	Collider.SetBoxCollider(Point(x - 10, y - 11), Point(x + 10, y + 10));
	while (CheckMove(w, a) == false && s != speed)
	{
		s++;
		y = y - 1;
		ChangeCol();
	}
	if (CheckMove(w, a) != false && this->enemy == true)
		p = 1 + rand() % 4;
	ChangeCol();
}

void Tank::MoveUpAi(vector<Wall> &w, vector<Tank> &a, Tank &t)
{
	short int s = 0;
	p = 1;
	Collider.SetBoxCollider(Point(x - 10, y - 10), Point(x + 10, y + 11));
	while (CheckMoveAi(w, a,t) == false && s != speed)
	{
			s++;
			y = y + 1;
			ChangeCol();
	}
	if (CheckMoveAi(w, a,t) != false && this->enemy == true)
		p = 1 + rand() % 4;
	ChangeCol();
}

void Tank::MoveRightAi(vector<Wall> &w, vector<Tank> &a, Tank &t)
{
	short int s = 0;
	p = 2;
	Collider.SetBoxCollider(Point(x - 10, y - 10), Point(x + 11, y + 10));
	while (CheckMoveAi(w, a, t) == false && s != speed)
	{
		s++;
		x = x + 1;
		ChangeCol();
	}
	if (CheckMoveAi(w, a, t) != false && this->enemy == true)
		p = 1 + rand() % 4;
	ChangeCol();
}

void Tank::MoveLeftAi(vector<Wall> &w, vector<Tank> &a, Tank &t)
{
	short int s = 0;
	p = 3;
	Collider.SetBoxCollider(Point(x - 11, y - 10), Point(x + 10, y + 10));
	while (CheckMoveAi(w, a, t) == false && s != speed)
	{
		s++;
		x = x - 1;
		ChangeCol();
	}
	if (CheckMoveAi(w, a, t) != false && this->enemy == true)
		p = 1 + rand() % 4;
	ChangeCol();
}

void Tank::MoveDownAi(vector<Wall> &w, vector<Tank> &a, Tank &t)
{
	short int s = 0;
	p = 4;
	Collider.SetBoxCollider(Point(x - 10, y - 11), Point(x + 10, y + 10));
	while (CheckMoveAi(w, a, t) == false && s != speed)
	{
		s++;
		y = y - 1;
		ChangeCol();
	}
	if (CheckMoveAi(w, a, t) != false && this->enemy == true)
		p = 1 + rand() % 4;
	ChangeCol();
}

void Tank::MoveAi(vector<Wall> &w, vector<Tank> &tI, Tank &t)
{
	switch (p)
	{
	case 1:
		this->MoveUpAi(w, tI, t);
		break;
	case 2:
		this->MoveRightAi(w, tI, t);
		break;
	case 3:
		this->MoveLeftAi(w, tI, t);
		break;
	case 4:
		this->MoveDownAi(w, tI, t);
		break;
	}
}

void Tank::MovePlayer(Controls k, vector<Wall> &w, vector<Tank> &tI)
{
	if (k.keyPressedUp == true)
		MoveUp(w, tI);
	if (k.keyPressedDown == true)
		MoveDown(w, tI);
	if (k.keyPressedRight == true)
		MoveRight(w, tI);
	if (k.keyPressedLeft == true)
		MoveLeft(w, tI);
}

istream &operator >> (istream &in, Tank &c)
{
	in >> c.x >> c.y;
	in >> c.Collider;
	in >> c.speed >> c.p >> c.enemy >> c.hp >> c.attack;
	return in;
}

void FT(Tank pl, Tank &ii)
{
	ii.SetTarget(true);
	int num;
	srand(time(NULL));
	num = rand() % 2;
	if (num == 0) {
		if (ii.GetX() > pl.GetX() && ii.GetY() != pl.GetY())ii.SetP(3);
		if (ii.GetX() < pl.GetX() && ii.GetY() != pl.GetY())ii.SetP(2);
		if (ii.GetX() == pl.GetX())
			if (ii.GetY() > pl.GetY()) ii.SetP(4);
			else ii.SetP(1);
	}
	if (num == 1) {
		if (ii.GetY() > pl.GetY() && ii.GetX() != pl.GetX())ii.SetP(4);
		if (ii.GetY() < pl.GetY() && ii.GetX() != pl.GetX())ii.SetP(1);
		if (ii.GetY() == pl.GetY())
			if (ii.GetX() > pl.GetX()) ii.SetP(3);
			else ii.SetP(2);
	}
	short int j;
	j = 1000 + rand() % 200;
	Sleep(j);
	ii.SetTarget(false);
}