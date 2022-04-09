#include <iostream>

const int maxlegth = 3;
typedef int elementtype;
typedef int position;

class Stos {
    int S[maxlegth];
    position Top;//szczyt stosu
public:
    Stos() {
        Top = -1;
    }

    void Push(elementtype x) {
        if (Top < maxlegth - 1) {
            Top++;
            S[Top] = x;
        }
    }

    void Pop() {
        if (Top >= 0) {
            Top--;
        }
    }

    bool Empty() {
        if (Top == -1)
            return true;
        else
            return false;
    }

    elementtype TopElem() {
        if (Top >= 0)
            return S[Top];
    }

    void Makenull() {
        Top = -1;
    }
};


int main() {

    Stos stos;

    std::cout<<"Empty: "<<stos.Empty()<<std::endl;
    stos.Push(5);
    std::cout<<stos.TopElem()<<std::endl;
    std::cout<<"Empty: "<<stos.Empty()<<std::endl;
    stos.Pop();
    std::cout<<"Empty: "<<stos.Empty()<<std::endl;
    stos.Push(10);
    stos.Push(11);
    std::cout<<stos.TopElem()<<std::endl;
    stos.Push(2);
    stos.Push(3);
    std::cout<<"Empty: "<<stos.Empty()<<std::endl;
    std::cout<<stos.TopElem()<<std::endl;


    return 0;
}
