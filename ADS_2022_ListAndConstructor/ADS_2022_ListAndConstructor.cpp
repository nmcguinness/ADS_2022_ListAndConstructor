// ADS_2022_ListAndConstructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
/*
* 1. class Point2D
	- 2 floats (x,y)
	- default, full
	- destructor
	- getters
	- ostream <<
*/
class Point2D {
private:
	float x, y;
public:
	Point2D() : x(0), y(0) {
		cout << "constructor" << endl;
	}
	Point2D(float x, float y) : x(x), y(y) {
		cout << "constructor" << endl;
	}
	~Point2D() {
		this->x = 0; this->y = 0;
		cout << "destructor" << endl;
	}
	float getX() const { return this->x; }
	float getY() const { return this->y; }
	friend ostream& operator<<(ostream& out, const Point2D& point2D)
	{
		out << point2D.x << "," << point2D.y;
		return out;
	}

	Point2D(const Point2D& copy) {
		cout << "copy constructor" << endl;
		this->x = copy.getX();
		this->y = copy.getY();
	}
};

int main()
{
	Point2D spawnPoint(10, 20);

	//copy constructor
	Point2D p1(spawnPoint);
}