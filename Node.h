/** @file Node.h
 * @class Node
 * Implements a node to hold an item and smart pointers for both next and previous nodes. 
 */

#ifndef NODE_
#define NODE_

#include <memory>

template<class ItemType>
class Node
{
private:
    /** A data item stored in the node. */
    ItemType item;

    /** A shared pointer to the next node in the list. */
    std::shared_ptr<Node<ItemType>> next;

    /** A weak pointer to the previous node in the list. */
    std::weak_ptr<Node<ItemType>> previous;

public:
    /** Default constructor that initializes an empty node. */
    Node();

    /** Constructs a node with a given item and no links to next or previous nodes.
     * @param anItem The item to store in the node. */
    Node(const ItemType& anItem);

    /** Constructs a node with a given item and links to next and previous nodes.
     * @param anItem The item to store in the node.
     * @param nextNodePtr A shared pointer to the next node.
     * @param previousNodePtr A weak pointer to the previous node. */
    Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr, std::weak_ptr<Node<ItemType>> previousNodePtr);

    /** Sets the item stored in the node.
     * @pre None
     * @post Item is stored in the node.
     * @param anItem The item to store in the node. */
    void setItem(const ItemType& anItem) noexcept;

    /** Sets the link to the next node in the list.
     * @pre None
     * @post Shared pointer is stored in the node.
     * @param nextNodePtr A shared pointer to the next node. */
    void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) noexcept;

    /** Sets the link to the previous node in the list.
     * @pre None
     * @post Weak pointer is stored in the node.
     * @param previousNodePtr A weak pointer to the previous node. */
    void setPrevious(std::weak_ptr<Node<ItemType>> previousNodePtr) noexcept;

    /** Retrieves the item stored in the node.
     * @pre None
     * @post The node is unchanged.
     * @return The item stored in the node. */
    ItemType getItem() const noexcept;

    /** Retrieves the next node in the list.
     * @pre None
     * @post The node is unchanged.
     * @return A pointer to the next node in the list. */
    auto getNext() const noexcept;

    /** Retrieves the previous node in the list.
     * @pre None
     * @post The node is unchanged.
     * @return A pointer to the previous node in the list. */
    auto getPrevious() const noexcept;

};

#include "Node.cpp"
#endif