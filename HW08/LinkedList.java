
/**
*A simple class that implements Queue and List.
*@author Yusuf Can
*/

public class LinkedList<E> implements Queue<E>,List<E>{

	private E[] inner;	

	/**
	*Constructor that creates inner array with size 20.
	*/
	@SuppressWarnings("unchecked")
	public LinkedList(){		
		inner=(E[])new Object[20];	
 	}
	
	/**
	*Constructor that takes array.
	*@param c the array which is going to be holded.
	*/
	@SuppressWarnings("unchecked")
	public LinkedList(E[] c){
		inner=(E[])new Object[c.length];
		for(int i=0;i<c.length;i++)
			inner[i]=c[i];	
	}
	
	/**
	*Setter method for inner array.
	*@param inner_ inner array
	*/
	public void setInner(E[] inner_){
		inner = inner_;
	}
	
	@Override
	public Iterator<E> iterator(){
		Iterator<E> iter = new Iterator<E>(inner,this);
		return iter;
	}
	
	@Override
	@SuppressWarnings("unchecked")
	public void add(E e){ 
		if(inner==null){
			inner = (E[])new Object[1];
			inner[0]=e;
		}
		else{
			int size = inner.length;
			E[] temp = (E[])new Object[size+1];
			for(int i=0;i<size;i++){
				temp[i]=inner[i];
			}
			temp[size] = e;
			inner = temp;
		}
	}

	@Override
	public void addAll(Collection<E> c){ 
		Iterator<E> iter = c.iterator();
		while(iter.hasNext()){
			this.add(iter.getCurrent());
			iter.next();
		}
		this.add(iter.getCurrent());
	}

	@Override
	public void clear(){
		inner = null;
	 }

	@Override
	public boolean contains(E e){ 
		Iterator<E> iter = this.iterator();
		int size=inner.length;
	
		while(iter.hasNext()){
			if( e.equals(iter.getCurrent()))	return true;
			iter.next();
		}
		if( e.equals(iter.getCurrent()))	return true;

		return false;
	}

	@Override
	public boolean containsAll(Collection<E> c){ 
		Iterator<E> iter = c.iterator();
		int how_many=0;
		while(iter.hasNext()){
			if(this.contains(iter.getCurrent())){
				how_many++;
			}
			iter.next();
		}
		if(this.contains(iter.getCurrent())) how_many++;
		
		if(how_many==c.size())	return true;
		else	return false;
	}

	@Override
	public boolean isEmpty(){ 
		if(inner == null)	return true;
		else	return false;	
	}

	@Override
	public void remove(E e){
		Iterator<E> iter = this.iterator();
		while(iter.hasNext()){
			if(e.equals(iter.getCurrent())) iter.remove();
			iter.next();
		}
		if(e == iter.getCurrent()) iter.remove();
	}

	@Override
	public void removeAll(Collection<E> c){ 
		Iterator<E> iter = c.iterator();

		while(iter.hasNext()){
			this.remove(iter.getCurrent());
			iter.next();
		}
		this.remove(iter.getCurrent());
	}

	@Override
	public void retainAll(Collection<E> c){
		Iterator<E> iter = this.iterator();
		int flag=0;

		while(iter.hasNext()){
			if( !(c.contains(iter.getCurrent())) ) {
				iter.remove();
				flag=1;
			}
			if(flag==0)
				iter.next();
			flag=0;
		}

		if( !(c.contains(iter.getCurrent())) ) {
			iter.remove();
		}
		
	}

	@Override
	public int size(){ 
		if(inner==null)	return 0;
		else	return inner.length;
	}
	
	/**
	*Prints all elements which contained that collection.
	*@throws NullPointerException if LinkedList is empty.
	*/
	public void printAll()throws NullPointerException{
		
			int size = inner.length;
			System.out.printf(" \n ");
			for(int i=0;i<size;i++){
				System.out.printf(" %s ",inner[i]);
			}
			System.out.printf(" \n ");
	}

	@Override
	@SuppressWarnings("unchecked")
	public E element() throws NullPointerException{
			return inner[0];
	}

	public void offer(E e){
		this.add(e);
	}

	@Override
	@SuppressWarnings("unchecked")
	public E poll() throws NullPointerException{
			E temp;
			temp = inner[0];
			this.remove(inner[0]);
			return temp;
	}

	@Override
    public String toString(){
		StringBuilder str = new StringBuilder();
		Iterator<E> iter = this.iterator();

      	while(iter.hasNext()) {
    		str.append(iter.getCurrent());
        	str.append(" ");
         	iter.next();
         }
		 str.append(iter.getCurrent());
		 str.append("\n");
		 String string = str.toString();
         return string;
	}
}
























