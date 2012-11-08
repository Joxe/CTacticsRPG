#ifndef GUI_H
#define GUI_H

#include "Game.h"

class Game;

class GUI {
	public:
		GUI(Game* a_game) : m_game(*a_game) { }
		virtual void load() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual bool mouseOverGUI() = 0;
	protected:
		bool m_collidedWithGui;
		Game& m_game;
		//TODO Lua
		//std::map<std::string, GUIAddon> m_addons;
};

#endif