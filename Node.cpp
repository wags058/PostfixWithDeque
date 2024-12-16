/** @file Node.cpp
 * Node class implements a node to hold an item and smart pointers to the next and previous nodes.
 * @author Stephen Wagner
 * @date 11/26/2024
 * CSCI 591 Section 1
 */

#include "Node.h"

template<class ItemType>
Node<ItemType>::Node()
{ } // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{ } // end parameterized constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr, 
    std::weak_ptr<Node<ItemType>> previousNodePtr) : item(anItem), next(nextNodePtr), 
    previous(previousNodePtr)
{ } // end parameterized constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) noexcept
{
    item = anItem;
}  // end setItem

template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) noexcept
{
    next = nextNodePtr;
}  // end setNext

template<class ItemType>
void Node<ItemType>::setPrevious(std::weak_ptr<Node<ItemType>> previousNodePtr) noexcept
{
    previous = previousNodePtr;
}  // end setPrevious

template<class ItemType>
ItemType Node<ItemType>::getItem() const noexcept
{
    return item;
}  // end getItem

template<class ItemType>
auto Node<ItemType>::getNext() const noexcept
{
    return next;
}  // end getNext

template<class ItemType>
auto Node<ItemType>::getPrevious() const noexcept
{
    // Return a pointer converted to shared
    return previous.lock();
}  // end getPrevious