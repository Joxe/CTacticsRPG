#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"
#include "MainFramework.h"
#include "PrimitivesFramework.h"

class Game;

class GameObject {
	protected:
		V2<float> m_position;
		V2<float> m_parentOffset;
		Game& m_game;
		GameObject* m_parent;
	public:
		GameObject(::Game* a_game) : m_game(*a_game) { }
		GameObject(V2<float> a_position, ::Game* a_game) : m_game(*a_game) { }
		GameObject(GameObject*);
		virtual void load() = 0;
		virtual void update() {
			if (m_parent) {
				m_position = m_parent -> getPosition() + m_parentOffset;
			}
		}
		virtual void draw() = 0;
		GameObject* getParent();
		void setParent(GameObject*);

		virtual V2<float>getPosition() const {
			return m_position;
		}
		virtual void setPosition(V2<float> a_position) {
			m_position = a_position;
		}
		virtual void move(V2<float> a_distance) {
			m_position += a_distance;
		}

		V2<float> getOffset() const { }
		void setOffset(V2<float>) { }
};

#endif