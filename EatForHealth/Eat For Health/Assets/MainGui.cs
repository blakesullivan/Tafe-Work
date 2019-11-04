using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class MainGui : MonoBehaviour 
{
	public int[] iTypeSizes;
	public string[] sVeg;
	public string[] sFruit;
	public string[] sGrain;
	public string[] sMeat;
	public string[] sDairy;
	public string[] sFat;
	public string[] sOther;

	public Rect[] rButtons;
	public GUIContent[] gcButtons;
	public bool[] bButtonPressed;

	public List<bool> lbVeg;
	public List<bool> lbFruit;
	public List<bool> lbGrain;
	public List<bool> lbMeat;
	public List<bool> lbDairy;
	public List<bool> lbFat;
	public List<bool> lbOther;

	// Use this for initialization
	void Start () 
	{

	}
	
	// Update is called once per frame
	void Update () 
	{
		for (int i = 0; i < iTypeSizes.Length; i++)
		{
			rButtons[i] = new Rect(20, 10 + (60 * i), 200, 50);
			if (bButtonPressed[i] == true)
			{

			}
		}


	}

	void OnGUI()
	{
		for (int i = 0; i < rButtons.Length; i++) 
		{
			if (GUI.Button (rButtons[i], gcButtons[i]))
			{
				bButtonPressed[i] = true;
			}
		}
	}
}
