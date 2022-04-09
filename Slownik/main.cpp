#include <iostream>

const int B = 65;
typedef char *elementtype;
struct celltype {
    elementtype element;
    celltype *next;
};
typedef celltype *position;

class dictionary {
protected :
    position D[B];
public:
    dictionary() {
        for (int i = 0; i < B; i++)
            D[i] = NULL;
    }

    ~dictionary() {
        position tmp;
        for (int i = 0; i < B; i++) {
            while (D[i] != NULL) {
                tmp = D[i];
                D[i] = D[i]->next;
                delete tmp;
            }
        }
    }

    void Makenul() {
        position tmp;
        for (int i = 0; i < B; i++) {
            while (D[i] != NULL) {
                tmp = D[i];
                D[i] = D[i]->next;
                delete tmp;
            }
        }
    }

    bool Member(elementtype x) {
        position current;
        current = D[H(x)];
        while (current != NULL) {
            if (current->element == x) return true;
            else current = current->next;
        }
        return false;
    }

    void Insert(elementtype x) {
        int bucket;
        position oldheader;
        if (!Member(x)) {
            bucket = H(x);
            oldheader = D[bucket];
            D[bucket] = new celltype;
            D[bucket]->element = x;
            D[bucket]->next = oldheader;
        }
    }

    void Delete(elementtype x) {
        position p, current;
        int bucket;
        bucket = H(x);
        if (D[bucket] != NULL) {
            if (D[bucket]->element == x)
            {
                p = D[bucket];
                D[bucket] = D[bucket]->next;
                delete p;
            } else
            {
                current = D[bucket];
                while (current->next != NULL)
                    if ((current->next->element) == x) {
                        p = current->next;
                        current->next = current->next->next;
                        delete p;
                        break;
                    } else current = current->next;
            }
        }
    }

    int H(elementtype x) {
        return (int(x[0])) % B;
    }
};

int main() {
    dictionary d;
    d.Insert("Ala");
    std::cout<<"Member "<<d.Member("Ala")<<std::endl;
    std::cout<<"Funkcja "<<d.H("Ala")<<std::endl;

    d.Insert("As");
    std::cout<<"Member "<<d.Member("As")<<std::endl;
    std::cout<<"Funkcja "<<d.H("As")<<std::endl;

    std::cout<<"Member "<<d.Member("Ala")<<std::endl;
    std::cout<<"Funkcja "<<d.H("Ala")<<std::endl;

    d.Insert("Pawlicki");
    std::cout<<"Funkcja "<<d.H("Pawlicki")<<std::endl;
    std::cout<<"Member "<<d.Member("Pawlicki")<<std::endl;

    d.Delete("Ala");
    std::cout<<"Member "<<d.Member("As")<<std::endl;
    std::cout<<"Member "<<d.Member("Ala")<<std::endl;

    d.Makenul();
    std::cout<<"Member "<<d.Member("As")<<std::endl;
    std::cout<<"Member "<<d.Member("Pawlicki")<<std::endl;
}