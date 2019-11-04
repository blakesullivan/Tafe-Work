//Blake Sullivan - ButtonManager.cpp
#include "ButtonManager.h"
ButtonManager::ButtonManager()
{
	//m_vButtons.clear();
	//m_vButtons = new vector<Button>;
}

ButtonManager::~ButtonManager()
{

}

void ButtonManager::AddButton(int x, int y, std::string t, unsigned int w, unsigned int h, Colours cN, Colours cH, Colours cD)
{
	int id = 0;
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
		{id++;}

	Button temp(w, h);
	temp.Init(x, y, id, t);
	temp.SetStateColours(buttonNorm, cN.iRed, cN.iGreen, cN.iBlue, cN.iAlpha);
	temp.SetStateColours(buttonHighlight, cH.iRed, cH.iGreen, cH.iBlue, cH.iAlpha);
	temp.SetStateColours(buttonDown, cD.iRed, cD.iGreen, cD.iBlue, cD.iAlpha);
	m_vButtons.push_back(temp);
}
void ButtonManager::AddColours(unsigned int id, int colState, int red, int green, int blue, int alpha)
{
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		if (m_vButtonsIT->GetID() == id)
		{
			m_vButtonsIT->SetStateColours(colState, red, green, blue, alpha);
			break;
		}
	}
}

void ButtonManager::UpdateButton(int mouseX, int mouseY)
{
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		if (m_vButtonsIT->GetState() != buttonDown)
		{
			if (mouseX > m_vButtonsIT->GetX() && mouseX < m_vButtonsIT->GetX() + m_vButtonsIT->GetWidth())
			{
				if (mouseY > m_vButtonsIT->GetY() && mouseY < m_vButtonsIT->GetY() + m_vButtonsIT->GetHeight())
					{m_vButtonsIT->SetState(buttonHighlight);}
				else
					{m_vButtonsIT->SetState(buttonNorm);}
			}
			else
				{m_vButtonsIT->SetState(buttonNorm);}
		}
	}
}
void ButtonManager::ButtonPressed(int mouseX, int mouseY)
{
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		if (mouseX > m_vButtonsIT->GetX() && mouseX < m_vButtonsIT->GetX() + m_vButtonsIT->GetWidth())
		{
			if (mouseY > m_vButtonsIT->GetY() && mouseY < m_vButtonsIT->GetY() + m_vButtonsIT->GetHeight())
			{
				m_vButtonsIT->SetState(buttonDown);
				m_vButtonsIT->SetPressed(true);
				break;
			}
		}
	}
}

int ButtonManager::CheckButtonPressed()
{
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		if (m_vButtonsIT->GetPressed() == true)
		{
			return m_vButtonsIT->GetID();
		}
	}
	return -1;
}

void ButtonManager::ButtonUnPressed(int id)
{
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		if (m_vButtonsIT->GetID() == id)
		{
			m_vButtonsIT->SetPressed(false);
		}
	}
}

void ButtonManager::DrawButton(SDL_Surface* screen)
{
	for (m_vButtonsIT = m_vButtons.begin(); m_vButtonsIT != m_vButtons.end(); m_vButtonsIT++)
	{
		boxRGBA(screen, m_vButtonsIT->GetX(), m_vButtonsIT->GetY(), 
				m_vButtonsIT->GetX() + m_vButtonsIT->GetWidth(),
				m_vButtonsIT->GetY() + m_vButtonsIT->GetHeight(),
				m_vButtonsIT->GetRed(m_vButtonsIT->GetState()),
				m_vButtonsIT->GetGreen(m_vButtonsIT->GetState()),
				m_vButtonsIT->GetBlue(m_vButtonsIT->GetState()),
				m_vButtonsIT->GetAlpha(m_vButtonsIT->GetState())
				);
		dt.DrawTextToSurface(screen, m_vButtonsIT->GetText().c_str(), m_vButtonsIT->GetX() + 5, m_vButtonsIT->GetY() + (m_vButtonsIT->GetHeight() / 2));
	}
}