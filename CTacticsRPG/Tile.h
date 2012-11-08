#ifndef TILE_H
#define TILE_H

#include "MainFramework.h"
#include "BattlefieldObject.h"
#include "TexturedObject.h"
#include "MathManager.h"

class Tile : public TexturedObject {
	public:
		enum TileState {
			Normal, Hover, Pressed, Toggle
		};
	private:
		int X;
		int Y;
		int m_height;
		static const int TILE_WIDTH = 256;
		static const int TILE_HEIGHT = 222;
		bool m_collided;
		bool m_hoverOverToggle;
		bool m_ignoreMouse;
		BattlefieldObject* m_obstructingObject;
		TileState m_tileState;
		Tile* m_tileAbove;
		GLuint* m_hover;
		GLuint* m_pressed;
		GLuint* m_toggle;
	public:
		Tile(int, int, std::string, ::Game*);
		~Tile();
		void load();
		void update();
		void draw();
		int getX();
		int getY();
		V2<int> getMapPosition();
		TileState getTileState();
		void setTileState(TileState);
		int getHeight();
		void setHeight(int);
		BattlefieldObject* getObstructingObject();
		void setObstructingObject(BattlefieldObject*);
		void ignoreMouse(bool);
		void restoreState();
		bool isObstructed();
};

#endif