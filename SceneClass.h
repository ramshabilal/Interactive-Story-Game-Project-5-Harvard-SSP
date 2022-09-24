/*
Ramsha Bilal
bilal_week5_gp
Game Project 5
SceneClass.h
PC
*/

#ifndef SCENE_CLASS_H
#define SCENE_CLASS_H
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std; 

class Scene
{
public: 
	string m_scene;
	string prompts[2] = {"@0", "@0"};
	int jumpTo[2] = { -1, -1 };
public: 
	Scene();
	string getScene();
	void setScene(string scene);
}; 

#endif