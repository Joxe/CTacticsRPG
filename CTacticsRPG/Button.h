#ifndef BUTTON_H
#define BUTTON_H

#include "Game.h"
#include "TexturedObject.h"
#include "MainFramework.h"

class Button : public TexturedObject {
	public:
		Button(V2<float>, std::string, ::Game*);
		void load();
		void update();
		void draw();
};

#endif