#ifndef MATHMANAGER_H
#define MATHMANAGER_H

class MathManager {
	public:
		static bool isEven(int a_number) {
			return (a_number & 1) == 0;
		}
};

#endif