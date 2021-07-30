#pragma once
#include<iostream>

using namespace std;

class Point
{
protected:
	int x;
	int y;
public:
	int GetX() { return x; }
	void SetX(int xn) { x = xn; }
	int GetY() { return y; }
	void SetY(int yn) { y = yn; }

	Point();
	Point(int xn, int yn);
	Point(const Point &a);

	friend istream &operator >> (istream &in, Point &c);  //���� �� �����
};

class BoxCollider
{
private:
	Point DLP;	//������ ����� �����
	Point URP;  //������ ������ �����
public:
	BoxCollider();
	BoxCollider(int x1, int y1, int x2, int y2);
	BoxCollider(Point a1, Point a2);
	BoxCollider(const BoxCollider &b);

	Point GetDLP() {return DLP;}
	Point GetURP(){return URP;}

	void SetBoxCollider(Point a1, Point a2);

	bool operator && (BoxCollider &c);		//���������� �������� ����������� ���� �����������
	friend istream &operator >> (istream &in, BoxCollider &c);	//���� �� �����
};