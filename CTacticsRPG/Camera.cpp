#include "Camera.h"

Camera::Camera(Game* a_game) : GameObject(a_game) {
	m_zoom = 1.0f;
}

void Camera::load() {
	m_camerabox = JRectangle(
		0.0f, 0.0f, 
		static_cast<float>(m_game.getXRes()), 
		static_cast<float>(m_game.getYRes())
	);
}

void Camera::update() {
	m_camerabox.X = m_position.X;
	m_camerabox.Y = m_position.Y;
}

void Camera::draw() {

}

void Camera::setPosition(V2<int> a_position) {
	m_camerabox.X = static_cast<float>(a_position.X);
	m_camerabox.Y = static_cast<float>(a_position.Y);
}

JRectangle Camera::getCameraBox() {
	return m_camerabox;
}

void Camera::setZoom(float a_zoom) {
	m_zoom = a_zoom;
}

void Camera::appendZoom(float a_zoom) {
	m_zoom += a_zoom;
}

float Camera::getZoom() {
	return m_zoom;
}

void Camera::setRotation(float a_rotation) {
	m_rotation = a_rotation;
}

void Camera::appendRotation(float a_rotation) {
	m_rotation += a_rotation;
}

float Camera::getRotation() {
	return m_rotation;
}

int Camera::getX() {
	return static_cast<int>(m_camerabox.X);
}

int Camera::getY() {
	return static_cast<int>(m_camerabox.Y);
}