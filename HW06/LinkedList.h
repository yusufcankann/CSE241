#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "List.h"
#include "Queue.h"

namespace Java{
template<class E,class C=std::vector<E> >
class LinkedList: public List<E,C>, public Queue<E,C> {
public:
	LinkedList();
	LinkedList(C& c);

	/*BIG THREE*/
	LinkedList(const LinkedList &set);
	LinkedList& operator=(LinkedList &set);
	~LinkedList();

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

	E element()throw();
	void offer(E e)throw();
	E poll()throw();


	void printElements()throw(); /* This function helps the driver file. It only helps print the current
						   * elements on the screen.*/
private:
	C *inner;
};
}
#endif /* LINKEDLIST_H_ */
