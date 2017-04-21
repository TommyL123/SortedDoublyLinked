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
                                                             size(0) { }

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList(std::shared_ptr<Node<ItemType>> head, std::weak_ptr<Node<ItemType>> tail, int size) :
        head(head), tail(tail), size(size) { }

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList(const SortedDoublyLinkedList<ItemType> &list) {
    
    
    
    this->head = nullptr;
    this->tail = nullptr;

    if (list.head == nullptr)
    {
        return;
    }
    else
    {
        vector<int> vecList = list.toVector();
        for (auto a:vecList) {
            this->add(a);
        }
    }
}

template<class ItemType>
std::shared_ptr<Node<ItemType>> SortedDoublyLinkedList<ItemType>::getPointerTo(const ItemType &target) const {
   


    if(!this->contains(target)){
        return nullptr;
    }
    else
    {
        std::shared_ptr<Node<ItemType>> current = head;
        while (current->getItem() != target) {
            current = current->getNext();
        }
        return current;
    }



}

template<class ItemType>
SortedDoublyLinkedList<ItemType>::~SortedDoublyLinkedList() {
    
    this->head = nullptr;
}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getCurrentSize() const {
    
    int count = 0;

    std::shared_ptr<Node<ItemType>> curr = head;

    while (curr != nullptr) {
        curr = curr->getNext();
        count++;
    }
    return count;
    
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::isEmpty() const {
   
    if (this->head == nullptr) {
        return true;
    } else {
        return false;
    }
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::add(const ItemType &newEntry) {

    std::shared_ptr<Node<ItemType>> newNode = std::make_shared<Node<ItemType>>(newEntry);
    std::shared_ptr<Node<ItemType>> curr = head;
    std::shared_ptr<Node<ItemType>> prev;

    if (this->head == nullptr)
    {
        head = tail = newNode;
    }

    else
    {

        while (curr != nullptr && curr->getItem() <= newEntry)
        {
            prev = curr;
            curr = curr->getNext();
        }

        if (curr == nullptr) {
            newNode->setPrev(tail);
            tail->setNext(newNode);
            tail = newNode;
        }

        else if (curr == head)
        {
            newNode->setNext(head);
            head->setPrev(newNode);
            head = newNode;

        }

        else
        {
            newNode->setNext(curr);
            newNode->setPrev(prev);
            prev->setNext(newNode);
            curr->setPrev(newNode);
        }
    }

    size++;

    return true;


}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::remove(const ItemType &anEntry) {

    std::shared_ptr<Node<ItemType>> curr = head;
    std::shared_ptr<Node<ItemType>> prev;



    if(!this->contains(anEntry))
    {
        return false;
    }
    else
    {
        while (curr->getItem() != anEntry)
        {
            prev = curr;
            curr = curr->getNext();
        }

        if (curr == head)
        {
            head = curr->getNext();
            curr = nullptr;
            size--;
            return true;
        }

        if (curr != tail)
        {
            curr->getNext()->setPrev(curr->getPrev());
        }

        prev->setNext(curr->getNext());
        if(curr == tail)
        {
            tail = prev;
        }
        curr = nullptr;
    }
    size--;

    return true;
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::contains(const ItemType &anEntry) const {

    shared_ptr<Node<ItemType>> current = head;

    while (current != nullptr)
    {
        if (current->getItem() == anEntry)
        {
            return true;
            
        } else {
            current = current->getNext();
        }
    }

    return false;
}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    
    int count = 0;
    
    shared_ptr<Node<ItemType>> curr = head;

    while (curr != nullptr) {
        
        if (curr->getItem() == anEntry) {
            
            count++;
        }
        curr = curr->getNext();
    }
    return count;
}

template<class ItemType>
vector<ItemType> SortedDoublyLinkedList<ItemType>::toVector() const {
    // DO NOT MODIFY THIS FUNCTION
    vector <ItemType> myVector;
    std::shared_ptr<Node<ItemType>> cur;
    cur = this->head;
    while (cur != nullptr) {
        myVector.push_back(cur->getItem());
        cur = cur->getNext();
    }
    return myVector;
}



