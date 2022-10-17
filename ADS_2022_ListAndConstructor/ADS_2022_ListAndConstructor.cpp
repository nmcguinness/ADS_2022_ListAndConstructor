// ADS_2022_ListAndConstructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
using namespace std;
/*
* Task 1. class Point2D
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

void demoEmplace()
{
	//Point2D spawnPoint(10, 20);
	//copy constructor
	//Point2D p1(spawnPoint);

	list<Point2D> ptList;

	//technique 1 - make separate object and pass in
	//Point2D p1(1, 2);
	//ptList.push_back(p1);

	//technique 2 - make object in place and pass in
	//ptList.push_back(Point2D(3, 4));

	//technique 3 - add object to list using EMPLACE
	ptList.emplace_back(5, 6);

	//technique 4 - use EMPLACE with iterator
	list<Point2D>::const_iterator iter = ptList.begin();
	ptList.emplace(iter, 7, 8);

	//lets check that our EMPLACE function added in correct location
	for (Point2D pt : ptList)
		cout << pt << endl;
}

/*
* Task 2 - Write a print() to print Point2D in a list
*/
void print(list<Point2D> list)
{
	for (Point2D p : list)
		cout << p << endl;
}

template <typename E>
void print(list<E> list)
{
	for (E theObj : list)
		cout << theObj << endl;
}

void print(list<Point2D>::iterator iter, list<Point2D>::iterator end)
{
	while (iter != end) {
		cout << *iter << endl;
		iter++;
	}
}

template <typename Iter>
void print(Iter iter, Iter end)
{
	while (iter != end) {
		cout << *iter << endl;
		iter++;
	}
}
int main()
{
	//demoEmplace();

	//demo the template print for Point2Ds
	list<Point2D> ptList;
	ptList.emplace_back(1, 2);	ptList.emplace_back(3, 4);
	ptList.emplace_back(5, 6);	ptList.emplace_back(7, 8);
	list<Point2D>::iterator start = ptList.begin();
	list<Point2D>::iterator end = ptList.end();
	//print<list<Point2D>::iterator>(start, end);

	//demo the template print for floats
	list<float> numList;
	numList.push_back(10.2);
	numList.push_back(20.4);
	numList.push_back(30.6);
	//print<list<float>::iterator>(numList.begin(), numList.end());

	//demo the template print working BACKWARDS
	list<string> nameList;
	nameList.push_front("anna");
	nameList.push_front("bea");
	nameList.push_front("ciaran");

	//in order to print backwards we need reverse_iterators
	list<string>::reverse_iterator startRev = nameList.rbegin();
	list<string>::reverse_iterator endRev = nameList.rend();

	cout << *startRev << endl;
}