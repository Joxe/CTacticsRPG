#ifndef CAMERAHANDLER_H
#define CAMERAHANDLER_H

#include "State.h"
#include "Camera.h"
#include "include\SDL_opengl.h"

class CameraHandler {
	private:
		enum CameraType {
			GameCamera, MenuCamera
		};
		CameraType m_type;
		Camera* m_camera;
		Game& m_game;
	public:
		CameraHandler(Game*);
		CameraHandler(State*, Camera*, Game*);
		void setCamera(Camera*);
		void update();
		void drawTexture(GLuint*, float, float, float, float);
		float getZoom();
		V2<int> getCoordsInt();
		V2<float> getCoordsFloat();
};

#endif