//Blake Sullivan - Player.h
#ifndef PLAYER_H
#define PLAYER_H

//#include <math.h>
#include "SDL_gfxPrimitives.h"
#include "Bullet.h"
#include "PlayerStats.h"
#include <string>
using std::string;
#include <vector>
using std::vector;

class Player
{
private:
	static int ms_iMyID;
	int m_iCharacterID;
	float m_fX, m_fY;
	bool m_bAlive, m_bInGame;
	SDL_Surface* m_Character;
	std::string m_sName;
	vector <Bullet> m_vBullets;
	vector <Bullet>::iterator m_vBulletsIT;
	PlayerStats m_pStats;

public:
	Player();
	~Player();

	void Init(int cID, float x, float y, std::string name);
	void LoadCharDiff(int cID);
	
	void AddBullet();
	void DrawBullets(SDL_Surface* screen);

	void MoveBullets(float fdt);
	void MoveLeft(float fdt, int speedMult);
	void MoveRight(float fdt, int speedMult);
	void MoveUp(float fdt, int speedMult);
	void MoveDown(float fdt, int speedMult);

	static void SetMyID(static int);
	void SetX(float);
	void SetY(float);
	void SetCharacterID(int);
	void SetAlive(bool);
	void SetInGame(bool);
	void SetCharacterSurface(std::string);
	void SetName(std::string);

	static int GetMyID();
	float GetX();
	float GetY();
	int GetCharacterID();
	float GetDirection();
	bool GetAlive();
	bool GetInGame();
	SDL_Surface* GetCharacterSurface();
	std::string GetName();
};
#endif