#include "MouseHandler.h"

MouseHandler::MouseHandler() {
	m_currState.lmb = false;
	m_currState.mmb = false;
	m_currState.rmb = false;

	m_backState.lmb = false;
	m_backState.mmb = false;
	m_backState.rmb = false;
}

bool MouseHandler::lmbPressed() {
	return m_currState.lmb == true && m_backState.lmb == false;
}

bool MouseHandler::lmbReleased() {
	return m_currState.lmb == false && m_backState.lmb == true;
}

bool MouseHandler::lmbDown() {
	return m_currState.lmb == true;
}
		
bool MouseHandler::rmbPressed() {
	return m_currState.rmb == true && m_backState.rmb == false;
}
		
bool MouseHandler::rmbReleased() {
	return m_currState.rmb == false && m_backState.rmb == true;
}

bool MouseHandler::rmbDown() {
	return m_currState.rmb == true;
}

bool MouseHandler::mmbPressed() {
	return m_currState.mmb == true && m_backState.mmb == false;
}

bool MouseHandler::mmbReleased() {
	return m_currState.mmb == false && m_backState.mmb == true;
}

bool MouseHandler::mmbDown() {
	return m_currState.mmb == true;
}

V2<int> MouseHandler::getCurrentCoords() {
	return V2<int>(m_currState.X, m_currState.Y);
}

V2<int> MouseHandler::getPrevCoords() {
	return V2<int>(m_backState.X, m_backState.Y);
}

V2<int> MouseHandler::getDifference() {
	return V2<int>(m_backState.X - m_currState.X, m_backState.Y - m_currState.Y);
}
		
void MouseHandler::update() {
	m_backState = m_currState;

	Uint8 l_mouseState = SDL_GetMouseState(&m_currState.X, &m_currState.Y);

	m_currState.lmb = l_mouseState == SDL_BUTTON(SDL_BUTTON_LEFT);
	m_currState.mmb = l_mouseState == SDL_BUTTON(SDL_BUTTON_MIDDLE);
	m_currState.rmb = l_mouseState == SDL_BUTTON(SDL_BUTTON_RIGHT);
	//TODO
}