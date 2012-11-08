#ifndef STATE_H
#define STATE_H

#include "Game.h"
#include "include\SDL.h"
#include "GameObject.h"
#include "ResourceHandler.h"
#include <vector>
#include <map>
#include <string>

class Game;
class GameObject;

class State {
	public:
		State(Game* a_game) : m_game(*a_game) { }
		std::vector<GameObject*> m_gameObjectList;
		Game& m_game;
		virtual bool load() = 0;
		virtual bool update() = 0;
		virtual bool draw() = 0;
};

#endif