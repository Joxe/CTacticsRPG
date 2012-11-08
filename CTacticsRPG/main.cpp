#include "Game.h"

int main(int argc, char* args[]) {
	Game m_game;

	if (!m_game.initialize()) {
		return 1;
	}
	if (!m_game.load()) {
		return 2;
	}
	while (true) {
		if (!m_game.update()) {
			break;
		}
		if (!m_game.draw()) {
			break;
		}
	}
	if (!m_game.quit()) {
		return 5;
	}

	return 0; 
}