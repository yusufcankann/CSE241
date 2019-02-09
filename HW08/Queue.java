
/**
 *Queue interface is the child interface of Collection.
 *It includes all the necessary basic methods for a simple queue.
 *@author Yusuf Can
*/


public interface Queue<E> extends Collection<E>{

	public Iterator<E> iterator();
	public void add(E e);
	public void addAll(Collection<E> c);
	public void clear();
	public boolean contains(E e);
	public boolean containsAll(Collection<E> c);
	public boolean isEmpty();
	public void remove(E e);
	public void removeAll(Collection<E> c);
	public void retainAll(Collection<E> c);
	public int size();

	/**
	*Retrieves, but does not remove, the head of this queue.
	*@return the head of queue.
	*@throws NullPointerException if this queue is empty.
	*/
	public E element()throws NullPointerException;
	
	/**
	*Inserts the specified element into this queue.
	*@param e is the object that trying to be inserted.
	*/
	public void offer(E e);

	/**
	*Retrieves and removes the head of this queue.
	*@return head of the queue.
	*@throws NullPointerException if this queue is empty.
	*/
	public E poll() throws NullPointerException;

}
