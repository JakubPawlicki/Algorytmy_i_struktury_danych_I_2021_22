#include <iostream>

typedef int elementtype;
struct celltype {
    elementtype element;
    celltype *next;
};
typedef celltype *position;

class Lista {

protected :
    position l; // wskaźnik do głowy listy

public:

    Lista() {
        l = new celltype;
        l->next = NULL;
    }

    ~Lista() {
        position temp;
        if ((l != NULL) && (l->next != NULL))
            while (l->next != NULL) {
                temp = l->next;
                l->next = temp->next;
                delete temp;
            }
    } //destruktor

    void Insert(elementtype x, position p) {
        position tmp;
        tmp = p->next;
        p->next = new celltype;
        p->next->element = x;
        p->next->next = tmp;
    }

    void Delete(position p) {
        position tmp;
        tmp = p->next;
        p->next = p->next->next;
        delete tmp;
    }

    elementtype Retrieve(position p) {
        if (p->next != NULL)
            return p->next->element;
    }

    position Locate(elementtype x) {
        position temp = l;
        while (temp->next != NULL) {
            if (temp->next->element == x)
                return temp;
            temp = temp->next;
        }
        return temp;
    }

    position First() {
        return l;
    }

    position Next(position p) {
        return p->next;
    }

    position Previous(position p) {
        position temp = l;
        while (temp->next != p)
            temp = temp->next;
        return temp;
    }

    position END() {
        position temp = l;
        while (temp->next != NULL)
            temp = temp->next;
        return temp;
    }

    void print() {
        position temp = l;
        while (temp->next != NULL) {
            std::cout << Retrieve(temp) << ", ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Lista l;
    l.Insert(5, l.First());
    l.print();
    l.Insert(2, l.First());
    l.print();
    l.Insert(1, l.Next(l.First()));
    l.print();
    l.Delete(l.Locate(2));
    l.print();
}
