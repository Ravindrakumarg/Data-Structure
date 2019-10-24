#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
    public:
        Node();
        virtual ~Node();

        void setData(T data){ this->data =  data;}
        void setLeft(Node<T> left) { this->left = left; }
        void setRight(Node<T> right) { this->right = right; }

        T getData() { return this->data;}
        Node<T>* getLeft(){return this->left; }
        Node<T>* getRight() { return this->right;}


    protected:

    private:
        T data;
        Node<T>* left;
        Node<T>* right;

};

#endif // NODE_H
