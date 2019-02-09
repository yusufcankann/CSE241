#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <vector>
#include <iostream>

using namespace std;





/*No next element exception class*/
class NextElem1{
public:
	NextElem1();
	NextElem1(string a_){a=a_;}
	void getMessage(){ cout<<"There is no next element...";}

private:
	string a;
};




namespace Java{
template<typename D,typename C >
class Iterator {
public:
	Iterator(C& a);
	bool hasNext()throw();
	D next()throw(NextElem1);
	void remove()throw(NextElem1);
	typename C::iterator getIterator()const;


private:
	typename C::iterator iter;
	C *data;


};
}

#endif /* ITERATOR_H_ */
