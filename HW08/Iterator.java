import java.lang.ArrayIndexOutOfBoundsException;
import java.lang.NullPointerException;


/**
 * Simple Iterator generic class.
 * This class provides the facility of iterating 
 * the elements in a forward direction only.
 * @author Yusuf Can
 */

public class Iterator<E>{

	 /**
     * The array of all elements in the Collection object.
     */
	private E[] data;

	/**
	*Current limit of elements.
	*/
	private int size;

	/**
	*Current value.
	*/
	private int current;

	/**
	*Collection object which iterated.
	*/
	private Collection obj;
	
	/**
	*Constructor that creates inner array and
	*sets size 20, current 0.
	*/
	@SuppressWarnings("unchecked")
	public Iterator(){
		obj=null;
		data=(E[])new Object[20];
		size=20;
		current = 0;
	}

	/**
	*Constructor that takes array and
	*sets current 0, collection reference is null.
	*@param c the array which holded by collection object.
	*/
	public Iterator(E[] c){
		obj=null;
		data=c;
		size = c.length;
		current=0;
	}

	/**
	*Constructor that takes array and collection object
	*sets current 0.
	*@param c the array which holded by collection object.
	*@param obj_ the collection object which wants to iterated.
	*/
	public Iterator(E[] c,Collection obj_){
		obj=obj_;
		data=c;
		size = c.length;	
		current=0;
	}
	
	/**
	*Looks iterator has next element.
	*@return true if it has next element.
	*/
	public boolean hasNext(){
		if(current < size-1) return true;
		else return false;
	}

	/**
	*Returns the value of the next element,
    *and pushes iterator to the next address.
	*@return next element.
	*@throws NullPointerException if collection is empty.
	*@throws ArrayIndexOutOfBoundsException if there is no next element.
	*/
	public E next()
		throws ArrayIndexOutOfBoundsException{
			current++;
			return data[current];
	}

	/**
	*Removes from the underlying collection the last 
	*element returned by this iterator
	*/
	@SuppressWarnings("unchecked")
	public void remove(){
		
		int index_count=0;
		E[] temp = (E[])new Object[size-1];

		for(int i=0;i<size;i++){
			if(i!=current){
				temp[index_count] = data[i];
				index_count++;
			}
		}
		int current_temp = current;
		data=temp;
		current=current_temp;
		size--;

	/*Downcasting*/
		if(obj instanceof HashSet){
			((HashSet)obj).setInner(data);
		}
		if(obj instanceof ArrayList){
			((ArrayList)obj).setInner(data);
		}
		if(obj instanceof LinkedList){
			((LinkedList)obj).setInner(data);
		}
		
		if(current == size){
			current--;
		}
	}
	
	/*
	*getter method for current element.
	*@return current element.
	**/
	public E getCurrent(){
		return data[current];
	}

	public void setCurrent(int current_){
		current = current_;
	}

	public int getCurrentSize(){
		return current;
	}

	public String toString(){
		return String.format("Current Element = %s", this.getCurrent());
	}











	
}














