#ifndef TEXTUREDOBJECT_H
#define TEXTUREDOBJECT_H

#include "Game.h"
#include "GameObject.h"
#include "MainFramework.h"
#include "GraphicsFramework.h"
#include "include\SDL_opengl.h"
#include <string>

class TexturedObject : public GameObject {
	protected:
		Color m_color;
		float m_layer;
		float m_rotation;
		float m_scale;
		V2<int> m_dimensions;
		std::string m_filepath;
		GLuint* m_texture;
		bool m_isInCamera;
		JShape* m_hitbox;
		TexturedObject(const TexturedObject &other);
		TexturedObject& operator=(const TexturedObject &other);
	public:
		TexturedObject(V2<float>, std::string, ::Game*);
		~TexturedObject();
		void load();
		void update();
		void draw();
		Color getColor() const;
		void  setColor(Color);

		float getScale() const;
		void  setScale(float);
		void  appendScale(float);
		
		float getRotation();
		void  setRotation(float);

		float getLayer();
		void  setLayer(float);

		bool isInCamera();
		JShape* getHitBox();
		using GameObject::move;
};

#endif