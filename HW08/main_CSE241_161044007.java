
/**
 * Driver class for Collection hierarchy
 * @author Yusuf Can
*/



public class main_CSE241_161044007{
	public static void main(String[] args){


		Integer[] array1=new Integer[20];
		for(int i=0;i<array1.length;i++){
			array1[i]=i;
		}



		Integer[] array2=new Integer[4];
		array2[0]=1;
		array2[1]=2;
		array2[2]=3;
		array2[3]=4;



		Integer[] array3=new Integer[3];
		array3[0]=20;
		array3[1]=21;
		array3[2]=22;

		System.out.printf("\n");
	/*HashSet int test.*/
		System.out.println("-------------HashSet<int>-------------");
		System.out.printf("\n");
		/*Constructor tests.*/
		HashSet<Integer> hash1 = new HashSet<Integer>();

		/*setInner method Test*/
		hash1.setInner(array1);
		
		HashSet<Integer> hash2 = new HashSet<Integer>(array2);
		HashSet<Integer> hash3 = new HashSet<Integer>(array3);

		System.out.printf(" HashSet1 elements;");
		hash1.printAll();
		System.out.printf("HashSet2 elements;");
		hash2.printAll();
		System.out.printf("HashSet3 elements;");
		hash3.printAll();
		System.out.printf("\n");

		/*Iterator function test*/
		
		Iterator<Integer> iter1 = new Iterator<Integer>(array1,hash1);
		System.out.printf(" Iterator prints elements(HashSet1)\n");
		while(iter1.hasNext()){
			System.out.printf(" %d ",iter1.getCurrent());
			iter1.next();
		}
		System.out.printf(" %d ",iter1.getCurrent());
		System.out.printf("\n \n");

		hash1.add(29);
		System.out.printf(" HashSet1.add(29);");
		hash1.printAll();

		System.out.printf("\n");

		System.out.printf("HashSet1.addAll(HashSet3);");
		hash1.addAll(hash3);
		hash1.printAll();

		System.out.printf("\n");

		System.out.printf(" HashSet3.clear();");
		System.out.printf("\n HashSet3.add(10);");
		System.out.printf("\n HashSet3.add(11);");
		hash3.clear();
		hash3.add(10);
		hash3.add(11);
		hash3.printAll();
		System.out.printf("\n");

		System.out.printf("HashSet3.contains(10);");
		System.out.printf("\n %b",(hash3.contains(10)));
		System.out.printf("\n");

		System.out.printf("\n HashSet1.containsAll(HashSet2);");
		System.out.printf("\n %b",(hash1.containsAll(hash2)));
		System.out.printf("\n \n");

		System.out.printf(" HashSet3.isEmpty();");
		System.out.printf("\n %b",hash3.isEmpty());
		System.out.printf("\n HashSet3.clear();");
		hash3.clear();
		System.out.printf("\n HashSet3.isEmpty();");
		System.out.printf("\n %b",hash3.isEmpty());
		hash3.add(10);
		hash3.add(11);
		hash3.add(21);
		System.out.printf("\n\n");

		System.out.printf(" HashSet1.remove(0);");
		hash1.remove(0);
		hash1.printAll();
		System.out.printf(" HashSet1.remove(14);");
		hash1.remove(14);
		hash1.printAll();
		System.out.printf(" HashSet1.remove(22);");
		hash1.remove(22);
		hash1.printAll();
		System.out.printf("\n\n");

		System.out.printf(" HashSet1 elements;");
		hash1.printAll();
		System.out.printf("HashSet2 elements;");
		hash2.printAll();
		System.out.printf("HashSet3 elements;");
		hash3.printAll();

		System.out.printf("\n");
		System.out.printf(" HashSet1.removeAll(HashSet3);");
		hash1.removeAll(hash3);
		hash1.printAll();

		System.out.printf("\n");
		System.out.printf(" HashSet1.retainAll(HashSet2);");
		hash1.retainAll(hash2);
		hash1.printAll();
		
		System.out.printf("\n");
		System.out.printf(" HashSet1.size()");
		System.out.printf("\n %d",hash1.size());
		
		
		System.out.printf("\n \n");
		System.out.printf(" HashSet3.equals(HashSet2)");
		System.out.printf("\n %s",hash3.equals(hash2));
		System.out.printf("\n HashSet3.clear()");
		System.out.printf("\n HashSet3.add(1)");
		System.out.printf("\n HashSet3.add(2)");
		System.out.printf("\n HashSet3.add(3)");
		System.out.printf("\n HashSet3.add(4)");
		hash3.clear();
		hash3.add(1);
		hash3.add(2);
		hash3.add(3);
		hash3.add(4);
		System.out.printf("\n HashSet3.equals(HashSet2)");
		System.out.printf("\n %s",hash3.equals(hash2));

		System.out.printf("\n \nHashSet3.ToString()");	
		System.out.printf("\n%s",hash3);



		







		String[] array4=new String[5];
		array4[0]="Yusuf";
		array4[1]="Can";
		array4[2]="Kan";
		array4[3]="GTU";
		array4[4]="CSE241";


		String[] array5=new String[3];
		array5[0]="Can";
		array5[1]="Kan";
		array5[2]="CSE241";



		String[] array6=new String[3];
		array6[0]="OOP";
		array6[1]="JAVA";
		array6[2]="Iterator";

		System.out.printf("\n");
	/*HashSet string test.*/
		System.out.println("\n-------------HashSet<string>-------------");
		System.out.printf("\n");
		/*Constructor tests.*/
		HashSet<String> hash4 = new HashSet<String>();

		/*setInner method Test*/
		hash4.setInner(array4);
		
		HashSet<String> hash5 = new HashSet<String>(array5);
		HashSet<String> hash6 = new HashSet<String>(array6);

		System.out.printf(" HashSet4 elements;");
		hash4.printAll();
		System.out.printf("HashSet5 elements;");
		hash5.printAll();
		System.out.printf("HashSet6 elements;");
		hash6.printAll();
		System.out.printf("\n");

		/*Iterator function test*/
		
		Iterator<String> iter4 = new Iterator<String>(array4,hash4);
		System.out.printf(" Iterator prints elements(HashSet4)\n");
		while(iter4.hasNext()){
			System.out.printf(" %s ",iter4.getCurrent().toString() );
			iter4.next();
		}
		System.out.printf(" %s ",iter4.getCurrent());
		System.out.printf("\n \n");

		hash4.add("Java");
		System.out.printf(" HashSet4.add('Java');");
		hash4.printAll();

		System.out.printf("\n");

		System.out.printf("HashSet4.addAll(HashSet6);");
		hash4.addAll(hash6);
		hash4.printAll();

		System.out.printf("\n");

		System.out.printf(" HashSet6.clear();");
		System.out.printf("\n HashSet6.add('Yusuf');");
		System.out.printf("\n HashSet6.add('Can');");
		hash6.clear();
		hash6.add("Yusuf");
		hash6.add("Can");
		hash6.printAll();
		System.out.printf("\n");

		System.out.printf("HashSet6.contains('Yusuf');");
		System.out.printf("\n %b",(hash6.contains("Yusuf")));
		System.out.printf("\n");

		System.out.printf("\n HashSet4.containsAll(HashSet5);");
		System.out.printf("\n %b",(hash4.containsAll(hash5)));
		System.out.printf("\n \n");

		System.out.printf(" HashSet6.isEmpty();");
		System.out.printf("\n %b",hash6.isEmpty());
		System.out.printf("\n HashSet6.clear();");
		hash6.clear();
		System.out.printf("\n HashSet6.isEmpty();");
		System.out.printf("\n %b",hash6.isEmpty());
		hash6.add("Can");
		hash6.add("JAVA");
		System.out.printf("\n\n");

		System.out.printf(" HashSet4.remove('Yusuf');");
		hash4.remove("Yusuf");
		hash4.printAll();
		System.out.printf(" HashSet4.remove('CSE241');");
		hash4.remove("CSE241");
		hash4.printAll();
		System.out.printf(" HashSet4.remove('Iterator');");
		hash4.remove("Iterator");
		hash4.printAll();
		System.out.printf("\n\n");

		System.out.printf(" HashSet4 elements;");
		hash4.printAll();
		System.out.printf("HashSet5 elements;");
		hash5.printAll();
		System.out.printf("HashSet6 elements;");
		hash6.printAll();

		System.out.printf("\n");
		System.out.printf(" HashSet4.removeAll(HashSet6);");
		hash4.removeAll(hash6);
		hash4.printAll();

		System.out.printf("\n");
		System.out.printf(" HashSet4.retainAll(HashSet5);");
		hash4.retainAll(hash5);
		hash4.printAll();
		
		System.out.printf("\n");
		System.out.printf(" HashSet5.size()");
		System.out.printf("\n %s",hash5.size());

		System.out.printf("\n \n");
		System.out.printf(" HashSet6.equals(HashSet5)");
		System.out.printf("\n %s",hash6.equals(hash5));
		System.out.printf("\n HashSet5.clear()");
		System.out.printf("\n HashSet5.add('Can')");
		System.out.printf("\n HashSet5.add('JAVA')");
		hash5.clear();
		hash5.add("Can");
		hash5.add("JAVA");
		System.out.printf("\n HashSet6.equals(HashSet5)");
		System.out.printf("\n %s",hash6.equals(hash5));
		

		System.out.printf("\n \nHashSet6.ToString()");	
		System.out.printf("\n%s",hash6);

	



	



		Integer[] array7=new Integer[20];
		for(int i=0;i<array7.length;i++){
			array7[i]=i;
		}



		Integer[] array8=new Integer[4];
		array8[0]=1;
		array8[1]=2;
		array8[2]=3;
		array8[3]=4;



		Integer[] array9=new Integer[3];
		array9[0]=20;
		array9[1]=21;
		array9[2]=22;

		System.out.printf("\n");
	/*ArrayList int test.*/
		System.out.println("\n-------------ArrayList<int>-------------");
		System.out.printf("\n");
		/*Constructor tests.*/
		ArrayList<Integer> list7 = new ArrayList<Integer>();

		/*setInner method Test*/
		list7.setInner(array7);
		
		ArrayList<Integer> list8 = new ArrayList<Integer>(array8);
		ArrayList<Integer> list9 = new ArrayList<Integer>(array9);

		System.out.printf(" ArrayList7 elements;");
		list7.printAll();
		System.out.printf("ArrayList8 elements;");
		list8.printAll();
		System.out.printf("ArrayList9 elements;");
		list9.printAll();
		System.out.printf("\n");

		/*Iterator function test*/
		
		Iterator<Integer> iter5 = new Iterator<Integer>(array7,list7);
		System.out.printf(" Iterator prints elements(ArrayList7)\n");
		while(iter5.hasNext()){
			System.out.printf(" %d ",iter5.getCurrent());
			iter5.next();
		}
		System.out.printf(" %d ",iter5.getCurrent());
		System.out.printf("\n \n");

		list7.add(29);
		System.out.printf(" ArrayList7.add(29);");
		list7.printAll();

		System.out.printf("\n");

		System.out.printf("ArrayList7.addAll(ArrayList9);");
		list7.addAll(list9);
		list7.printAll();

		System.out.printf("\n");

		System.out.printf(" ArrayList9.clear();");
		System.out.printf("\n ArrayList9.add(10);");
		System.out.printf("\n ArrayList9.add(11);");
		list9.clear();
		list9.add(10);
		list9.add(11);
		list9.printAll();
		System.out.printf("\n");

		System.out.printf("ArrayList9.contains(10);");
		System.out.printf("\n %b",(list9.contains(10)));
		System.out.printf("\n");

		System.out.printf("\n ArrayList7.containsAll(ArrayList8);");
		System.out.printf("\n %b",(list7.containsAll(list8)));
		System.out.printf("\n \n");

		System.out.printf(" ArrayList9.isEmpty();");
		System.out.printf("\n %b",list9.isEmpty());
		System.out.printf("\n ArrayList9.clear();");
		list9.clear();
		System.out.printf("\n ArrayList9.isEmpty();");
		System.out.printf("\n %b",list9.isEmpty());
		list9.add(10);
		list9.add(11);
		list9.add(21);
		System.out.printf("\n\n");

		System.out.printf(" ArrayList7.remove(0);");
		list7.remove(0);
		list7.printAll();
		System.out.printf(" ArrayList7.remove(14);");
		list7.remove(14);
		list7.printAll();
		System.out.printf(" ArrayList7.remove(22);");
		list7.remove(22);
		list7.printAll();
		System.out.printf("\n\n");

		System.out.printf(" ArrayList7 elements;");
		list7.printAll();
		System.out.printf("ArrayList8 elements;");
		list8.printAll();
		System.out.printf("ArrayList9 elements;");
		list9.printAll();

		System.out.printf("\n");
		System.out.printf(" ArrayList7.removeAll(ArrayList9);");
		list7.removeAll(list9);
		list7.printAll();

		System.out.printf("\n");
		System.out.printf(" ArrayList7.retainAll(ArrayList8);");
		list7.retainAll(list8);
		list7.printAll();
		
		System.out.printf("\n");
		System.out.printf(" ArrayList7.size()");
		System.out.printf("\n %d",list7.size());
		
		System.out.printf("\n \n");
		System.out.printf(" ArrayList9.equals(ArrayList8)");
		System.out.printf("\n %s",list9.equals(list8));
		System.out.printf("\n ArrayList9.clear()");
		System.out.printf("\n ArrayList9.add(1)");
		System.out.printf("\n ArrayList9.add(2)");
		System.out.printf("\n ArrayList9.add(3)");
		System.out.printf("\n ArrayList9.add(4)");
		list9.clear();
		list9.add(1);
		list9.add(2);
		list9.add(3);
		list9.add(4);
		System.out.printf("\n ArrayList9.equals(ArrayList8)");
		System.out.printf("\n %s",list9.equals(list8));

		System.out.printf("\n \nArrayList9.ToString()");	
		System.out.printf("\n%s",list9);







	



		String[] array10=new String[5];
		array10[0]="Yusuf";
		array10[1]="Can";
		array10[2]="Kan";
		array10[3]="GTU";
		array10[4]="CSE241";


		String[] array11=new String[3];
		array11[0]="Can";
		array11[1]="Kan";
		array11[2]="CSE241";



		String[] array12=new String[3];
		array12[0]="OOP";
		array12[1]="JAVA";
		array12[2]="Iterator";





		System.out.printf("\n");
	/*ArrayList string test.*/
		System.out.println("\n-------------ArrayList<string>-------------");
		System.out.printf("\n");
		/*Constructor tests.*/
		ArrayList<String> list10 = new ArrayList<String>();

		/*setInner method Test*/
		list10.setInner(array10);
		
		ArrayList<String> list11 = new ArrayList<String>(array11);
		ArrayList<String> list12 = new ArrayList<String>(array12);

		System.out.printf(" ArrayList10 elements;");
		list10.printAll();
		System.out.printf("ArrayList11 elements;");
		list11.printAll();
		System.out.printf("ArrayList12 elements;");
		list12.printAll();
		System.out.printf("\n");

		/*Iterator function test*/
		
		Iterator<String> iter6 = new Iterator<String>(array10,list10);
		System.out.printf(" Iterator prints elements(ArrayList10)\n");
		while(iter6.hasNext()){
			System.out.printf(" %s ",iter6.getCurrent().toString() );
			iter6.next();
		}
		System.out.printf(" %s ",iter6.getCurrent());
		System.out.printf("\n \n");

		list10.add("Java");
		System.out.printf(" ArrayList10.add('Java');");
		list10.printAll();

		System.out.printf("\n");

		System.out.printf("ArrayList10.addAll(ArrayList12);");
		list10.addAll(list12);
		list10.printAll();

		System.out.printf("\n");

		System.out.printf(" ArrayList12.clear();");
		System.out.printf("\n ArrayList12.add('Yusuf');");
		System.out.printf("\n ArrayList12.add('Can');");
		list12.clear();
		list12.add("Yusuf");
		list12.add("Can");
		list12.printAll();
		System.out.printf("\n");

		System.out.printf("ArrayList12.contains('Yusuf');");
		System.out.printf("\n %b",(list12.contains("Yusuf")));
		System.out.printf("\n");

		System.out.printf("\n ArrayList10.containsAll(ArrayList11);");
		System.out.printf("\n %b",(list10.containsAll(list11)));
		System.out.printf("\n \n");

		System.out.printf(" ArrayList12.isEmpty();");
		System.out.printf("\n %b",list12.isEmpty());
		System.out.printf("\n ArrayList12.clear();");
		list12.clear();
		System.out.printf("\n ArrayList12.isEmpty();");
		System.out.printf("\n %b",list12.isEmpty());
		list12.add("Can");
		list12.add("JAVA");
		System.out.printf("\n\n");

		System.out.printf(" ArrayList10.remove('Yusuf');");
		list10.remove("Yusuf");
		list10.printAll();
		System.out.printf(" ArrayList10.remove('CSE241');");
		list10.remove("CSE241");
		list10.printAll();
		System.out.printf(" ArrayList10.remove('Iterator');");
		list10.remove("Iterator");
		list10.printAll();
		System.out.printf("\n\n");

		System.out.printf(" ArrayList10 elements;");
		list10.printAll();
		System.out.printf("ArrayList11 elements;");
		list11.printAll();
		System.out.printf("ArrayList12 elements;");
		list12.printAll();

		System.out.printf("\n");
		System.out.printf(" ArrayList10.removeAll(ArrayList12);");
		list10.removeAll(list12);
		list10.printAll();

		System.out.printf("\n");
		System.out.printf(" ArrayList10.retainAll(ArrayList11);");
		list10.retainAll(list11);
		list10.printAll();
		
		System.out.printf("\n");
		System.out.printf(" ArrayList11.size()");
		System.out.printf("\n %s",list11.size());
		

		System.out.printf("\n \n");
		System.out.printf(" ArrayList12.equals(ArrayList11)");
		System.out.printf("\n %s",list12.equals(list11));
		System.out.printf("\n ArrayList11.clear()");
		System.out.printf("\n ArrayList11.add('Can')");
		System.out.printf("\n ArrayList11.add('JAVA')");
		list11.clear();
		list11.add("Can");
		list11.add("JAVA");
		System.out.printf("\n ArrayList12.equals(ArrayList11)");
		System.out.printf("\n %s",list12.equals(list11));


		System.out.printf("\n \nArrayList12.ToString()");	
		System.out.printf("\n%s",list12);











		Integer[] array13=new Integer[20];
		for(int i=0;i<array13.length;i++){
			array13[i]=i;
		}



		Integer[] array14=new Integer[4];
		array14[0]=1;
		array14[1]=2;
		array14[2]=3;
		array14[3]=4;



		Integer[] array15=new Integer[3];
		array15[0]=20;
		array15[1]=21;
		array15[2]=22;
	
		System.out.printf("\n");
	/*LinkedList int test.*/
		System.out.println("\n-------------LinkedList<int>-------------");
		System.out.printf("\n");
		/*Constructor tests.*/
		LinkedList<Integer> linked1 = new LinkedList<Integer>();

		/*setInner method Test*/
		linked1.setInner(array13);
		
		LinkedList<Integer> linked2 = new LinkedList<Integer>(array14);
		LinkedList<Integer> linked3 = new LinkedList<Integer>(array15);

		System.out.printf(" LinkedList1 elements;");
		linked1.printAll();
		System.out.printf("LinkedList2 elements;");
		linked2.printAll();
		System.out.printf("LinkedList3 elements;");
		linked3.printAll();
		System.out.printf("\n");

		/*Iterator function test*/
		
		Iterator<Integer> iter7 = new Iterator<Integer>(array13,linked1);
		System.out.printf(" Iterator prints elements(LinkedList1)\n");
		while(iter7.hasNext()){
			System.out.printf(" %d ",iter7.getCurrent());
			iter7.next();
		}
		System.out.printf(" %d ",iter7.getCurrent());
		System.out.printf("\n \n");

		linked1.add(29);
		System.out.printf(" LinkedList1.add(29);");
		linked1.printAll();

		System.out.printf("\n");

		System.out.printf("LinkedList1.addAll(LinkedList3);");
		linked1.addAll(linked3);
		linked1.printAll();

		System.out.printf("\n");

		System.out.printf(" LinkedList3.clear();");
		System.out.printf("\n LinkedList3.add(10);");
		System.out.printf("\n LinkedList3.add(11);");
		linked3.clear();
		linked3.add(10);
		linked3.add(11);
		linked3.printAll();
		System.out.printf("\n");

		System.out.printf("LinkedList3.contains(10);");
		System.out.printf("\n %b",(linked3.contains(10)));
		System.out.printf("\n");

		System.out.printf("\n LinkedList1.containsAll(LinkedList2);");
		System.out.printf("\n %b",(linked1.containsAll(linked2)));
		System.out.printf("\n \n");

		System.out.printf(" LinkedList3.isEmpty();");
		System.out.printf("\n %b",linked3.isEmpty());
		System.out.printf("\n LinkedList3.clear();");
		linked3.clear();
		System.out.printf("\n LinkedList3.isEmpty();");
		System.out.printf("\n %b",linked3.isEmpty());
		linked3.add(10);
		linked3.add(11);
		linked3.add(21);
		System.out.printf("\n\n");

		System.out.printf(" LinkedList1.remove(0);");
		linked1.remove(0);
		linked1.printAll();
		System.out.printf(" LinkedList1.remove(14);");
		linked1.remove(14);
		linked1.printAll();
		System.out.printf(" LinkedList1.remove(22);");
		linked1.remove(22);
		linked1.printAll();
		System.out.printf("\n\n");

		System.out.printf(" LinkedList1 elements;");
		linked1.printAll();
		System.out.printf("LinkedList2 elements;");
		linked2.printAll();
		System.out.printf("LinkedList3 elements;");
		linked3.printAll();

		System.out.printf("\n");
		System.out.printf(" LinkedList1.removeAll(LinkedList3);");
		linked1.removeAll(linked3);
		linked1.printAll();

		System.out.printf("\n");
		System.out.printf(" LinkedList1.retainAll(LinkedList2);");
		linked1.retainAll(linked2);
		linked1.printAll();
		
		System.out.printf("\n");
		System.out.printf(" LinkedList1.size()");
		System.out.printf("\n %d",linked1.size());

		System.out.printf("\n");
		System.out.printf(" LinkedList3.element()");
		System.out.printf("\n %s",linked3.element());
		
		System.out.printf("\n \n");
		linked1.offer(29);
		System.out.printf(" LinkedList1.offer(29);");
		linked1.printAll();
		

		System.out.printf("\n");
		linked1.poll();
		System.out.printf(" LinkedList1.poll();");
		linked1.printAll();
		
		System.out.printf("\n \n");
		System.out.printf(" LinkedList3.equals(LinkedList2)");
		System.out.printf("\n %s",linked3.equals(linked2));
		System.out.printf("\n LinkedList2.clear()");
		System.out.printf("\n LinkedList2.add(10)");
		System.out.printf("\n LinkedList2.add(11)");
		System.out.printf("\n LinkedList2.add(21)");
		linked2.clear();
		linked2.add(10);
		linked2.add(11);
		linked2.add(21);
		System.out.printf("\n LinkedList3.equals(LinkedList2)");
		System.out.printf("\n %s",linked3.equals(linked2));

		System.out.printf("\n \nLinkedList3.ToString()");	
		System.out.printf("\n%s",linked3);



	


	
		String[] array16=new String[5];
		array16[0]="Yusuf";
		array16[1]="Can";
		array16[2]="Kan";
		array16[3]="GTU";
		array16[4]="CSE241";


		String[] array17=new String[3];
		array17[0]="Can";
		array17[1]="Kan";
		array17[2]="CSE241";



		String[] array18=new String[3];
		array18[0]="OOP";
		array18[1]="JAVA";
		array18[2]="Iterator";

	/*LinkedList string test.*/
		System.out.println("\n-------------LinkedList<string>-------------");
		System.out.printf("\n");
		/*Constructor tests.*/
		LinkedList<String> linked4 = new LinkedList<String>();

		/*setInner method Test*/
		linked4.setInner(array16);
		
		LinkedList<String> linked5 = new LinkedList<String>(array17);
		LinkedList<String> linked6 = new LinkedList<String>(array18);

		System.out.printf(" LinkedList4 elements;");
		linked4.printAll();
		System.out.printf("LinkedList5 elements;");
		linked5.printAll();
		System.out.printf("LinkedList6 elements;");
		linked6.printAll();
		System.out.printf("\n");

		/*Iterator function test*/
		
		Iterator<String> iter8 = new Iterator<String>(array16,linked4);
		System.out.printf(" Iterator prints elements(LinkedList4)\n");
		while(iter8.hasNext()){
			System.out.printf(" %s ",iter8.getCurrent().toString() );
			iter8.next();
		}
		System.out.printf(" %s ",iter8.getCurrent());
		System.out.printf("\n \n");

		linked4.add("Java");
		System.out.printf(" LinkedList4.add('Java');");
		linked4.printAll();

		System.out.printf("\n");

		System.out.printf("LinkedList4.addAll(LinkedList6);");
		linked4.addAll(linked6);
		linked4.printAll();

		System.out.printf("\n");

		System.out.printf(" LinkedList6.clear();");
		System.out.printf("\n LinkedList6.add('Yusuf');");
		System.out.printf("\n LinkedList6.add('Can');");
		linked6.clear();
		linked6.add("Yusuf");
		linked6.add("Can");
		linked6.printAll();
		System.out.printf("\n");

		System.out.printf("LinkedList6.contains('Yusuf');");
		System.out.printf("\n %b",(linked6.contains("Yusuf")));
		System.out.printf("\n");

		System.out.printf("\n LinkedList4.containsAll(LinkedList5);");
		System.out.printf("\n %b",(linked4.containsAll(linked5)));
		System.out.printf("\n \n");

		System.out.printf(" LinkedList6.isEmpty();");
		System.out.printf("\n %b",linked6.isEmpty());
		System.out.printf("\n LinkedList6.clear();");
		linked6.clear();
		System.out.printf("\n LinkedList6.isEmpty();");
		System.out.printf("\n %b",linked6.isEmpty());
		linked6.add("Can");
		linked6.add("JAVA");
		System.out.printf("\n\n");

		System.out.printf(" LinkedList4.remove('Yusuf');");
		linked4.remove("Yusuf");
		linked4.printAll();
		System.out.printf(" LinkedList4.remove('CSE241');");
		linked4.remove("CSE241");
		linked4.printAll();
		System.out.printf(" LinkedList4.remove('Iterator');");
		linked4.remove("Iterator");
		linked4.printAll();
		System.out.printf("\n\n");

		System.out.printf(" LinkedList4 elements;");
		linked4.printAll();
		System.out.printf("LinkedList5 elements;");
		linked5.printAll();
		System.out.printf("LinkedList6 elements;");
		linked6.printAll();

		System.out.printf("\n");
		System.out.printf(" LinkedList4.removeAll(LinkedList6);");
		linked4.removeAll(linked6);
		linked4.printAll();

		System.out.printf("\n");
		System.out.printf(" LinkedList4.retainAll(LinkedList5);");
		linked4.retainAll(linked5);
		linked4.printAll();
		
		System.out.printf("\n");
		System.out.printf(" LinkedList5.size()");
		System.out.printf("\n %s",linked5.size());


		System.out.printf("\n \n");
		System.out.printf(" LinkedList6.element()");
		System.out.printf("\n %s",linked6.element());
		
		System.out.printf("\n \n");
		linked4.offer("Yusuff");
		System.out.printf(" LinkedList4.offer('Yusuf');");
		linked4.offer("GTU");
		System.out.printf(" LinkedList4.offer('GTU');");
		linked4.printAll();
		

		System.out.printf("\n");
		linked4.poll();
		System.out.printf(" LinkedList4.poll();");
		linked4.printAll();		


		
		System.out.printf("\n \n");
		System.out.printf(" LinkedList6.equals(LinkedList5)");
		System.out.printf("\n %s",linked6.equals(linked5));
		System.out.printf("\n LinkedList5.clear()");
		System.out.printf("\n LinkedList5.add('Can')");
		System.out.printf("\n LinkedList5.add('JAVA')");
		linked5.clear();
		linked5.add("Can");
		linked5.add("JAVA");
		System.out.printf("\n LinkedList6.equals(LinkedList5)");
		System.out.printf("\n %s",linked6.equals(linked5));
	

		System.out.printf("\n");
		System.out.println("\n-------------Iterator-------------");

		HashSet<Integer> hashset = new HashSet<Integer>(array1);
		Iterator<Integer> iter9 = new Iterator<Integer> (array1,hashset);
		
		System.out.printf("iter.next() - iter.hasNext() - iter.getCurrent()");
		System.out.printf("\n");
		while(iter9.hasNext()){
			System.out.printf(" %d ", iter9.getCurrent());
			iter9.next();
		}


		System.out.printf(" %d ", iter9.getCurrent());
		System.out.printf("\n\niter.remove()");
		iter9.remove();
		hashset.printAll();

		System.out.printf("\niter.ToString()");	
		System.out.printf("\n%s",iter9);
	
		System.out.printf("\n \nLinkedList6.ToString()");	
		System.out.printf("\n%s",linked6);

		System.out.printf("\n\niter.getCurrentSize()");
		System.out.printf("\n%d",iter9.getCurrentSize());
		
		System.out.printf("\n\niter.setCurrent(12)");
		iter9.setCurrent(12);

		System.out.printf("\n\niter.getCurrentSize()");
		System.out.printf("\n%d",iter9.getCurrentSize());

		System.out.printf("\n");
		System.out.println("\n-------------Exceptions-------------");

		hash1.clear();
		try{
			hash1.printAll();
		}catch(NullPointerException e){
			System.out.printf("\nEmpty HashSet");
		}

		list10.clear();
		try{
			list10.printAll();
		}catch(NullPointerException e){
			System.out.printf("\nEmpty ArrayList");
		}
		
		linked1.clear();
		try{
			linked1.printAll();
		}catch(NullPointerException e){
			System.out.printf("\nEmpty LinkedList");
		}
		System.out.printf("\n");

		linked2.clear();
		try{
			linked2.element();
		}
		catch(NullPointerException a){
			System.out.println("LinkedList is empty.");
		}

		try{
			linked2.poll();
		}catch(NullPointerException a){
			System.out.println("LinkedList is empty.");
		}
		try{
			iter9.next();
		}
		catch(ArrayIndexOutOfBoundsException e){
			iter9.setCurrent(iter9.getCurrentSize()-1);
			System.out.println("There is no next element.");
		}







	}
}




















