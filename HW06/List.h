
#ifndef LIST_H_
#define LIST_H_

#include "Collection.h"

namespace Java{
template<class E,class C=std::vector<E> >
class List:virtual public Collection<E,C> {
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

#endif /* LIST_H_ */
