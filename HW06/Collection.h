#ifndef COLLECTION_H_
#define COLLECTION_H_

#include <vector>
#include <iostream>

#include "Iterator.h"

namespace Java{
class Duplicate{
	public:
		Duplicate(string a_){
			a=a_;
		}
		void getMessage(){
			cout<<endl<<"Same elements is already in the class.("<<a<<")"<<endl;
		}
	private:
		string a;
};


/*If the stl type variables size is 0 then this exceptin class will be thrown.*/
class ZeroSize{
	public:
		ZeroSize(){ }
		void getMessage(){
			cout<<endl<<"Size is 0. You can't do any operation.!!"<<endl;
		}
};





template<class E,class C=std::vector<E> >
class Collection{

public:
	virtual Iterator<E,C> iterator()=0;
	virtual void add(E e)=0;
	virtual void addAll(Collection<E,C> &c)=0;
	virtual void clear()=0;
	virtual bool contains(E e)=0;
	virtual bool containsAll(Collection &c)=0;
	virtual bool isEmpty()=0;
	virtual void remove(E e)=0;
	virtual void removeAll(Collection &c)=0;
	virtual	void retainAll(Collection &c)=0;
	virtual int size()=0;

private:


};

}
#endif
