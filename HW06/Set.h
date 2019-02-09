#ifndef SET_H_
#define SET_H_

#include "Collection.h"
#include <iostream>

namespace Java{
template<class E,class C=std::vector<E> >
class Set: public Collection<E,C> {

public:
	virtual Iterator<E,C> iterator()=0;
	virtual void add(E e)=0;
	virtual void addAll(Collection<E,C> &c)=0;
	virtual void clear()=0;
	virtual bool contains(E e)=0;
	virtual bool containsAll(Collection<E,C> &c)=0;
	virtual bool isEmpty()=0;
	virtual void remove(E e)=0;
	virtual void removeAll(Collection<E,C> &c)=0;
	virtual	void retainAll(Collection<E,C> &c)=0;
	virtual int size()=0;

private:

};
}
#endif /* SET_H_ */
