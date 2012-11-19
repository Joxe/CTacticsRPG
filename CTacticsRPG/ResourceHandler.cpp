#include "ResourceHandler.h"

GLuint* ResourceHandler::loadImage(std::string a_filepath) {
	GLuint l_texture;
	GLenum l_textureFormat;
	GLint l_nOfColors;

	if (m_imageMap[a_filepath].references++ == 0) {
		SDL_Surface* l_loaded = nullptr;
		l_loaded = IMG_Load(a_filepath.c_str());

		if ((l_loaded -> w & (l_loaded -> w - 1)) != 0 && (l_loaded -> h & (l_loaded -> h - 1)) != 0) {
			return nullptr;
		}

		if (l_loaded != nullptr) {
			l_nOfColors = l_loaded -> format -> BytesPerPixel;

			if (l_nOfColors == 4) {
				if (l_loaded -> format -> Rmask == 0x000000ff) {
					l_textureFormat = GL_RGBA;
				} else {
					l_textureFormat = GL_BGRA;
				}
			} else if (l_nOfColors == 3) {
				if (l_loaded -> format -> Rmask == 0x000000ff) {
					l_textureFormat = GL_RGB;
				} else {
					l_textureFormat = GL_BGR;
				}
			} else {
				//ERROR: Shit is going down, not true-color
				m_imageMap[a_filepath].references--;
				return nullptr;
			}

			glGenTextures(1, &l_texture);
			glBindTexture(GL_TEXTURE_2D, l_texture);

			glTexImage2D(GL_TEXTURE_2D, 0, l_nOfColors, l_loaded -> w, l_loaded -> h, 0, l_textureFormat, GL_UNSIGNED_BYTE, l_loaded -> pixels);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			m_imageMap[a_filepath].m_surface = l_texture;
			m_imageMap[a_filepath].m_dimensions = V2<int>(l_loaded -> w, l_loaded -> h);
			SDL_FreeSurface(l_loaded);
			glBindTexture(GL_TEXTURE_2D, NULL);
		}
	}
	
	return &m_imageMap[a_filepath].m_surface;
}

void ResourceHandler::unloadImage(std::string a_name) {
	if (--m_imageMap[a_name].references == 0) {
		glDeleteTextures(1, &m_imageMap[a_name].m_surface);
		m_imageMap.erase(a_name);
	}
}

GLuint* ResourceHandler::getSurface(std::string a_name) {
	return &m_imageMap[a_name].m_surface;
}

V2<int> ResourceHandler::getSurfaceSize(std::string a_name) {
	return m_imageMap[a_name].m_dimensions;
}