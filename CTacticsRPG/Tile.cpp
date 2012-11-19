#include "Tile.h"
#include "Game.h"
#include "ResourceHandler.h"
#include "GameState.h"

Tile::Tile(int a_x, int a_y, std::string a_tileSet, ::Game* a_game) : TexturedObject(V2<float>((float)(a_x * TILE_WIDTH), (float)(a_y * TILE_HEIGHT)), a_tileSet + "normal.png", a_game) {
	X = a_x;
	Y = a_y;
	m_tileAbove = nullptr;
	m_obstructingObject = nullptr;
	m_tileState = Normal;
	m_hoverOverToggle = false;
	TexturedObject::m_layer = 0.500f - a_y / 1000.0f;
	if (MathManager::isEven(a_x)) {
		TexturedObject::m_layer -= 0.0001f;
	}

	//TODO Höjdbaserade sprites
}

Tile::~Tile() {
	std::string l_tileSet = ((GameState*)m_game.getCurrentState()) -> getTileMap() -> getTileSet();
	m_game.getResourceHandler() -> unloadImage(l_tileSet + "hover.png");
	m_game.getResourceHandler() -> unloadImage(l_tileSet + "pressed.png");
	m_game.getResourceHandler() -> unloadImage(l_tileSet + "toggle.png");
}

void Tile::load() {
	TexturedObject::load();
	std::string l_tileSet = ((GameState*)m_game.getCurrentState()) -> getTileMap() -> getTileSet();
	m_hover = m_game.getResourceHandler() -> loadImage(l_tileSet + "hover.png");
	m_pressed = m_game.getResourceHandler() -> loadImage(l_tileSet + "pressed.png");
	m_toggle = m_game.getResourceHandler() -> loadImage(l_tileSet + "toggle.png");

	if (Y > 0) {
		m_tileAbove = ((GameState*)m_game.getCurrentState()) -> getTileMap() -> getTile(X, Y - 1);
	}
	move(V2<float>((float)-(X * 64), -111.0f));
	m_hitbox = new JHexagon(m_position + V2<float>(0, 17), V2<float>((float)TILE_WIDTH, (float)TILE_HEIGHT));
}

void Tile::update() {
	TexturedObject::update();
	if (m_hitbox -> contains(V2<int>(((GameState*)m_game.getCurrentState()) -> getWorldMouseInt())) && !m_ignoreMouse /*&& !getTileMap -> ignoreMouse*/) {
		//getTileMap -> hover = this
		if (m_tileAbove) {
			m_tileAbove -> ignoreMouse(true);
		}
		switch (m_tileState) {
			case Tile::Normal: {
				m_tileState = Hover;
				break;
			}
			case Tile::Hover: {
				if (m_game.getMouse() -> lmbPressed()) {
					m_tileState = Pressed;
				}
				//TODO
				break;
			}
			case Tile::Pressed: {
				if (m_game.getMouse() -> lmbReleased()) {
					m_tileState = Hover;
				}
				//TODO
				break;
			}
			case Tile::Toggle: {
				if (m_game.getMouse() -> lmbReleased()) {
					m_tileState = Normal;
				}
				m_tileState = Hover;
				//TODO
				break;
			}
		}
	} else {
		if (m_hoverOverToggle) {
			m_tileState = Toggle;
		} else {
			m_tileState = Normal;
		}
		if (m_tileAbove) {
			m_tileAbove -> ignoreMouse(false);
		}
	}
}

void Tile::draw() {
	GLuint* l_textureToDraw = nullptr;
	switch (m_tileState) {
		case Normal: {
			l_textureToDraw = m_texture;
			break;
		}
		case Hover: {
			l_textureToDraw = m_hover;
			break;
		}
		case Pressed: {
			l_textureToDraw = m_pressed;
			break;
		}
		case Toggle: {
			l_textureToDraw = m_toggle;
			break;
		}
	}
	((GameState*)m_game.getCurrentState()) -> getCameraHandler() -> drawTexture(l_textureToDraw, m_position.X, m_position.Y, 256, 256); //TODO
}

int Tile::getX() {
	return X;
}

int Tile::getY() {
	return Y;
}

V2<int> Tile::getMapPosition() {
	return V2<int>(X, Y);
}

Tile::TileState Tile::getTileState() {
	return m_tileState;
}

void Tile::setTileState(Tile::TileState a_tileState) {
	m_tileState = a_tileState;
}

int Tile::getHeight() {
	return m_height;
}

void Tile::setHeight(int a_height) {
	m_height = a_height;
}

BattlefieldObject* Tile::getObstructingObject() {
	return m_obstructingObject;
}

void Tile::setObstructingObject(BattlefieldObject* a_object) {
	m_obstructingObject = a_object;
}

void Tile::ignoreMouse(bool a_ignore) {
	m_ignoreMouse = a_ignore;
}

void Tile::restoreState() {
	m_tileState = Tile::Normal;
}

bool Tile::isObstructed() {
	return m_obstructingObject == 0;
}