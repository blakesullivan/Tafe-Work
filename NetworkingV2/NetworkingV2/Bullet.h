//Blake Sullivan - Bullet.h
#ifndef BULLET_H
#define BULLET_H

class Bullet
{
private:
	float m_fX, m_fY, m_fDirection;
	float m_fDamage;
	float m_fMoveSpeed;
	float m_fSize;
	float m_fLife;
	int m_iMaxLife;

public:
	Bullet();

	void Init(float x, float y, float dir, int ml, float dam, float ms, float size);
	void MoveBullet(float fdt);

	void SetX(float x);
	void SetY(float y);
	void SetDirection(float d);
	void SetDamage(float d);
	void SetMoveSpeed(float ms);
	void SetSize(float s);
	void SetLife(float l);
	void SetMaxLife(int ml);

	float GetX();
	float GetY();
	float GetDirection();
	float GetDamage();
	float GetMoveSpeed();
	float GetSize();
	float GetLife();
	int GetMaxLife();
};
#endif