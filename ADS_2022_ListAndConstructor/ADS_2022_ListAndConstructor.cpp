#include <iostream>
#include <list>
#include "Point2D.h"

using namespace std;

void demoPushBackOrFront();
void demoPrintWithStandardForLoop();
void demoPrintWithReferenceForLoop();
void demoPrintWithPointerForLoop();
void demoEmplace();
void demoIterators();
void demoTemplatePrint();
void demoIteratorsWithPrint();

/// @brief Prints a list of Point2D
/// @param list
void print(list<Point2D> list)
{
	for (const Point2D& p : list)
		cout << p << endl;
}

/// @brief Prints a list of Point2D using iterators
/// @param iter
/// @param end
void print(list<Point2D>::iterator iter, list<Point2D>::iterator end)
{
	while (iter != end)
	{
		cout << *iter << endl;
		iter++;
	}
}

/// @brief Prints a list containing any type (e.g. int, float, bool, string, Point2D, BackAccount etc)
/// @tparam E
/// @param list
template <typename E>
void print(list<E> list)
{
	for (const E& theObj : list)
		cout << theObj << endl;
}

/// @brief Prints any data structure that can provide an iterator to the start and end of the structure
/// @tparam Iter
/// @param iter
/// @param end
template <typename Iter>
void print(Iter iter, Iter end)
{
	while (iter != end)
	{
		cout << *iter << endl;
		iter++;
	}
}

int main()
{
	cout << endl << "/************************** References & Pointers (in a List & For loop) ******************************/" << endl;

	cout << endl << "demoPushBackOrFront()..." << endl;
	demoPushBackOrFront();

	cout << endl << "demoEmplace()................................." << endl;
	demoEmplace();

	cout << endl << "demoPrintWithStandardForLoop()................................." << endl;
	demoPrintWithStandardForLoop();

	cout << endl << "demoPrintWithReferenceForLoop()................................." << endl;
	demoPrintWithReferenceForLoop();

	cout << endl << "demoPrintWithPointerForLoop()................................." << endl;
	demoPrintWithPointerForLoop();

	cout << endl << "/************************** Templates & Iterators ******************************/" << endl;

	cout << endl << "demoTemplatePrint()................................." << endl;
	demoTemplatePrint();

	cout << endl << "demoIterators()................................." << endl;
	demoIterators();

	cout << endl << "demoIteratorsWithPrint()................................." << endl;
	demoIteratorsWithPrint();
}

/// @brief Demonstrates that the push_back and push_front functions call the Point2D copy constructor when copying a point into the list - which is bad!
void demoPushBackOrFront()
{
	list<Point2D> pList;
	pList.push_back(Point2D(3, 4));
}

/// @brief Demonstrates that copying the object into the variable p, when using a for loop, is less efficent than the approach used in demoPrintWithReferenceForLoop()
void demoPrintWithStandardForLoop()
{
	list<Point2D> pList;

	//using emplace_front or emplace_back means we DONT call the Point2D copy constructor - which is good
	pList.emplace_front(3, 4);
	pList.emplace_front(6, 8);
	pList.emplace_front(9, 12);

	//using a for loop which copies the contents of each Point2D from the list into the variable p means that we DO call the Point2D copy constructor - which is bad!
	for (Point2D p : pList)
		cout << p << endl;
}

/// @brief Demonstrates that using a reference (&) when using a for loop is more efficent than the approach used in demoPrintWithStandardForLoop()
void demoPrintWithReferenceForLoop() {
	list<Point2D> pList;

	//using emplace_front or emplace_back means we dont call the Point2D copy constructor - which is good
	pList.emplace_front(3, 4);
	pList.emplace_front(6, 8);
	pList.emplace_front(9, 12);

	//using a for loop which copies a reference (see how we use &) to each Point2D from the list into the variable p means that we DONT call the Point2D copy constructor - which is good
	for (Point2D& p : pList)
		cout << p << endl;
}

/// @brief Demonstrates that storing pointers to an object is more efficient than storing a copy of the object in a list
void demoPrintWithPointerForLoop() {
	//storing pointers to an object (e.g. Point2D) in the list is preferable since it means that we DONT call the Point2D copy constructor - which is good
	list<Point2D*> pList;
	Point2D p1(1, 2);
	pList.push_back(&p1);
	Point2D p2(3, 4);
	pList.push_back(&p2);

	//using a for loop which copies a pointer (see how we use *) to each Point2D from the list into the variable ptr means that we DONT call the Point2D copy constructor - which is good
	for (Point2D* ptr : pList)
		cout << *ptr << endl;
}

/// @brief Demonstrates that the emplace_front (or emplace_back) functions DONT call the copy constructor of Point2D - which is good
void demoEmplace()
{
	list<Point2D> pList;
	pList.emplace_front(3, 4);
	pList.emplace_front(6, 8);
	pList.emplace_front(9, 12);
}

/// @brief Demonstrates the use of the template print() function for Point2D and string
void demoTemplatePrint() {
	list<Point2D> pList;
	pList.emplace_front(3, 4);
	pList.emplace_front(6, 8);
	pList.emplace_front(9, 12);
	print<Point2D>(pList);

	cout << endl << "lets use the same function to print strings..." << endl;
	//lets use the same function to print strings
	list<string> namesList;
	namesList.push_back("ana");
	namesList.push_back("bea");
	namesList.push_back("ciara");
	namesList.push_back("dave");
	print<string>(namesList);
}

/// @brief Demonstrates how we can use iterators to access elements in a list
void demoIterators()
{
	list<int> numList;
	numList.emplace_back(10);
	numList.emplace_back(20);
	numList.emplace_back(30);

	//we can retrieve pointers to the (left of) the first and (right of) the last elements in the list
	list<int>::iterator start = numList.begin();
	list<int>::iterator end = numList.end();

	//de-reference the iterator (pointer)
	cout << *start << endl;

	//we can move those iterators using ++ or -- operators
	start++;
	cout << *start << endl;
	start--;
	cout << *start << endl;
}

/// @brief Demonstrates how we can use iterators in a template print function
void demoIteratorsWithPrint()
{
	list<int> numList;
	numList.emplace_back(10);
	numList.emplace_back(20);
	numList.emplace_back(30);

	//we can retrieve pointers to the (left of) the first and (right of) the last elements in the list
	list<int>::iterator start1 = numList.begin();
	list<int>::iterator end1 = numList.end();
	print<list<int>::iterator>(start1, end1);

	cout << endl << "lets use the same function to print strings..." << endl;

	//lets use the same function to print strings
	list<string> namesList;
	namesList.push_back("ana");
	namesList.push_back("bea");
	namesList.push_back("ciara");
	namesList.push_back("dave");

	//we can retrieve pointers to the (left of) the first and (right of) the last elements in the list
	list<string>::iterator start2 = namesList.begin();
	list<string>::iterator end2 = namesList.end();
	print<list<string>::iterator>(start2, end2);
}