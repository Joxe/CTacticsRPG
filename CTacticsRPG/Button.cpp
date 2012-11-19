#include "Button.h"
#include "GameState.h"

Button::Button(V2<float> a_position, std::string a_filename, Game* a_game) : GUIElement(a_position, a_filename, a_game) {

}

void Button::load() {

}

void Button::update() {
	GUIElement::update();
	if (m_buttonState != Disabled && m_hitbox -> contains(((GameState*)m_game.getCurrentState()) -> getWorldMouseInt())) {
		m_buttonState = Hover;
		if (m_buttonState != Pressed && m_game.getMouse() -> lmbPressed()) {
			m_buttonState = Pressed;
			//playDownSound();
		}
		if (m_buttonState == Pressed && m_game.getMouse() -> lmbReleased()) {
			m_buttonState = Hover;
			if (m_clickFunc) {
				m_clickFunc(this);
			}
			//playUpSound();
		}
	} else {
		m_buttonState = Normal;
	}
	//TODO Hotkey
}

void Button::draw() {
	GUIElement::draw();
	//TODO rita olika texturer beroende på state
}

bool Button::isButtonPressed() {
	return m_buttonState == Pressed;
}

void Button::setText(std::string a_text) {
	//TODO
	//m_text.setText(a_text);
}

std::string Button::getText() {
	//TODO
	//return m_btnText.getText();
	return "";
}

void Button::setTextOffset(V2<float> a_offset) {
	m_textOffset = a_offset;
}

V2<float> Button::getTextOffset() {
	return m_textOffset;
}

void Button::setClickFunc(clickFunc a_function) {
	m_clickFunc = a_function;
}