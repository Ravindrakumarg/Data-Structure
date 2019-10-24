#include "LinkedList.h"
#include <math.h>

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{

}

template<typename T>
bool LinkedList<T>::IsEmpty()
{
    if(this->head == nullptr)
        return true;
    else
        return false;
}

template<typename T>
int LinkedList<T>::Length()
{
    Link<T>* hd = this->GetHead();
    int len = 1;
    while(hd->next != nullptr)
    {
        len++;
        hd = hd->next;
    }

    return len;
}

template<typename T>
void LinkedList<T>::Show(Link<T>* head)
{
    if(head == nullptr)
        return;

   std::cout<<head->data<<" ";
   Show(head->next);
}

template<typename T>
void LinkedList<T>::Add(T data)
{
    if(this->head == nullptr)
        this->head = new Link<T>(data);
    else
    {
        Link<T>* hd = this->GetHead();

        while(hd->next != nullptr)
                hd = hd->next;

        hd->next = new Link<T>(data);
        hd = nullptr;
    }
}
template<typename T>
void LinkedList<T>::AddAtBegining(T data)
{
    if(this->head == nullptr)
        this->head = new Link<T>(data);
    else
    {
        Link<T>* n = new Link<T>(data);
        n->next = this->head;
        this->head = n;
    }
}

template<typename T>
void LinkedList<T>::AddAtMiddle(T data)
{
    if(this->head == nullptr)
        this->head = new Link<T>(data);
    else
    {
        if(this->Length() == 1)
            Add(data);
        else
        {
            Link<T>* hd = this->GetHead();
            int midPos = ceil(this->Length() / 2);
            for(int i=1; i<midPos; i++)
                hd = hd->next;

            Link<T>* n = new Link<T>(data);
            n->next = hd->next;
            hd->next = n;

            hd = nullptr;
        }
    }
}

template<typename T>
void LinkedList<T>::AddAtNthPosition(T data, int n)
{
    if(this->head == nullptr)
        this->head = new Link<T>(data);

    try
    {
        if(n > this->Length())
            throw "Wrong Position!....Maximum possible position is : ";
        else
        {
            if(n == 1)
                AddAtBegining(data);
            else
            {
                Link<T>* hd = this->GetHead();
                for(int i=1; i<n-1; i++)
                    hd = hd->next;

                Link<T>* n = new Link<T>(data);
                n->next = hd->next;
                hd->next = n;

                hd = nullptr;
            }
        }
    }
    catch(const char* ex)
    {
        std::cout<<ex<<this->Length()<<std::endl;
    }
}

template<typename T>
void LinkedList<T>::Remove()
{
    Link<T>* hd = this->GetHead();
    if(hd == nullptr)
        return;

    Link<T>* temp = nullptr;
    while(hd->next != nullptr)
    {
        temp = hd;
        hd = hd->next;
    }

    temp->next = nullptr;
    delete hd;

    //Set reference pointer to NULL.
    temp = nullptr;
}

template<typename T>
void LinkedList<T>::RemoveAtBegining()
{

}

template<typename T>
void LinkedList<T>::RemoveFromMiddle()
{

}

template<typename T>
void LinkedList<T>::RemoveAtMiddle()
{

}

template<typename T>
void LinkedList<T>::Remove(T data)
{

}

template<typename T>
Link<T>* LinkedList<T>::Find(T data)
{
    Link<T>* hd = this->GetHead();
    while(hd != nullptr)
    {
        if(hd->data == data)
            break;
        else
            hd = hd->next;
    }

    if(hd == nullptr)
        std::cout<<data<<" doesn't exist in LinkedList"<<std::endl;
    else
        std::cout<<data<<" exist in LinkedList"<<std::endl;
    return hd;
}
