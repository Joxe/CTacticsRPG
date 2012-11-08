#ifndef TILEMAP_H
#define TILEMAP_H

#include "Game.h"
#include "GameObject.h"
#include "Tile.h"
#include "MathManager.h"
#include <vector>
#include <map>
#include <string>

class TileMap : public GameObject {
	private:
		std::vector<Tile*> m_tileMap;
		const int m_width;
		const int m_height;
		std::string m_tileSet;
		Tile* m_hoveredTile;
	public:
		TileMap(int a_width, int a_height, std::string, ::Game*);
		~TileMap();
		void load();
		void update();
		void draw();
		Tile* getTile(int x, int y);
		Tile* getHoverTile();
		std::vector<Tile*> getRangeOfTiles(Tile* a_tile, int a_range);
		bool ignoreMouse();
		void restoreStates();
		std::string getTileSet();
};

#endif