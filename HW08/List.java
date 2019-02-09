
/**
 *List interface is the child interface of Collection.
 *It includes all the necessary basic methods for a simple list.
 *@author Yusuf Can
*/

public interface List<E> extends Collection<E>{

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


}
