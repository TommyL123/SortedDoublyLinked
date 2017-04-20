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


    if (list.isEmpty())
    {
        return;
    }

    auto cur = list.head;

    while(cur)
    {
        this->add(cur.get()->getItem() );
        cur = cur.get()->getNext();
    }

    }

    //TODO - Implement the copy constructor



template<class ItemType>
std::shared_ptr<Node<ItemType>> SortedDoublyLinkedList<ItemType>::getPointerTo(const ItemType &target) const {
    Node<ItemType> current = *head;

    auto cur = this->head;
    while (cur != nullptr && cur.get()->getItem()!= target)
        cur = cur.get()->getNext();
    return cur;

    //TODO - Return the Node pointer that contains the target(return nullptr if not found)
}
// 7828, 8199, 2238, 4947, 2244, 3691


template<class ItemType>
SortedDoublyLinkedList<ItemType>::~SortedDoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;

    //TODO - Implement the destructor
}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getCurrentSize() const {


    return size;

    //TODO - Return the current size
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::isEmpty() const {
    if (this->head == nullptr) {
        return true;
    } else {
        return false;
     }
    //TODO - Return True if the list is empty
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::add(const ItemType &newEntry) {

    if( newEntry != NULL)
    {
        auto cur = std::make_shared<Node<ItemType >>(newEntry);

        if(!(this->isEmpty()))
        {
            auto curPtr = head;
            auto curnext = head.get()->getNext();
            auto curprev = head.get()->getPrev();
            while (curPtr != nullptr && curPtr.get()->getItem() < newEntry )
            {
                curprev = curPtr;
                curPtr = curPtr.get()->getNext();
            }

            cur.get()->setNext(curPtr);
            cur.get()->setPrev(curprev);
            if(curprev.lock().get() != nullptr)
                curprev.lock().get()->setNext( cur);
            if(curPtr != nullptr)
                curPtr.get()->setPrev(cur);

            if(curPtr == head )
                head = cur;
            if(curPtr == nullptr)
                tail = cur;

        }
        else
        {
            head = tail = cur;
        }

        size++;
        return true;

    }
    return false;

    //TODO - Add an item to the sorted Doubly Linked list
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::remove(const ItemType &anEntry) {

    bool found=false;
    if(this->isEmpty())
        return found;
    auto cur = this->head;
    if(cur.get()->getItem()== anEntry)
    {
        head = head.get()->getNext();
        size--;
        if(size==0)
        {
            head=tail= nullptr;
        }
        return true;
    }
    auto aprev= cur;
    cur=cur.get()->getNext();
    while(!found && cur)
    {
        if (cur.get()->getItem() == anEntry)
            found = true;
        else
        {
            aprev=cur;
            cur=cur.get()->getNext();
        }
    }
    if(found)
    {
        aprev.get()->setNext(cur.get() ->getNext());
        size--;
    }
    if(cur == tail)
        tail = aprev;

    return found;

    //TODO - Remove the Item(anEntry) from the list - Return true if successful
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::contains(const ItemType &anEntry) const {


    auto cur = this->head;
    while (cur != nullptr && cur.get()->getItem()!= anEntry)
        cur = cur.get()->getNext();
    return cur == nullptr?false: true;

    //TODO - Check if the List contains the Item(anEntry)- Return true if successful
}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getFrequencyOf(const ItemType &anEntry) const {

    int counter =0;
    auto cur = this->head;
    while (cur != nullptr)
    {
        if (cur.get()->getItem() == anEntry)
            counter ++;
        cur = cur.get()->getNext();
    }
    return counter;

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
