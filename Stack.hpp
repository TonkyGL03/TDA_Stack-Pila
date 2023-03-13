#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

template<class T, int ARRAYSIZE = 1024>
class Stack{

private:
    T data[ARRAYSIZE];
     int top;
     void copyAll(const Stack<T, ARRAYSIZE>&);

public:
    Stack(); //constructor inicializador
    Stack(const Stack<T, ARRAYSIZE>&); //constructor copia

     void push(const T&);

     T getTop();
     T pop();

     bool isEmpty();
     bool isFull();

     Stack<T, ARRAYSIZE>& operator = (const Stack<T, ARRAYSIZE>&);
};

//implementacion de metodos
using namespace std;


template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() : top(-1){}   //Inicializacion de Pila

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack<T, ARRAYSIZE>& s){
copyAll(s);

}

template<class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE>& s){
int i (0);
while(i <= s.top){
    this ->data[ i ] = s.data[ i ];
    i++;
}
this->top = s.top;
}

template<class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty(){

return top == -1;
}

template<class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull(){

return top == ARRAYSIZE - 1;

}


template<class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T& s)
{
    if(isFull()){cout<<"Pila llena"; return; }
    data[top + 1]  = s;
    top++;
    }

template<class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop()
{
return data[top];
}

template<class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::pop()
{
    if(isEmpty()){cout<<"Pila vacia"<<endl;
    fflush(stdin);
    getchar();
    abort();
    }

    return data[top--];
}

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator=(const Stack<T, ARRAYSIZE>& s)
{
copyAll(s);
return *this;
}




#endif // STACK_HPP_INCLUDED
