#ifndef COLOR_H
#define COLOR_H

struct Color {
	unsigned char Red, Green, Blue, Alpha;
	static const Color WHITE;
	static const Color BLACK;
	static const Color CORNFLOWER_BLUE;
};

class GraphicsFramework {
	public:
		static float* toOGLColor(Color);
};

#endif