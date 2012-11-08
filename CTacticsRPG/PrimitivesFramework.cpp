#include "PrimitivesFramework.h"

#pragma region Rectangle
JRectangle::JRectangle(float a_x, float a_y, float a_width, float a_height) {
	X = a_x;
	Y = a_y;
	Width = a_width;
	Height = a_height;
}

JRectangle::JRectangle() {
	X = 0.0f;
	Y = 0.0f;
	Width = 0.0f;
	Height = 0.0f;
}

bool JRectangle::contains(V2<int> a_point) {
	return contains(V2<float>((float)a_point.X, (float)a_point.Y));
}

bool JRectangle::contains(V2<float> a_point) {
	return a_point.X > X 
		&& a_point.X < X + Width 
		&& a_point.Y > Y
		&& a_point.Y < Y + Height;
}

/*
bool JRectangle::contains(JRectangle a_rectangle) {
	return (a_rectangle.X > X && a_rectangle.X < X + Width)
		|| (a_rectangle.X < X + Width && a_rectangle.X > X)
		|| (a_rectangle.Y > Y && a_rectangle.Y < Y + Height)
		|| (a_rectangle.Y < Y + Height && a_rectangle.Y > Y);
}
*/

void JRectangle::setPosition(V2<float> a_position) {
	X = a_position.X;
	Y = a_position.Y;
}

void JRectangle::move(V2<float> a_distance) {
	X += a_distance.X;
	Y += a_distance.Y;
}

void JRectangle::setDimensions(V2<float> a_dimension) {
	Width = a_dimension.X;
	Height = a_dimension.Y;
}
#pragma endregion

#pragma region Hexagon
JHexagon::JHexagon(V2<float> a_position, V2<float> a_dimension) {
	Left        = V2<float>(a_position.X                        , a_position.Y + a_dimension.Y / 2);
	TopLeft     = V2<float>(a_position.X + a_dimension.X * 0.25f, a_position.Y                    );
	TopRight    = V2<float>(a_position.X + a_dimension.X * 0.75f, a_position.Y                    );
	Right       = V2<float>(a_position.X + a_dimension.X        , a_position.Y + a_dimension.Y / 2);
	BottomRight = V2<float>(a_position.X + a_dimension.X * 0.75f, a_position.Y + a_dimension.Y    );
	BottomLeft  = V2<float>(a_position.X + a_dimension.X * 0.25f, a_position.Y + a_dimension.Y    );
}

JHexagon::JHexagon() {
	Left        = V2<float>();
	TopLeft     = V2<float>();
	TopRight    = V2<float>();
	Right       = V2<float>();
	BottomRight = V2<float>();
	BottomLeft  = V2<float>();
}

bool JHexagon::contains(V2<int> a_point) {
	return contains(V2<float>((float)a_point.X, (float)a_point.Y));
}

bool JHexagon::contains(V2<float> a_point) {
	float l_middleX = Left.X + (Right.X - Left.X) / 2;

	if ((a_point.X > Left.X && a_point.X < Right.X) && (a_point.Y > TopLeft.Y && a_point.Y < BottomLeft.Y)) {
		if (a_point.Y < Left.Y) {
			if (a_point.X < l_middleX) {
				return ((TopLeft.X - Left.X) * (a_point.Y - Left.Y) - (TopLeft.Y - Left.Y) * (a_point.X - Left.X)) > 0;
			} else {
				return ((Right.X - TopRight.X) * (a_point.Y - TopRight.Y) - (Right.Y - TopRight.Y) * (a_point.X - TopRight.X)) > 0;
			}
		} else {
			if (a_point.X < l_middleX) {
				return ((BottomLeft.X - Left.X) * (a_point.Y - Left.Y) - (BottomLeft.Y - Left.Y) * (a_point.X - Left.X)) < 0;
			} else {
				return ((Right.X - BottomRight.X) * (a_point.Y - BottomRight.Y) - (Right.Y - BottomRight.Y) * (a_point.X - BottomRight.X)) < 0;
			}
		}
	} else {
		return false;
	}
}

void JHexagon::setPosition(V2<float> a_position) {
	V2<float> l_dimension(Right.X - Left.X, BottomLeft.Y - TopLeft.Y);

	Left        = V2<float>(a_position.X                        , a_position.Y + l_dimension.Y / 2);
	TopLeft     = V2<float>(a_position.X + l_dimension.X * 0.25f, a_position.Y                    );
	TopRight    = V2<float>(a_position.X + l_dimension.X * 0.75f, a_position.Y                    );
	Right       = V2<float>(a_position.X + l_dimension.X        , a_position.Y + l_dimension.Y / 2);
	BottomRight = V2<float>(a_position.X + l_dimension.X * 0.75f, a_position.Y + l_dimension.Y    );
	BottomLeft  = V2<float>(a_position.X + l_dimension.X * 0.25f, a_position.Y + l_dimension.Y    );
}

void JHexagon::move(V2<float> a_distance) {
	Left        += a_distance;
	TopLeft     += a_distance;
	TopRight    += a_distance;
	Right       += a_distance;
	BottomRight += a_distance;
	BottomLeft  += a_distance;
}
#pragma endregion