/** @file LinkedDeque.h
 * @class LinkedDeque
 * Implements a deque. Provides functionality for adding, removing, and peeking at items from both the front and back. This implementation uses a circular doubly linked structure with a single pointer to the front.
 */

#ifndef LINKED_DEQUE_
#define LINKED_DEQUE_

#include "DequeInterface.h"
#include "Node.h"
#include <memory>

template<class ItemType>
class LinkedDeque : public DequeInterface<ItemType>
{
private:
    /** Pointer to the front of the deque. */
    std::shared_ptr<Node<ItemType>> frontPtr;

    /** Number of items currently in the deque. */
    int itemCount;

public:
    /** Default constructor initializes an empty deque.
     * @pre None
     * @post The deque is empty with frontPtr set to nullptr and itemCount set to 0. */
    LinkedDeque();

    /** Copy constructor creates a deep copy of another LinkedDeque.
     * @pre None
     * @post A new deque is created, with all nodes copied from the source deque.
     * @param otherDeque The LinkedDeque object to copy. */
    LinkedDeque(const LinkedDeque<ItemType>& originalDeque);

    /** Destructor clears the deque and frees memory.
     * @pre None
     * @post All nodes in the deque are released, and itemCount is set to 0. */
    virtual ~LinkedDeque();

    /** Checks if the deque is empty.
     * @pre None
     * @post The deque remains unchanged.
     * @return True if the deque is empty, false otherwise. */
    bool isEmpty() const noexcept override;

    /** Adds a new entry to the front of the deque.
     * @pre None
     * @post If the deque was empty, the new node points to itself. Otherwise, the new node is inserted before the current front node, and the circular links are updated.
     * @param newEntry The item to be added as a new entry at the front.
     * @return True if the addition is successful. */
    bool enqueueFront(const ItemType& newEntry) noexcept override;

    /** Adds a new entry to the back of the deque.
     * @pre None
     * @post If the deque was empty, the new node points to itself. Otherwise, the new node is inserted after the current back node, and the circular links are updated.
     * @param newEntry The item to be added as a new entry at the back.
     * @return True if the addition is successful. */
    bool enqueueBack(const ItemType& newEntry) noexcept override;

    /** Removes the front of the deque.
     * @pre The deque is not empty.
     * @post The front node is removed, and the circular links are updated.
     * @return True if the removal is successful.
     * @throw PrecondViolatedExcept if the deque is empty. */
    bool dequeueFront() override;

    /** Removes the back of the deque.
     * @pre The deque is not empty.
     * @post The back node is removed, and the circular links are updated.
     * @return True if the removal is successful.
     * @throw PrecondViolatedExcept if the deque is empty. */
    bool dequeueBack() override;

    /** Returns a copy of the front of the deque.
     * @pre The deque is not empty.
     * @post The deque remains unchanged.
     * @return A copy of the front item.
     * @throw PrecondViolatedExcept if the deque is empty. */
    ItemType peekFront() const override;

    /** Returns a copy of the back of the deque.
     * @pre The deque is not empty.
     * @post The deque remains unchanged.
     * @return A copy of the back item.
     * @throw PrecondViolatedExcept if the deque is empty. */
    ItemType peekBack() const override;

    /** Clears the deque.
     * @pre None
     * @post All nodes are removed, and the deque is empty. */
    void clear() noexcept override final;
};

#include "LinkedDeque.cpp"
#endif