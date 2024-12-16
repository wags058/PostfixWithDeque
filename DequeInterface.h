/** @file DequeInterface.h
 * @class DequeInterface
 * Interface for classes of a deque that allow enqueueing and dequeueing elements from both the front and back of the deque.
 */

#ifndef DEQUE_INTERFACE_
#define DEQUE_INTERFACE_

template<class ItemType>
class DequeInterface
{
public:
    /** Sees whether this deque is empty.
     * @pre None
     * @post The deque is unchanged.
     * @return True if the deque is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the front of this deque.
     * @pre None
     * @post If the operation was successful, newEntry is at the front of the deque.
     * @param newEntry The item to be added as a new entry at the front.
     * @return True if the addition is successful or false if not. */
    virtual bool enqueueFront(const ItemType& newEntry) = 0;

    /** Adds a new entry to the back of this deque.
     * @pre None
     * @post If the operation was successful, newEntry is at the back of the deque.
     * @param newEntry The item to be added as a new entry at the back.
     * @return True if the addition is successful or false if not. */
    virtual bool enqueueBack(const ItemType& newEntry) = 0;

    /** Removes the front of this deque.
     * @pre The deque is not empty.
     * @post If the operation was successful, the front of the deque has been removed.
     * @return True if the removal is successful or false if not. */
    virtual bool dequeueFront() = 0;

    /** Removes the back of this deque.
     * @pre The deque is not empty.
     * @post If the operation was successful, the back of the deque has been removed.
     * @return True if the removal is successful or false if not. */
    virtual bool dequeueBack() = 0;

    /** Returns a copy of the front of this deque.
     * @pre The deque is not empty.
     * @post A copy of the front of the deque has been returned, and the deque is unchanged.
     * @return A copy of the front of the deque. */
    virtual ItemType peekFront() const = 0;

    /** Returns a copy of the back of this deque.
     * @pre The deque is not empty.
     * @post A copy of the back of the deque has been returned, and the deque is unchanged.
     * @return A copy of the back of the deque. */
    virtual ItemType peekBack() const = 0;

    /** Clears all entries in the deque.
     * @pre None
     * @post The deque is empty and all entries have been removed. */
    virtual void clear() = 0;

    /** Destroys this deque and frees its assigned memory.
     * @pre None
     * @post All memory associated with this deque has been released. */
    virtual ~DequeInterface() { }
};  // end DequeInterface

#endif