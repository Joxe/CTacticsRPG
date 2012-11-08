#ifndef PRIMITIVESFRAMEWORK_H
#define PRIMITIVESFRAMEWORK_H

#include "MainFramework.h"

class JShape {
	public:
		virtual bool contains(V2<int>) = 0;
		virtual bool contains(V2<float>) = 0;
		virtual void setPosition(V2<float>) = 0;
		virtual void move(V2<float>) = 0;
};

class JRectangle : public JShape {
	public:
		float X;
		float Y;
		float Width;
		float Height;

		JRectangle(float a_x, float a_y, float a_width, float a_height);
		JRectangle();
		/*
		JRectangle &operator=(const JRectangle &other) {
			X = other.X;
			Y = other.Y;
			Width = other.Width;
			Height = other.Height;
			return *this;
		}
		*/
		bool contains(JRectangle);
		void setDimensions(V2<float>);
		
		bool contains(V2<int>);
		bool contains(V2<float>);
		void setPosition(V2<float>);
		void move(V2<float>);
};

class JHexagon : public JShape {
	public:
		V2<float> TopLeft;
		V2<float> TopRight;
		V2<float> Right;
		V2<float> BottomRight;
		V2<float> BottomLeft;
		V2<float> Left;

		JHexagon(V2<float>, V2<float>);
		JHexagon();

		bool contains(V2<int>);
		bool contains(V2<float>);
		void setPosition(V2<float>);
		void move(V2<float>);
};

#endif