#ifndef CAMERA_H
#define CAMERA_H

#include "Game.h"
#include "GameObject.h"
#include "MainFramework.h"
#include "GraphicsFramework.h"

class Camera : public GameObject {
	private:
		float m_zoom, m_rotation;
		JRectangle m_camerabox;
	public:
		Camera(Game*);
		void load();
		void update();
		void draw();
		void setPosition(V2<int>);
		JRectangle getCameraBox();
		void setZoom(float);
		void appendZoom(float);
		float getZoom();
		void setRotation(float);
		void appendRotation(float);
		float getRotation();
		int getX();
		int getY();
};

#endif