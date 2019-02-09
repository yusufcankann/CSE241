#include "Iterator.h"
#include <iostream>
#include <list>
#include <iterator>
#include <vector>





namespace Java{


template<class D,class C>
Iterator<D,C>::Iterator(C& a){
	iter = a.begin();
	data = &a;
}
template<class D,class C>
bool Iterator<D,C>::hasNext()throw(){
	typename C::iterator temp = iter;
	if((++temp) != (data)->end() ) return 1;
	else return 0;
}


template<class D,class C>
D Iterator<D,C>::next()throw(NextElem1){

try{
	if( !(this->hasNext())){
		throw NextElem1("error");
	}
	return (*(++iter));
	}
	catch(NextElem1 &a){
		a.getMessage();
	}

	return (*(iter));
}

template<class D,class C>
void Iterator<D,C>::remove()throw(NextElem1){
try{
	if( !(this->hasNext())){
		throw NextElem1("error");
	}
	iter = data->erase(iter);
}
catch(NextElem1 &a){
	a.getMessage();
}
}

template<class D,class C>
typename C::iterator Iterator<D,C>::getIterator()const{
	return iter;
}



}

