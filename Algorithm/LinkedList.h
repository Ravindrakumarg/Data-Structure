#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<typename T>
struct Link
{
    T data;
    Link<T>* next;

    Link(){}
    Link(T d)
    {
        data = d;
        next = nullptr;
    }
};

template<typename T>
class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();

        //Helper Operations
        bool IsEmpty();
        void Show(Link<T>* head);
        int Length();

        //Basic Operations
        void Add(T data);
        void AddAtBegining(T data);
        void AddAtMiddle(T data);
        void AddAtNthPosition(T data, int n);

        void Remove();
        void RemoveAtBegining();
        void RemoveFromMiddle();
        void RemoveAtMiddle();
        void Remove(T data);


        Link<T>* Find(T data);

        Link<T>* GetHead() { return head; }

    protected:
        void SetHead(Link<T>* head) { this->head = head; }
    private:
        Link<T>* head;
};

#include "LinkedList_Impl.h"

#endif // LINKEDLIST_H
