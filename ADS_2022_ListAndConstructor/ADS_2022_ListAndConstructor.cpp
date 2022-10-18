#include <iostream>
#include <list>
#include "Point2D.h"

using namespace std;

void demoPushBackOrFront();
void demoPrintFromList();
void demoPrintAsReference();
void demoEmplace();
void demoIterators();

int main()
{
	//demoPushBackOrFront();
	demoPrintFromList();
	//demoPrintAsReference();
	//demoEmplace();
	//demoIterators();
}

void demoPushBackOrFront()
{
	list<Point2D> pList;
	pList.push_back(Point2D(3, 4));
}
void demoPrintFromList()
{
	list<Point2D> pList;
	pList.emplace_front(3, 4);
	pList.emplace_front(6, 8);
	pList.emplace_front(9, 12);

	for (Point2D p : pList)
		cout << p << endl;
}
void demoPrintAsReference() {
	list<Point2D> pList;
	pList.emplace_front(3, 4);
	pList.emplace_front(6, 8);
	pList.emplace_front(9, 12);

	for (Point2D& p : pList)
		cout << p << endl;
}
void demoPrintAsPointer() {
	list<Point2D*> pList;
	Point2D p1(1, 2);
	pList.push_back(&p1);
	Point2D p2(3, 4);
	pList.push_back(&p2);

	for (Point2D* ptr : pList)
		cout << *ptr << endl;
}

void demoEmplace()
{
	list<Point2D> pList;
	pList.emplace_front(3, 4);
	pList.emplace_front(6, 8);
	pList.emplace_front(9, 12);

	//for (Point2D p : pList)
	//	cout << p << endl;
}
void demoIterators()
{
	list<int> numList;
	numList.emplace_back(10);
	numList.emplace_back(20);
	numList.emplace_back(30);

	list<int>::iterator start = numList.begin();
	list<int>::iterator end = numList.end();

	start--;
	//de-reference the iterator (pointer)
	cout << *start << endl;
	/*start++;
	cout << *start << endl;
	start--;
	cout << *start << endl;*/
}