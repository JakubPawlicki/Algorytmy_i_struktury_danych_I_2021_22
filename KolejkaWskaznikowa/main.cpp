#include <iostream>

typedef int elementtype;
struct celltype {
    elementtype element;
    celltype *next;
};
typedef celltype *position;

class Queue {
protected:
    position Front;
    position Rear;
public:
    Queue() {
        Front = new celltype;
        Rear = Front;
        Front->next = NULL;
    }

    ~Queue() {
        position tmp;
        while (Front->next != NULL) {
            tmp = Front;
            Front = Front->next;
            delete tmp;
        }
        delete Front;
    }

    void Enqueue(elementtype x) {
        position p = new celltype;
        p->element = x;
        p->next = NULL;
        Rear->next = p;
        Rear = p;
    }

    void Dequeue() {
        if (!Empty()) {
            position p = Front;
            Front = Front->next;
            delete p;
        }
    }

    elementtype FrontElem() {
        if (!Empty())
            return Front->next->element;
    }

    bool Empty() {
        return (Front->next == NULL);
    }
};

int main() {
    Queue k;

    std::cout << "Czy pusta: " << k.Empty() << std::endl;
    k.Enqueue(5);
    std::cout << "Czy pusta: " << k.Empty() << std::endl;
    std::cout << "Element front: " << k.FrontElem() << std::endl;
    k.Dequeue();
    std::cout << "Czy pusta: " << k.Empty() << std::endl;
    k.Enqueue(4);
    k.Enqueue(3);
    k.Enqueue(2);
    std::cout << "Element front: " << k.FrontElem() << std::endl;
    k.Enqueue(1);
    std::cout << "Element front: " << k.FrontElem() << std::endl;
    k.Dequeue();
    std::cout << "Element front: " << k.FrontElem() << std::endl;
    k.Enqueue(6);
    std::cout << "Element front: " << k.FrontElem() << std::endl;
    k.Dequeue();
    k.Dequeue();
    std::cout << "Element front: " << k.FrontElem() << std::endl;
}