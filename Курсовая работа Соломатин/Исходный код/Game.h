#pragma once
#include "Painter.h"
#include "Tank.h"

using namespace std;

class Game
{
public:
	const int ScreenSizeX = GetSystemMetrics(SM_CXSCREEN);
	const int ScreenSizeY = GetSystemMetrics(SM_CYSCREEN);
	const int WindowSizeX = 800;	//������ ���� � �����
	const int WindowSizeY = 700;	//������ ���� � �����
	
	short int Score;	//����
	short int Waves;	//�����
	short int state;	//��������� ���� 0-������� 1-��������� 2-����� �����
	//���������� ����������� ��� �������� FPS
	char FPS[10];
	int frame;			
	int time;
	int timebase;
	
	Tank t;							//���� ������
	vector<Bullet> ArrayOfBullet;	//������ ���� ���� � ����
	vector<Tank> ArrayOfBots;		//������ ���� �����
	vector<Wall> ArrayOfWall;		//������ ���� ����
	Controls keyboard;				//����������� ����������
	
	Game();
	void Restart();				//���������� ���� ����� ���������
	void Respawn();				//������� ������ ����� ��������� � ���� ����
	void GameOver();			//���������
	void LoadLevel();			//�������� ������
	void OtherGameObjects();	//��������� �����, ��� ���������� � ������� ���������
	void Bullets();				//��������� �����, ��� ���������� � ������
	void Player();				//��������� �����, ��� ���������� � �������
	void Bots();				//��������� �����, ��� ���������� � ������
};