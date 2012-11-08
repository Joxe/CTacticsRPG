#include "EventHandler.h"
#include "Game.h"

EventHandler::EventHandler(Game* a_game) : m_game(*a_game) {

}

void EventHandler::update() {
	while (SDL_PollEvent(&m_event)) {
		switch (m_event.type) {
			case SDL_QUIT: {
				m_game.quitGame();
			}
		}
	}
}