#include "GameState.h"
#include "KeyboardHandler.h"

GameState::GameState(::Game* a_game) : m_tileMap(5, 5, "test", a_game), m_event(a_game), m_cameraHandler(this, new Camera(a_game), a_game), State(a_game) {
	
}

GameState::~GameState() {
	//m_gameGui.~GameGUI();
}

bool GameState::load() {
	//m_gameGui.load();
	//TODO
	m_cameraHandler.setCamera(new Camera(&m_game));
	for (unsigned int i = 0; i < m_gameObjectList.size(); i++) {
		m_gameObjectList[i] -> load();
	}
	m_tileMap.load();
	return true;
}

bool GameState::update() {
	//m_gameGui.update();
	//TODO
	m_event.update();
	m_cameraHandler.update();
	for (unsigned int i = 0; i < m_gameObjectList.size(); i++) {
		m_gameObjectList[i] -> update();
	}
	m_tileMap.update();
	return true;
}

bool GameState::draw() {
	//m_gameGui.draw();
	//TODO
	for (unsigned int i = 0; i < m_gameObjectList.size(); i++) {
		//if (m_camera.isInCamera(&m_gameObjectList[i])) {
			m_gameObjectList[i] -> draw();
		//}
		//TODO
	}
	m_tileMap.draw();
	return true;
}

TileMap* GameState::getTileMap() {
	return &m_tileMap;
}

CameraHandler* GameState::getCameraHandler() {
	return &m_cameraHandler;
}

V2<float> GameState::getWorldMouseFloat() {
	V2<float> l_return((float)m_game.getMouse() -> getCurrentCoords().X, (float)m_game.getMouse() -> getCurrentCoords().Y);
	V2<float> l_camera((float)m_cameraHandler.getCoords().X, (float)m_cameraHandler.getCoords().Y);
	V2<float> l_resolution((float)m_game.getResolution().X, (float)m_game.getResolution().Y);

	return (l_return / m_cameraHandler.getZoom()) + l_camera - ((l_resolution / 2) / m_cameraHandler.getZoom());
}

V2<int> GameState::getWorldMouseInt() {
	return m_game.getMouse() -> getCurrentCoords() + m_cameraHandler.getCoords();
	//TODO zoom
}