
class Character
{
public:

	Character();

	void setX(int);
	void setY(int);

	int getX();
	int getY();

	void setAlive(bool);
	bool getAlive();

	void setUserID(int);
	int getUserID();

private:

	int x;
	int y;
	bool alive;
	int userID;

};