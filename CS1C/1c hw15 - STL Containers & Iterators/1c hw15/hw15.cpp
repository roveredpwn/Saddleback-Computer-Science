// hw15.cpp
// to illustrate stl containers & iterators

/*************************************************************************
 * AUTHOR     : Aaron Geesink
 * HW15       : stl containers & iterators
 * CLASS      : CS 1C
 * SECTION    : M T W Th - 3:00 PM
*************************************************************************/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::vector;

// function & class definitions go into hw15.cpp:

// hw15.cpp

namespace hw15 {

//
// list conainter, iterator example code adapted from Chapter 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

template<typename Elem>
struct Link
{
    Link* prev;    // previous link
    Link* succ;    // successor (next) link
    Elem  val;     // the value
    Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0) : val{v}, prev{p}, succ{s} { }
};

//--Q#3-------------------------------------------------------------------------

template<typename Elem>
class list
{
    // representation and implementation details
public:
    class iterator;         // forward declaration of member type: class iterator
    class const_iterator;   // forward declaration of member type: class const_iterator

    list() : first(new Link<Elem>()), last{first} { }
    ~list()
    {
        while (first != last)
        {
            Link<Elem> *next = first->succ;
            delete first;
            first = next;
        }
        delete last;
    }

    iterator begin();   // iterator to first element
    iterator end();     // iterator to one beyond last element

    // add missing const iterators begin, end here

	const iterator begin() const;  // constant iterator to first element
	const iterator end() const;  // constant iterator to one beyond last element

    iterator insert(iterator p, const Elem& v); // insert v into list after p
    iterator erase(iterator p);                 // remove p from the list

    void push_back(const Elem& v);  // insert v at end
    void push_front(const Elem& v); // insert v at front
    void pop_front();   // remove the first element
    void pop_back();    // remove the last element

    Elem& front();      // the first element
    Elem& back();       // the last element

    Link<Elem>* first;
    Link<Elem>* last;   // one-beyond-the-last link
};

//--Q#4-------------------------------------------------------------------------

template<typename Elem>
class list<Elem>::iterator // definition for class iterator
{
private:
    Link<Elem>* curr;   // current node

public:
    iterator(Link<Elem>* p) : curr{p} { }
    iterator& operator++() // forward
    {
		curr = curr->succ;
                        // temp, replace when defining function
        return *this; // included so that incomplete lab code will compile
    }
    iterator& operator--() // backwards
    {
		curr = curr->prev;
                        // temp, replace when defining function
        return *this; // included so that incomplete lab code will compile
    }
    Elem& operator*() // get value (dereference)
    {
                        // temp, replace when defining function
        return curr->val; // included so that incomplete lab code will compile
    }

    bool operator==(const iterator& rhs) const // lhs, rhs iterators point to the same node (equal)
    {
                      // temp, replace when defining function
        return this->curr == rhs.curr; // included so that incomplete lab code will compile
    }
    bool operator!=(const iterator& rhs) const // lhs, rhs iterators do not point to the same node (not equal)
    {
                      // temp, replace when defining function
        return this->curr != rhs.curr; // included so that incomplete lab code will compile
    }
};

//--Q#4-------------------------------------------------------------------------

template<typename Elem>
class list<Elem>::const_iterator // definition for class const_iterator
{
    const Link<Elem>* curr;   // current node
                              // node pointed to by curr is immutable (i.e. can't be changed)
                              // fine to modify curr pointer itself (i.e. pointer value stored in curr)
                              // refer to const correctness reading
public:

    // add missing constructor, overloaded ++, --, *, ==, != operators here
	const_iterator(Link<Elem>* p) : curr{ p } { }
	const iterator& operator++() // forward
	{
		curr = curr->succ;
		// temp, replace when defining function
		return this; // included so that incomplete lab code will compile
	}
	const iterator& operator--() // backwards
	{
		curr = curr->prev;
		// temp, replace when defining function
		return this; // included so that incomplete lab code will compile
	}
	const Elem& operator*() // get value (dereference)
	{
		// temp, replace when defining function
		return curr->val; // included so that incomplete lab code will compile
	}

	const bool operator==(const iterator& rhs) const // lhs, rhs iterators point to the same node (equal)
	{
		// temp, replace when defining function
		return this->curr == rhs->curr; // included so that incomplete lab code will compile
	}
	const bool operator!=(const iterator& rhs) const // lhs, rhs iterators do not point to the same node (not equal)
	{
		// temp, replace when defining function
		return this->curr != rhs->curr; // included so that incomplete lab code will compile
	}
    
};

//------------------------------------------------------------------------------

template<typename Elem> 
typename list<Elem>::iterator list<Elem>::begin()  // iterator to first element
{ 
    return iterator(first); 
}

//--Q#3-------------------------------------------------------------------------

// constant iterator to first element
template<typename Elem>
typename const list<Elem>::iterator list<Elem>::begin() const // iterator to first element
{
	return iterator(first);
}

//------------------------------------------------------------------------------

template<typename Elem> 
typename list<Elem>::iterator list<Elem>::end() // iterator to one beyond last element
{ 
    return iterator(last); 
}

//--Q#3-------------------------------------------------------------------------

// constant iterator to last element

template<typename Elem>
typename const list<Elem>::iterator list<Elem>::end() const // iterator to one beyond last element
{
	return iterator(last);
}

//------------------------------------------------------------------------------

template<typename Elem> 
void list<Elem>::push_front(const Elem& v) // insert v at front
{
    first = new Link<Elem>(v,0,first);
}

//
// low algorithms adapted from Chapter 20.1, 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//--Q#5-------------------------------------------------------------------------

double* low_doubles(double* first, double* last)
    // return a pointer to the element in [first,last) that has the lowest value
{
    double l = -1;
    double* low = first;
    for(double* p = first; p!=last; ++p)
        if (*p < l) { low = p; l = *p; }
    return low;
}

//--Q#5-------------------------------------------------------------------------

// implement templated low algorithm here

template <class iterator>
iterator low(iterator first, iterator last)
    // return a pointer to the element in [first,last) that has the lowest value
{
	//iterator low = first;
	for (iterator p = first; p != last; ++p)
	{
		if (*p < *first)
		{
			first = p;
		}
	}
    return first;
}

//------------------------------------------------------------------------------

} // hw15

//------------------------------------------------------------------------------

using namespace hw15;

//
// list conainter, iterator example code adapted from Chapter 20.4
// low algorithms adapted from Chapter 20.1, 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

int main()
{
    // console header
	cout << endl;
	cout << "************************************** " << endl;
	cout << "*           Running HW15             * " << endl;
	cout << "*      Programmed by Aaron Geesink   * " << endl;
	cout << "*         CS1C M T W Th 3:00 PM      * " << endl;
	cout << "************************************** " << endl;
	cout << endl;

	// Q#3,4 - containters & iterators

    list<int> myList;
	for (int i = 2; i < 10; i++)
	{
		cout << i << endl;
		myList.push_front(i);
	}

	// Q#5 - low_doubles algorithm

    double d[] = {1,2,3,4,5,-99.25,100,10,500.123,5};       // init array of doubles
    vector<double> v = {1,2,3,4,5,-99.25,100,10,500.123,5}; // init identical vector of doubles

    double* lowa = low_doubles(&d[0], &d[9]); // min of array
    cout << endl << "low_doubles alg: double array min value is " << *lowa << endl << endl;

    double* middle = &v[0] + v.size()/2;
    double* lowv1 = low_doubles(&v[0], middle);          // min of vector first half
    double* lowv2 = low_doubles(middle, &v[0]+v.size()); // min of vector second half
    cout << "low_doubles alg: double vector min value first half is " << *lowv1 << endl;
    cout << "low_doubles alg: double vector min value second half is " << *lowv2 << endl << endl;

	// Q#5 - low algorithm

    // NOTE: uncomment code below once low algorithm definition is complete

    lowa = low(&d[0], &d[9]); // min of array
    cout << "low alg: double array min value is " << *lowa << endl << endl;

    lowv1 = low(&v[0], middle);          // min of vector first half
    lowv2 = low(middle, &v[0]+v.size()); // min of vector second half
    cout << "low alg: double vector min value first half is " << *lowv1 << endl;
    cout << "low alg: double vector min value second half is " << *lowv2 << endl << endl;

    list<int>::iterator p = low(myList.begin(), myList.end()); // min of list
    if (p==myList.end())    // did we reach the end?
        cout << "low alg: the list is empty";
    else
        cout << "low alg: the lowest value in the list is " << *p << "\n\n";

	system("pause");
    return 0;
}

//------------------------------------------------------------------------------

// WRITTEN ANSWERS

// Q#1
/*
An STL container is a templated class that can store a set of data. Vectors, Linked Lists,
Queues, and Stacks are all examples of STL containers. many of them can either be node based or array based.
An STL iterator is a pointer to data in an STL class. iterators allow you to
use pointer arithmetic to access a container's data. The begin() and end() functions are
both examples of functions that return iterators to elements in a container. Some type of iterators
include input and output iterators, forward iterators, and bidirectional iterators. All STL containers
have some kind of iterator implementation. STL algorithms are a set of functions that modify and process
data. iterators to element locations in STL containers are used by STL algorithms 
to process data within the containers. sort, copy, swap, and move are all examples 
of STL algorithms.
*/

// Q#2
/*
Iterators allow for the decoupling of algorithms and container class into seperate implementations
by allowing for pointers to multiple elements in a container to be passed as an argument for algorithms
rather than passing the container itself. All the algorithm needs is the iterator for the beginning and
end of a container, and it can iterate and process the entire container without worrying about its 
implementation. This allows for the implementation of algorithms to be used
on every container class without having to implement additional functionality, as we can access
memory locations within a container and modify those memory locations directly.
*/

// Q#5
/*
The low_doubles might cause an issue if no value in the array is less than -1 as that is what
low is assigned to, so the low doubles array does not work for negative integers. low_double and low are similar because
they both iterate through a list using pointers to return the lowest value it can find in that list. they are different
because low_doubles can only return double pointers, while low can return a pointer of any implemented
iterator as it is implemented using STL algorithm standards. with its default implementation, the low_doubles function does not compile,
as low is never initialized. We can fix this by setting l to first, but this fixes the function and removes any
discrepencies between low and low doubles.
*/