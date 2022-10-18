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
	demoPushBackOrFront();
	demoPrintFromList();
	demoPrintAsReference();
	//demoEmplace();
	//demoIterators();
}

void demoPushBackOrFront()
{
}
void demoPrintFromList()
{
}
void demoPrintAsReference() {
}

void demoEmplace()
{
	//Point2D p1(1, 2);
	list<Point2D> pList;
	//pList.push_back(Point2D(3, 4));

	pList.emplace_front(3, 4);
	pList.emplace_front(6, 8);
	pList.emplace_front(9, 12);

	for (Point2D p : pList)
		cout << p << endl;
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