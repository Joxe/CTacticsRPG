#include "TileMap.h"

TileMap::TileMap(int a_width, int a_height, std::string a_tileSet, ::Game* a_game) : m_width(a_width), m_height(a_height), GameObject(a_game) {
	m_tileSet = "Data/Images/TileSet/" + a_tileSet + "/";
	V2<int> l_v2;
	for (int i = 0; i < m_width * m_height; i++) {
		m_tileMap.push_back(new Tile(l_v2.X, l_v2.Y, m_tileSet, &m_game));
		l_v2.Y++;
		if (MathManager::isEven(l_v2.X)) {
			m_tileMap.back() -> move(V2<float>(0.0f, 111.0f));
		}
		if (l_v2.Y == m_height) {
			l_v2.Y = 0;
			l_v2.X++;
		}
	}
}

TileMap::~TileMap() {
	for (unsigned int i = 0; i < m_tileMap.size(); i++) {
		delete m_tileMap[i];
	}
}

void TileMap::load() {
	for (unsigned int i = 0; i < m_tileMap.size(); i++) {
		m_tileMap[i] -> load();
	}
}

void TileMap::update() {
	for (unsigned int i = 0; i < m_tileMap.size(); i++) {
		m_tileMap[i] -> update();
	}
}

void TileMap::draw() {
	for (unsigned int i = 0; i < m_tileMap.size(); i++) {
		m_tileMap[i] -> draw();
	}
}

Tile* TileMap::getTile(int x, int y) {
	return m_tileMap[x * m_height + y];
}

std::vector<Tile*> TileMap::getRangeOfTiles(Tile* a_tile, int a_range) {
	std::vector<Tile*> l_returnList;

	if (a_range == 0) {
		return l_returnList;
	}

	unsigned short infinity = 65535;

	int evenX[] = { -1,  0,  1,  1,  0, -1 };
	int evenY[] = {  1, -1,  0,  1,  1,  0 };
	int oddX[]  = {  1,  0,  1, -1,  0, -1 };
	int oddY[]  = { -1, -1,  0, -1,  1,  0 };

	std::map<Tile*, unsigned short> l_distance;

	for (int i = 0; m_tileMap[i] != NULL; i++) {
		l_distance[m_tileMap[i]] = infinity;
	}

	l_distance[a_tile] = 0;
	std::vector<Tile*> l_tileMap = m_tileMap;

	while (!l_tileMap.empty()) {
		Tile* l_tile = l_tileMap.front();
		std::vector<Tile*>::iterator it;

		for (unsigned int i = 0; i < l_tileMap.size(); i++) {
			if (l_distance[l_tileMap[i]] < l_distance[l_tile]) {
				l_tile = l_tileMap[i];
				it = l_tileMap.begin() + i;
			}
		}

		l_tileMap.erase(it);
		if (l_distance[l_tile] = infinity || l_distance[l_tile] > a_range) {
			break;
		}

		for (int i = 0; i < 6; i++) {
			int alt = l_distance[l_tile] + 1;

			if (l_tile -> getX() /* IS EVEN */) {
				Tile* l_neighbour = getTile(l_tile -> getX() + evenX[i], l_tile -> getY() + evenY[i]);
				l_distance[l_neighbour] = alt;
				l_returnList.push_back(l_neighbour);
			} else {
				Tile* l_neighbour = getTile(l_tile -> getX() + oddX[i], l_tile -> getY() + oddY[i]);
				l_distance[l_neighbour] = alt;
				l_returnList.push_back(l_neighbour);
			}
		}
	}

	l_tileMap.clear();
	l_distance.clear();

	return l_returnList;
}

std::string TileMap::getTileSet() {
	return m_tileSet;
}