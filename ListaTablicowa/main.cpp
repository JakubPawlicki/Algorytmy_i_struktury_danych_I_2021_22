#include <iostream>

typedef int elementtype, position;
const int maxlength = 10;
struct List {
    elementtype elements[maxlength];
    int last;           //indeks ostatniego elementu listy
};

position END(List l) {
    return (l.last + 1);
}

position First(List l) {
    return 0;
}

position Next(position p, List l) {
    if (p > l.last || p < 0)
        return -1;
    else
        return p + 1;
}

position Previous(position p, List l) {
    if (p < 0 || p > l.last + 1)
        return -1;
    else
        return p - 1;
}

position Locate(elementtype x, List l) { //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
    position p = 0;
    for (const auto &item: l.elements) {
        if (item == x)
            return p;
        else
            p++;
    }
    return END(l);

}

const int MIN = -10000000;

elementtype Retrieve(position p, List l) {
    if (p > l.last || p < 0)
        return MIN;

    return l.elements[p];
}

bool Insert(int x, position p, List &l) {
    if (l.last >= maxlength)
        return false;
    if (p > l.last + 1 || p < 0)
        return false;
    for (int i = l.last; i >= p; i--) {
        l.elements[i + 1] = l.elements[i];
    }
    l.elements[p] = x;
    l.last++;

    return true;
}

bool Delete(position p, List &l) {
    if (p > l.last || p < 0)
        return false;
    for (int i = p; i < l.last; i++)
        l.elements[i] = l.elements[i + 1];

    l.last--;
    return true;

}


//##############################################
void print(List l) {
    position i = First(l);
    while (i != END(l)) {
        printf("  %d,", Retrieve(i, l));
        i = Next(i, l);
    }
    printf("\n");

}

void Duplicate(List &l) {
    int size = l.last;
    for (int i = 0; i <= size; i++)
        Insert(l.elements[i], l.last + 1, l);
}

void Delete_Duplcations(List &l) {
    for (int i = 0; i <= l.last; i++) {
        for (int j = 0; j <= l.last; j++) {
            if (l.elements[i] == l.elements[j] && i != j)
                Delete(j, l);
        }
    }
}

int main() {

    List l;
    l.last = -1;
    Insert(100, First(l), l);
    print(l);

    for (int i = 0; i < 3; i++)
        Insert(i, First(l), l);
    print(l);

    Insert(20, Previous(END(l), l), l);
    print(l);
    //Insert(8,Locate(100, l), l);

    Delete(Locate(20, l), l);
    print(l);

///////////////////////
    Duplicate(l);
    print(l);
    Insert(100, Previous(END(l), l), l);
    print(l);


    Delete_Duplcations(l);
    print(l);


    return 0;
}

// + Dodawanie duplikatu do listy
// Usuwanie duplikatu z listy, nie wiadomo ile jest duplikatow i na ktorym miejscu w liscie sa