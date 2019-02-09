#ifndef QUEUE_H_
#define QUEUE_H_

#include "Collection.h"

namespace Java{

/*For offer function.*/
class EmptyQueue{
public:
	EmptyQueue(){ };
	void getMessage(){ cout<<"Queue is empty";}
};


template<class E,class C=std::vector<E> >
class Queue:virtual public Collection<E,C>{
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

	virtual E element()=0;
	virtual void offer(E e)=0;
	virtual E poll()=0;
private:

};
}
#endif /* QUEUE_H_ */
