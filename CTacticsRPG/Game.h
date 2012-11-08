#ifndef GAME_H
#define GAME_H

#include "include\SDL.h"
#include "MouseHandler.h"
#include "ResourceHandler.h"
#include "KeyboardHandler.h"
#include "include\SDL_opengl.h"
#include "State.h"

class State;

class Game {
	private:
		SDL_Surface* m_screen;
		MouseHandler m_mouse;
		KeyboardHandler m_keyboard;
		ResourceHandler m_resource;
		State* m_currentState;
		bool m_running;
		int XRes, YRes;
		void setupOpenGL();
	public:
		Game();
		MouseHandler* getMouse();
		KeyboardHandler* getKeyboard();
		ResourceHandler* getResourceHandler();
		State* getCurrentState();
		bool initialize();
		bool load();
		bool update();
		bool draw();
		bool quit();
		void drawTexture(GLuint*, float, float, float, float);
		void quitGame();
		int getXRes();
		int getYRes();
		V2<int> getResolution();
};

#endif