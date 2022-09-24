/*
Ramsha Bilal
bilal_week5_gp
Game Project 5
main.cpp
PC
*/
#include <iostream>
#include <string> 
#include<sstream>
#include<fstream>
#include "SceneClass.h"
using namespace std;

void game();
bool debugIt = false;
int main() 
{
	game();
	return 0; 
}

/*
contains the program for the game
reads the file into a dynamic array of Scene objects
each scene has corresponsing prompts and next scenes to jump to
debug version displays the contents of the array. 
a loop asks displays a scene, asks user to choose from one of two prompts and 
jumps to the next scene accordingly until @0 is encountered. 
*/
void game()
{
	int answer=0; 
	cout << "Would you like to debug? Press 1 for yes, 0 for no. " << endl;
	cin >> answer;
	if (answer == 1)
		debugIt = true;
	string scene, prompt1, prompt2;
	Scene* scenesArray, * startArray;
	const int SIZE = 20;
	scenesArray = new Scene[SIZE];  // ZERO TO NINE SUBTRACT ONE LATER TO ACCESS THE CORRECT SCENES
	startArray = scenesArray;
	int i = 0;
	
	ifstream inFile;
	inFile.open("Text.txt");
	if (inFile.fail())
		cout << "File couldn't open";
	int noOfLoops = 0;
	while (!inFile.eof())
	{
		getline(inFile, scene);
		if (scene.substr(0, 2) == "@s")
		{
			scenesArray->setScene(scene);
			scenesArray++;
		}
	}
	inFile.close();

	scenesArray = startArray;
	inFile.open("Text.txt");
	while (!inFile.eof())
	{
		getline(inFile, scene);
		if (scene.substr(0, 2) == "@p")
		{
			if (scene.substr(0, 3) == "@p1")
			{
				scenesArray->prompts[0] = scene;
			}
			else if (scene.substr(0, 3) == "@p2")
			{
				scenesArray->prompts[1] = scene;
				scenesArray++;
			}
		}
		else if (scene.substr(0, 2) == "@0")
		{
			scenesArray->prompts[0] = scene;
			scenesArray->prompts[1] = scene;
			scenesArray++;
		}

	}
	
	inFile.close();

	scenesArray = startArray;
	inFile.open("Text.txt");
	while (!inFile.eof())
	{
		getline(inFile, scene);
		if (!(scene.substr(0, 1) == "@"))
		{
			stringstream geek(scene);
			int x = 0;
			geek >> x;
			if (scenesArray->jumpTo[0] == -1)
				scenesArray->jumpTo[0] = x;

			else
			{
				scenesArray->jumpTo[1] = x;
				scenesArray++;
			}
		}
	}
	inFile.close();

	scenesArray = startArray;
	
	if (debugIt == true) 
	{
		//display array - debug version 
		for (int i = 0; i < 10; i++)
		{
			cout << scenesArray->getScene() << endl << endl
				<< scenesArray->prompts[0] << endl << endl
				<< scenesArray->jumpTo[0] << endl << endl
				<< scenesArray->prompts[1] << endl << endl
				<< scenesArray->jumpTo[1] << endl << endl;
			scenesArray++;
		}

		scenesArray = startArray;
	}

	int index = 0;
	bool stop = false; 
	while (scenesArray[index].prompts[0] != "@0")
	{
		cout << scenesArray[index].m_scene << endl;
		cout << "Choice 1: " << scenesArray[index].prompts[0] << endl
			<< "Choice 2: " << scenesArray[index].prompts[1] << endl << endl;
		cout << "Pick your choice. (press 1 or 2 accordingly.)" << endl;
		int response = 0;
		
		while (response != 1 && response != 2)
		{
			cin >> response;
			if (response == 1)
				index = (scenesArray[index].jumpTo[0]-1);
			else if (response == 2)
				index = (scenesArray[index].jumpTo[1]-1);
			else
				cout << "Pick a valid choice." << endl;
		}
	} 
		cout << scenesArray[index].m_scene << endl;
		delete[]startArray;
}



