/*161044007 - Yusuf Can Kan*/









/*
 * At the first look code seems too long but it doesn't.
 *
 * My tests goes with some order and with that order I tested every function.
 *
 * My driver file goes that order;
 * =>Iterator
 * 		=>Iterator Array int tests.
 * 		=>Iterator Array string tests
 * 		=>Iterator List int tests.
 * 		=>Iterator List string tests.
 * 		=>Iterator Set int tests.
 * 		=>Iterator Set String tests.
 * -=>HashSet
 * 		=>HashSet Array int tests.
 * 		=>HashSet Array string tests
 * 		=>HashSet List int tests.
 * 		=>HashSet List string tests.
 * 		=>HashSet Set int tests.
 * 		=>HashSet Set String tests.
 * =>ArrayList
 * 		=>ArrayList Array int tests.
 * 		=>ArrayList Array string tests
 * 		=>ArrayList List int tests.
 * 		=>ArrayList List string tests.
 * 		=>ArrayList Set int tests.
 * 		=>ArrayList Set String tests.
 *  =>LinkedList
 * 		=>LinkedList Array int tests.
 * 		=>LinkedList Array string tests
 * 		=>LinkedList List int tests.
 * 		=>LinkedList List string tests.
 * 		=>LinkedList Set int tests.
 * 		=>LinkedList Set String tests.
 * 	=>Exception Tests.
 *
 *
 *		When you runing the code if you examine the code at the same time, you can see every function will be tested.
 *
 *
 * 		I tested every function with every combination.(set-list-array).
 *
 *
 *
 *
 *
 *
 * 		In remove function there is some bug. When user tries to delete last element of some stl type with erase() function,
 * 		stl::erase() automatically pushes iterator 1 forward. But 1 forward is doesn't belong to us so compiler gives us sementation fault.
 *
 * 		I solved that problem and I tested it in my code.So that is the reason why my remove function is long.
 *
 * 		At remove function tests i delete the last element. You can see it in there.
 *
 *
 *
 * 		There will be some warning because of somefunction()throw();.
 *
 * 		Throw list defining deprecated from cpp. That is the reason some warning.
 *
 * 		But we learn that in class so i used it.
 *
 *
 *
 *
 *
 *
 */





























#include <iostream>
#include "Collection.h"
#include "Set.h"
#include "Queue.h"
#include "List.h"
#include <vector>
#include <list>
#include <set>
#include "HashSet.h"
#include "HashSet.cpp"
#include "ArrayList.cpp"
#include <string>
#include "LinkedList.cpp"

using namespace std;
using namespace Java;



int main(){


/*Combination Implementations*/
/*----------------------------------------------------*/
	vector <int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	Iterator<int,vector<int> > itervec1(vec);
/*----------------------------------------------------*/
	vector <string> vecs;
	vecs.push_back("yusuf");
	vecs.push_back("can");
	vecs.push_back("kan");
	vecs.push_back("GTU");
	vecs.push_back("Computer Engineering");
	Iterator<string,vector<string> > itervec2(vecs);
/*----------------------------------------------------*/
	list <int> list1;
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);
	list1.push_back(6);
	Iterator<int,list<int> > iterlist1(list1);
/*----------------------------------------------------*/

	list <string> list2;
	list2.push_back("yusuf");
	list2.push_back("can");
	list2.push_back("kan");
	list2.push_back("GTU");
	list2.push_back("Computer Engineering");
	Iterator<string,list<string> > iterlist2(list2);
/*---------------------------------------------------*/

	int arrset[4] = {3,4,5,6};
	std::set<int> set1 (arrset,arrset+4);
	Iterator<int,set<int> > iterset1(set1);

/*----------------------------------------------------*/

	string arrset2[5] = {"yusuf","can","kan","GTU","Computer Engineering"};
	std::set<string> set2(arrset2,arrset2+5);
	Iterator<string,set<string> > iterset2(set2);

/*----------------------------------------------------*/



	cout<<endl<<endl<<"----------ITERATOR TEST----------";

	cout<<endl<<"------Vector-------";
	cout<<endl<<endl;
	cout<<"=>For vector<int>"<<endl;
	cout<<"Vector inside elements= 3-4-5-6"<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<itervec1.hasNext()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<itervec1.next()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<itervec1.next()<<endl;
	cout<<"Current element="<<(*(itervec1.getIterator()))<<endl;
	cout<<"Iter.remove();"<<endl;
	itervec1.remove();
	cout<<"Current element="<<(*(itervec1.getIterator()))<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<itervec1.hasNext()<<endl;

	cout<<endl<<"=>For vector<string>"<<endl;
	cout<<"Vector inside elements= \"yusuf\"-\"can\"-\"kan\"-\"GTU\"-\"Computer Engineering\" "<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<itervec2.hasNext()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<itervec2.next()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<itervec2.next()<<endl;
	cout<<"Current element="<<(*(itervec2.getIterator()))<<endl;
	cout<<"Iter.remove();"<<endl;
	itervec2.remove();
	cout<<"Current element="<<(*(itervec2.getIterator()))<<endl;
	cout<<"Iter.Next() returns=";
	cout<<itervec2.next()<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<itervec2.hasNext()<<endl;
/*----------------------------------------------*/
	cout<<endl<<"------List-------";
	cout<<endl<<endl;
	cout<<"=>For list<int>"<<endl;
	cout<<"List inside elements= 3-4-5-6"<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<iterlist1.hasNext()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<iterlist1.next()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<iterlist1.next()<<endl;
	cout<<"Current element="<<(*(iterlist1.getIterator()))<<endl;
	cout<<"Iter.remove();"<<endl;
	iterlist1.remove();
	cout<<"Current element="<<(*(iterlist1.getIterator()))<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<iterlist1.hasNext()<<endl;

	cout<<endl<<"=>For list<string>"<<endl;
	cout<<"List inside elements= \"yusuf\"-\"can\"-\"kan\"-\"GTU\"-\"Computer Engineering\" "<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<iterlist2.hasNext()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<iterlist2.next()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<iterlist2.next()<<endl;
	cout<<"Current element="<<(*(iterlist2.getIterator()))<<endl;
	cout<<"Iter.remove();"<<endl;
	iterlist2.remove();
	cout<<"Current element="<<(*(iterlist2.getIterator()))<<endl;
	cout<<"Iter.Next() returns=";
	cout<<iterlist2.next()<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<iterlist2.hasNext()<<endl;
/*----------------------------------------------*/

	cout<<endl<<"------Set-------";
	cout<<endl<<endl;
	cout<<"=>For set<int>"<<endl;
	cout<<"Set inside elements= 3-4-5-6     NOTE:Because it is set it's order will be random."<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<iterset1.hasNext()<<endl;

	cout<<"Iter.Next() returns=";
	cout<<iterset1.next()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<iterset1.next()<<endl;
	cout<<"Current element="<<(*(iterset1.getIterator()))<<endl;
	cout<<"Iter.remove();"<<endl;
	iterset1.remove();
	cout<<"Current element="<<(*(iterset1.getIterator()))<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<iterset1.hasNext()<<endl;



	cout<<endl<<"=>For set<string>    NOTE:Because it is set it's order will be random."<<endl;
	cout<<"Set inside elements= \"yusuf\"-\"can\"-\"kan\"-\"GTU\"-\"Computer Engineering\" "<<endl;
	cout<<"Set.hasNext() returns=";
	cout<<iterset2.hasNext()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<iterset2.next()<<endl;
	cout<<"Iter.Next() returns=";
	cout<<iterset2.next()<<endl;
	cout<<"Current element="<<(*(iterset2.getIterator()))<<endl;
	cout<<"Iter.remove();"<<endl;
	iterset2.remove();
	cout<<"Current element="<<(*(iterset2.getIterator()))<<endl;
	cout<<"Iter.Next() returns=";
	cout<<iterset2.next()<<endl;
	cout<<"Iter.hasNext() returns=";
	cout<<iterset2.hasNext()<<endl;

/*----------------------------------------------*/










	/***********************************************************************************************************************/
	cout<<endl<<endl<<"----------------------------HASHSET TEST----------------------------"<<endl;

	vector <int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);

	vector <int> vec2;
	vec2.push_back(7);
	vec2.push_back(8);
	vec2.push_back(9);
	vec2.push_back(10);
	vec2.push_back(11);
	vec2.push_back(12);

	vector <int> vec3;
	vec3.push_back(4);
	vec3.push_back(5);
	vec3.push_back(6);

	HashSet<int,vector<int> > HashSet1(vec1);
	HashSet<int,vector<int> > HashSet2(vec2);
	HashSet<int,vector<int> > HashSet3(vec3);



	/***************************  VECTOR<INT> ****************************************/
	cout<<"=>=>==>=>=>=>>=> For vector<int> <=<=<=<=<=<=<=<="<<endl;



	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<int,vector<int> > hashsetiter = HashSet1.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current HashSet;"<<endl;
	cout<< *(hashsetiter.getIterator());
	while(hashsetiter.hasNext() != 0){
		hashsetiter.next();
		cout<<" "<< *(hashsetiter.getIterator());
	}



	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	HashSet1.add(20);
	cout<<endl<<"20 added HashSet1";
	HashSet1.add(21);
	cout<<endl<<"21 added HashSet1";
	HashSet1.add(22);
	cout<<endl<<"22 added HashSet1";
	HashSet1.add(23);
	cout<<endl<<"23 added HashSet1"<<endl<<endl;

	cout<<"Current HashSet;"<<endl;
	HashSet1.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"HashSet3 current elements;"<<endl;
	HashSet3.printElements();

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();

	cout<<endl<<"After HashSet1.addAll(HashSet3);";
	HashSet1.addAll(HashSet3);

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"HashSet2 current elements;"<<endl;
	HashSet2.printElements();

	cout<<endl<<"HashSet2.clear();";
	HashSet2.clear();

	cout<<endl<<"HashSet2.add(5);";
	HashSet2.add(5);

	cout<<endl<<"HashSet2 current elements;"<<endl;
	HashSet2.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();

	cout<<endl<<"HastSet1.contains(5) returns;"<<endl;
	cout<<HashSet1.contains(5);

	cout<<endl<<"HastSet1.contains(30) returns;"<<endl;
	cout<<HashSet1.contains(30);



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();

	cout<<endl<<"HashSet3 current elements;"<<endl;
	HashSet3.printElements();

	cout<<endl<<endl<<"HastSet1.containsAll(HashSet3) returns;"<<endl;
	cout<<HashSet1.containsAll(HashSet3);

	cout<<endl<<endl<<"HashSet3.add(50);"<<endl;
	HashSet3.add(50);

	cout<<endl<<"HastSet1.containsAll(HashSet3) returns;"<<endl;
	cout<<HashSet1.containsAll(HashSet3);



	cout<<endl<<endl<<"-----------";




	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"HashSet2.isEmpty() returns;"<<endl;
	cout<<HashSet2.isEmpty()<<endl;
	cout<<"HashSet2.clear();"<<endl;
	HashSet2.clear();
	cout<<"HashSet2.isEmpty() returns;"<<endl;
	cout<<HashSet2.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();

	cout<<endl<<endl<<"HashSet1.remove(6)"<<endl;
	HashSet1.remove(6);
	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();

	cout<<endl<<endl<<"HashSet1.remove(2)"<<endl;
		HashSet1.remove(2);
		cout<<endl<<"HashSet1 current elements;"<<endl;
		HashSet1.printElements();




	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	HashSet2.add(20);
	HashSet2.add(22);
	HashSet2.add(23);

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();

	cout<<endl<<"HashSet2 current elements;"<<endl;
	HashSet2.printElements();

	cout<<endl<<endl<<"HashSet1.removeAll(HashSet2);"<<endl;
	HashSet1.removeAll(HashSet2);

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	HashSet3.clear();
	HashSet3.add(21);
	HashSet3.add(4);
	HashSet3.add(5);

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();

	cout<<endl<<"HashSet3 current elements;"<<endl;
	HashSet3.printElements();

	cout<<endl<<endl<<"HashSet1.retainAll(HashSet3);";
	HashSet1.retainAll(HashSet3);

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"size() function test;"<<endl;
	cout<<"HashSet1.size() returns;"<<endl;
	cout<<HashSet1.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();

	cout<<endl<<"HashSet2 current elements;"<<endl;
	HashSet2.printElements();
	cout<<endl<<"HashSet1 = HashSet2"<<endl;
	HashSet1 = HashSet2;
	cout<<endl<<"HashSet1 current elements;"<<endl;
	HashSet1.printElements();

	cout<<endl<<"-----------";


cout<<endl<<endl<<endl;


/**************************************************************************************/
	cout<<endl<<endl<<"=>=>=>=>VECTOR STRING TEST<=<=<=<="<<endl<<endl;
	vector <string> vec4;
	vec4.push_back("yusuf");
	vec4.push_back("can");
	vec4.push_back("kan");

	vector <string> vec5;
	vec5.push_back("GEBZE");
	vec5.push_back("TEKNIK");
	vec5.push_back("UNIVERSITESI");
	vec5.push_back("BM");
	vec5.push_back("CSE");
	vec5.push_back("GTU");

	vector <string> vec6;
	vec6.push_back("CSE241");
	vec6.push_back("OOP");
	vec6.push_back("JAVA");

	HashSet<string,vector<string> > HashSet4(vec4);
	HashSet<string,vector<string> > HashSet5(vec5);
	HashSet<string,vector<string> > HashSet6(vec6);




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<string,vector<string> > hashsetiter1 = HashSet4.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current HashSet;"<<endl;
	cout<< *(hashsetiter1.getIterator());
	while(hashsetiter1.hasNext() != 0){
		hashsetiter1.next();
		cout<<" "<< *(hashsetiter1.getIterator());
	}




	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	HashSet4.add("kitap");
	cout<<endl<<"'kitap' added HashSet1";
	HashSet4.add("defter");
	cout<<endl<<"'defter' added HashSet1";
	HashSet4.add("kalem");
	cout<<endl<<"'kalem' added HashSet1";
	HashSet4.add("YCK");
	cout<<endl<<"'YCK' added HashSet1"<<endl<<endl;

	cout<<"Current HashSet;"<<endl;
	HashSet4.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"HashSet6 current elements;"<<endl;
	HashSet6.printElements();

	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();

	cout<<endl<<endl<<"After HashSet4.addAll(HashSet6);"<<endl;
	HashSet4.addAll(HashSet6);

	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();



	cout<<endl<<endl<<"-----------";


	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"HashSet5 current elements;"<<endl;
	HashSet5.printElements();

	cout<<endl<<"HashSet5.clear();";
	HashSet5.clear();

	cout<<endl<<"HashSet5.add('ALI');";
	HashSet5.add("ALI");

	cout<<endl<<"HashSet5 current elements;"<<endl;
	HashSet5.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();

	cout<<endl<<"HastSet4.contains('OOP') returns;"<<endl;
	cout<<HashSet4.contains("OOP");

	cout<<endl<<"HastSet1.contains('asd') returns;"<<endl;
	cout<<HashSet4.contains("asd");



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();

	cout<<endl<<"HashSet6 current elements;"<<endl;
	HashSet6.printElements();

	cout<<endl<<endl<<"HastSet4.containsAll(HashSet6) returns;"<<endl;
	cout<<HashSet4.containsAll(HashSet6);

	cout<<endl<<endl<<"HashSet6.add('COMPUTER');"<<endl;
	HashSet6.add("COMPUTER");

	cout<<endl<<"HastSet1.containsAll(HashSet6) returns;"<<endl;
	cout<<HashSet4.containsAll(HashSet6);



	cout<<endl<<endl<<"-----------";




	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"HashSet5.isEmpty() returns;"<<endl;
	cout<<HashSet5.isEmpty()<<endl;
	cout<<"HashSet5.clear();"<<endl;
	HashSet5.clear();
	cout<<"HashSet5.isEmpty() returns;"<<endl;
	cout<<HashSet5.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();

	cout<<endl<<endl<<"HashSet4.remove('OOP')"<<endl;
	HashSet4.remove("OOP");
	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();

	cout<<endl<<endl<<"HashSet4.remove('JAVA')"<<endl;
		HashSet4.remove("JAVA");
		cout<<endl<<"HashSet4 current elements;"<<endl;
		HashSet4.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	HashSet5.add("kitap");
	HashSet5.add("defter");
	HashSet5.add("kalem");

	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();

	cout<<endl<<"HashSet5 current elements;"<<endl;
	HashSet5.printElements();

	cout<<endl<<endl<<"HashSet4.removeAll(HashSet5);"<<endl;
	HashSet4.removeAll(HashSet5);

	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	HashSet6.clear();
	HashSet6.add("kan");
	HashSet6.add("can");


	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();

	cout<<endl<<"HashSet6 current elements;"<<endl;
	HashSet6.printElements();

	cout<<endl<<endl<<"HashSet4.retainAll(HashSet6);";
	HashSet4.retainAll(HashSet6);

	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();



	cout<<endl<<"-----------";

	cout<<endl<<"size() function test;"<<endl;
	cout<<"HashSet4.size() returns;"<<endl;
	cout<<HashSet4.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();

	cout<<endl<<"HashSet5 current elements;"<<endl;
	HashSet5.printElements();
	cout<<endl<<"HashSet4 = HashSet5"<<endl;
	HashSet4 = HashSet5;
	cout<<endl<<"HashSet4 current elements;"<<endl;
	HashSet4.printElements();

	cout<<endl<<"-----------";















cout<<endl<<endl<<"**************************HASHSET LIST TEST*****************************"<<endl<<endl;



	list <int> vec7;
	vec7.push_back(1);
	vec7.push_back(2);
	vec7.push_back(3);

	list <int> vec8;
	vec8.push_back(7);
	vec8.push_back(8);
	vec8.push_back(9);
	vec8.push_back(10);
	vec8.push_back(11);
	vec8.push_back(12);

	list <int> vec9;
	vec9.push_back(4);
	vec9.push_back(5);
	vec9.push_back(6);

	HashSet<int,list<int> > HashSet7(vec7);
	HashSet<int,list<int> > HashSet8(vec8);
	HashSet<int,list<int> > HashSet9(vec9);




	/***************************  LIST<INT> ****************************************/
	cout<<"=>=>==>=>=>=>>=> For list<int> <=<=<=<=<=<=<=<="<<endl;




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<int,list<int> > hashsetiter2 = HashSet7.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current HashSet;"<<endl;
	cout<< *(hashsetiter2.getIterator());
	while(hashsetiter2.hasNext() != 0){
		hashsetiter2.next();
		cout<<" "<< *(hashsetiter2.getIterator());
	}




	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	HashSet7.add(20);
	cout<<endl<<"20 added HashSet7";
	HashSet7.add(21);
	cout<<endl<<"21 added HashSet7";
	HashSet7.add(22);
	cout<<endl<<"22 added HashSet7";
	HashSet7.add(23);
	cout<<endl<<"23 added HashSet7"<<endl<<endl;

	cout<<"Current HashSet;"<<endl;
	HashSet7.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"HashSet9 current elements;"<<endl;
	HashSet9.printElements();

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();

	cout<<endl<<"After HashSet7.addAll(HashSet9);";
	HashSet7.addAll(HashSet9);

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"HashSet8 current elements;"<<endl;
	HashSet8.printElements();

	cout<<endl<<"HashSet8.clear();";
	HashSet8.clear();

	cout<<endl<<"HashSet8.add(5);";
	HashSet8.add(5);

	cout<<endl<<"HashSet8 current elements;"<<endl;
	HashSet8.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();

	cout<<endl<<"HastSet1.contains(5) returns;"<<endl;
	cout<<HashSet7.contains(5);

	cout<<endl<<"HastSet1.contains(30) returns;"<<endl;
	cout<<HashSet7.contains(30);



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();

	cout<<endl<<"HashSet9 current elements;"<<endl;
	HashSet9.printElements();

	cout<<endl<<endl<<"HastSet1.containsAll(HashSet9) returns;"<<endl;
	cout<<HashSet7.containsAll(HashSet9);

	cout<<endl<<endl<<"HashSet9.add(50);"<<endl;
	HashSet9.add(50);

	cout<<endl<<"HastSet1.containsAll(HashSet9) returns;"<<endl;
	cout<<HashSet7.containsAll(HashSet9);



	cout<<endl<<endl<<"-----------";

	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"HashSet8.isEmpty() returns;"<<endl;
	cout<<HashSet8.isEmpty()<<endl;
	cout<<"HashSet8.clear();"<<endl;
	HashSet8.clear();
	cout<<"HashSet8.isEmpty() returns;"<<endl;
	cout<<HashSet8.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();

	cout<<endl<<endl<<"HashSet7.remove(6)"<<endl;
	HashSet7.remove(6);
	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();

	cout<<endl<<endl<<"HashSet7.remove(2)"<<endl;
	HashSet7.remove(2);
	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	HashSet8.add(20);
	HashSet8.add(22);
	HashSet8.add(23);

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();

	cout<<endl<<"HashSet8 current elements;"<<endl;
	HashSet8.printElements();

	cout<<endl<<endl<<"HashSet7.removeAll(HashSet8);"<<endl;
	HashSet7.removeAll(HashSet8);

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();


	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	HashSet9.clear();
	HashSet9.add(21);
	HashSet9.add(4);
	HashSet9.add(5);

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();

	cout<<endl<<"HashSet9 current elements;"<<endl;
	HashSet9.printElements();

	cout<<endl<<endl<<"HashSet7.retainAll(HashSet9);";
	HashSet7.retainAll(HashSet9);

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();



	cout<<endl<<"-----------";


	cout<<endl<<"size() function test;"<<endl;
	cout<<"HashSet7.size() returns;"<<endl;
	cout<<HashSet7.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();

	cout<<endl<<"HashSet8 current elements;"<<endl;
	HashSet8.printElements();
	cout<<endl<<"HashSet7 = HashSet8"<<endl;
	HashSet7 = HashSet8;
	cout<<endl<<"HashSet7 current elements;"<<endl;
	HashSet7.printElements();

	cout<<endl<<"-----------";

	cout<<endl<<endl<<endl;
























/**************************************************************************************/
cout<<endl<<endl<<"=>=>=>=>HASHSET LIST STRING TEST<=<=<=<="<<endl<<endl;
	list <string> vec10;
	vec10.push_back("yusuf");
	vec10.push_back("can");
	vec10.push_back("kan");

	list <string> vec11;
	vec11.push_back("GEBZE");
	vec11.push_back("TEKNIK");
	vec11.push_back("UNIVERSITESI");
	vec11.push_back("BM");
	vec11.push_back("CSE");
	vec11.push_back("GTU");

	list <string> vec12;
	vec12.push_back("CSE241");
	vec12.push_back("OOP");
	vec12.push_back("JAVA");

	HashSet<string,list<string> > HashSet10(vec10);
	HashSet<string,list<string> > HashSet11(vec11);
	HashSet<string,list<string> > HashSet12(vec12);




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<string,list<string> > hashsetiter3 = HashSet10.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current HashSet;"<<endl;
	cout<< *(hashsetiter3.getIterator());
	while(hashsetiter3.hasNext() != 0){
		hashsetiter3.next();
		cout<<" "<< *(hashsetiter3.getIterator());
	}




	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	HashSet10.add("kitap");
	cout<<endl<<"'kitap' added HashSet1";
	HashSet10.add("defter");
	cout<<endl<<"'defter' added HashSet1";
	HashSet10.add("kalem");
	cout<<endl<<"'kalem' added HashSet1";
	HashSet10.add("YCK");
	cout<<endl<<"'YCK' added HashSet1"<<endl<<endl;

	cout<<"Current HashSet;"<<endl;
	HashSet10.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"HashSet12 current elements;"<<endl;
	HashSet12.printElements();

	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();

	cout<<endl<<endl<<"After HashSet10.addAll(HashSet12);"<<endl;
	HashSet10.addAll(HashSet12);

	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();



	cout<<endl<<endl<<"-----------";


	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"HashSet11 current elements;"<<endl;
	HashSet11.printElements();

	cout<<endl<<"HashSet11.clear();";
	HashSet11.clear();

	cout<<endl<<"HashSet11.add('ALI');";
	HashSet11.add("ALI");

	cout<<endl<<"HashSet11 current elements;"<<endl;
	HashSet11.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();

	cout<<endl<<"HastSet4.contains('OOP') returns;"<<endl;
	cout<<HashSet10.contains("OOP");

	cout<<endl<<"HastSet1.contains('asd') returns;"<<endl;
	cout<<HashSet10.contains("asd");



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();

	cout<<endl<<"HashSet12 current elements;"<<endl;
	HashSet12.printElements();

	cout<<endl<<endl<<"HastSet4.containsAll(HashSet12) returns;"<<endl;
	cout<<HashSet10.containsAll(HashSet12);

	cout<<endl<<endl<<"HashSet12.add('COMPUTER');"<<endl;
	HashSet12.add("COMPUTER");

	cout<<endl<<"HastSet1.containsAll(HashSet12) returns;"<<endl;
	cout<<HashSet10.containsAll(HashSet12);



	cout<<endl<<endl<<"-----------";




	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"HashSet11.isEmpty() returns;"<<endl;
	cout<<HashSet11.isEmpty()<<endl;
	cout<<"HashSet11.clear();"<<endl;
	HashSet11.clear();
	cout<<"HashSet11.isEmpty() returns;"<<endl;
	cout<<HashSet11.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();

	cout<<endl<<endl<<"HashSet10.remove('OOP')"<<endl;
	HashSet10.remove("OOP");
	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();

	cout<<endl<<endl<<"HashSet10.remove('JAVA')"<<endl;
		HashSet10.remove("JAVA");
		cout<<endl<<"HashSet10 current elements;"<<endl;
		HashSet10.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	HashSet11.add("kitap");
	HashSet11.add("defter");
	HashSet11.add("kalem");

	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();

	cout<<endl<<"HashSet11 current elements;"<<endl;
	HashSet11.printElements();

	cout<<endl<<endl<<"HashSet10.removeAll(HashSet11);"<<endl;
	HashSet10.removeAll(HashSet11);

	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	HashSet12.clear();
	HashSet12.add("kan");
	HashSet12.add("can");


	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();

	cout<<endl<<"HashSet12 current elements;"<<endl;
	HashSet12.printElements();

	cout<<endl<<endl<<"HashSet10.retainAll(HashSet12);";
	HashSet10.retainAll(HashSet12);

	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();



	cout<<endl<<"-----------";

	cout<<endl<<"size() function test;"<<endl;
	cout<<"HashSet10.size() returns;"<<endl;
	cout<<HashSet10.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();

	cout<<endl<<"HashSet11 current elements;"<<endl;
	HashSet11.printElements();
	cout<<endl<<"HashSet10 = HashSet11"<<endl;
	HashSet10 = HashSet11;
	cout<<endl<<"HashSet10 current elements;"<<endl;
	HashSet10.printElements();

	cout<<endl<<"-----------";
























cout<<endl<<endl<<endl<<"=>=>=>=>HASHSET SET TEST INT<=<=<=<="<<endl<<endl;









cout<<endl<<endl;




	int arrset13[3] = {1,2,3};
	set<int> vec13 (arrset13,arrset13+3);


	int arrset14[6] = {7,8,9,10,11,12};
	set<int> vec14 (arrset14,arrset14+6);

	int arrset15[3] = {4,5,6};
	set<int> vec15 (arrset15,arrset15+3);



	HashSet<int,set<int> > HashSet13(vec13);

	HashSet<int,set<int> > HashSet14(vec14);
	HashSet<int,set<int> > HashSet15(vec15);

/***************************  SET<INT> ****************************************/
	cout<<"=>=>==>=>=>=>>=> For set<int> <=<=<=<=<=<=<=<="<<endl;




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<int,set<int> > hashsetiter4 = HashSet13.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current HashSet;"<<endl;
	cout<< *(hashsetiter4.getIterator());
	while(hashsetiter4.hasNext() != 0){
		hashsetiter4.next();
		cout<<" "<< *(hashsetiter4.getIterator());
	}



	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	HashSet13.add(20);
	cout<<endl<<"20 added HashSet13";
	HashSet13.add(21);
	cout<<endl<<"21 added HashSet13";
	HashSet13.add(22);
	cout<<endl<<"22 added HashSet13";
	HashSet13.add(23);
	cout<<endl<<"23 added HashSet13"<<endl<<endl;

	cout<<"Current HashSet;"<<endl;
	HashSet13.printElements();



	cout<<endl<<endl<<"-----------";


	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"HashSet15 current elements;"<<endl;
	HashSet15.printElements();

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();

	cout<<endl<<"After HashSet13.addAll(HashSet15);";
	HashSet13.addAll(HashSet15);

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();



	cout<<endl<<endl<<"-----------";

	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"HashSet14 current elements;"<<endl;
	HashSet14.printElements();

	cout<<endl<<"HashSet14.clear();";
	HashSet14.clear();

	cout<<endl<<"HashSet14.add(5);";
	HashSet14.add(5);

	cout<<endl<<"HashSet14 current elements;"<<endl;
	HashSet14.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();

	cout<<endl<<"HastSet1.contains(5) returns;"<<endl;
	cout<<HashSet13.contains(5);

	cout<<endl<<"HastSet1.contains(30) returns;"<<endl;
	cout<<HashSet13.contains(30);



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();

	cout<<endl<<"HashSet15 current elements;"<<endl;
	HashSet15.printElements();

	cout<<endl<<endl<<"HastSet1.containsAll(HashSet15) returns;"<<endl;
	cout<<HashSet13.containsAll(HashSet15);

	cout<<endl<<endl<<"HashSet15.add(50);"<<endl;
	HashSet15.add(50);

	cout<<endl<<"HastSet1.containsAll(HashSet15) returns;"<<endl;
	cout<<HashSet13.containsAll(HashSet15);



	cout<<endl<<endl<<"-----------";

	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"HashSet14.isEmpty() returns;"<<endl;
	cout<<HashSet14.isEmpty()<<endl;
	cout<<"HashSet14.clear();"<<endl;
	HashSet14.clear();
	cout<<"HashSet14.isEmpty() returns;"<<endl;
	cout<<HashSet14.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();

	cout<<endl<<endl<<"HashSet13.remove(6)"<<endl;
	HashSet13.remove(6);
	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();

	cout<<endl<<endl<<"HashSet13.remove(2)"<<endl;
	HashSet13.remove(2);
	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	HashSet14.add(20);
	HashSet14.add(22);
	HashSet14.add(23);

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();

	cout<<endl<<"HashSet14 current elements;"<<endl;
	HashSet14.printElements();

	cout<<endl<<endl<<"HashSet13.removeAll(HashSet14);"<<endl;
	HashSet13.removeAll(HashSet14);

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();


	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	HashSet15.clear();
	HashSet15.add(21);
	HashSet15.add(4);
	HashSet15.add(5);

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();

	cout<<endl<<"HashSet15 current elements;"<<endl;
	HashSet15.printElements();

	cout<<endl<<endl<<"HashSet13.retainAll(HashSet15);";
	HashSet13.retainAll(HashSet15);

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();



	cout<<endl<<"-----------";


	cout<<endl<<"size() function test;"<<endl;
	cout<<"HashSet13.size() returns;"<<endl;
	cout<<HashSet13.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();

	cout<<endl<<"HashSet14 current elements;"<<endl;
	HashSet14.printElements();
	cout<<endl<<"HashSet13 = HashSet14"<<endl;
	HashSet13 = HashSet14;
	cout<<endl<<"HashSet13 current elements;"<<endl;
	HashSet13.printElements();

	cout<<endl<<"-----------";

cout<<endl<<endl<<endl;










cout<<endl<<endl<<endl<<"=>=>=>=>HASHSET SET TEST STRING<=<=<=<="<<endl<<endl;




	string arrset16[3] = {"yusuf","can","kan"};
	set<string> vec16 (arrset16,arrset16+3);


	string arrset17[6] = {"GEBZE","TEKNIK","UNIVERSİTESI","BM","CSE","GTU"};
	set<string> vec17 (arrset17,arrset17+6);

	string arrset18[3] = {"CSE241","OOP","JAVA"};
	set<string> vec18 (arrset18,arrset18+3);

	HashSet<string,set<string> > HashSet16(vec16);
	HashSet<string,set<string> > HashSet17(vec17);
	HashSet<string,set<string> > HashSet18(vec18);


	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<string,set<string> > hashsetiter5 = HashSet16.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current HashSet;"<<endl;
	cout<< *(hashsetiter5.getIterator());
	while(hashsetiter5.hasNext() != 0){
		hashsetiter5.next();
		cout<<" "<< *(hashsetiter5.getIterator());
	}



	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	HashSet16.add("kitap");
	cout<<endl<<"'kitap' added HashSet1";
	HashSet16.add("defter");
	cout<<endl<<"'defter' added HashSet1";
	HashSet16.add("kalem");
	cout<<endl<<"'kalem' added HashSet1";
	HashSet16.add("YCK");
	cout<<endl<<"'YCK' added HashSet1"<<endl<<endl;

	cout<<"Current HashSet;"<<endl;
	HashSet16.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"HashSet18 current elements;"<<endl;
	HashSet18.printElements();

	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();

	cout<<endl<<endl<<"After HashSet16.addAll(HashSet18);"<<endl;
	HashSet16.addAll(HashSet18);

	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();



	cout<<endl<<endl<<"-----------";


	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"HashSet17 current elements;"<<endl;
	HashSet17.printElements();

	cout<<endl<<"HashSet17.clear();";
	HashSet17.clear();

	cout<<endl<<"HashSet17.add('ALI');";
	HashSet17.add("ALI");

	cout<<endl<<"HashSet17 current elements;"<<endl;
	HashSet17.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();

	cout<<endl<<"HastSet4.contains('OOP') returns;"<<endl;
	cout<<HashSet16.contains("OOP");

	cout<<endl<<"HastSet1.contains('asd') returns;"<<endl;
	cout<<HashSet16.contains("asd");


	cout<<endl<<"-----------";

	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();

	cout<<endl<<"HashSet18 current elements;"<<endl;
	HashSet18.printElements();

	cout<<endl<<endl<<"HastSet4.containsAll(HashSet18) returns;"<<endl;
	cout<<HashSet16.containsAll(HashSet18);

	cout<<endl<<endl<<"HashSet18.add('COMPUTER');"<<endl;
	HashSet18.add("COMPUTER");

	cout<<endl<<"HastSet1.containsAll(HashSet18) returns;"<<endl;
	cout<<HashSet16.containsAll(HashSet18);



	cout<<endl<<endl<<"-----------";




	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"HashSet17.isEmpty() returns;"<<endl;
	cout<<HashSet17.isEmpty()<<endl;
	cout<<"HashSet17.clear();"<<endl;
	HashSet17.clear();
	cout<<"HashSet17.isEmpty() returns;"<<endl;
	cout<<HashSet17.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();

	cout<<endl<<endl<<"HashSet16.remove('OOP')"<<endl;
	HashSet16.remove("OOP");
	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();

	cout<<endl<<endl<<"HashSet16.remove('JAVA')"<<endl;
		HashSet16.remove("JAVA");
		cout<<endl<<"HashSet16 current elements;"<<endl;
		HashSet16.printElements();



	cout<<endl<<"-----------";


	cout<<endl<<"removeAll() function test;"<<endl;

	HashSet17.add("kitap");
	HashSet17.add("defter");
	HashSet17.add("kalem");

	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();

	cout<<endl<<"HashSet17 current elements;"<<endl;
	HashSet17.printElements();

	cout<<endl<<endl<<"HashSet16.removeAll(HashSet17);"<<endl;
	HashSet16.removeAll(HashSet17);

	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	HashSet18.clear();
	HashSet18.add("kan");
	HashSet18.add("can");


	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();

	cout<<endl<<"HashSet18 current elements;"<<endl;
	HashSet18.printElements();

	cout<<endl<<endl<<"HashSet16.retainAll(HashSet18);";
	HashSet16.retainAll(HashSet18);

	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();



	cout<<endl<<"-----------";

	cout<<endl<<"size() function test;"<<endl;
	cout<<"HashSet16.size() returns;"<<endl;
	cout<<HashSet16.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();

	cout<<endl<<"HashSet17 current elements;"<<endl;
	HashSet17.printElements();
	cout<<endl<<"HashSet16 = HashSet17"<<endl;
	HashSet16 = HashSet17;
	cout<<endl<<"HashSet16 current elements;"<<endl;
	HashSet16.printElements();

	cout<<endl<<"-----------";




cout<<endl<<endl<<endl<<"#########################################################################"<<endl;
cout<<"#########################################################################"<<endl;
cout<<"#########################################################################"<<endl;


cout<<"-----------------------------------ARRAY LIST CLASS FUNCTION TESTS-----------------------------------"<<endl<<endl<<endl;

cout<<endl<<endl;





/***********************************************************************************************************************/
cout<<endl<<endl<<"----------------------------ArrayList TEST----------------------------"<<endl;

vector <int> vec19;
vec19.push_back(1);
vec19.push_back(2);
vec19.push_back(3);

vector <int> vec20;
vec20.push_back(7);
vec20.push_back(8);
vec20.push_back(9);
vec20.push_back(10);
vec20.push_back(11);
vec20.push_back(12);

vector <int> vec21;
vec21.push_back(4);
vec21.push_back(5);
vec21.push_back(6);

ArrayList<int,vector<int> > ArrayList19(vec19);
ArrayList<int,vector<int> > ArrayList20(vec20);
ArrayList<int,vector<int> > ArrayList21(vec21);



/***************************  VECTOR<INT> ****************************************/
cout<<"=>=>==>=>=>=>>=> For vector<int> <=<=<=<=<=<=<=<="<<endl;



cout<<endl<<endl<<"-----------";
cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
/*It creates the iterator.*/
Iterator<int,vector<int> > ArrayListiter = ArrayList19.iterator();
/*It prints the elements with using iterator.*/
cout<<"Current ArrayList;"<<endl;
cout<< *(ArrayListiter.getIterator());
while(ArrayListiter.hasNext() != 0){
	ArrayListiter.next();
	cout<<" "<< *(ArrayListiter.getIterator());
}



cout<<endl<<endl<<"-----------";



/*First adds the elements and after that prints the result on the screen.*/
cout<<endl<<"Add function test"<<endl;
ArrayList19.add(20);
cout<<endl<<"20 added ArrayList19";
ArrayList19.add(21);
cout<<endl<<"21 added ArrayList19";
ArrayList19.add(22);
cout<<endl<<"22 added ArrayList19";
ArrayList19.add(23);
cout<<endl<<"23 added ArrayList19"<<endl<<endl;

cout<<"Current ArrayList;"<<endl;
ArrayList19.printElements();



cout<<endl<<endl<<"-----------";



/*
 * First prints the currents elements of variables.
 * After that uses addAll() and prints result on the screen.
 */
cout<<endl<<"AddAll function test;";
cout<<endl<<"ArrayList21 current elements;"<<endl;
ArrayList21.printElements();

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();

cout<<endl<<"After ArrayList19.addAll(ArrayList21);";
ArrayList19.addAll(ArrayList21);

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();



cout<<endl<<endl<<"-----------";



/*
 * First it prints the currents elements. After that it applies clear() function.
 * After that it adds an element on the empty sets.
 * After that it prints the most current version.
 */

cout<<endl<<"clear() function test;"<<endl;

cout<<endl<<"ArrayList20 current elements;"<<endl;
ArrayList20.printElements();

cout<<endl<<"ArrayList20.clear();";
ArrayList20.clear();

cout<<endl<<"ArrayList20.add(5);";
ArrayList20.add(5);

cout<<endl<<"ArrayList20 current elements;"<<endl;
ArrayList20.printElements();



cout<<endl<<endl<<"-----------";



/*Test for contain function.*/
cout<<endl<<"contains() function test;"<<endl;

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();

cout<<endl<<"HastSet1.contains(5) returns;"<<endl;
cout<<ArrayList19.contains(5);

cout<<endl<<"HastSet1.contains(30) returns;"<<endl;
cout<<ArrayList19.contains(30);



cout<<endl<<"-----------";



/*
 * First it test the true return situation.
 * After that it adds one element and test the false return situation.
 */
cout<<endl<<"containsAll() function test;"<<endl;

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();

cout<<endl<<"ArrayList21 current elements;"<<endl;
ArrayList21.printElements();

cout<<endl<<endl<<"HastSet1.containsAll(ArrayList21) returns;"<<endl;
cout<<ArrayList19.containsAll(ArrayList21);

cout<<endl<<endl<<"ArrayList21.add(50);"<<endl;
ArrayList21.add(50);

cout<<endl<<"ArrayList19.containsAll(ArrayList21) returns;"<<endl;
cout<<ArrayList19.containsAll(ArrayList21);



cout<<endl<<endl<<"-----------";




/*
 * isEmpty() function test. It prints the return values.
 */
cout<<endl<<"isEmpty() function test;"<<endl;

cout<<"ArrayList20.isEmpty() returns;"<<endl;
cout<<ArrayList20.isEmpty()<<endl;
cout<<"ArrayList20.clear();"<<endl;
ArrayList20.clear();
cout<<"ArrayList20.isEmpty() returns;"<<endl;
cout<<ArrayList20.isEmpty();



cout<<endl<<"-----------";



cout<<endl<<"remove() function test;"<<endl;

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();

cout<<endl<<endl<<"ArrayList19.remove(6)"<<endl;
ArrayList19.remove(6);
cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();

cout<<endl<<endl<<"ArrayList19.remove(2)"<<endl;
	ArrayList19.remove(2);
	cout<<endl<<"ArrayList19 current elements;"<<endl;
	ArrayList19.printElements();




cout<<endl<<"-----------";



cout<<endl<<"removeAll() function test;"<<endl;

ArrayList20.add(20);
ArrayList20.add(22);
ArrayList20.add(23);

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();

cout<<endl<<"ArrayList20 current elements;"<<endl;
ArrayList20.printElements();

cout<<endl<<endl<<"ArrayList19.removeAll(ArrayList20);"<<endl;
ArrayList19.removeAll(ArrayList20);

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();



cout<<endl<<"-----------";



cout<<endl<<"retainAll() function test;"<<endl;

ArrayList21.clear();
ArrayList21.add(21);
ArrayList21.add(4);
ArrayList21.add(5);

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();

cout<<endl<<"ArrayList21 current elements;"<<endl;
ArrayList21.printElements();

cout<<endl<<endl<<"ArrayList19.retainAll(ArrayList21);";
ArrayList19.retainAll(ArrayList21);

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();



cout<<endl<<"-----------";



cout<<endl<<"size() function test;"<<endl;
cout<<"ArrayList19.size() returns;"<<endl;
cout<<ArrayList19.size();


cout<<endl<<"-----------";

cout<<endl<<"Assignment operator function test;"<<endl;

cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();

cout<<endl<<"ArrayList20 current elements;"<<endl;
ArrayList20.printElements();
cout<<endl<<"ArrayList19 = ArrayList20"<<endl;
ArrayList19 = ArrayList20;
cout<<endl<<"ArrayList19 current elements;"<<endl;
ArrayList19.printElements();

cout<<endl<<"-----------";


cout<<endl<<endl<<endl<<endl;












/**************************************************************************************/
	cout<<endl<<endl<<"=>=>=>=>ARRAY LIST VECTOR STRING TEST<=<=<=<="<<endl<<endl;
	vector <string> vec22;
	vec22.push_back("yusuf");
	vec22.push_back("can");
	vec22.push_back("kan");

	vector <string> vec23;
	vec23.push_back("GEBZE");
	vec23.push_back("TEKNIK");
	vec23.push_back("UNIVERSITESI");
	vec23.push_back("BM");
	vec23.push_back("CSE");
	vec23.push_back("GTU");

	vector <string> vec24;
	vec24.push_back("CSE241");
	vec24.push_back("OOP");
	vec24.push_back("JAVA");

	ArrayList<string,vector<string> > ArrayList22(vec22);
	ArrayList<string,vector<string> > ArrayList23(vec23);
	ArrayList<string,vector<string> > ArrayList24(vec24);




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<string,vector<string> > ArrayListiter1 = ArrayList22.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current ArrayList;"<<endl;
	cout<< *(ArrayListiter1.getIterator());
	while(ArrayListiter1.hasNext() != 0){
		ArrayListiter1.next();
		cout<<" "<< *(ArrayListiter1.getIterator());
	}




	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	ArrayList22.add("kitap");
	cout<<endl<<"'kitap' added ArrayList1";
	ArrayList22.add("defter");
	cout<<endl<<"'defter' added ArrayList1";
	ArrayList22.add("kalem");
	cout<<endl<<"'kalem' added ArrayList1";
	ArrayList22.add("YCK");
	cout<<endl<<"'YCK' added ArrayList1"<<endl<<endl;

	cout<<"Current ArrayList;"<<endl;
	ArrayList22.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"ArrayList24 current elements;"<<endl;
	ArrayList24.printElements();

	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();

	cout<<endl<<endl<<"After ArrayList22.addAll(ArrayList24);"<<endl;
	ArrayList22.addAll(ArrayList24);

	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();



	cout<<endl<<endl<<"-----------";


	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"ArrayList23 current elements;"<<endl;
	ArrayList23.printElements();

	cout<<endl<<"ArrayList23.clear();";
	ArrayList23.clear();

	cout<<endl<<"ArrayList23.add('ALI');";
	ArrayList23.add("ALI");

	cout<<endl<<"ArrayList23 current elements;"<<endl;
	ArrayList23.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();

	cout<<endl<<"HastSet4.contains('OOP') returns;"<<endl;
	cout<<ArrayList22.contains("OOP");

	cout<<endl<<"HastSet1.contains('asd') returns;"<<endl;
	cout<<ArrayList22.contains("asd");



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();

	cout<<endl<<"ArrayList24 current elements;"<<endl;
	ArrayList24.printElements();

	cout<<endl<<endl<<"HastSet4.containsAll(ArrayList24) returns;"<<endl;
	cout<<ArrayList22.containsAll(ArrayList24);

	cout<<endl<<endl<<"ArrayList24.add('COMPUTER');"<<endl;
	ArrayList24.add("COMPUTER");

	cout<<endl<<"HastSet1.containsAll(ArrayList24) returns;"<<endl;
	cout<<ArrayList22.containsAll(ArrayList24);



	cout<<endl<<endl<<"-----------";




	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"ArrayList23.isEmpty() returns;"<<endl;
	cout<<ArrayList23.isEmpty()<<endl;
	cout<<"ArrayList23.clear();"<<endl;
	ArrayList23.clear();
	cout<<"ArrayList23.isEmpty() returns;"<<endl;
	cout<<ArrayList23.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();

	cout<<endl<<endl<<"ArrayList22.remove('OOP')"<<endl;
	ArrayList22.remove("OOP");
	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();

	cout<<endl<<endl<<"ArrayList22.remove('JAVA')"<<endl;
		ArrayList22.remove("JAVA");
		cout<<endl<<"ArrayList22 current elements;"<<endl;
		ArrayList22.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	ArrayList23.add("kitap");
	ArrayList23.add("defter");
	ArrayList23.add("kalem");

	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();

	cout<<endl<<"ArrayList23 current elements;"<<endl;
	ArrayList23.printElements();

	cout<<endl<<endl<<"ArrayList22.removeAll(ArrayList23);"<<endl;
	ArrayList22.removeAll(ArrayList23);

	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	ArrayList24.clear();
	ArrayList24.add("kan");
	ArrayList24.add("can");


	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();

	cout<<endl<<"ArrayList24 current elements;"<<endl;
	ArrayList24.printElements();

	cout<<endl<<endl<<"ArrayList22.retainAll(ArrayList24);";
	ArrayList22.retainAll(ArrayList24);

	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();



	cout<<endl<<"-----------";

	cout<<endl<<"size() function test;"<<endl;
	cout<<"ArrayList22.size() returns;"<<endl;
	cout<<ArrayList22.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();

	cout<<endl<<"ArrayList23 current elements;"<<endl;
	ArrayList23.printElements();
	cout<<endl<<"ArrayList22 = ArrayList23"<<endl;
	ArrayList22 = ArrayList23;
	cout<<endl<<"ArrayList22 current elements;"<<endl;
	ArrayList22.printElements();

	cout<<endl<<"-----------";





























/****************************************************/
	cout<<endl<<endl<<endl<<endl<<endl;

	list <int> vec25;
	vec25.push_back(1);
	vec25.push_back(2);
	vec25.push_back(3);

	list <int> vec26;
	vec26.push_back(7);
	vec26.push_back(8);
	vec26.push_back(9);
	vec26.push_back(10);
	vec26.push_back(11);
	vec26.push_back(12);

	list <int> vec27;
	vec27.push_back(4);
	vec27.push_back(5);
	vec27.push_back(6);

	ArrayList<int,list<int> > ArrayList25(vec25);
	ArrayList<int,list<int> > ArrayList26(vec26);
	ArrayList<int,list<int> > ArrayList27(vec27);




	/*************************** ARRAYLIST  LIST<INT> ****************************************/
	cout<<"=>=>==>=>=>=>>=> For ArrayList list<int> <=<=<=<=<=<=<=<="<<endl;




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<int,list<int> > ArrayListiter2 = ArrayList25.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current ArrayList;"<<endl;
	cout<< *(ArrayListiter2.getIterator());
	while(ArrayListiter2.hasNext() != 0){
		ArrayListiter2.next();
		cout<<" "<< *(ArrayListiter2.getIterator());
	}




	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	ArrayList25.add(20);
	cout<<endl<<"20 added ArrayList25";
	ArrayList25.add(21);
	cout<<endl<<"21 added ArrayList25";
	ArrayList25.add(22);
	cout<<endl<<"22 added ArrayList25";
	ArrayList25.add(23);
	cout<<endl<<"23 added ArrayList25"<<endl<<endl;

	cout<<"Current ArrayList;"<<endl;
	ArrayList25.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"ArrayList27 current elements;"<<endl;
	ArrayList27.printElements();

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();

	cout<<endl<<"After ArrayList25.addAll(ArrayList27);";
	ArrayList25.addAll(ArrayList27);

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"ArrayList26 current elements;"<<endl;
	ArrayList26.printElements();

	cout<<endl<<"ArrayList26.clear();";
	ArrayList26.clear();

	cout<<endl<<"ArrayList26.add(5);";
	ArrayList26.add(5);

	cout<<endl<<"ArrayList26 current elements;"<<endl;
	ArrayList26.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();

	cout<<endl<<"HastSet1.contains(5) returns;"<<endl;
	cout<<ArrayList25.contains(5);

	cout<<endl<<"HastSet1.contains(30) returns;"<<endl;
	cout<<ArrayList25.contains(30);



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();

	cout<<endl<<"ArrayList27 current elements;"<<endl;
	ArrayList27.printElements();

	cout<<endl<<endl<<"HastSet1.containsAll(ArrayList27) returns;"<<endl;
	cout<<ArrayList25.containsAll(ArrayList27);

	cout<<endl<<endl<<"ArrayList27.add(50);"<<endl;
	ArrayList27.add(50);

	cout<<endl<<"HastSet1.containsAll(ArrayList27) returns;"<<endl;
	cout<<ArrayList25.containsAll(ArrayList27);



	cout<<endl<<endl<<"-----------";

	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"ArrayList26.isEmpty() returns;"<<endl;
	cout<<ArrayList26.isEmpty()<<endl;
	cout<<"ArrayList26.clear();"<<endl;
	ArrayList26.clear();
	cout<<"ArrayList26.isEmpty() returns;"<<endl;
	cout<<ArrayList26.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();

	cout<<endl<<endl<<"ArrayList25.remove(6)"<<endl;
	ArrayList25.remove(6);
	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();

	cout<<endl<<endl<<"ArrayList25.remove(2)"<<endl;
	ArrayList25.remove(2);
	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	ArrayList26.add(20);
	ArrayList26.add(22);
	ArrayList26.add(23);

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();

	cout<<endl<<"ArrayList26 current elements;"<<endl;
	ArrayList26.printElements();

	cout<<endl<<endl<<"ArrayList25.removeAll(ArrayList26);"<<endl;
	ArrayList25.removeAll(ArrayList26);

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();


	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	ArrayList27.clear();
	ArrayList27.add(21);
	ArrayList27.add(4);
	ArrayList27.add(5);

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();

	cout<<endl<<"ArrayList27 current elements;"<<endl;
	ArrayList27.printElements();

	cout<<endl<<endl<<"ArrayList25.retainAll(ArrayList27);";
	ArrayList25.retainAll(ArrayList27);

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();



	cout<<endl<<"-----------";


	cout<<endl<<"size() function test;"<<endl;
	cout<<"ArrayList25.size() returns;"<<endl;
	cout<<ArrayList25.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();

	cout<<endl<<"ArrayList26 current elements;"<<endl;
	ArrayList26.printElements();
	cout<<endl<<"ArrayList25 = ArrayList26"<<endl;
	ArrayList25 = ArrayList26;
	cout<<endl<<"ArrayList25 current elements;"<<endl;
	ArrayList25.printElements();

	cout<<endl<<"-----------";

	cout<<endl<<endl<<endl;


	cout<<endl<<endl<<endl;

	/**************************************************************************************/
	cout<<endl<<endl<<"=>=>=>=>ArrayList LIST STRING TEST<=<=<=<="<<endl<<endl;
	list <string> vec28;
	vec28.push_back("yusuf");
	vec28.push_back("can");
	vec28.push_back("kan");

	list <string> vec29;
	vec29.push_back("GEBZE");
	vec29.push_back("TEKNIK");
	vec29.push_back("UNIVERSITESI");
	vec29.push_back("BM");
	vec29.push_back("CSE");
	vec29.push_back("GTU");

	list <string> vec30;
	vec30.push_back("CSE241");
	vec30.push_back("OOP");
	vec30.push_back("JAVA");

	ArrayList<string,list<string> > ArrayList28(vec28);
	ArrayList<string,list<string> > ArrayList29(vec29);
	ArrayList<string,list<string> > ArrayList30(vec30);



	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<string,list<string> > ArrayListiter3 = ArrayList28.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current ArrayList;"<<endl;
	cout<< *(ArrayListiter3.getIterator());
	while(ArrayListiter3.hasNext() != 0){
		ArrayListiter3.next();
		cout<<" "<< *(ArrayListiter3.getIterator());
	}




	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	ArrayList28.add("kitap");
	cout<<endl<<"'kitap' added ArrayList1";
	ArrayList28.add("defter");
	cout<<endl<<"'defter' added ArrayList1";
	ArrayList28.add("kalem");
	cout<<endl<<"'kalem' added ArrayList1";
	ArrayList28.add("YCK");
	cout<<endl<<"'YCK' added ArrayList1"<<endl<<endl;

	cout<<"Current ArrayList;"<<endl;
	ArrayList28.printElements();



	cout<<endl<<endl<<"-----------";



		/*
		 * First prints the currents elements of variables.
	 	 * After that uses addAll() and prints result on the screen.
		 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"ArrayList30 current elements;"<<endl;
	ArrayList30.printElements();

	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();

	cout<<endl<<endl<<"After ArrayList28.addAll(ArrayList30);"<<endl;
	ArrayList28.addAll(ArrayList30);

	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();



	cout<<endl<<endl<<"-----------";


		/*
		 * First it prints the currents elements. After that it applies clear() function.
		 * After that it adds an element on the empty sets.
		 * After that it prints the most current version.
		 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"ArrayList29 current elements;"<<endl;
	ArrayList29.printElements();

	cout<<endl<<"ArrayList29.clear();";
	ArrayList29.clear();

	cout<<endl<<"ArrayList29.add('ALI');";
	ArrayList29.add("ALI");

	cout<<endl<<"ArrayList29 current elements;"<<endl;
	ArrayList29.printElements();



	cout<<endl<<endl<<"-----------";



		/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();

	cout<<endl<<"HastSet4.contains('OOP') returns;"<<endl;
	cout<<ArrayList28.contains("OOP");

	cout<<endl<<"HastSet1.contains('asd') returns;"<<endl;
	cout<<ArrayList28.contains("asd");



	cout<<endl<<"-----------";



		/*
		 * First it test the true return situation.
		 * After that it adds one element and test the false return situation.
		 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();

	cout<<endl<<"ArrayList30 current elements;"<<endl;
	ArrayList30.printElements();

	cout<<endl<<endl<<"HastSet4.containsAll(ArrayList30) returns;"<<endl;
	cout<<ArrayList28.containsAll(ArrayList30);

	cout<<endl<<endl<<"ArrayList30.add('COMPUTER');"<<endl;
	ArrayList30.add("COMPUTER");

	cout<<endl<<"HastSet1.containsAll(ArrayList30) returns;"<<endl;
	cout<<ArrayList28.containsAll(ArrayList30);



	cout<<endl<<endl<<"-----------";




		/*
		 * isEmpty() function test. It prints the return values.
		 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"ArrayList29.isEmpty() returns;"<<endl;
	cout<<ArrayList29.isEmpty()<<endl;
	cout<<"ArrayList29.clear();"<<endl;
	ArrayList29.clear();
	cout<<"ArrayList29.isEmpty() returns;"<<endl;
	cout<<ArrayList29.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();

	cout<<endl<<endl<<"ArrayList28.remove('OOP')"<<endl;
	ArrayList28.remove("OOP");
	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();

	cout<<endl<<endl<<"ArrayList28.remove('JAVA')"<<endl;
	ArrayList28.remove("JAVA");
	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	ArrayList29.add("kitap");
	ArrayList29.add("defter");
	ArrayList29.add("kalem");

	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();

	cout<<endl<<"ArrayList29 current elements;"<<endl;
	ArrayList29.printElements();

	cout<<endl<<endl<<"ArrayList28.removeAll(ArrayList29);"<<endl;
	ArrayList28.removeAll(ArrayList29);

	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	ArrayList30.clear();
	ArrayList30.add("kan");
	ArrayList30.add("can");


	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();

	cout<<endl<<"ArrayList30 current elements;"<<endl;
	ArrayList30.printElements();

	cout<<endl<<endl<<"ArrayList28.retainAll(ArrayList30);";
	ArrayList28.retainAll(ArrayList30);

	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();



	cout<<endl<<"-----------";

	cout<<endl<<"size() function test;"<<endl;
	cout<<"ArrayList28.size() returns;"<<endl;
	cout<<ArrayList28.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();

	cout<<endl<<"ArrayList29 current elements;"<<endl;
	ArrayList29.printElements();
	cout<<endl<<"ArrayList28 = ArrayList29"<<endl;
	ArrayList28 = ArrayList29;
	cout<<endl<<"ArrayList28 current elements;"<<endl;
	ArrayList28.printElements();

	cout<<endl<<"-----------";





















	cout<<endl<<endl<<endl<<"=>=>=>=>ArrayList SET TEST INT<=<=<=<="<<endl<<endl;


	cout<<endl<<endl;




		int arrset31[3] = {1,2,3};
		set<int> vec31 (arrset31,arrset31+3);


		int arrset32[6] = {7,8,9,10,11,12};
		set<int> vec32 (arrset32,arrset32+6);

		int arrset33[3] = {4,5,6};
		set<int> vec33 (arrset33,arrset33+3);



		ArrayList<int,set<int> > ArrayList31(vec31);
		ArrayList<int,set<int> > ArrayList32(vec32);
		ArrayList<int,set<int> > ArrayList33(vec33);

	/***************************  SET<INT> ****************************************/
	cout<<"=>=>==>=>=>=>>=> For set<int> <=<=<=<=<=<=<=<="<<endl;




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<int,set<int> > ArrayListiter4 = ArrayList31.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current ArrayList;"<<endl;
	cout<< *(ArrayListiter4.getIterator());
	while(ArrayListiter4.hasNext() != 0){
		ArrayListiter4.next();
		cout<<" "<< *(ArrayListiter4.getIterator());
	}



	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	ArrayList31.add(20);
	cout<<endl<<"20 added ArrayList31";
	ArrayList31.add(21);
	cout<<endl<<"21 added ArrayList31";
	ArrayList31.add(22);
	cout<<endl<<"22 added ArrayList31";
	ArrayList31.add(23);
	cout<<endl<<"23 added ArrayList31"<<endl<<endl;

	cout<<"Current ArrayList;"<<endl;
	ArrayList31.printElements();



	cout<<endl<<endl<<"-----------";


		/*
		 * First prints the currents elements of variables.
		 * After that uses addAll() and prints result on the screen.
		 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"ArrayList33 current elements;"<<endl;
	ArrayList33.printElements();

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();

	cout<<endl<<"After ArrayList31.addAll(ArrayList33);";
	ArrayList31.addAll(ArrayList33);

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();



	cout<<endl<<endl<<"-----------";

	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"ArrayList32 current elements;"<<endl;
	ArrayList32.printElements();

	cout<<endl<<"ArrayList32.clear();";
	ArrayList32.clear();

	cout<<endl<<"ArrayList32.add(5);";
	ArrayList32.add(5);

	cout<<endl<<"ArrayList32 current elements;"<<endl;
	ArrayList32.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();

	cout<<endl<<"HastSet1.contains(5) returns;"<<endl;
	cout<<ArrayList31.contains(5);

	cout<<endl<<"HastSet1.contains(30) returns;"<<endl;
	cout<<ArrayList31.contains(30);



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();

	cout<<endl<<"ArrayList33 current elements;"<<endl;
	ArrayList33.printElements();

	cout<<endl<<endl<<"HastSet1.containsAll(ArrayList33) returns;"<<endl;
	cout<<ArrayList31.containsAll(ArrayList33);

	cout<<endl<<endl<<"ArrayList33.add(50);"<<endl;
	ArrayList33.add(50);

	cout<<endl<<"HastSet1.containsAll(ArrayList33) returns;"<<endl;
	cout<<ArrayList31.containsAll(ArrayList33);



	cout<<endl<<endl<<"-----------";

	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"ArrayList32.isEmpty() returns;"<<endl;
	cout<<ArrayList32.isEmpty()<<endl;
	cout<<"ArrayList32.clear();"<<endl;
	ArrayList32.clear();
	cout<<"ArrayList32.isEmpty() returns;"<<endl;
	cout<<ArrayList32.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();

	cout<<endl<<endl<<"ArrayList31.remove(6)"<<endl;
	ArrayList31.remove(6);
	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();

	cout<<endl<<endl<<"ArrayList31.remove(2)"<<endl;
	ArrayList31.remove(2);
	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	ArrayList32.add(20);
	ArrayList32.add(22);
	ArrayList32.add(23);

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();

	cout<<endl<<"ArrayList32 current elements;"<<endl;
	ArrayList32.printElements();

	cout<<endl<<endl<<"ArrayList31.removeAll(ArrayList32);"<<endl;
	ArrayList31.removeAll(ArrayList32);

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();


	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	ArrayList33.clear();
	ArrayList33.add(21);
	ArrayList33.add(4);
	ArrayList33.add(5);

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();

	cout<<endl<<"ArrayList33 current elements;"<<endl;
	ArrayList33.printElements();

	cout<<endl<<endl<<"ArrayList31.retainAll(ArrayList33);";
	ArrayList31.retainAll(ArrayList33);

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();



	cout<<endl<<"-----------";


	cout<<endl<<"size() function test;"<<endl;
	cout<<"ArrayList31.size() returns;"<<endl;
	cout<<ArrayList31.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();

	cout<<endl<<"ArrayList32 current elements;"<<endl;
	ArrayList32.printElements();
	cout<<endl<<"ArrayList31 = ArrayList32"<<endl;
	ArrayList31 = ArrayList32;
	cout<<endl<<"ArrayList31 current elements;"<<endl;
	ArrayList31.printElements();

	cout<<endl<<"-----------";

	cout<<endl<<endl<<endl;





	cout<<endl<<endl<<endl<<"=>=>=>=>ArrayList SET TEST STRING<=<=<=<="<<endl<<endl;



	string arrset34[3] = {"yusuf","can","kan"};
	set<string> vec34 (arrset34,arrset34+3);


	string arrset35[6] = {"GEBZE","TEKNIK","UNIVERSİTESI","BM","CSE","GTU"};
	set<string> vec35 (arrset35,arrset35+6);

	string arrset36[3] = {"CSE241","OOP","JAVA"};
	set<string> vec36 (arrset36,arrset36+3);

	ArrayList<string,set<string> > ArrayList34(vec34);
	ArrayList<string,set<string> > ArrayList35(vec35);
	ArrayList<string,set<string> > ArrayList36(vec36);


	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<string,set<string> > ArrayListiter5 = ArrayList34.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current ArrayList;"<<endl;
	cout<< *(ArrayListiter5.getIterator());
	while(ArrayListiter5.hasNext() != 0){
		ArrayListiter5.next();
		cout<<" "<< *(ArrayListiter5.getIterator());
	}


	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	ArrayList34.add("kitap");
	cout<<endl<<"'kitap' added ArrayList1";
	ArrayList34.add("defter");
	cout<<endl<<"'defter' added ArrayList1";
	ArrayList34.add("kalem");
	cout<<endl<<"'kalem' added ArrayList1";
	ArrayList34.add("YCK");
	cout<<endl<<"'YCK' added ArrayList1"<<endl<<endl;

	cout<<"Current ArrayList;"<<endl;
	ArrayList34.printElements();



	cout<<endl<<endl<<"-----------";



		/*
		 * First prints the currents elements of variables.
		 * After that uses addAll() and prints result on the screen.
		 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"ArrayList36 current elements;"<<endl;
	ArrayList36.printElements();

	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();

	cout<<endl<<endl<<"After ArrayList34.addAll(ArrayList36);"<<endl;
	ArrayList34.addAll(ArrayList36);

	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();



	cout<<endl<<endl<<"-----------";


		/*
		 * First it prints the currents elements. After that it applies clear() function.
		 * After that it adds an element on the empty sets.
		 * After that it prints the most current version.
		 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"ArrayList35 current elements;"<<endl;
	ArrayList35.printElements();

	cout<<endl<<"ArrayList35.clear();";
	ArrayList35.clear();

	cout<<endl<<"ArrayList35.add('ALI');";
	ArrayList35.add("ALI");

	cout<<endl<<"ArrayList35 current elements;"<<endl;
	ArrayList35.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();

	cout<<endl<<"HastSet4.contains('OOP') returns;"<<endl;
	cout<<ArrayList34.contains("OOP");

	cout<<endl<<"HastSet1.contains('asd') returns;"<<endl;
	cout<<ArrayList34.contains("asd");


	cout<<endl<<"-----------";

		/*
		 * First it test the true return situation.
		 * After that it adds one element and test the false return situation.
		 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();

	cout<<endl<<"ArrayList36 current elements;"<<endl;
	ArrayList36.printElements();

	cout<<endl<<endl<<"HastSet4.containsAll(ArrayList36) returns;"<<endl;
	cout<<ArrayList34.containsAll(ArrayList36);

	cout<<endl<<endl<<"ArrayList36.add('COMPUTER');"<<endl;
	ArrayList36.add("COMPUTER");

	cout<<endl<<"HastSet1.containsAll(ArrayList36) returns;"<<endl;
	cout<<ArrayList34.containsAll(ArrayList36);



	cout<<endl<<endl<<"-----------";




		/*
		 * isEmpty() function test. It prints the return values.
		 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"ArrayList35.isEmpty() returns;"<<endl;
	cout<<ArrayList35.isEmpty()<<endl;
	cout<<"ArrayList35.clear();"<<endl;
	ArrayList35.clear();
	cout<<"ArrayList35.isEmpty() returns;"<<endl;
	cout<<ArrayList35.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();

	cout<<endl<<endl<<"ArrayList34.remove('OOP')"<<endl;
	ArrayList34.remove("OOP");
	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();

	cout<<endl<<endl<<"ArrayList34.remove('JAVA')"<<endl;
	ArrayList34.remove("JAVA");
	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();



	cout<<endl<<"-----------";


	cout<<endl<<"removeAll() function test;"<<endl;

	ArrayList35.add("kitap");
	ArrayList35.add("defter");
	ArrayList35.add("kalem");

	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();

	cout<<endl<<"ArrayList35 current elements;"<<endl;
	ArrayList35.printElements();

	cout<<endl<<endl<<"ArrayList34.removeAll(ArrayList35);"<<endl;
	ArrayList34.removeAll(ArrayList35);

	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	ArrayList36.clear();
	ArrayList36.add("kan");
	ArrayList36.add("can");


	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();

	cout<<endl<<"ArrayList36 current elements;"<<endl;
	ArrayList36.printElements();

		cout<<endl<<endl<<"ArrayList34.retainAll(ArrayList36);";
	ArrayList34.retainAll(ArrayList36);

	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();



	cout<<endl<<"-----------";

	cout<<endl<<"size() function test;"<<endl;
	cout<<"ArrayList34.size() returns;"<<endl;
	cout<<ArrayList34.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();

	cout<<endl<<"ArrayList35 current elements;"<<endl;
	ArrayList35.printElements();
	cout<<endl<<"ArrayList34 = ArrayList35"<<endl;
	ArrayList34 = ArrayList35;
	cout<<endl<<"ArrayList34 current elements;"<<endl;
	ArrayList34.printElements();

	cout<<endl<<"-----------";


















	cout<<endl<<endl<<endl;




















	/***********************************************************************************************************************/
	cout<<endl<<endl<<"----------------------------LinkedList TEST----------------------------"<<endl;

	vector <int> vec37;
	vec37.push_back(1);
	vec37.push_back(2);
	vec37.push_back(3);

	vector <int> vec38;
	vec38.push_back(7);
	vec38.push_back(8);
	vec38.push_back(9);
	vec38.push_back(10);
	vec38.push_back(11);
	vec38.push_back(12);

	vector <int> vec39;
	vec39.push_back(4);
	vec39.push_back(5);
	vec39.push_back(6);

	LinkedList<int,vector<int> > LinkedList37(vec37);
	LinkedList<int,vector<int> > LinkedList38(vec38);
	LinkedList<int,vector<int> > LinkedList39(vec39);



	/***************************  VECTOR<INT> ****************************************/
	cout<<"=>=>==>=>=>=>>=> For vector<int> <=<=<=<=<=<=<=<="<<endl;



	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<int,vector<int> > LinkedListiter = LinkedList37.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current LinkedList;"<<endl;
	cout<< *(LinkedListiter.getIterator());
	while(LinkedListiter.hasNext() != 0){
		LinkedListiter.next();
		cout<<" "<< *(LinkedListiter.getIterator());
	}



	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	LinkedList37.add(20);
	cout<<endl<<"20 added LinkedList37";
	LinkedList37.add(21);
	cout<<endl<<"21 added LinkedList37";
	LinkedList37.add(22);
	cout<<endl<<"22 added LinkedList37";
	LinkedList37.add(23);
	cout<<endl<<"23 added LinkedList37"<<endl<<endl;

	cout<<"Current LinkedList;"<<endl;
	LinkedList37.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"LinkedList39 current elements;"<<endl;
	LinkedList39.printElements();

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<"After LinkedList37.addAll(LinkedList39);";
	LinkedList37.addAll(LinkedList39);

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"LinkedList38 current elements;"<<endl;
	LinkedList38.printElements();

	cout<<endl<<"LinkedList38.clear();";
	LinkedList38.clear();

	cout<<endl<<"LinkedList38.add(5);";
	LinkedList38.add(5);

	cout<<endl<<"LinkedList38 current elements;"<<endl;
	LinkedList38.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<"HastSet1.contains(5) returns;"<<endl;
	cout<<LinkedList37.contains(5);

	cout<<endl<<"HastSet1.contains(30) returns;"<<endl;
	cout<<LinkedList37.contains(30);



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<"LinkedList39 current elements;"<<endl;
	LinkedList39.printElements();

	cout<<endl<<endl<<"HastSet1.containsAll(LinkedList39) returns;"<<endl;
	cout<<LinkedList37.containsAll(LinkedList39);

	cout<<endl<<endl<<"LinkedList39.add(50);"<<endl;
	LinkedList39.add(50);

	cout<<endl<<"LinkedList37.containsAll(LinkedList39) returns;"<<endl;
	cout<<LinkedList37.containsAll(LinkedList39);



	cout<<endl<<endl<<"-----------";




	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"LinkedList38.isEmpty() returns;"<<endl;
	cout<<LinkedList38.isEmpty()<<endl;
	cout<<"LinkedList38.clear();"<<endl;
	LinkedList38.clear();
	cout<<"LinkedList38.isEmpty() returns;"<<endl;
	cout<<LinkedList38.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<endl<<"LinkedList37.remove(6)"<<endl;
	LinkedList37.remove(6);
	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<endl<<"LinkedList37.remove(2)"<<endl;
		LinkedList37.remove(2);
		cout<<endl<<"LinkedList37 current elements;"<<endl;
		LinkedList37.printElements();




	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	LinkedList38.add(20);
	LinkedList38.add(22);
	LinkedList38.add(23);

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<"LinkedList38 current elements;"<<endl;
	LinkedList38.printElements();

	cout<<endl<<endl<<"LinkedList37.removeAll(LinkedList38);"<<endl;
	LinkedList37.removeAll(LinkedList38);

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	LinkedList39.clear();
	LinkedList39.add(21);
	LinkedList39.add(4);
	LinkedList39.add(5);

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<"LinkedList39 current elements;"<<endl;
	LinkedList39.printElements();

	cout<<endl<<endl<<"LinkedList37.retainAll(LinkedList39);";
	LinkedList37.retainAll(LinkedList39);

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"size() function test;"<<endl;
	cout<<"LinkedList37.size() returns;"<<endl;
	cout<<LinkedList37.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator test;"<<endl;

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<"LinkedList38 current elements;"<<endl;
	LinkedList38.printElements();
	cout<<endl<<"LinkedList37 = LinkedList38"<<endl;
	LinkedList37 = LinkedList38;
	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<"-----------"<<endl;

	cout<<endl<<"element() function test;"<<endl;

	cout<<"LinkedList37.element(); function return value;"<<endl;
	cout<<LinkedList37.element();



	cout<<endl<<"-----------";

	cout<<endl<<"offer() function test;"<<endl;

	cout<<"LinkedList37.offer(6);"<<endl;
	LinkedList37.offer(6);

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();


	cout<<endl<<"-----------";

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<"poll() function test;"<<endl;

	cout<<"LinkedList37.poll(); return value;"<<endl;
	cout<<LinkedList37.poll();

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList37.printElements();

	cout<<endl<<"-----------";

	cout<<endl<<endl<<endl<<endl;










cout<<endl<<endl<<"=>=>=>=>VECTOR STRING TEST<=<=<=<="<<endl<<endl;
	vector <string> vec40;
	vec40.push_back("yusuf");
	vec40.push_back("can");
	vec40.push_back("kan");

	vector <string> vec41;
	vec41.push_back("GEBZE");
	vec41.push_back("TEKNIK");
	vec41.push_back("UNIVERSITESI");
	vec41.push_back("BM");
	vec41.push_back("CSE");
	vec41.push_back("GTU");

	vector <string> vec42;
	vec42.push_back("CSE241");
	vec42.push_back("OOP");
	vec42.push_back("JAVA");

	LinkedList<string,vector<string> > LinkedList40(vec40);
	LinkedList<string,vector<string> > LinkedList41(vec41);
	LinkedList<string,vector<string> > LinkedList42(vec42);




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<string,vector<string> > LinkedListiter1 = LinkedList40.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current LinkedList;"<<endl;
	cout<< *(LinkedListiter1.getIterator());
	while(LinkedListiter1.hasNext() != 0){
		LinkedListiter1.next();
		cout<<" "<< *(LinkedListiter1.getIterator());
	}




	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	LinkedList40.add("kitap");
	cout<<endl<<"'kitap' added LinkedList1";
	LinkedList40.add("defter");
	cout<<endl<<"'defter' added LinkedList1";
	LinkedList40.add("kalem");
	cout<<endl<<"'kalem' added LinkedList1";
	LinkedList40.add("YCK");
	cout<<endl<<"'YCK' added LinkedList1"<<endl<<endl;

	cout<<"Current LinkedList;"<<endl;
	LinkedList40.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"LinkedList42 current elements;"<<endl;
	LinkedList42.printElements();

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<endl<<"After LinkedList40.addAll(LinkedList42);"<<endl;
	LinkedList40.addAll(LinkedList42);

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();



	cout<<endl<<endl<<"-----------";


	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"LinkedList41 current elements;"<<endl;
	LinkedList41.printElements();

	cout<<endl<<"LinkedList41.clear();";
	LinkedList41.clear();

	cout<<endl<<"LinkedList41.add('ALI');";
	LinkedList41.add("ALI");

	cout<<endl<<"LinkedList41 current elements;"<<endl;
	LinkedList41.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<"HastSet4.contains('OOP') returns;"<<endl;
	cout<<LinkedList40.contains("OOP");

	cout<<endl<<"HastSet1.contains('asd') returns;"<<endl;
	cout<<LinkedList40.contains("asd");



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<"LinkedList42 current elements;"<<endl;
	LinkedList42.printElements();

	cout<<endl<<endl<<"HastSet4.containsAll(LinkedList42) returns;"<<endl;
	cout<<LinkedList40.containsAll(LinkedList42);

	cout<<endl<<endl<<"LinkedList42.add('COMPUTER');"<<endl;
	LinkedList42.add("COMPUTER");

	cout<<endl<<"HastSet1.containsAll(LinkedList42) returns;"<<endl;
	cout<<LinkedList40.containsAll(LinkedList42);



	cout<<endl<<endl<<"-----------";




	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"LinkedList41.isEmpty() returns;"<<endl;
	cout<<LinkedList41.isEmpty()<<endl;
	cout<<"LinkedList41.clear();"<<endl;
	LinkedList41.clear();
	cout<<"LinkedList41.isEmpty() returns;"<<endl;
	cout<<LinkedList41.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<endl<<"LinkedList40.remove('OOP')"<<endl;
	LinkedList40.remove("OOP");
	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<endl<<"LinkedList40.remove('JAVA')"<<endl;
		LinkedList40.remove("JAVA");
		cout<<endl<<"LinkedList40 current elements;"<<endl;
		LinkedList40.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	LinkedList41.add("kitap");
	LinkedList41.add("defter");
	LinkedList41.add("kalem");

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<"LinkedList41 current elements;"<<endl;
	LinkedList41.printElements();

	cout<<endl<<endl<<"LinkedList40.removeAll(LinkedList41);"<<endl;
	LinkedList40.removeAll(LinkedList41);

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	LinkedList42.clear();
	LinkedList42.add("kan");
	LinkedList42.add("can");


	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<"LinkedList42 current elements;"<<endl;
	LinkedList42.printElements();

	cout<<endl<<endl<<"LinkedList40.retainAll(LinkedList42);";
	LinkedList40.retainAll(LinkedList42);

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();



	cout<<endl<<"-----------";

	cout<<endl<<"size() function test;"<<endl;
	cout<<"LinkedList40.size() returns;"<<endl;
	cout<<LinkedList40.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<"LinkedList41 current elements;"<<endl;
	LinkedList41.printElements();
	cout<<endl<<"LinkedList40 = LinkedList41"<<endl;
	LinkedList40 = LinkedList41;
	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();



	cout<<endl<<"-----------"<<endl;

	cout<<endl<<"element() function test;"<<endl;

	cout<<"LinkedList40.element(); function return value;"<<endl;
	cout<<LinkedList40.element();



	cout<<endl<<"-----------";

	cout<<endl<<"offer() function test;"<<endl;

	cout<<"LinkedList40.offer('yusuf');"<<endl;
	LinkedList40.offer("yusuf");

	cout<<endl<<"LinkedList37 current elements;"<<endl;
	LinkedList40.printElements();


	cout<<endl<<"-----------";

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<"poll() function test;"<<endl;

	cout<<"LinkedList40.poll(); return value;"<<endl;
	cout<<LinkedList40.poll();

	cout<<endl<<"LinkedList40 current elements;"<<endl;
	LinkedList40.printElements();

	cout<<endl<<"-----------";

	cout<<endl<<endl<<endl<<endl;













cout<<endl<<endl<<"**************************LinkedList LIST TEST*****************************"<<endl<<endl;



	list <int> vec49;
	vec49.push_back(1);
	vec49.push_back(2);
	vec49.push_back(3);

	list <int> vec50;
	vec50.push_back(7);
	vec50.push_back(8);
	vec50.push_back(9);
	vec50.push_back(10);
	vec50.push_back(11);
	vec50.push_back(12);

	list <int> vec51;
	vec51.push_back(4);
	vec51.push_back(5);
	vec51.push_back(6);

	LinkedList<int,list<int> > LinkedList49(vec49);
	LinkedList<int,list<int> > LinkedList50(vec50);
	LinkedList<int,list<int> > LinkedList51(vec51);






/***************************  LinkedList LIST<INT> ****************************************/
	cout<<"=>=>==>=>=>=>>=> For LinkedList list<int> <=<=<=<=<=<=<=<="<<endl;




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<int,list<int> > LinkedListiter2 = LinkedList49.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current LinkedList;"<<endl;
	cout<< *(LinkedListiter2.getIterator());
	while(LinkedListiter2.hasNext() != 0){
		LinkedListiter2.next();
		cout<<" "<< *(LinkedListiter2.getIterator());
	}




	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	LinkedList49.add(20);
	cout<<endl<<"20 added LinkedList49";
	LinkedList49.add(21);
	cout<<endl<<"21 added LinkedList49";
	LinkedList49.add(22);
	cout<<endl<<"22 added LinkedList49";
	LinkedList49.add(23);
	cout<<endl<<"23 added LinkedList49"<<endl<<endl;

	cout<<"Current LinkedList;"<<endl;
	LinkedList49.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"LinkedList51 current elements;"<<endl;
	LinkedList51.printElements();

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<"After LinkedList49.addAll(LinkedList51);";
	LinkedList49.addAll(LinkedList51);

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"LinkedList50 current elements;"<<endl;
	LinkedList50.printElements();

	cout<<endl<<"LinkedList50.clear();";
	LinkedList50.clear();

	cout<<endl<<"LinkedList50.add(5);";
	LinkedList50.add(5);

	cout<<endl<<"LinkedList50 current elements;"<<endl;
	LinkedList50.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<"HastSet1.contains(5) returns;"<<endl;
	cout<<LinkedList49.contains(5);

	cout<<endl<<"HastSet1.contains(30) returns;"<<endl;
	cout<<LinkedList49.contains(30);



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<"LinkedList51 current elements;"<<endl;
	LinkedList51.printElements();

	cout<<endl<<endl<<"HastSet1.containsAll(LinkedList51) returns;"<<endl;
	cout<<LinkedList49.containsAll(LinkedList51);

	cout<<endl<<endl<<"LinkedList51.add(50);"<<endl;
	LinkedList51.add(50);

	cout<<endl<<"HastSet1.containsAll(LinkedList51) returns;"<<endl;
	cout<<LinkedList49.containsAll(LinkedList51);



	cout<<endl<<endl<<"-----------";

	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"LinkedList50.isEmpty() returns;"<<endl;
	cout<<LinkedList50.isEmpty()<<endl;
	cout<<"LinkedList50.clear();"<<endl;
	LinkedList50.clear();
	cout<<"LinkedList50.isEmpty() returns;"<<endl;
	cout<<LinkedList50.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<endl<<"LinkedList49.remove(6)"<<endl;
	LinkedList49.remove(6);
	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<endl<<"LinkedList49.remove(2)"<<endl;
	LinkedList49.remove(2);
	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	LinkedList50.add(20);
	LinkedList50.add(22);
	LinkedList50.add(23);

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<"LinkedList50 current elements;"<<endl;
	LinkedList50.printElements();

	cout<<endl<<endl<<"LinkedList49.removeAll(LinkedList50);"<<endl;
	LinkedList49.removeAll(LinkedList50);

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();


	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	LinkedList51.clear();
	LinkedList51.add(21);
	LinkedList51.add(4);
	LinkedList51.add(5);

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<"LinkedList51 current elements;"<<endl;
	LinkedList51.printElements();

	cout<<endl<<endl<<"LinkedList49.retainAll(LinkedList51);";
	LinkedList49.retainAll(LinkedList51);

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();



	cout<<endl<<"-----------";


	cout<<endl<<"size() function test;"<<endl;
	cout<<"LinkedList49.size() returns;"<<endl;
	cout<<LinkedList49.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<"LinkedList50 current elements;"<<endl;
	LinkedList50.printElements();
	cout<<endl<<"LinkedList49 = LinkedList50"<<endl;
	LinkedList49 = LinkedList50;
	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<"-----------";


	cout<<endl<<"element() function test;"<<endl;

	cout<<"LinkedList49.element(); function return value;"<<endl;
	cout<<LinkedList49.element();



	cout<<endl<<"-----------";

	cout<<endl<<"offer() function test;"<<endl;

	cout<<"LinkedList49.offer(6);"<<endl;
	LinkedList49.offer(6);

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();


	cout<<endl<<"-----------";

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<"poll() function test;"<<endl;

	cout<<"LinkedList49.poll(); return value;"<<endl;
	cout<<LinkedList49.poll();

	cout<<endl<<"LinkedList49 current elements;"<<endl;
	LinkedList49.printElements();

	cout<<endl<<"-----------";

	cout<<endl<<endl<<endl<<endl;




/**************************************************************************************/
cout<<endl<<endl<<"=>=>=>=>LinkedList LIST STRING TEST<=<=<=<="<<endl<<endl;
	list <string> vec52;
	vec52.push_back("yusuf");
	vec52.push_back("can");
	vec52.push_back("kan");

	list <string> vec53;
	vec53.push_back("GEBZE");
	vec53.push_back("TEKNIK");
	vec53.push_back("UNIVERSITESI");
	vec53.push_back("BM");
	vec53.push_back("CSE");
	vec53.push_back("GTU");

	list <string> vec54;
	vec54.push_back("CSE241");
	vec54.push_back("OOP");
	vec54.push_back("JAVA");

	LinkedList<string,list<string> > LinkedList52(vec52);
	LinkedList<string,list<string> > LinkedList53(vec53);
	LinkedList<string,list<string> > LinkedList54(vec54);




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<string,list<string> > LinkedListiter3 = LinkedList52.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current LinkedList;"<<endl;
	cout<< *(LinkedListiter3.getIterator());
	while(LinkedListiter3.hasNext() != 0){
		LinkedListiter3.next();
		cout<<" "<< *(LinkedListiter3.getIterator());
	}




	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	LinkedList52.add("kitap");
	cout<<endl<<"'kitap' added LinkedList1";
	LinkedList52.add("defter");
	cout<<endl<<"'defter' added LinkedList1";
	LinkedList52.add("kalem");
	cout<<endl<<"'kalem' added LinkedList1";
	LinkedList52.add("YCK");
	cout<<endl<<"'YCK' added LinkedList1"<<endl<<endl;

	cout<<"Current LinkedList;"<<endl;
	LinkedList52.printElements();



	cout<<endl<<endl<<"-----------";



	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"LinkedList54 current elements;"<<endl;
	LinkedList54.printElements();

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<endl<<"After LinkedList52.addAll(LinkedList54);"<<endl;
	LinkedList52.addAll(LinkedList54);

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();



	cout<<endl<<endl<<"-----------";


	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"LinkedList53 current elements;"<<endl;
	LinkedList53.printElements();

	cout<<endl<<"LinkedList53.clear();";
	LinkedList53.clear();

	cout<<endl<<"LinkedList53.add('ALI');";
	LinkedList53.add("ALI");

	cout<<endl<<"LinkedList53 current elements;"<<endl;
	LinkedList53.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<"HastSet4.contains('OOP') returns;"<<endl;
	cout<<LinkedList52.contains("OOP");

	cout<<endl<<"HastSet1.contains('asd') returns;"<<endl;
	cout<<LinkedList52.contains("asd");



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<"LinkedList54 current elements;"<<endl;
	LinkedList54.printElements();

	cout<<endl<<endl<<"HastSet4.containsAll(LinkedList54) returns;"<<endl;
	cout<<LinkedList52.containsAll(LinkedList54);

	cout<<endl<<endl<<"LinkedList54.add('COMPUTER');"<<endl;
	LinkedList54.add("COMPUTER");

	cout<<endl<<"HastSet1.containsAll(LinkedList54) returns;"<<endl;
	cout<<LinkedList52.containsAll(LinkedList54);



	cout<<endl<<endl<<"-----------";




	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"LinkedList53.isEmpty() returns;"<<endl;
	cout<<LinkedList53.isEmpty()<<endl;
	cout<<"LinkedList53.clear();"<<endl;
	LinkedList53.clear();
	cout<<"LinkedList53.isEmpty() returns;"<<endl;
	cout<<LinkedList53.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<endl<<"LinkedList52.remove('OOP')"<<endl;
	LinkedList52.remove("OOP");
	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<endl<<"LinkedList52.remove('JAVA')"<<endl;
		LinkedList52.remove("JAVA");
		cout<<endl<<"LinkedList52 current elements;"<<endl;
		LinkedList52.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	LinkedList53.add("kitap");
	LinkedList53.add("defter");
	LinkedList53.add("kalem");

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<"LinkedList53 current elements;"<<endl;
	LinkedList53.printElements();

	cout<<endl<<endl<<"LinkedList52.removeAll(LinkedList53);"<<endl;
	LinkedList52.removeAll(LinkedList53);

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	LinkedList54.clear();
	LinkedList54.add("kan");
	LinkedList54.add("can");


	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<"LinkedList54 current elements;"<<endl;
	LinkedList54.printElements();

	cout<<endl<<endl<<"LinkedList52.retainAll(LinkedList54);";
	LinkedList52.retainAll(LinkedList54);

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();



	cout<<endl<<"-----------";

	cout<<endl<<"size() function test;"<<endl;
	cout<<"LinkedList52.size() returns;"<<endl;
	cout<<LinkedList52.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<"LinkedList53 current elements;"<<endl;
	LinkedList53.printElements();
	cout<<endl<<"LinkedList52 = LinkedList53"<<endl;
	LinkedList52 = LinkedList53;
	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<"-----------"<<endl;

	cout<<endl<<"element() function test;"<<endl;

	cout<<"LinkedList52.element(); function return value;"<<endl;
	cout<<LinkedList52.element();



	cout<<endl<<"-----------";

	cout<<endl<<"offer() function test;"<<endl;

	cout<<"LinkedList52.offer('yusuf');"<<endl;
	LinkedList52.offer("yusuf");

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();


	cout<<endl<<"-----------";

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<"poll() function test;"<<endl;

	cout<<"LinkedList52.poll(); return value;"<<endl;
	cout<<LinkedList52.poll();

	cout<<endl<<"LinkedList52 current elements;"<<endl;
	LinkedList52.printElements();

	cout<<endl<<"-----------";

	cout<<endl<<endl<<endl<<endl;




cout<<endl<<endl<<endl<<"=>=>=>=>LinkedList SET TEST INT<=<=<=<="<<endl<<endl;






cout<<endl<<endl;




	int arrset43[3] = {1,2,3};
	set<int> vec43 (arrset43,arrset43+3);


	int arrset44[6] = {7,8,9,10,11,12};
	set<int> vec44 (arrset44,arrset44+6);

	int arrset45[3] = {4,5,6};
	set<int> vec45 (arrset45,arrset45+3);



	LinkedList<int,set<int> > LinkedList43(vec43);
	LinkedList<int,set<int> > LinkedList44(vec44);
	LinkedList<int,set<int> > LinkedList45(vec45);

/***************************  SET<INT> ****************************************/
	cout<<"=>=>==>=>=>=>>=> For set<int> <=<=<=<=<=<=<=<="<<endl;




	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<int,set<int> > LinkedListiter4 = LinkedList43.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current LinkedList;"<<endl;
	cout<< *(LinkedListiter4.getIterator());
	while(LinkedListiter4.hasNext() != 0){
		LinkedListiter4.next();
		cout<<" "<< *(LinkedListiter4.getIterator());
	}



	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	LinkedList43.add(20);
	cout<<endl<<"20 added LinkedList43";
	LinkedList43.add(21);
	cout<<endl<<"21 added LinkedList43";
	LinkedList43.add(22);
	cout<<endl<<"22 added LinkedList43";
	LinkedList43.add(23);
	cout<<endl<<"23 added LinkedList43"<<endl<<endl;

	cout<<"Current LinkedList;"<<endl;
	LinkedList43.printElements();



	cout<<endl<<endl<<"-----------";


	/*
	 * First prints the currents elements of variables.
	 * After that uses addAll() and prints result on the screen.
	 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"LinkedList45 current elements;"<<endl;
	LinkedList45.printElements();

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<"After LinkedList43.addAll(LinkedList45);";
	LinkedList43.addAll(LinkedList45);

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();



	cout<<endl<<endl<<"-----------";

	/*
	 * First it prints the currents elements. After that it applies clear() function.
	 * After that it adds an element on the empty sets.
	 * After that it prints the most current version.
	 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"LinkedList44 current elements;"<<endl;
	LinkedList44.printElements();

	cout<<endl<<"LinkedList44.clear();";
	LinkedList44.clear();

	cout<<endl<<"LinkedList44.add(5);";
	LinkedList44.add(5);

	cout<<endl<<"LinkedList44 current elements;"<<endl;
	LinkedList44.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<"HastSet1.contains(5) returns;"<<endl;
	cout<<LinkedList43.contains(5);

	cout<<endl<<"HastSet1.contains(30) returns;"<<endl;
	cout<<LinkedList43.contains(30);



	cout<<endl<<"-----------";



	/*
	 * First it test the true return situation.
	 * After that it adds one element and test the false return situation.
	 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<"LinkedList45 current elements;"<<endl;
	LinkedList45.printElements();

	cout<<endl<<endl<<"HastSet1.containsAll(LinkedList45) returns;"<<endl;
	cout<<LinkedList43.containsAll(LinkedList45);

	cout<<endl<<endl<<"LinkedList45.add(50);"<<endl;
	LinkedList45.add(50);

	cout<<endl<<"HastSet1.containsAll(LinkedList45) returns;"<<endl;
	cout<<LinkedList43.containsAll(LinkedList45);



	cout<<endl<<endl<<"-----------";

	/*
	 * isEmpty() function test. It prints the return values.
	 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"LinkedList44.isEmpty() returns;"<<endl;
	cout<<LinkedList44.isEmpty()<<endl;
	cout<<"LinkedList44.clear();"<<endl;
	LinkedList44.clear();
	cout<<"LinkedList44.isEmpty() returns;"<<endl;
	cout<<LinkedList44.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<endl<<"LinkedList43.remove(6)"<<endl;
	LinkedList43.remove(6);
	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<endl<<"LinkedList43.remove(2)"<<endl;
	LinkedList43.remove(2);
	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"removeAll() function test;"<<endl;

	LinkedList44.add(20);
	LinkedList44.add(22);
	LinkedList44.add(23);

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<"LinkedList44 current elements;"<<endl;
	LinkedList44.printElements();

	cout<<endl<<endl<<"LinkedList43.removeAll(LinkedList44);"<<endl;
	LinkedList43.removeAll(LinkedList44);

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();


	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	LinkedList45.clear();
	LinkedList45.add(21);
	LinkedList45.add(4);
	LinkedList45.add(5);

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<"LinkedList45 current elements;"<<endl;
	LinkedList45.printElements();

	cout<<endl<<endl<<"LinkedList43.retainAll(LinkedList45);";
	LinkedList43.retainAll(LinkedList45);

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();



	cout<<endl<<"-----------";


	cout<<endl<<"size() function test;"<<endl;
	cout<<"LinkedList43.size() returns;"<<endl;
	cout<<LinkedList43.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<"LinkedList44 current elements;"<<endl;
	LinkedList44.printElements();
	cout<<endl<<"LinkedList43 = LinkedList44"<<endl;
	LinkedList43 = LinkedList44;
	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<"-----------";


	cout<<endl<<"element() function test;"<<endl;

	cout<<"LinkedList43.element(); function return value;"<<endl;
	cout<<LinkedList43.element();



	cout<<endl<<"-----------";

	cout<<endl<<"offer() function test;"<<endl;

	cout<<"LinkedList43.offer(6);"<<endl;
	LinkedList43.offer(6);

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();


	cout<<endl<<"-----------";

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<"poll() function test;"<<endl;

	cout<<"LinkedList43.poll(); return value;"<<endl;
	cout<<LinkedList43.poll();

	cout<<endl<<"LinkedList43 current elements;"<<endl;
	LinkedList43.printElements();

	cout<<endl<<"-----------";

	cout<<endl<<endl<<endl<<endl;






	cout<<endl<<endl<<endl<<"=>=>=>=>LinkedList SET TEST STRING<=<=<=<="<<endl<<endl;



	string arrset55[3] = {"yusuf","can","kan"};
	set<string> vec55 (arrset55,arrset55+3);


	string arrset56[6] = {"GEBZE","TEKNIK","UNIVERSİTESI","BM","CSE","GTU"};
	set<string> vec56 (arrset56,arrset56+6);

	string arrset57[3] = {"CSE241","OOP","JAVA"};
	set<string> vec57 (arrset57,arrset57+3);

	LinkedList<string,set<string> > LinkedList55(vec55);
	LinkedList<string,set<string> > LinkedList56(vec56);
	LinkedList<string,set<string> > LinkedList57(vec57);


	cout<<endl<<endl<<"-----------";
	cout<<endl<<"iterator() function test,Please examine the code.;"<<endl;
	/*It creates the iterator.*/
	Iterator<string,set<string> > LinkedListiter5 = LinkedList55.iterator();
	/*It prints the elements with using iterator.*/
	cout<<"Current LinkedList;"<<endl;
	cout<< *(LinkedListiter5.getIterator());
	while(LinkedListiter5.hasNext() != 0){
		LinkedListiter5.next();
		cout<<" "<< *(LinkedListiter5.getIterator());
	}


	cout<<endl<<endl<<"-----------";



	/*First adds the elements and after that prints the result on the screen.*/
	cout<<endl<<"Add function test"<<endl;
	LinkedList55.add("kitap");
	cout<<endl<<"'kitap' added LinkedList1";
	LinkedList55.add("defter");
	cout<<endl<<"'defter' added LinkedList1";
	LinkedList55.add("kalem");
	cout<<endl<<"'kalem' added LinkedList1";
	LinkedList55.add("YCK");
	cout<<endl<<"'YCK' added LinkedList1"<<endl<<endl;

	cout<<"Current LinkedList;"<<endl;
	LinkedList55.printElements();



	cout<<endl<<endl<<"-----------";



		/*
		 * First prints the currents elements of variables.
		 * After that uses addAll() and prints result on the screen.
		 */
	cout<<endl<<"AddAll function test;";
	cout<<endl<<"LinkedList57 current elements;"<<endl;
	LinkedList57.printElements();

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<endl<<"After LinkedList55.addAll(LinkedList57);"<<endl;
	LinkedList55.addAll(LinkedList57);

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();



	cout<<endl<<endl<<"-----------";


		/*
		 * First it prints the currents elements. After that it applies clear() function.
		 * After that it adds an element on the empty sets.
		 * After that it prints the most current version.
		 */

	cout<<endl<<"clear() function test;"<<endl;

	cout<<endl<<"LinkedList56 current elements;"<<endl;
	LinkedList56.printElements();

	cout<<endl<<"LinkedList56.clear();";
	LinkedList56.clear();

	cout<<endl<<"LinkedList56.add('ALI');";
	LinkedList56.add("ALI");

	cout<<endl<<"LinkedList56 current elements;"<<endl;
	LinkedList56.printElements();



	cout<<endl<<endl<<"-----------";



	/*Test for contain function.*/
	cout<<endl<<"contains() function test;"<<endl;

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<"HastSet4.contains('OOP') returns;"<<endl;
	cout<<LinkedList55.contains("OOP");

	cout<<endl<<"HastSet1.contains('asd') returns;"<<endl;
	cout<<LinkedList55.contains("asd");


	cout<<endl<<"-----------";

		/*
		 * First it test the true return situation.
		 * After that it adds one element and test the false return situation.
		 */
	cout<<endl<<"containsAll() function test;"<<endl;

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<"LinkedList57 current elements;"<<endl;
	LinkedList57.printElements();

	cout<<endl<<endl<<"HastSet4.containsAll(LinkedList57) returns;"<<endl;
	cout<<LinkedList55.containsAll(LinkedList57);

	cout<<endl<<endl<<"LinkedList57.add('COMPUTER');"<<endl;
	LinkedList57.add("COMPUTER");

	cout<<endl<<"HastSet1.containsAll(LinkedList57) returns;"<<endl;
	cout<<LinkedList55.containsAll(LinkedList57);



	cout<<endl<<endl<<"-----------";




		/*
		 * isEmpty() function test. It prints the return values.
		 */
	cout<<endl<<"isEmpty() function test;"<<endl;

	cout<<"LinkedList56.isEmpty() returns;"<<endl;
	cout<<LinkedList56.isEmpty()<<endl;
	cout<<"LinkedList56.clear();"<<endl;
	LinkedList56.clear();
	cout<<"LinkedList56.isEmpty() returns;"<<endl;
	cout<<LinkedList56.isEmpty();



	cout<<endl<<"-----------";



	cout<<endl<<"remove() function test;"<<endl;

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<endl<<"LinkedList55.remove('OOP')"<<endl;
	LinkedList55.remove("OOP");
	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<endl<<"LinkedList55.remove('JAVA')"<<endl;
	LinkedList55.remove("JAVA");
	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();



	cout<<endl<<"-----------";


	cout<<endl<<"removeAll() function test;"<<endl;

	LinkedList56.add("kitap");
	LinkedList56.add("defter");
	LinkedList56.add("kalem");

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<"LinkedList56 current elements;"<<endl;
	LinkedList56.printElements();

	cout<<endl<<endl<<"LinkedList55.removeAll(LinkedList56);"<<endl;
	LinkedList55.removeAll(LinkedList56);

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();



	cout<<endl<<"-----------";



	cout<<endl<<"retainAll() function test;"<<endl;

	LinkedList57.clear();
	LinkedList57.add("kan");
	LinkedList57.add("can");


	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<"LinkedList57 current elements;"<<endl;
	LinkedList57.printElements();

		cout<<endl<<endl<<"LinkedList55.retainAll(LinkedList57);";
	LinkedList55.retainAll(LinkedList57);

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();



	cout<<endl<<"-----------";

	cout<<endl<<"size() function test;"<<endl;
	cout<<"LinkedList55.size() returns;"<<endl;
	cout<<LinkedList55.size();


	cout<<endl<<"-----------";

	cout<<endl<<"Assignment operator function test;"<<endl;

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<"LinkedList56 current elements;"<<endl;
	LinkedList56.printElements();
	cout<<endl<<"LinkedList55 = LinkedList56"<<endl;
	LinkedList55 = LinkedList56;
	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<"-----------"<<endl;

	cout<<endl<<"element() function test;"<<endl;

	cout<<"LinkedList55.element(); function return value;"<<endl;
	cout<<LinkedList55.element();



	cout<<endl<<"-----------";

	cout<<endl<<"offer() function test;"<<endl;

	cout<<"LinkedList55.offer('yusuf');"<<endl;
	LinkedList55.offer("yusuf");

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();


	cout<<endl<<"-----------";

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<"poll() function test;"<<endl;

	cout<<"LinkedList55.poll(); return value;"<<endl;
	cout<<LinkedList55.poll();

	cout<<endl<<"LinkedList55 current elements;"<<endl;
	LinkedList55.printElements();

	cout<<endl<<"-----------"<<endl;

	cout<<endl<<endl<<endl<<endl;



	cout<<"--------------------------EXCEPTION TESTS--------------------------------------------";
	cout<<"Please examine the code."<<endl;

	cout<<endl<<endl;

	vector<int> xx;

	xx.push_back(10);
	xx.push_back(20);
	cout<<endl<<"-----------"<<endl;
	cout<<"Iterator.Next() exception"<<endl;

	Iterator<int,vector<int> > itertemp(xx);

	cout<<"iter.next();"<<endl;
	cout<<itertemp.next()<<endl;
	cout<<"iter.next();"<<endl;
	cout<<"Last Element:"<<itertemp.next()<<endl;
	cout<<endl<<"-----------"<<endl;

	cout<<endl<<"Iterator.Remove() exception"<<endl;

	cout<<"iter.remove();"<<endl;
	itertemp.remove();

	cout<<endl<<"-----------"<<endl;
	cout<<endl<<"HashSet.Remove() exception"<<endl;

	cout<<"iter.remove();"<<endl;
	HashSet1.clear();
	HashSet1.remove(5);
	cout<<endl<<"-----------"<<endl;
	cout<<endl<<"LinkedList.Remove() exception"<<endl;

	cout<<"iter.remove();"<<endl;
	LinkedList43.clear();
	LinkedList43.remove(5);

	cout<<endl<<"-----------"<<endl;
	cout<<endl<<"ArrayList.Remove() exception"<<endl;

	cout<<"iter.remove();"<<endl;
	ArrayList25.clear();
	ArrayList25.remove(5);

	cout<<endl<<"-----------"<<endl;
	cout<<endl<<"HashSet.Add() Duplicate exception"<<endl;

	cout<<"HashSet8 Current Values;"<<endl;
	HashSet8.printElements();


	cout<<endl<<endl<<"HashSet8.add(20);"<<endl;

	HashSet8.add(20);





































































	return 0;
}



