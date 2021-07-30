#pragma once
#include <vector>
#include <ctime>
#include<Windows.h>
#include"BoxCollider.h"
#include"Bullet.h"
#include"Control.h"

class Tank :public Bullet
{
private:
	int hp;
	bool attack;	
	bool target=false;
	void ChangeCol();
	bool CheckMoveAi(vector<Wall> &w, vector<Tank> &a, Tank &t);
	bool CheckMove(vector<Wall> &w, vector<Tank> &a);
	void MoveUpAi(vector<Wall> &w, vector<Tank> &a, Tank &t);
	void MoveRightAi(vector<Wall> &w, vector<Tank> &a, Tank &t);
	void MoveLeftAi(vector<Wall> &w, vector<Tank> &a, Tank &t);
	void MoveDownAi(vector<Wall> &w, vector<Tank> &a, Tank &t);
	void MoveUp(vector<Wall> &w, vector<Tank> &a);
	void MoveRight(vector<Wall> &w, vector<Tank> &a);
	void MoveLeft(vector<Wall> &w, vector<Tank> &a);
	void MoveDown(vector<Wall> &w, vector<Tank> &a);

public:	
	Tank();
	Tank(int xn, int yn, int hpn, int s, int pn, bool at, bool en, BoxCollider bc);
	Tank(const Tank &a);
	
	int GetHp() { return hp; }
	void SetHp(int h) { hp = h; }
	bool GetAttack() { return attack; }
	void SetAttack(bool at) { attack = at; }
	bool GetTarget() { return target; }
	void SetTarget(bool t) { target = t; }

	void Shoot(int Cooldown, vector<Bullet> &b, Tank &a);
	void MoveAi(vector<Wall> &w, vector<Tank> &tI, Tank &t);
	void MovePlayer(Controls k, vector<Wall> &w, vector<Tank> &tI);
	void FindTarget(Tank pl, Tank &ii);

	friend istream &operator >> (istream &in, Tank &c);
	friend void Shoot—ooldown(int Cooldown,vector<Bullet> &b, Tank &a);	
	friend void FT(Tank pl, Tank &ii);
};