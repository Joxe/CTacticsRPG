#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "include\SDL.h"
#include "Game.h"

class EventHandler {
	private:
		Game& m_game;
		SDL_Event m_event;
	public:
		EventHandler(Game*);
		void update();
};

#endif