 /*
 * linkedlist.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
	friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) {
  value = val;
  next = NULL;
}

template <class T>
Link<T>::Link(T val, Link* nxt) {
  value = val;
  next = nxt;

}

template <class T>
Link<T>::Link(const Link<T> &source) {
  value = source.val;
  next = source.next;
}

template <class T>
class List {
public:
	List();
	List(const List<T>&) throw (OutOfMemory);
	~List();

	void addFirst(T) throw (OutOfMemory);
	void add(T) throw (OutOfMemory);
	T    getFirst() const throw (NoSuchElement);
	T    removeFirst() throw (NoSuchElement);
	int  length() const;
	T    get(int) const throw (IndexOutOfBounds, NoSuchElement);
	bool contains(T) const;
	bool empty() const;
	void clear();
	std::string toString() const;
	void operator= (const List&) throw (OutOfMemory);

	void addBefore(ListIterator<T>&, T) throw (IllegalAction, OutOfMemory);
	void addAfter(ListIterator<T>&, T) throw (IllegalAction, OutOfMemory);
	T    removeCurrent(ListIterator<T>&) throw (IllegalAction);

	bool set(int, T) throw (IndexOutOfBounds);
	int  indexOf(T) const;
	int  lastIndexOf(T) const;
	T    remove(int) throw (IndexOutOfBounds);
	bool removeFirstOcurrence(T);
	bool removeLastOcurrence(T);

private:
	Link<T> *head;
	int 	size;

	friend class ListIterator<T>;
};

template <class T>
List<T>::List(){
  head = NULL;
  size = 0;
}

template <class T>
List<T>::~List() {
  clear();
  head = NULL;
  size = 0;
}

/**
 * Regresa verdadero si la lista está vacía, 
 * de lo contrario regresa falso
 * @return true: si la lista está vacía
 * @return false: si la lista no está vacía
 */
template <class T>
bool List<T>::empty() const {
  if (head == NULL) {
    return true;
  } 
	return false;

  //Alternativa
  if (size == 0) {
    return true;
  }
  return false;
}

template <class T>
int List<T>::length() const {
  
  int i = 0;
  
  if(head == NULL) {
    return i;
  }

  Link<T> * apuntador = head;
  i++;

  while (apuntador->next != NULL) {
    apuntador = apuntador->next;
    i++;
  } 
  return i;

  //Alternativa
	return size;
}

template <class T>
bool List<T>::contains(T val) const {
	return false;
}

template <class T>
T List<T>::getFirst() const throw (NoSuchElement) {
	return 0;
}

template <class T>
void List<T>::addFirst(T val) throw (OutOfMemory) {
  //Crear nuevo nodo con el valor val
  Link<T> * nuevo = new Link<T>(val);

  if(nuevo == NULL) {
    throw OutOfMemory();
  }
  
  //Apuntar el siguiente del nuevo nodo a head
  nuevo->next = head;

  //head apuntarlo al nuevo nodo
  head = nuevo;

  //incrementar el tamaño
  size++;
}

template <class T>
void List<T>::add(T val) throw (OutOfMemory) {
  //Si la lista está vacía, agregar al principio
  if (empty()) {
    addFirst(val);
    return;
  }
  
  //Crear un nuevo nodo
  Link<T> * nuevo = new Link<T>(val);

  if(nuevo == NULL) {
    throw OutOfMemory();
  }

  //Crear un apuntador actual
  Link<T> * actual = head;

  //Recorrer la lista hasta llegar al final
  while (actual->next != NULL) {
    actual = actual->next;
  }

  //Apuntar actual al nuevo nodo
  actual->next = nuevo;

  //Aumentar el tamaño de la lista
  size++;
}

template <class T>
T List<T>::removeFirst() throw (NoSuchElement) {
	return 0;
}

template <class T>
T List<T>::get(int index) const throw (IndexOutOfBounds, NoSuchElement) {
	return 0;
}

template <class T>
void List<T>::clear() {
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
List<T>::List(const List<T> &source) throw (OutOfMemory) {
  
  head = NULL;
  size = 0;

  //Si la lista está vacía
  if(source.empty()) {
    return;
  }
  
  //Recorrer la lista source
  Link<T> * actual = source.head;

  //Por cada nodo que se visita, crear un nuevo nodo al final
  while(actual != NULL) {
    add(actual->value);
    actual = actual->next;
  }

}

template <class T>
void List<T>::operator=(const List<T> &source) throw (OutOfMemory) {
}

template <class T>
void List<T>::addBefore(ListIterator<T> &itr, T val) throw (IllegalAction, OutOfMemory) {
}

template <class T>
void List<T>::addAfter(ListIterator<T> &itr, T val) throw (IllegalAction, OutOfMemory) {
}

template <class T>
T List<T>::removeCurrent(ListIterator<T> &itr) throw (IllegalAction) {
	return 0;
}

template <class T>
bool List<T>::set(int index, T val) throw (IndexOutOfBounds) {
	return false;
}

template <class T>
int List<T>::indexOf(T val) const {
	return -1;
}

template <class T>
int List<T>::lastIndexOf(T val) const {
	return -1;
}

template <class T>
T List<T>::remove(int index) throw (IndexOutOfBounds) {
	return 0;
}

template <class T>
bool List<T>::removeFirstOcurrence(T val) {
	return false;
}

template <class T>
bool List<T>::removeLastOcurrence(T val) {
	return false;
}

template <class T>
class ListIterator {
public:
	ListIterator(List<T>*);
	ListIterator(const ListIterator<T>&);

	bool begin();
	bool end();
	T&   operator() () throw (NoSuchElement);
	bool operator++ ();
	void operator= (T) throw (NoSuchElement);

private:
	Link<T> *current;
	Link<T> *previous;
	List<T> *theList;

	friend class List<T>;
};

template <class T>
ListIterator<T>::ListIterator(List<T> *aList) : theList(aList) {
	begin();
}

template <class T>
ListIterator<T>::ListIterator(const ListIterator<T> &source) : theList(source.theList) {
	begin();
}

template <class T>
bool ListIterator<T>::begin() {
	previous = 0;
	current = theList->head;
	return (current != 0);
}

template <class T>
T& ListIterator<T>::operator() () throw (NoSuchElement) {
	if (current == 0) {
		throw NoSuchElement();
	}
	return current->value;
}

template <class T>
bool ListIterator<T>::end() {
	if (current == 0) {
		if (previous != 0) {
			current = previous->next;
		}
	}
	return (current == 0);
}

template <class T>
bool ListIterator<T>::operator++ () {
	if (current == 0) {
		if (previous == 0) {
			current = theList->head;
		} else {
			current = previous->next;
		}
	} else {
		previous = current;
		current = current->next;
	}
	return (current != 0);
}

template <class T>
void ListIterator<T>::operator= (T val) throw (NoSuchElement) {
	if (current == 0) {
		throw NoSuchElement();
	}
	current->value = val;
}

#endif /* LINKEDLIST_H_ */
