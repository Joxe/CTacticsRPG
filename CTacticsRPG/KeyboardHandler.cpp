#include "KeyboardHandler.h"

bool KeyboardHandler::keyDown(SDLKey a_key) {
	return m_currState[a_key] == 1;
}

bool KeyboardHandler::keyPressed(SDLKey a_key) {
	return m_backState[a_key] == 0 && m_currState[a_key] == 1;
}

bool KeyboardHandler::keyReleased(SDLKey a_key) {
	return m_backState[a_key] == 1 && m_currState[a_key] == 0;
}

void KeyboardHandler::update() {
	m_backState = m_currState;
	m_currState = SDL_GetKeyState(nullptr);
}