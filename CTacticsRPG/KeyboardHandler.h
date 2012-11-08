#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include "include\SDL.h"

class KeyboardHandler {
	private:
		Uint8* m_currState;
		Uint8* m_backState;
	public:
		bool keyPressed(SDLKey);
		bool keyReleased(SDLKey);
		bool keyDown(SDLKey);

		void update();
};

#endif