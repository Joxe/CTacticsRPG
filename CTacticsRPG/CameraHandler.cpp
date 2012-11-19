#include "CameraHandler.h"
#include "KeyboardHandler.h"
#include "GameState.h"

CameraHandler::CameraHandler(State* a_state, Camera* a_camera, Game* a_game) : m_game(*a_game) {
	if (dynamic_cast<GameState*>(a_state)) {
		m_type = GameCamera;
	}
	//m_camera = a_camera;
	m_game = *a_game;
}

void gameCameraUpdate(Camera* a_camera, Game& a_game) {
	if (a_game.getKeyboard() -> keyDown(SDLK_LEFT)) {
		a_camera -> move(V2<float>(-5, 0));
	}
	if (a_game.getKeyboard() -> keyDown(SDLK_RIGHT)) {
		a_camera -> move(V2<float>(5, 0));
	}
	if (a_game.getKeyboard() -> keyDown(SDLK_UP)) {
		a_camera -> move(V2<float>(0, -5));
	}
	if (a_game.getKeyboard() -> keyDown(SDLK_DOWN)) {
		a_camera -> move(V2<float>(0, 5));
	}
	a_camera -> update();
}

void menuCameraUpdate(Camera* a_camera) {

}

void CameraHandler::update() {
	switch (m_type) {
		case GameCamera: {
			gameCameraUpdate(m_camera, m_game);
			break;
		}
		case MenuCamera: {
			menuCameraUpdate(m_camera);
			break;
		}
	}
}

void CameraHandler::setCamera(Camera* a_camera) {
	m_camera = a_camera;
}

void CameraHandler::drawTexture(GLuint* a_surface, float X, float Y, float W, float H) {
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, *a_surface);
	glBegin(GL_QUADS);
	X -= m_camera -> getX();
	Y -= m_camera -> getY();

	//Bottom-left vertex (corner)
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(X , Y);

	//Bottom-right vertex (corner)
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(X + W, Y);
 
	//Top-right vertex (corner)
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(X + W, Y + H);
 
	//Top-left vertex (corner)
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(X, Y + H);
	glEnd();
}

float CameraHandler::getZoom() {
	return m_camera -> getZoom();
}

V2<int> CameraHandler::getCoordsInt() {
	return V2<int>((int)m_camera -> getCameraBox().X, (int)m_camera -> getCameraBox().Y);
}

V2<float> CameraHandler::getCoordsFloat() {
	return V2<float>(m_camera -> getCameraBox().X , m_camera -> getCameraBox().Y);
}