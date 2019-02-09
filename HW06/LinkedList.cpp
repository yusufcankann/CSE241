#include "LinkedList.h"

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
template<class E,class C>
LinkedList<E,C>::LinkedList(){ }

template<class E,class C>
LinkedList<E,C>::LinkedList(C& c){
	inner = new C;
	typename C::reverse_iterator i;
	typename C::iterator temp=(*inner).begin();

	for(i=c.rbegin();i!=c.rend();++i){
		temp=(*inner).insert(temp,*i);
	}
}

/*Copy constructer.*/
template<class E,class C>
LinkedList<E,C>::LinkedList(const LinkedList &c){

	/*First it controls if elements are the same or what?*/
	if((&c) != inner ){
		/*It controls the pointer is null or what.*/
		if(inner != nullptr)
			delete inner;

		/*It creates new inner and assignes all values in it.*/
		inner = new C;
		typename C::reverse_iterator i;
		typename C::iterator temp=(*inner).begin();

		this->addAll(c);
	}
}

/*Assignment operator.*/
template<class E,class C>
LinkedList<E,C>& LinkedList<E,C>::operator=(LinkedList &c){
	/*First it controls if elements are the same or what?*/
	if(this->containsAll(c))
		return *this;
	/*It controls the pointer is null or what.*/
	if(inner != nullptr)
		delete inner;
	/*It creates new inner and assignes all values in it.*/
	inner = new C;
	typename C::reverse_iterator i;
	typename C::iterator temp=(*inner).begin();

	this->addAll(c);
	return *this;
}

template<class E,class C>
LinkedList<E,C>::~LinkedList(){
	delete inner;
}

template<class E,class C>
Iterator<E,C> LinkedList<E,C>::iterator()throw(){
	Iterator<E,C> iter(*inner);
	return iter;
}

/*
 * It adds the element.
 */
template<class E,class C >
void LinkedList<E,C>::add(E e)throw(){
	typename C::iterator x= (*inner).end();
		(*inner).insert(x,e);
}

/*It adds all the element inside the collection.*/
template<class E,class C>
void LinkedList<E,C>::addAll(Collection<E,C> &c)throw(){
	Iterator<E,C> iter = c.iterator();
	while(iter.hasNext()){
		(this)->add(*(iter.getIterator()));
		iter.next();
	}
	(this)->add(*(iter.getIterator()));/*last element.*/
}

/*Clears the inner shape.*/
template<class E,class C >
void LinkedList<E,C>::clear()throw(){
	(*inner).clear();
}

/*Checks every element if it contains or not.*/
template<class E,class C>
bool LinkedList<E,C>::contains(E e)throw(){
	for(auto a:(*inner)){
		if(a==e) return 1;
	}
	return 0;
}

/*Check every element for every collection element if its contains or not.*/
template<class E,class C >
bool LinkedList<E,C>::containsAll(Collection<E,C> &c)throw(){
	bool a=0;
	Iterator<E,C> iter = c.iterator();

	while(iter.hasNext() ){
		if( !((*this).contains(*(iter.getIterator())) ) ) a=1;

		if(a==1) return 0;

		a=0;
		iter.next();
	}
	/*While loop doesn't check the last element. I check it above.*/
	if( !((*this).contains(*(iter.getIterator())) ) ) return 0;

	return 1;
}

template<class E,class C >
bool LinkedList<E,C>::isEmpty()throw(){
	return ((*inner).empty());
}

template<class E,class C >
void LinkedList<E,C>::remove(E e)throw(ZeroSize){
	Iterator<E,C> iter((*inner));/*It creates an iterator for inner.*/
	int counter=0;
	try{
		if((*inner).size() == 0){ /*If inner size 0 , it throws exception.*/
			throw(ZeroSize() );
		}

		int size = (*inner).size(); /*Tooks the size.*/

		/*Goes inside inner.*/
		while(iter.hasNext()){
			counter++;/*Counts every element.*/
			/*If it is found it deletes.*/
			if(*(iter.getIterator()) == e){

				iter.remove();
				counter++;/*It increases the counter because erase
						   *moves iterator 1 forward.*/
			}
			if(counter != size)/*If it is not last element it is goes forward.*/
				iter.next();
		}
		/*Here it checks the last element. If last element must be deleted than it creates
		 * new inner.
		 *
		 * The reason why we did that is when erase deletes last element it want go 1 forward.
		 * We don't have any element after last element. It gives us error.*/
		if( (*iter.getIterator()) == e){
			C *ptr = new C;
			C *ptr2 = new C;
			typename C::iterator temppp=((*inner).begin());
			typename C::iterator temppp1=next(temppp,size-1);
			typename C::iterator ite = (*ptr).begin();
			typename C::iterator ite2 = (*ptr2).begin();
			int x=0;

			for(auto i = inner->begin(); i!= inner->end();i++){
				if(x!=size-1){
					ite = (*ptr).insert(ite,(*i));
				}
				x++;
			}
			x=0;

			/*I used this loop because */
			for(auto i = ptr->begin(); i!= ptr->end();i++){
				if(x!=size-1){
					ite2 = (*ptr2).insert(ite2,(*i));
				}
				x++;
			}
			delete inner;
			delete ptr;
			inner = ptr2;
		}
	}catch(ZeroSize &a){
		a.getMessage();
	}
}

/*It checks every element. If it is in collection then remove function calls.*/
template<class E,class C >
void LinkedList<E,C>::removeAll(Collection<E,C> &c)throw(){
	Iterator<E,C> iter  = c.iterator();
	while (iter.hasNext()){
		(this)->remove((*(iter.getIterator())));
		iter.next();
	}
	(this)->remove((*(iter.getIterator())));
}


/*It deletes all elements except the given collection.*/
template<class E,class C >
void LinkedList<E,C>::retainAll(Collection<E,C> &c)throw(){
	bool a=0;
	bool mark=0;

	Iterator<E,C> iter = c.iterator();/*For collection iterator*/
	Iterator<E,C> iterinner((*inner));/*It creates an iterator for inner.*/

	while(iterinner.hasNext()){/*It controls inner iterator.*/
		/*It turns collection iterator for every inner iterator.*/
		while(iter.hasNext()){

			/*
			 * If element is in the collection then it marks that. And if element doesn't mark
			 * It deletes it below.
			 */
			if( (*(iterinner.getIterator())) == (*(iter.getIterator()))  ){
				a=1;
			}
			iter.next();/*Collection iterator goes one forward.*/
		}
		if( (*(iterinner.getIterator())) == (*(iter.getIterator()))  ){
			/*For last element of collection set.*/
			a=1;
		}
		if(a!=1){
			/*If element doesn't in the collection it deletes it.*/
			iterinner.remove();
			//this->remove( *(iterinner.getIterator()) );
			mark=1;
		}
		iter = c.iterator();/*Resets the collection iterator.*/
		if(mark!=1) iterinner.next();/*It pushes forward to inner iterator.*/
		a=0;
		mark=0;
	}
	/*It controls the last element of inner the same way.*/
	a=0;
	iter = c.iterator();
	/*Goes all collections.*/
	while(iter.hasNext()){
		/*If element is in the collection it marks it.*/
		if( (*(iterinner.getIterator())) == (*(iter.getIterator()))  ){
			a=1;
		}
		iter.next();
	}
	/*Controls the collections last element.*/
	if( (*(iterinner.getIterator())) == (*(iter.getIterator()))  ){
		a=1;
	}
	/*If it is not in the list it deletes it.*/
	if(a!=1){
		iterinner.remove();
		//this->remove( *(iterinner.getIterator()) );
	}
}

template<class E,class C >
int LinkedList<E,C>::size()throw(){
	return (*inner).size();
}

template<class E,class C>
void LinkedList<E,C>::printElements()throw(){
	for(auto i : (*inner)){
		cout<<" "<<i<<" ";
	}
}

template<class E,class C>
E LinkedList<E,C>::element()throw(){
	return (*(inner->begin() ));
}
template<class E,class C>
void LinkedList<E,C>::offer(E e)throw(){
	this->add(e);
}
template<class E,class C>
E LinkedList<E,C>::poll()throw(){
	try{
		if(inner->size() == 0)
			throw EmptyQueue();

		E temp;
		temp = (*(inner->begin()));
		inner->erase((inner->begin()));

		return temp;

	}
	catch(EmptyQueue &a){
		a.getMessage();
	}

	return *(inner->begin());
}
}








