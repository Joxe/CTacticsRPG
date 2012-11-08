#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"
#include "State.h"
#include "EventHandler.h"
#include "TileMap.h"
#include "CameraHandler.h"

class GameState : public State {
	private:
		EventHandler m_event;
		TileMap m_tileMap;
		CameraHandler m_cameraHandler;
	public:
		GameState(::Game*);
		~GameState();
		bool load();
		bool update();
		bool draw();
		TileMap* getTileMap();
		CameraHandler* getCameraHandler();
		V2<float> getWorldMouseFloat();
		V2<int> getWorldMouseInt();
};

#endif