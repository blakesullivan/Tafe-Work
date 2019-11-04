//Blake Sullivan - GridPiece.h
#ifndef GRIDPIECE
#define GRIDPIECE
#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h" 

class GridPiece
{
private:
	static const int scm_iGridSize = 16;
	int m_iX, m_iY, m_iPicPos;
	bool m_bAlive, m_bChange;
	int m_iXPos, m_iYPos;

public:
	GridPiece();
	~GridPiece();

	void Draw(SDL_Surface, SDL_Surface);
	void SwapCell();

	void Init(const int, const int, const int, const bool, const int, const int);
	void SetX(const int);
	void SetY(const int);
	void SetPicPos(const int);
	void SetAlive(const bool);
	void SetChange(const bool);
	void SetXPos(const int);
	void SetYPos(const int);
	int GetX() const;
	int GetY() const;
	int GetPicPos() const;
	bool GetAlive() const;
	bool GetChange() const;
	int GetXPos() const;
	int GetYPos() const;

};
#endif