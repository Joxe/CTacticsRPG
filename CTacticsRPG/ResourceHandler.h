#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include "include\SDL.h"
#include "include\SDL_image.h"
#include "include\SDL_opengl.h"
#include <string>
#include <map>
#include "MainFramework.h"

class ResourceHandler {
	private:
		struct SurfaceRef {
			SurfaceRef() {
				m_surface = 0;
				references = 0;
				m_dimensions = V2<int>(0, 0);
			}
			GLuint m_surface;
			int references;
			V2<int> m_dimensions;
		};
		std::map<std::string, SurfaceRef> m_imageMap;
	public:
		GLuint* loadImage(std::string);
		GLuint* getSurface(std::string);
		void unloadImage(std::string);
		V2<int> getSurfaceSize(std::string);
};

#endif