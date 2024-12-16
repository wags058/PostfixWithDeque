/** @file LinkedDeque.cpp
 * @class LinkedDeque
 * Implements a deque using a circular doubly linked chain.
 * @author Stephen Wagner
 * @date 11/26/2024
 * CSCI 591 Section 1
 */

#include "LinkedDeque.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
LinkedDeque<ItemType>::LinkedDeque() : frontPtr(nullptr), itemCount(0)
{ } // end default constructor

template<class ItemType>
LinkedDeque<ItemType>::LinkedDeque(const LinkedDeque<ItemType>& originalDeque) : frontPtr(nullptr), itemCount(0)
{
    auto origChainPtr = originalDeque.frontPtr;  // Points to nodes in the original deque

    if (origChainPtr != nullptr)
    {
        // Copy the first node
        frontPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem());
        itemCount++;

        // Set up pointers for the circular doubly linked structure
        auto endChainPtr = frontPtr;  // Points to the last node in the new deque

        // Move to the next node in the original deque
        origChainPtr = origChainPtr->getNext();

        // Copy remaining nodes
        while (origChainPtr != originalDeque.frontPtr)
        {
            // Copy the next item from the original deque
            ItemType nextItem = origChainPtr->getItem();
            auto newNode = std::make_shared<Node<ItemType>>(nextItem);

            // Link the new node to the current chain
            newNode->setPrevious(endChainPtr);
            endChainPtr->setNext(newNode);

            // Move the end pointer to the new node
            endChainPtr = newNode;
            itemCount++;

            // Move to the next node in the original deque
            origChainPtr = origChainPtr->getNext();
        }

        // Complete the circular linking
        endChainPtr->setNext(frontPtr);
        frontPtr->setPrevious(endChainPtr);
    }
} // end copy constructor

template<class ItemType>
LinkedDeque<ItemType>::~LinkedDeque()
{
    clear();
} // end destructor

template<class ItemType>
bool LinkedDeque<ItemType>::isEmpty() const noexcept
{
    return itemCount == 0;
} // end isEmpty

template<class ItemType>
bool LinkedDeque<ItemType>::enqueueFront(const ItemType& newEntry) noexcept
{
    auto newNode = std::make_shared<Node<ItemType>>(newEntry);
    if (isEmpty())
    {
        // First node points to itself in a circular structure
        newNode->setNext(newNode);
        newNode->setPrevious(newNode);
        frontPtr = newNode;
    }
    else
    {
        auto backPtr = frontPtr->getPrevious(); // Get the last node
        newNode->setNext(frontPtr);
        newNode->setPrevious(backPtr);
        frontPtr->setPrevious(newNode);
        backPtr->setNext(newNode);
        frontPtr = newNode; // Update frontPtr to the new node
    }
    itemCount++;
    return true;
} // end enqueueFront

template<class ItemType>
bool LinkedDeque<ItemType>::enqueueBack(const ItemType& newEntry) noexcept
{
    auto newNode = std::make_shared<Node<ItemType>>(newEntry);
    if (isEmpty())
    {
        // First node points to itself in a circular structure
        newNode->setNext(newNode);
        newNode->setPrevious(newNode);
        frontPtr = newNode;
    }
    else
    {
        auto backPtr = frontPtr->getPrevious(); // Get the last node
        newNode->setNext(frontPtr);
        newNode->setPrevious(backPtr);
        backPtr->setNext(newNode);
        frontPtr->setPrevious(newNode);
    }
    itemCount++;
    return true;
} // end enqueueBack

template<class ItemType>
bool LinkedDeque<ItemType>::dequeueFront()
{
    if (isEmpty())
    {
        throw PrecondViolatedExcept("Attempted to remove from the front of an empty deque.");
    }
    else if (itemCount == 1)
    {
        frontPtr.reset(); // Only one node, clear it
    }
    else
    {
        auto backPtr = frontPtr->getPrevious(); // Get the last node
        frontPtr = frontPtr->getNext();         // Move frontPtr to the next node
        frontPtr->setPrevious(backPtr);
        backPtr->setNext(frontPtr);
    }
    itemCount--;
    return true;
} // end dequeueFront

template<class ItemType>
bool LinkedDeque<ItemType>::dequeueBack()
{
    if (isEmpty())
    {
        throw PrecondViolatedExcept("Attempted to remove from the back of an empty deque.");
    }
    else if (itemCount == 1)
    {
        // Only one node, clear it
        frontPtr.reset();
    }
    else
    {
        // Get the current last node (backPtr) and the new last node (newBackPtr)
        auto backPtr = frontPtr->getPrevious();
        auto newBackPtr = backPtr->getPrevious();
        newBackPtr->setNext(frontPtr);
        frontPtr->setPrevious(newBackPtr);
    }

    itemCount--;
    return true;
} // end dequeueBack

template<class ItemType>
ItemType LinkedDeque<ItemType>::peekFront() const
{
    if (isEmpty())
    {
        throw PrecondViolatedExcept("Attempted to peek at the front of an empty deque.");
    }
    return frontPtr->getItem();
} // end peekFront

template<class ItemType>
ItemType LinkedDeque<ItemType>::peekBack() const
{
    if (isEmpty())
    {
        throw PrecondViolatedExcept("Attempted to peek at the back of an empty deque.");
    }
    auto backPtr = frontPtr->getPrevious();
    return backPtr->getItem(); // Get item from last node
} // end peekBack

template<class ItemType>
void LinkedDeque<ItemType>::clear() noexcept
{
    frontPtr.reset(); // Clear all nodes by releasing front pointer
    itemCount = 0;
} // end clear