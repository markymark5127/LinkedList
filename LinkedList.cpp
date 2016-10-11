//
//  LinkedList.cpp
//

#include "LinkedList.h"
#include "Flags.h"

/* **************************************************************** */
using namespace std;
#if CONSTRUCTOR || ALL
// Constructor
template <class T>
LinkedList<T>::LinkedList()
{
    // TODO: Allocate dummy node
    dummy = new Node<T>();
    dummy->data = 0;
    dummy->next=dummy;
    dummy->prev=dummy;

}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
// Destructor
template <class T>
LinkedList<T>::~LinkedList()
{
    // TODO: Remove any nodes
    makeEmpty();
    // TODO: Free dummy node
    delete dummy;
    dummy=NULL;
}
#endif

/* **************************************************************** */

#if ALL || GETFIRST
// TODO: getFirst
template <class T>
const T& LinkedList<T>::getFirst() const
{
    return dummy->next->data;
}
#endif

/* **************************************************************** */

#if ALL || GETLAST
template <class T>
const T& LinkedList<T>::getLast() const
{
    return dummy->prev->data;
}
// TODO: getLast
#endif

/* **************************************************************** */

#if ALL || FIND
// TODO: find
template <class T>
bool LinkedList<T>::find(const T &x) const
{
    bool found = 0;

    if(!isEmpty())
    {
        Node<T> *p = dummy->next;

        while (p != dummy)
        {
            if(p->data == x)
            {
                found = 1;
            }
            p = p->next;
        }
        p=NULL;
        delete p;
    }
    return found;
}
#endif

/* **************************************************************** */

#if ALL || FINDNODE
// TODO: findNode
template <class T>
Node<T>*LinkedList<T>::findNode(const T &x) const
{

    Node<T> *node = dummy->next;
    while (node != dummy and node->data != x)
          node = node->next;
   return node;
}
#endif

/* **************************************************************** */

#if ALL || INSERT
// TODO: insert
template <class T>
void LinkedList<T>::insert(const T &x)
{

    Node<T> *node=new Node<T>();
    node->data=x;
    if (isEmpty())
    {
        dummy->next = node;
        dummy->prev = node;
        node->next = dummy;
        node->prev = dummy;
    }
    else
    {
        node->next = dummy->next;
        node->prev = dummy;
        dummy->next->prev = node;
        dummy->next = node;

    }
    node=NULL;
    delete node;
}
#endif

/* **************************************************************** */

#if ALL || REMOVE
// TODO: remove
template <class T>
void LinkedList<T>::remove(const T &x)
{
    Node<T> *found = new Node<T>();
    found = findNode(x);
    if(found != dummy)
    {
        found->prev->next = found->next;
        found->next->prev = found->prev;
    }
    found=NULL;
    delete found;
}
#endif

/* **************************************************************** */

#if ALL || ISEMPTY
// TODO: isEmpty
template <class T>
bool LinkedList<T>::isEmpty() const
{
    bool empty;
    if(dummy->next==dummy && dummy->prev == dummy)
    {
        empty = 1;
    }
    else
    {
        empty = 0;
    }
    return empty;
}
#endif

/* **************************************************************** */

#if ALL || MAKEEMPTY
// TODO: makeEmpty
template <class T>
void LinkedList<T>::makeEmpty()
{
    dummy->next = dummy;
    dummy->prev = dummy;
    Node<T> *q = NULL;
    Node<T> *p = dummy->next;
    while (p != dummy)
    {
        q = p;
        p = p->next;
        delete q;
        q = NULL;
    }
    p=NULL;
    delete p;
}
#endif

/* **************************************************************** */

#if ALL || COPY_CONSTRUCTOR
// TODO: Copy constructor
template <class T>
LinkedList<T> ::LinkedList(const LinkedList &rhs)
{
    dummy = new Node<T>();
    dummy->data = 0;
    dummy->next=dummy;
    dummy->prev=dummy;
    *this=rhs;
}
#endif

/* **************************************************************** */

#if ALL || ASSIGN
// TODO: Assignment operator
template <class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> & rhs)
{
    Node<T> *temp = new Node<T>();
    temp =rhs.dummy->prev;
    this->makeEmpty();
    while(temp != rhs.dummy)
    {
        this->insert(temp->data);
        temp=temp->prev;
    }
    temp=NULL;
    delete temp;
    return *this;
}

#endif

/* **************************************************************** */
// Do NOT modify anything below this line
/* **************************************************************** */

#ifndef BUILD_LIB
// Print list
template <class T>
void LinkedList<T>::printList()
{
    if(isEmpty())
    {
        // Empty list
        std::cout << "Empty List" << std::endl;
    } else {
        // Iterate to end
        Node<T> *p = dummy->next;
        // assign data to newNode
        // Loop to end
        while (p != dummy)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}



#endif

template class LinkedList<int>;
