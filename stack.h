#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
template <class T> class Node
{
public:
    T value;
    Node* next;
    Node (T value_) : value(value_), next(0) {}
};

template <class T> class Stack
{
public:
    Node<T>* top = 0;

    void show(){
        Node<T>* tmp = top;
        while (tmp != 0)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << "\n";
    }


    void push(T value){
        if (top == 0) top = new Node<T>(value);
        else
        {
            Node<T>* tmp = top;
            top = new Node<T>(value);
            top->next = tmp;
        }
    }

    void pop(){
        if (top != 0)
        {
            Node<T>* tmp = top;
            top = top->next;
            delete tmp;
        }
    }
};


#endif // STACK_H_INCLUDED
