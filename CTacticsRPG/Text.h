#include <string>
#include "GUIElement.h"

class Text : public GUIElement {
	private:
		std::string m_text;
	public:
		void setText();
		std::string getText();
};