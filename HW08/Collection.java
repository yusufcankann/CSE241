

/**
 * The Collection interface is the interface which is 
 * implemented by all the classes in the collection framework.
 * @author Yusuf Can
*/

public interface Collection<E>{

	/**
	*Creates an iterator for the collection object.
	*@return an iterator class.
	*/
	public Iterator<E> iterator();

	/**
	*Ensures that this collection contains 
	*the specified element.
    *@param e the object that trying to be added.
	*/
	public void add(E e);
	
	/**
	*Adds all of the elements in the 
	*specified collection to this collection.
	*@param c the collection that trying to be added.
	*/
	public void addAll(Collection<E> c);

	/**
	*Removes all of the elements from this collection.
	*/
	public void clear();

	/**
	*@return true if this collection contains the specified element.
	*@param e the object that is looking for.
	*/
	public boolean contains(E e);

	/**
	*@return true if this collection contains all of the elements in the specified collection.
	*@param c the the collection which is looking for.
	*/
	public boolean containsAll(Collection<E> c);
	
	/**
	*Controls the collection is empty or not.
	*@return true if this collection contains no elements.
	*/
	public boolean isEmpty();
	
	/**
	*Removes a single instance of the specified element
	*from this collection, if it is present.
	*@param e the object that trying to be deleted.
	*/
	public void remove(E e);

	/**
	*Removes all of this collection's elements that are 
	*also contained in the specified collection.
	*@param c the collection that trying to be deleted.
	*/
	public void removeAll(Collection<E> c);
	
	/**
	*Retains only the elements in this collection 
	*that are contained in the specified collection
	*@param c the collection that trying to be retained.
	*/
	public void retainAll(Collection<E> c);

	/**
	*Gets the number of elements in this collection.
	*@return the number of elements in this collection.
	*/
	public int size();

}
