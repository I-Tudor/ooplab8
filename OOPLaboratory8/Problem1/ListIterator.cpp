#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>



void ListIterator<TElem>::next() {
	//COMPLEXITIES
	// best case: 0(1)
	// worst case: 0(1)
	// overall: 0(1)

	if (!valid()) { //check if valid
		throw std::exception("Invalid iterator!");
	}

	current = current->next; //go to the next element in the iterator
}

bool ListIterator<TElem>::valid() const {
	//COMPLEXITIES
	// best case: 0(1)
	// worst case: 0(1)
	// overall: 0(1)

	return  current != nullptr; //return if the current node is not null
}

TElem ListIterator<TElem>::getCurrent() const {
	//COMPLEXITIES
	// best case: 0(1)
	// worst case: 0(1)
	// overall: 0(1)

	if (!valid()) { //check if valid
		throw std::exception("Invalid iterator!");
	}

	return current->e; //return the current value
}



