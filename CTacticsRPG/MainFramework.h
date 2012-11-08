#ifndef MAINFRAMEWORK_H
#define MAINFRAMEWORK_H

template<typename T>
class V2 {
	public:
		T X, Y;

		V2(T a_x, T a_y) {
			X = a_x;
			Y = a_y;
		}
		V2() : X(0), Y(0) { }

		//Compount Assignment Operators
		V2 operator+=(const V2 &right) const { return V2(T(this -> X) += right.X, T(this -> Y) += right.Y); }
		V2 operator-=(const V2 &right) const { return V2(T(this -> X) -= right.X, T(this -> Y) -= right.Y); }
		V2 operator*=(const V2 &right) const { return V2(T(this -> X) *= right.X, T(this -> Y) *= right.Y); }
		V2 operator/=(const V2 &right) const { return V2(T(this -> X) /= right.X, T(this -> Y) /= right.Y); }

		//Arimethic Operators
		V2 operator+(const V2 &right   ) const { return V2(this -> X + right.X, this -> Y + right.Y); }
		V2 operator+(const int right   ) const { return V2(this -> X + right, this -> Y + right); }
		V2 operator+(const float right ) const { return V2(this -> X + right, this -> Y + right); }
		V2 operator+(const double right) const { return V2(this -> X + right, this -> Y + right); }

		V2 operator-(const V2 &right   ) const { return V2(this -> X - right.X, this -> Y - right.Y); }
		V2 operator-(const int right   ) const { return V2(this -> X - right, this -> Y - right); }
		V2 operator-(const float right ) const { return V2(this -> X - right, this -> Y - right); }
		V2 operator-(const double right) const { return V2(this -> X - right, this -> Y - right); }

		V2 operator*(const V2 &right   ) const { return V2(this -> X * right.X, this -> Y * right.Y); }
		V2 operator*(const int right   ) const { return V2(this -> X * right, this -> Y * right); }
		V2 operator*(const float right ) const { return V2(this -> X * right, this -> Y * right); }
		V2 operator*(const double right) const { return V2(this -> X * right, this -> Y * right); }

		V2 operator/(const V2 &right   ) const { return V2(this -> X / right.X, this -> Y / right.Y); }
		V2 operator/(const int right   ) const { return V2(this -> X / right, this -> Y / right); }
		V2 operator/(const float right ) const { return V2(this -> X / right, this -> Y / right); }
		V2 operator/(const double right) const { return V2(this -> X / right, this -> Y / right); }

		V2 operator%(const V2 &right) const { return V2(this -> X % right.X, this -> Y % right.Y); }

		//Increment/Decrement Operators
		V2 operator++() const { return V2(T(this -> X)++, T(this -> Y)++); }
		V2 operator--() const { return V2(T(this -> X)--, T(this -> Y)--); }
		V2 operator++(int) const { return V2(++T(this -> X), ++T(this -> Y)); }
		V2 operator--(int) const { return V2(--T(this -> X), --T(this -> Y)); }

		//Comparasion Operators
		bool operator==(const V2 &right) const { return X == right.X && Y == right.Y; }
		bool operator!=(const V2 &right) const { return X != right.X || Y != right.Y; }
		bool operator>(const V2 &right) const { return this -> X + this -> Y > right.X + right.Y; }
		bool operator<(const V2 &right) const { return this -> X + this -> Y < right.X + right.Y; }
		bool operator>=(const V2 &right) const { return this -> X + this -> Y >= right.X + right.Y; }
		bool operator<=(const V2 &right) const { return this -> X + this -> Y <= right.X + right.Y; }
};

#endif