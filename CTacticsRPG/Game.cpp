#include "Game.h"
#include "GameState.h"

Game::Game() {
	m_screen = nullptr;
	m_running = true;
	XRes = 1280;
	YRes = 720;
}

void Game::setupOpenGL() {
	glClearColor(0.394f, 0.584f, 0.929f, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glViewport(0, 0, XRes, YRes);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, XRes, YRes, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

bool Game::initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	if ((m_screen = SDL_SetVideoMode(XRes, YRes, 32, SDL_OPENGL)) == nullptr) {
		return false;
	}

	setupOpenGL();

	SDL_WM_SetCaption("CTacticsRPG", 0);
	m_currentState = new GameState(this);
	return true;
}

bool Game::load() {
	m_currentState -> load();
	return true;
}

bool Game::update() {
	if (!m_running) {
		return false;
	}
	m_mouse.update();
	m_keyboard.update();
	m_currentState -> update();
	return true;
}

bool Game::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	m_currentState -> draw();
	SDL_GL_SwapBuffers();
	return true;
}

bool Game::quit() {
	return true;
}

MouseHandler* Game::getMouse() {
	return &m_mouse;
}

KeyboardHandler* Game::getKeyboard() {
	return &m_keyboard;
}

ResourceHandler* Game::getResourceHandler() {
	return &m_resource;
}

State* Game::getCurrentState() {
	return m_currentState;
}

void Game::quitGame() {
	m_running = false;
}

int Game::getXRes() {
	return XRes;
}

int Game::getYRes() {
	return YRes;
}

V2<int> Game::getResolution() {
	return V2<int>(XRes, YRes);
}