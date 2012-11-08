#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include "include\SDL.h"
#include "MainFramework.h"

class MouseHandler {
	private:
		struct MouseState {
			int X, Y;
			bool lmb, mmb, rmb;
		};

		MouseState m_currState;
		MouseState m_backState;
	public:
		MouseHandler();
		//Left Mouse Button
		bool lmbPressed();
		bool lmbReleased();
		bool lmbDown();
		//Right Mouse Button
		bool rmbPressed();
		bool rmbReleased();
		bool rmbDown();
		//Middle Mouse Button
		bool mmbPressed();
		bool mmbReleased();
		bool mmbDown();

		V2<int> getCurrentCoords();
		V2<int> getPrevCoords();
		V2<int> getDifference();
		void update();
};

#endif