#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include "include\SDL.h"
#include "include\SDL_image.h"
#include "include\SDL_opengl.h"
#include <string>
#include <map>

class ResourceHandler {
	private:
		struct SurfaceRef {
			GLuint m_surface;
			int references;
		};
		std::map<std::string, SurfaceRef> m_imageMap;
	public:
		GLuint* loadImage(std::string);
		GLuint* getSurface(std::string);
		void unloadImage(std::string);
};

#endif