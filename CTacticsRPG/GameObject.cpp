#include "GameObject.h"

GameObject::GameObject(::Game* a_game) : m_game(*a_game) {
	
}

GameObject::GameObject(V2<float> a_position, ::Game* a_game) : m_game(*a_game) {
	m_position = a_position;
}

GameObject::GameObject(GameObject* a_parent) : m_game(*a_parent.m_game) {
	m_parent = a_parent;
}

GameObject::~GameObject() {

}

void GameObject::load() {

}

void GameObject::update() {
	if (m_parent) {
		m_position = m_parent -> getPosition() + m_parentOffset;
	}
}

void GameObject::draw() {

}

TexturedObject* GameObject::getParent() {
	return m_parent;
}

void GameObject::setParent(GameObject* a_gameObject) {
	m_parent = a_gameObject;
}

V2<float> GameObject::getOffset() const {
	if (m_parent) {
		return m_parentOffset;
	}
	return V2<float>(0.0f, 0.0f);
}

void GameObject::setOffset(V2<float> a_parentOffset) {
	m_parentOffset = a_parentOffset;
}