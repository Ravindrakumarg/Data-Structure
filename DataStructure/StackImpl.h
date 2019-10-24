
#include "Stack.h"

template <typename T>
void Stack<T>::push(T data)
{
    if(top+1 == MAX_STACK_SIZE)
        cout << "Stack overflow case"<<endl;
    else
    {
        this->data[top+1] = data;
        top+=1;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if(is_stack_empty())
        cout << "Stack is empty"<<endl;
    else
    {
        int pop_item = this->data[top];
        top--;
        return pop_item;
    }
    return 0;
}

template <typename T>
bool Stack<T>::is_stack_empty()
{
    if(top == -1)
        return true;
    else
        return false;
}

template <typename T>
void Stack<T>::display_stack()
{
    if(is_stack_empty())
        cout << "Stack is empty"<<endl;
    else
    {
        cout << "Stack element:";
        for(int i=0; i<=top; i++)
            cout << this->data[i] << " ";
        cout <<endl;
    }
}

template <typename T>
void Stack<T>::reverse_stack()
{
    if(is_stack_empty())
        cout << "Stack is empty"<<endl;
    else
    {
        for(int i=0; i<(top+1)/2; i++)
        {
            T temp = this->data[i];
            this->data[i] = this->data[top-i];
            this->data[top-i] = temp;
        }
        cout << "Reversing Stack: ";
    }
}
