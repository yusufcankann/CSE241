#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "List.h"
#include "Set.h"
#include "Collection.h"
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

namespace Java{


template<class E,class C=std::vector<E> >
class ArrayList: public List<E,C> {
public:
	ArrayList();
	ArrayList(C& c);

	/*BIG THREE*/
	ArrayList(const ArrayList &set);
	ArrayList& operator=(ArrayList &set);
	~ArrayList();

	Iterator<E,C> iterator()throw();
	void add(E e)throw();
	void addAll(Collection<E,C> &c)throw();
	void clear()throw();
	bool contains(E e)throw();
	bool containsAll(Collection<E,C> &c)throw();
	bool isEmpty()throw();
	void remove(E e)throw(ZeroSize);
	void removeAll(Collection<E,C> &c)throw();
	void retainAll(Collection<E,C> &c)throw();
	int size()throw();


	void printElements()throw(); /* This function helps the driver file. It only helps print the current
						   * elements on the screen.*/
private:
	C *inner;
};
}


#endif
