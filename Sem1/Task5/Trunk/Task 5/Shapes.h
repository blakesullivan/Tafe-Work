//Blake Sullivan - Shapes.h
#ifndef SHAPES_H
#define SHAPES_H
#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class Shapes
{
private:
	
public:
	Shapes();
	
	void Init();

	void SetupRectangle();
	void DrawFRectangle(int, int, int, int, int, int, int, int);
	void DrawORectangle(int, int, int, int, int, int, int, int);

	void SetupCircle();
	void DrawFCircle(int, int, int, int, int, int, int, int);
	void DrawOCircle(int, int, int, int, int, int, int, int);

	void SetupTriangle();
	void DrawFTriangle(int, int, int, int, int, int, int, int, int);
	void DrawOTriangle(int, int, int, int, int, int, int, int, int);

	int GenerateRandomNum(int, int);
};
#endif