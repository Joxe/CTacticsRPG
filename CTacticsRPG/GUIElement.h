#include "Game.h"
#include "MainFramework.h"
#include "TexturedObject.h"
#include <string>

class GUIElement : public TexturedObject {
	protected:
		V2<float> m_screenPosition;
	public:
		GUIElement(V2<float>, std::string, Game*);
		void update();
		void setScreenPos(V2<float>);
		V2<float> getScreenPos();
};