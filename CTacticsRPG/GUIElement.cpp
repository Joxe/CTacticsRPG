#include "GUIElement.h"
#include "GameState.h"

GUIElement::GUIElement(V2<float> a_position, std::string a_filepath, Game* a_game)
	: TexturedObject(((GameState*)a_game -> getCurrentState()) -> getCameraHandler() -> getCoordsFloat() + a_position, a_filepath, a_game)
{
	m_screenPosition = a_position;
}

void GUIElement::update() {
	m_position = ((GameState*)m_game.getCurrentState()) -> getCameraHandler() -> getCoordsFloat() + m_screenPosition;
}

void GUIElement::setScreenPos(V2<float> a_position) {
	m_screenPosition = a_position;
}

V2<float> GUIElement::getScreenPos() {
	return m_screenPosition;
}