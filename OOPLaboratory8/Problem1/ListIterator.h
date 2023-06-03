#pragma once
#include "IteratedList.h"

//DO NOT CHANGE THIS PART

template<typename TElem>
class IteratedList;

template<typename TElem>
class ListIterator{
	friend class IteratedList<TElem>;
private:
	Node<TElem>* current;

	//DO NOT CHANGE THIS PART
	const IteratedList<TElem>& list;
	template<typename TElem>
	ListIterator(const IteratedList<TElem>& lista) {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		current = list.head; //set the current node to the first node
	}
public:
	void first() {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		current = list.head; //set the current node to the first node
	}
	void next();
	bool valid() const;
    TElem getCurrent() const;

};


