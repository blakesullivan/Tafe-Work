//Blake Sullivan - Player.h

#include <iostream>
using std::cout;

class Player
{
private:
	char mc_ID;
	float mf_X, mf_Y;
	float mf_Speed;
	int mi_Size;
	struct PlayerColour
	{
		int iRed;
		int iBlue;
		int iGreen;
		int iAlpha;
	};
	PlayerColour mpc_Colour;

public:
	Player();

	void Init(char id, float x, float y, float s, int size);

	void MovePlayer(char cDir, float fdt);

	void SetID(char id);
	void SetX(float x);
	void SetY(float y);
	void SetSpeed(float s);
	void SetSize(int size);
	void SetColour(int r, int g, int b, int a = 255);

	char GetID();
	float GetX();
	float GetY();
	float GetSpeed();
	int GetSize();
	int GetRed();
	int GetGreen();
	int GetBlue();
	int GetAlpha();
};