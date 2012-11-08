#include "TexturedObject.h"
#include "GameState.h"

TexturedObject::TexturedObject(V2<float> a_position, std::string a_filepath, ::Game* a_game) : GameObject(a_position, a_game) {
	m_position = a_position;
	m_color = Color::WHITE;
	m_scale = 1.0f;
	m_filepath = a_filepath;
	m_parent = nullptr;
}

TexturedObject::~TexturedObject() {
	m_game.getResourceHandler() -> unloadImage(m_filepath);
}

TexturedObject::TexturedObject(const TexturedObject &other) : GameObject(&other.m_game) {
	m_color = other.m_color;
	m_layer = other.m_layer;
	m_rotation = other.m_rotation;
	m_scale = other.m_scale;
	m_filepath = other.m_filepath;
	m_texture = m_game.getResourceHandler() -> loadImage(m_filepath);
}

TexturedObject& TexturedObject::operator=(const TexturedObject &other) {
	if (this != &other) {
		TexturedObject l_t(other.m_position, other.m_filepath, &other.m_game);
		l_t.m_color = other.m_color;
		l_t.m_layer = other.m_layer;
		l_t.m_rotation = other.m_rotation;
		l_t.m_scale = other.m_scale;
		l_t.m_texture = other.m_texture;
		delete &other;
	}
	return *this;
}

void TexturedObject::load() {
	m_texture = m_game.getResourceHandler() -> loadImage(m_filepath);
	//m_hitBox = JRectangle(GameObject::m_position.X, GameObject::m_position.Y, SPRITE_WIDTH, SPRITE_HEIGHT);
	//TODO
}

void TexturedObject::update() {
	//m_hitBox.setPosition(GameObject::m_position);
	//GameObject::update();
	//TODO
}

void TexturedObject::draw() {
	((GameState*)m_game.getCurrentState()) -> getCameraHandler() -> drawTexture(m_texture, m_position.X, m_position.Y, 256, 256); //TODO
	//m_sprite -> draw();
	//TODO
}

Color TexturedObject::getColor() const {
	return m_color;
}

void TexturedObject::setColor(Color a_color) {
	m_color = a_color;
}

float TexturedObject::getScale() const {
	return m_scale;
}

void TexturedObject::setScale(float a_scale) {
	m_scale = a_scale;
}

void TexturedObject::appendScale(float a_scale) {
	m_scale += a_scale;
}

float TexturedObject::getRotation() {
	return m_rotation;
}

void TexturedObject::setRotation(float a_rotation) {
	m_rotation = a_rotation; 
}

float TexturedObject::getLayer() {
	return m_layer;
}

void TexturedObject::setLayer(float a_layer) {
	m_layer = a_layer;
}

bool TexturedObject::isInCamera() {
	return true; //TODO
}

JShape* TexturedObject::getHitBox() {
	return m_hitbox;
}