#include <vector>
#include <memory>
#include "Node.hpp"

#pragma once


using namespace std;

template<class ItemType>
class SortedDoublyLinkedList {
    //DO NOT MODIFY THIS CLASS DECLARATION. FIND T-O-D-O-S to work on.
private:
    std::shared_ptr<Node<ItemType>> head;
    std::shared_ptr<Node<ItemType>> tail;
    int size;
public:

    SortedDoublyLinkedList();

    SortedDoublyLinkedList(std::shared_ptr<Node<ItemType>> head, std::weak_ptr<Node<ItemType>> tail, int size);

    SortedDoublyLinkedList(const SortedDoublyLinkedList<ItemType> &list);    // Copy constructor

    std::shared_ptr<Node<ItemType>> getPointerTo(const ItemType &target) const;

    virtual ~ SortedDoublyLinkedList();    // Destructor should be virtual

    int getCurrentSize() const;

    bool isEmpty() const;

    bool add(const ItemType &newEntry);

    bool remove(const ItemType &anEntry);

    bool contains(const ItemType &anEntry) const;

    int getFrequencyOf(const ItemType &anEntry) const;

    vector<ItemType> toVector() const;

};

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList() : head(nullptr), tail(),
                                                             size(0) {}

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList(std::shared_ptr<Node<ItemType>> head,
                                                         std::weak_ptr<Node<ItemType>> tail, int size) :
        head(head), tail(tail), size(size) {}

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList(const SortedDoublyLinkedList<ItemType> &list) {

    if(list.head == NULL) {
        head = NULL;
        tail = NULL;
    } else{
        std::shared_ptr<Node<ItemType>> walk = list.head;

        std::shared_ptr<Node<ItemType>> head;
        std::shared_ptr<Node<ItemType>> current;
        head->data=list.head->data;
        head->getPrev()=NULL;

        std::shared_ptr<Node<ItemType>> nextNode = walk->getNext();


        while(nextNode != NULL ){
            std::shared_ptr<Node<ItemType>> newNode;
            nextNode->data=newNode->data;
            newNode->getPrev()=current;
            newNode->getNext()=NULL;
            nextNode = nextNode->getNext();
            current->getNext()=newNode;
            current=current->getNext();
        }

    }
    //TODO - Implement the copy constructor
}

template<class ItemType>
std::shared_ptr<Node<ItemType>> SortedDoublyLinkedList<ItemType>::getPointerTo(const ItemType &target) const {
    Node<ItemType> current = *head;

    if (head == NULL) {
        return nullptr;
    } else {
        while (current != NULL) {
            if (current.getItem() == target) {
                return &current;
            } else {
                current = current.getNext();
            }
        }

        return nullptr;
    }
    //TODO - Return the Node pointer that contains the target(return nullptr if not found)
}

template<class ItemType>
SortedDoublyLinkedList<ItemType>::~SortedDoublyLinkedList() {
    // Node<ItemType> current = head;
    std::shared_ptr<Node<ItemType>> *can = new std::shared_ptr<Node<ItemType>>();
    std::shared_ptr<Node<ItemType>> walk = head;
    std::shared_ptr<Node<ItemType>> nextNode = walk->getNext();

    while(walk != NULL && nextNode != NULL){
        delete walk;
        walk = nextNode;
        nextNode = nextNode->getNext();

    }
    delete walk;
    //TODO - Implement the destructor
}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getCurrentSize() const {
    int count = 0;

    while (head != NULL) {
        head = head->getNext();
        count++;
    }
    return count;
    //TODO - Return the current size
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::isEmpty() const {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
    //TODO - Return True if the list is empty
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::add(const ItemType &newEntry) {

    // create node that contains newEntry
    if (head == NULL) {
        head->getNext()=newEntry;
        newEntry->prev = NULL;
        newEntry->next = NULL;
    } else {
        if (head != NULL) {
            newEntry->next = head;
            head-> getPrev()=newEntry;
            head=newEntry;
            newEntry->prev = NULL;
        }
        // heads next should be newEntry node
    }
    //TODO - Add an item to the sorted Doubly Linked list
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::remove(const ItemType &anEntry) {

    std::shared_ptr<Node<ItemType>> current = head;


    if (current == NULL) {
        return false;
    } else {
        while (current != NULL) {
            if (current == anEntry) {
                delete current;
                return true;
            }
            current = current->getNext();
        }
        return false;
    }
    //TODO - Remove the Item(anEntry) from the list - Return true if successful
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::contains(const ItemType &anEntry) const {
    shared_ptr<Node<ItemType>> current = head;

    while (current != NULL) {
        if (current == anEntry) {
            return true;
        } else {
            current = current->getNext();
        }
    }

    return false;
    //TODO - Check if the List contains the Item(anEntry)- Return true if successful
}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    int count = 0;
    shared_ptr<Node<ItemType>>current = head;

    while (current != NULL) {
        if (current == anEntry) {
            count++;
        }
        current = head->getNext();
    }
    return count;
    //TODO - Return the frequency of the Item(anEntry) in the list
}

template<class ItemType>
vector<ItemType> SortedDoublyLinkedList<ItemType>::toVector() const {
    // DO NOT MODIFY THIS FUNCTION
    vector<ItemType> myVector;
    std::shared_ptr<Node<ItemType>> cur;
    cur = this->head;
    while (cur != nullptr) {
        myVector.push_back(cur->getItem());
        cur = cur->getNext();
    }
    return myVector;
}
