
#include "Player.h"
Player::Player(): iMov(5),fRad(10)
{
	iXo=400;
	iYo=300;	
}

void Player::Move(char cMove)
{
	switch (cMove)
	{
	case 'u':
		if(iYo-iMov>=0+fRad+1)
			iYo-=iMov;
	break;
	case 'd':
		if(iYo+iMov<=600-fRad-1)
			iYo+=iMov;
	break;
	case 'r':
		if(iXo+iMov<=800-fRad-1)
			iXo+=iMov;
	break;
	case 'l':
		if(iXo-iMov>=0+fRad+1)
			iXo-=iMov;
	break;
	default:
		break;
	}

}

//bool Player::CollisionCheck(float BoxX, float BoxY, float BoxS)
//{
//   if(iXo-fRad > BoxX + BoxS)
//      return false;
//   if(iXo-fRad + (fRad*2) < BoxX)
//      return false;
//   if(iYo-fRad> BoxY + BoxS)
//      return false;
//   if(iYo-fRad + (fRad*2) < BoxY)
//      return false;
//   return true;
//}
bool Player::CollisionCheck(float BoxX, float BoxY, float BoxS)
{
  	if (sqrt(pow((BoxX-iXo),2) + pow((BoxY - iYo),2)) <= fRad+ BoxS) 
	{
 		return true;
	}
	else
		return false;

}

void Player::Draw()
{
	//rectangleRGBA(screen,iXo-fRad, iYo-fRad,iXo+fRad,iYo+fRad,0, 0, 255, 255);
	filledEllipseRGBA(screen,iXo, iYo,fRad,fRad,255, 0, 0, 255);

}