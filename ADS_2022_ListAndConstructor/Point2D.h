#pragma once

/*
Task 1
 - Add Point2D class
	- 2x floats (x,y)
	- default, full constructor, copy constructor, destructor
	- getters
	- << (output stream), = (assignment)
*/
#include <iostream>
using namespace std;

class Point2D {
private:
	float x, y;

public:
	Point2D() : x(0), y(0) { cout << "constructor" << endl; }
	Point2D(float x, float y) : x(x), y(y) { cout << "constructor" << endl; }
	Point2D(const Point2D& original) {
		cout << "copy constructor" << endl;
		this->x = original.getX();
		this->y = original.getY();
	}
	~Point2D() { cout << "destructor" << endl; }
	float getX() const { return this->x; }
	float getY() const { return this->y; }
	friend ostream& operator<<(ostream& out, const Point2D& point) {
		out << point.x << "," << point.y;
		return out;
	}
};
