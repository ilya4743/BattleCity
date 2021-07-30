#pragma once
#include "Painter.h"
#include "Tank.h"

using namespace std;

class Game
{
public:
	const int ScreenSizeX = GetSystemMetrics(SM_CXSCREEN);
	const int ScreenSizeY = GetSystemMetrics(SM_CYSCREEN);
	const int WindowSizeX = 800;	//Размер окна с игрой
	const int WindowSizeY = 700;	//Размер окна с игрой
	
	short int Score;	//Счёт
	short int Waves;	//Волны
	short int state;	//Состояние игры 0-обычная 1-Поражение 2-Новая волна
	//Переменные необходимые для подсчёта FPS
	char FPS[10];
	int frame;			
	int time;
	int timebase;
	
	Tank t;							//танк игрока
	vector<Bullet> ArrayOfBullet;	//массив всех пуль в игре
	vector<Tank> ArrayOfBots;		//массив всех ботов
	vector<Wall> ArrayOfWall;		//массив всех стен
	Controls keyboard;				//подключение управления
	
	Game();
	void Restart();				//перезапуск игры после поражения
	void Respawn();				//респавн игрока после попадания в него пули
	void GameOver();			//Поражение
	void LoadLevel();			//Загрузка уровня
	void OtherGameObjects();	//Обработка всего, что происходит с другими объектами
	void Bullets();				//Обработка всего, что происходит с пулями
	void Player();				//Обработка всего, что происходит с игроком
	void Bots();				//Обработка всего, что происходит с ботами
};