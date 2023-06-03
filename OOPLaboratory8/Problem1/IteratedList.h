#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART

#define NULL_TELEM -11111;

template<typename TElem>
struct Node {
	Node* next;
	Node* prev;
	TElem e;
};

template<typename TElem>
class IteratedList {
private:
	Node<TElem>* head;
	Node<TElem>* tail;
	int length;

	//DO NOT CHANGE THIS PART
	friend class ListIterator;
public:

	// constructor
	IteratedList<TElem>() {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		//make an empty iterated list
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	// returns the number of elements from the list
	int size() const {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		return length; //return the length of the list
	}

	// verifies if the list is empty
	bool isEmpty() const {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		return length == 0; //check if the list has length 0
	}

	// returns the first position from the list
	ListIterator first() const {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		return ListIterator(*this); //returns an iterator which points to the first node
	}

	// returns the element from the given position
	//throws an exception if the position is not valid
	TElem getElement(ListIterator pos) const {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		return pos.getCurrent(); //get the current element of the iterator
	}

	// changes the element from the current position to the given one.
	//returns the old value from the position
	//throws exception if the position is not valid
	TElem setElement(ListIterator pos, TElem e) {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		if (!pos.valid()) { //we check if the iterator is valid
			throw std::exception("Invalid iterator!");
		}

		//we remember the old value of the node
		Node<TElem>* current = pos.current;
		TElem oldElem = current->e;

		//we set the new value of the node
		current->e = e;

		return oldElem; //we return the old value of the node
	}

	// adds a new element to the end of the list
	void addToEnd(TElem e) {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		//we create a new node with the value e
		Node<TElem>* newNode = new Node<TElem>;
		newNode->e = e;

		if (head == nullptr) { //if the head is null we set it to be the new node and its previous node to be null
			head = newNode;
			newNode->prev = nullptr;
		}
		else { //else we add the element after the tail
			Node<TElem>* current = tail;
			current->next = newNode;
			newNode->prev = current;
		}
		tail = newNode; //we set the tail to be the new element
		newNode->next = nullptr; //we set the next node to be null
		length++; //we increase the length
	}
	
	//adds a new element to the beginning of the list
	void addToBeginning(TElem e) {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		//we create a new node with the value e
		Node<TElem>* newNode = new Node<TElem>;
		newNode->e = e;

		//we set the next node to be the head
		newNode->next = head;

		if (head != nullptr) { //if the head is not null we set its previous node to be the new node
			head->prev = newNode;
		}
		else {
			tail = newNode; //else we set the tail to be the new node
		}
		head = newNode; //we set the head to be the new node
		length++; //we increase the length
	}

	// // adds a new element after the current element from the iterator
	//after addition, pos points to the newly added element
	//throws an exception if pos is not valid
	void addToPosition(ListIterator& pos, TElem e) {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		if (!pos.valid()) { //we check if the iterator is valid
			throw std::exception("Invalid iterator!");
		}

		//we create a new node with the properties of the node we are currently at
		Node<TElem>* currentNode = pos.current;
		Node<TElem>* newNode = new Node<TElem>;
		newNode->e = e;
		newNode->prev = currentNode;
		newNode->next = currentNode->next;

		if (currentNode->next != nullptr) { //if the next node isn't null we set its previous node to be the new node
			currentNode->next->prev = newNode;
		}

		//we set the next element to be our new node
		currentNode<TElem>->next = newNode;

		if (tail == currentNode) { //if the current node was the tail we set the tail to be the new element
			tail = newNode;
		}

		length++; //we increase the length
		pos.current = pos.current->next; //we set the current node in the iterator to the new node
	}

	// removes the element from position pos
	//returns the removed element
	//after removal pos is positioned on the next element (the one after the removed one) or it is invalid if the last element was removed
	//throws an exception if pos is not valid
	TElem remove(ListIterator& pos) {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		if (!pos.valid()) { //check if the iterator is invalid
			throw std::exception("Invalid iterator!");
		}

		//create a node to remember the value from the removed node
		Node<TElem>* current = pos.current;
		TElem elem = current->e;

		if (current == head) { // if the removed node is the head we set the head to the next element
			head = current->next;
		}
		if (current == tail) {
			tail = current->prev; // if the removed node is the tail we set the tail to the previous element
		}

		if (current->prev != nullptr) { //if the previous node isn't null we set its next node to be the one after the removed node
			current->prev->next = current->next;
		}
		if (current->next != nullptr) { //if the next node isn't node we set its previous node to be the one before the removed node
			current->next->prev = current->prev;
		}

		pos.next(); //we go to the next position in the iterator
		length--; //we decrease the length
		return elem; //we return the value of the removed node
	}

	// searches for the first occurrance of an element 
	//returns an iterator that points to the element, if it appear in the list, or an invalid iterator if the element is not in the list
	ListIterator search(TElem e) const {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(n)
		// overall: O(n)

		ListIterator<TElem> it(*this); //we make a new iterator pointing to the first node
		while (it.valid()) { //we go through the list until we find the element we are searching for
			if (it.getCurrent() == e) {
				return it;
			}
			it.next();
		}
		return it;
	}

	//destructor

	~IteratedList() {
		//COMPLEXITIES
		// best case: 0(1)
		// worst case: 0(1)
		// overall: 0(1)

		head = nullptr; //we set the head to be null
	}
};
