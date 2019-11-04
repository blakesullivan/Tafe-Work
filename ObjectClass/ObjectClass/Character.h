//Blake Sullivan - Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Object.h"
#include "CharStats.h"
#include <string>
using namespace std;

class Character : public Object
{
private:
	int m_iCharID;
	string m_sName;
	bool m_bInGame;
	bool m_bIsBot;
	CharStats m_cStats;

public:
	Character();

	void Init(int cID, float x, float y, string name);
	void LoadCharDiff(int cID);

	void Draw(SDL_Surface* screen, float fDeltaTime);
	void Update(float fDeltaTime);
	void Collide(int type, int id, int damage);
	void Dispose();

	void MoveCharacter(char cDir, float fdt);
	void MoveLeft(float fdt, int speedMult);
	void MoveRight(float fdt, int speedMult);
	void MoveUp(float fdt, int speedMult);
	void MoveDown(float fdt, int speedMult);
	void RotateLeft(float fdt, int speedMult);
	void RotateRight(float fdt, int speedMult);

	void SetCharID(int);
	void SetName(string);
	void SetInGame(bool);
	void SetIsBot(bool);

	int GetCharID();
	string GetName();
	CharStats* GetStats();
	bool GetInGame();
	bool GetIsBot();
};

#endif