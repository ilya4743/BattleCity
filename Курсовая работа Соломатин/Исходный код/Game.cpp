#include"Game.h"
#include<thread>

void NewWave(vector<Tank> &ArrayOfBots, short int & state, short int &Score, short int &Waves, short int h)
{
	Sleep(3000);
	Tank b;
	fstream f2("2.txt", ios::in);
	while (!f2.eof())
	{
		f2 >> b;
		ArrayOfBots.push_back(b);
	};
	f2.close();
	state = 0;
	Score = Score + Waves * 100 + 20 * h;
	Waves++;
}

char* IntToStr(int n)
{
	char temp[10];
	sprintf(temp, "%d", n);
	return(temp);
}

Game::Game()
{
	t = Tank(351, 206, 5, 1, 1, false, false, BoxCollider(Point(351-10, 206-10), Point(351+10, 206+11)));
	Score = 0;
	frame = 0;
	time = 0;
	timebase = 0;
	Waves = 1;
	state = 0;
	LoadLevel();
}

void Game::GameOver()
{	
	Painter::drawText("Game Over", 9, 345, 450);
	char t1[20] = "Score: ";
	strcat(t1, IntToStr(Score));
	Painter::drawText(t1, 20, 355, 400);
	char t2[20] = "Waves: ";
	strcat(t2, IntToStr(Waves));
	Painter::drawText(t2, 20, 355, 350);
	Painter::drawText("Press r to restart or ESC to exit", 33, 270, 300);
}

void Game::OtherGameObjects()
{	
	Painter::DrawField();	//Отрисовываем игровое поле 

	char s1[20] = "Score: ";				//Отрисовываем элементы интерфейса
	strcat(s1, IntToStr(Score));
	Painter::drawText(s1, 20, 660, 600-20);

	char s2[20] = "Health: ";
	strcat(s2, IntToStr(t.GetHp()));
	Painter::drawText(s2, 20, 660, 550-20);

	char s3[20] = "Speed: ";
	strcat(s3, IntToStr(t.GetSpeed()));
	Painter::drawText(s3, 20, 660, 500-20);

	char s4[20] = "Waves: ";
	strcat(s4, IntToStr(Waves));
	Painter::drawText(s4, 20, 660, 450-20);

	char s5[20] = "Enemies: ";
	strcat(s5, IntToStr(ArrayOfBots.size()));
	Painter::drawText(s5, 20, 660, 400-20);
												//Подсчёт FPS
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(FPS, "FPS: %4.2f",
			frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
	Painter::drawText(FPS, 10, 660, 650-20);
												//Отрисовка стен
	for (int q = 0; q < ArrayOfWall.size(); q++)
		Painter::DrawWall(ArrayOfWall[q].GetX(), ArrayOfWall[q].GetY(), ArrayOfWall[q].GetType());	//Отрисовываем стены
}

void Game::Bots()
{
	for (int i = 0; i < ArrayOfBots.size(); i++)
	{
		Painter::DrawTank(ArrayOfBots[i].GetX(), ArrayOfBots[i].GetY(), ArrayOfBots[i].GetP(), ArrayOfBots[i].GetEnemy());	 //Отрисовываем бота

		if (ArrayOfBots[i].GetTarget() == false)ArrayOfBots[i].FindTarget(t, ArrayOfBots[i]);
		ArrayOfBots[i].MoveAi(ArrayOfWall, ArrayOfBots, t);								 //Движение бота
		short int cd = 1500 + rand() % 2000;
		if (ArrayOfBots[i].GetAttack() == false)
			ArrayOfBots[i].Shoot(cd, ArrayOfBullet, ArrayOfBots[i]);				 //Стрельба бота
	}
}		

void Game::Player()
{
	if (t.GetHp() > 0)
		Painter::DrawTank(t.GetX(), t.GetY(), t.GetP(), t.GetEnemy());	//Отрисовываем игрока 
	else
	{
		ArrayOfBots.clear();
		ArrayOfBullet.clear();
		ArrayOfWall.clear();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		state = 1;
	}
	t.MovePlayer(keyboard, ArrayOfWall, ArrayOfBots);					//Движение игрока

	if (t.GetAttack() == false && keyboard.keyPressedFire == true)
		t.Shoot(1000, ArrayOfBullet, t);								//Стрельба игрока
}

void Game::Bullets()
{
	for (int i = 0; i < ArrayOfBullet.size(); i++)
	{
		Painter::DrawBullet(ArrayOfBullet[i].GetX(), ArrayOfBullet[i].GetY());	//Отрисовываем пули
		ArrayOfBullet[i].MoveBullet();											//Движение пуль

		for (int l = 0; l < ArrayOfWall.size(); l++)							//Стрельба по стене
		{
			if (ArrayOfBullet[i].Collider&&ArrayOfWall[l].WallCollider && (ArrayOfWall[l].GetType() == 1 || ArrayOfWall[l].GetType() == 2))
			{
				ArrayOfBullet.erase(ArrayOfBullet.begin() + i);					//Удаляем пулю при столкновении со стеной
				if (ArrayOfWall[l].GetType() == 2)
					ArrayOfWall.erase(ArrayOfWall.begin() + l);
			}
		}

		for (int s = 0; s < ArrayOfBots.size(); s++)					//Стрельба по ботам 
		{
			if ((ArrayOfBullet[i].Collider&&ArrayOfBots[s].Collider) && ArrayOfBullet[i].GetEnemy() == false)
			{
				ArrayOfBullet.erase(ArrayOfBullet.begin() + i);
				ArrayOfBots[s].SetHp(ArrayOfBots[s].GetHp() - 1);
				if (ArrayOfBots[s].GetHp() == 0)
				{
					Score = Score + 100* ArrayOfBots[s].GetSpeed();
					ArrayOfBots.erase(ArrayOfBots.begin() + s);
					if (ArrayOfBots.size() == 0 && state != 2)
					{
						state = 2;
						thread Coold1(NewWave, ref(ArrayOfBots), ref(state), ref(Score), ref(Waves), t.GetHp());
						Coold1.detach();
					}
				}
			}
		}

		if (ArrayOfBullet[i].Collider&&t.Collider&&ArrayOfBullet[i].GetEnemy() == true) //Стрельба по игроку
		{
			ArrayOfBullet.erase(ArrayOfBullet.begin() + i);
			t.SetHp(t.GetHp() - 1);
			Respawn();
		}

		//Вылет пули за пределы экрана
		if (ArrayOfBullet[i].GetX() >= 650 || ArrayOfBullet[i].GetX() <= 50 || ArrayOfBullet[i].GetY() >= 650 || ArrayOfBullet[i].GetY() <= 50)
			ArrayOfBullet.erase(ArrayOfBullet.begin() + i);
	}
}

void Game::LoadLevel()
{
	char ch = 0;
	int i = 0;
	Wall w;
	fstream f1("1.txt", ios::in);
	while (!f1.eof())
	{
		f1 >> w;
		ArrayOfWall.push_back(w);
	};
	f1.close();
	Tank b;
	fstream f2("2.txt", ios::in);
	while (!f2.eof())
	{
		f2 >> b;
		ArrayOfBots.push_back(b);
	};
	f2.close();
}

void Game::Restart()
{
	if (state == 1)
	{
		state = 0;
		t = Tank(351, 206, 5, 1, 1, false, false, BoxCollider(Point(351 - 10, 206 - 10), Point(351 + 10, 206 + 11)));
		LoadLevel();
	}
}

void Game::Respawn()
{
	t.SetX(351);
	t.SetY(206);
	t.SetP(1);
	t.Collider.SetBoxCollider(Point(351 - 10, 206 - 10), Point(351 + 10, 206 + 11));
}