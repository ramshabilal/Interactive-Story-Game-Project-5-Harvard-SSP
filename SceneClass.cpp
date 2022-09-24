/*
Ramsha Bilal
bilal_week5_gp
Game Project 5
SceneClass.cpp
PC
*/
#include "SceneClass.h"

// default constructor for Scene Class
Scene::Scene(){}

//accessor and mutatator for m_scene 
// (i may not use these and keep members public for this code

string Scene:: getScene()
{
	return m_scene;
}
void Scene::setScene(string scene)
{
	m_scene = scene;
}
