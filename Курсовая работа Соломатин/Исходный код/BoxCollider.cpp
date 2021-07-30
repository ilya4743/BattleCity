#include "BoxCollider.h"
#include <fstream>

//Методы класса Point
Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int xn, int yn)
{
	x = xn;
	y = yn;
}

Point::Point(const Point &a)
{
	x = a.x;
	y = a.y;
}


istream &operator >> (istream &in, Point &c)
{
	in >> c.x >> c.y;
	return in;
}

//Методы класса BoxCollider
BoxCollider::BoxCollider()
{
	DLP.SetX(0);
	DLP.SetY(0);
	URP.SetX(0);
	URP.SetY(0);
}

BoxCollider::BoxCollider(int x1, int y1, int x2, int y2)
{
	DLP.SetX(x1);
	DLP.SetY(y1);
	URP.SetX(x2);
	URP.SetY(y2);
}

BoxCollider::BoxCollider(Point a1, Point a2)
{
	DLP = a1;
	URP = a2;
}

void BoxCollider::SetBoxCollider(Point a1, Point a2)
{
	DLP = a1;
	URP = a2;
}

bool BoxCollider::operator && (BoxCollider &c)
{
	return (URP.GetY() >= c.GetDLP().GetY()) && (DLP.GetY() <= c.GetURP().GetY()) && (URP.GetX() >= c.GetDLP().GetX()) && (DLP.GetX() <= c.GetURP().GetX());
}

BoxCollider::BoxCollider(const BoxCollider &b)
{
	DLP = b.DLP;
	URP = b.URP;
}

istream &operator >> (istream &in, BoxCollider &c)
{
	in >> c.DLP >> c.URP;
	return in;
}