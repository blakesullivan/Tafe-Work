#ifndef BADGUY
#define BADGUY
#define _USE_MATH_DEFINES
#include "Player.h"
#include "WayStar.h"
#include <fstream>
#include <string>
using std::ifstream;
using std::string;

const short cm_sXTiles=25;
const short cm_sYTiles=20;
const float csm_fRotSpeed=0.2;
class BadGuy : public Player
{
private:
	WayStar m_Star;
	float m_fAngle;
	bool m_bToggleMovement, m_bPreviousToggle;
	const static short csm_sMoveSpeed=4, csm_sTileSize=32;

	bool ModSteering(float);
public:
	BadGuy();
	void Move(short,short);
	bool getIdle();
	void MovementToggle();
	void DrawDir();
	bool getMovement();
	void setPrevious(bool);
};
#endif