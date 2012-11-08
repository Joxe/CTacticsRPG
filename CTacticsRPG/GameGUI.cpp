#include "GameGUI.h"

void updateMouse(GameGUI::GUIState, Game);

GameGUI::GameGUI(Game* a_game) : GUI(a_game) {
	//TODO sätta state
}

GameGUI::~GameGUI() {

}

void GameGUI::load() {
	//TODO ladda in addons
	//std::map<GUIAddon*>::iterator it;
	//for (it = m_addons.front(); it != m_addons.end(); it++) {
	//it.second() -> load();
	//} 
}

void GameGUI::update() {
	//uppdatera addons
	//std::map<GUIAddon*>::iterator it;
	//for (it = m_addons.front(); it != m_addons.end(); it++) {
	//it.second() -> update();
	//} 
	updateMouse(m_guiState, m_game);
}

void GameGUI::draw() {
	//TODO rita ut addons
	//std::map<GUIAddon*>::iterator it;
	//for (it = m_addons.front(); it != m_addons.end(); it++) {
	//it.second() -> draw();
	//} 
}

GameGUI::GUIState GameGUI::getGUIState() {
	return m_guiState;
}

void updateMouse(GameGUI::GUIState a_state, Game a_game) {
	if (a_game.getMouse() -> lmbPressed()) {
		switch (a_state) {
			case GameGUI::AttackTarget: {
				/*
				std::vector<Champion*>* l_champions = getGameState() -> championList;
				for (unsigned int i = 0; i < l_champions -> size(); i++) {
				if (l_champions[i].getHitBox().contains(MouseHandler.worldMouse()) && l_champion.getTile() -> getTileState() == Tile::Toggle) {
				getCurrentChampion -> attack(l_champion);
				}
				}
				delete l_champions;
				*/
				//TODO
				break;
			}
			case GameGUI::Move: {
				/*
				std::vector<Tile*>* l_tileList = getTileMap() -> toList(Tile::TileState::Toggle);
				for (unsigned int i = 0; i < l_tileList -> size(); i++) {
				if (l_tileList -> at(i) -> contains(MouseHandler.worldMouse()) {
				getCurrentChampion() -> moveTo(l_tile);
				getTileMap() -> restoreStates();
				break;
				}
				}
				delete l_tileList;
				*/
				//TODO
				break;
			}
			case GameGUI::SelectFacing: {
				/*
				std::vector<Tile*>* l_tileList = getTileMap() -> toList(Tile::TileState::Toggle);
				for (unsigned int i = 0; i < l_tileList -> size(); i++) {
				if (l_tileList -> at(i) -> contains(MouseHandler.worldMouse())) {
				getCurrentChampion() -> faceTile(l_tileList -> at(i));
				getTileMap() -> restoreStates();
				}
				}
				delete l_tileList;
				*/
				break;
			}
		}
	}
	if (a_game.getMouse() -> rmbPressed()) {
		if (a_state == GameGUI::AttackTarget || a_state == GameGUI::Move || a_state == GameGUI::ActionMenu) {
			//getTileMap() -> restoreStates();
		}
	}
}