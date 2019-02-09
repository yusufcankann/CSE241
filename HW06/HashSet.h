#ifndef HASHSET_H_
#define HASHSET_H_

#include "Set.h"
#include "Collection.h"
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;


/*
 * Because of this is list, elements cannot be twice.
 * When user tries to add same element program throw
 * this exception class.
 */



namespace Java{
template<class E,class C=std::vector<E> >
class HashSet: public Set<E,C> {
public:
	HashSet();
	HashSet(C& c);

	/*BIG THREE*/
	HashSet(const HashSet &set);
	HashSet& operator=(HashSet &set);
	~HashSet();

	Iterator<E,C> iterator()throw();
	void add(E e)throw(Duplicate);
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
#endif /* HASHSET_H_ */
