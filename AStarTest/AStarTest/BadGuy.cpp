#include "BadGuy.h"

BadGuy::BadGuy():Player(0), m_Star((int)cm_sXTiles,(int)cm_sYTiles)
{
	m_bToggleMovement=false;
	m_bPreviousToggle=false;
	m_fAngle=0.0;
	
	ifstream load("SavedMap.txt");
	string ssLine;
	string ssData;
	while (load.good()&&load.eof()==false) //If the file can be opened and not endoffile, read the line and add it to the string
	{
		getline(load,ssLine);
		short sLine=1;
		short sOpac=0;
		short sPass=0;
		short sTile=0;
		sscanf_s(ssLine.c_str()," %d.O: %d P: %d TN: %d",  &sLine,  &sOpac,  &sPass,  &sTile);
		ssData+=(char)(sPass+48);
		ssData+=';';
	}
	load.close();
	m_Star.LoadData(ssData.c_str());
}
void BadGuy::Move(short sTargetX, short sTargetY)	//Calculates where the bad guy should be going when given the target node
{
	if (m_bToggleMovement) //If it's allowed to move
	{

		if (m_bToggleMovement&&!m_bPreviousToggle) //Sets up the path
		{
			m_Star.Manager(m_fX/csm_sTileSize,m_fY/csm_sTileSize,sTargetX/csm_sTileSize,sTargetY/csm_sTileSize);
			//m_Star.Optimise(csm_sTileSize);
			m_bPreviousToggle=m_bToggleMovement;
		}

		float A;
		float B;
		if (m_Star.getNextX()!=sTargetX/csm_sTileSize||m_Star.getNextY()!=sTargetY/csm_sTileSize)
		{
			//Calculates and stores, in a temporary variable, the difference between the bad guy and the next node.
			A=(float)(m_Star.getNextX()*csm_sTileSize)-m_fX+csm_sTileSize/2;
			B=(float)(m_Star.getNextY()*csm_sTileSize)-m_fY+csm_sTileSize/2;

			if (A*A+B*B<100.0)
				m_Star.NextNode();
		}
		else
		{
			A=(float)sTargetX-m_fX;
			B=(float)sTargetY-m_fY;
			
			if (A*A+B*B<9.0)
				m_bToggleMovement=false;
		}
		float fAngle=atan2f(B,A);

		if (ModSteering(fAngle)&&fAngle>0&&m_fAngle<0)
			m_fAngle+=2*M_PI;
		else if (ModSteering(fAngle)&&fAngle<0&&m_fAngle>0)
			m_fAngle-=2*M_PI;

		if (m_fAngle>fAngle+csm_fRotSpeed/2)
			m_fAngle-=csm_fRotSpeed;
		else if (m_fAngle<fAngle-csm_fRotSpeed/2)
			m_fAngle+=csm_fRotSpeed;

		if (m_fAngle>2*M_PI)
			m_fAngle-=2*M_PI;
		else if (m_fAngle<-2*M_PI)
			m_fAngle+=2*M_PI;

		m_fX+=cos(m_fAngle)*csm_sMoveSpeed;
		m_fY+=sin(m_fAngle)*csm_sMoveSpeed;
		DrawDir();
		m_Star.DrawWaypoints(screen,csm_sTileSize);
	}
	else
		m_bPreviousToggle=false;
}
void BadGuy::MovementToggle()
{
	m_bToggleMovement=!m_bToggleMovement;
}
void BadGuy::DrawDir()
{
	lineRGBA(screen,m_fX,m_fY,16*cos(m_fAngle)+m_fX,16*sin(m_fAngle)+m_fY,255,255,255,255);
}
bool BadGuy::ModSteering(float fTargetAngle)
{
	if (fTargetAngle<0&&m_fAngle>0&&m_fAngle-fTargetAngle>M_PI)
		return true;
	else if (fTargetAngle>0&&m_fAngle<0&&fTargetAngle-m_fAngle>M_PI)
		return true;
	return false;
}
bool BadGuy::getMovement()
{
	return m_bToggleMovement;
}
void BadGuy::setPrevious(bool bPrev)
{
	m_bPreviousToggle=bPrev;
}