#ifndef BUTTON_H
#define BUTTON_H

#include "Game.h"
#include "GUIElement.h"
#include "MainFramework.h"
#include <string>

class Button : public GUIElement {
	private:
		std::string m_btnText;
		V2<float> m_textOffset;
		enum ButtonState {
			Normal, Hover, Pressed, Toggled, Disabled
		};
		ButtonState m_buttonState;
		//Function-pointer to click-function
		typedef void (*clickFunc)(Button*);
		clickFunc m_clickFunc;
		//----------------------------------
	public:
		Button(V2<float>, std::string, ::Game*);
		void load();
		void update();
		void draw();
		bool isButtonPressed();
		/*TODO
		void setDownSound(std::string);
		void playDownSound();
		void setUpSound(std::string);
		void playUpSound();
		*/
		void setText(std::string);
		std::string getText();
		void setTextOffset(V2<float>);
		V2<float> getTextOffset();
		void setClickFunc(clickFunc);
};

#endif