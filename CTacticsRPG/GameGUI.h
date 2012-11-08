#ifndef GAMEGUI_H
#define GAMEGUI_H

#include "GUI.h"
#include "Game.h"

class GameGUI : protected GUI {
	public:
		GameGUI(Game*);
		~GameGUI();
		enum GUIState {
			Normal, AttackTarget, Move, SelectFacing, UseAbility, ActionMenu
		};
		GUIState getGUIState();
		void load();
		void update();
		void draw();
	private:
		GUIState m_guiState;
};

#endif