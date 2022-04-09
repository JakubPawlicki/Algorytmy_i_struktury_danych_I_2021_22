#import <iostream>

const int maxlength = 20;
typedef int elementtype;
typedef int position;

class Kolejka {
protected :
    elementtype Queue[maxlength];
    position Front; // Indeks elementu czołowego
    position Rear; // Indeks ostatniego elementu
public:
    Kolejka() {
        Front = 0;
        Rear = maxlength - 1;
    };

    int AddOne(int i) {
        return ((i + 1) % maxlength);
    }

    void Enqueue(elementtype x) {
        if (!(AddOne(AddOne(Rear)) == Front)) {
            Rear = AddOne(Rear);
            Queue[Rear] = x;
        }
    }

    void Dequeue() {
        Front = AddOne(Front);
    }

    elementtype FrontElem() {
        if(!Empty())
            return Queue[Front];
    }

    void Makenull(){
        Front = 0;
        Rear = maxlength - 1;
    }

    bool Empty(){
        return AddOne(Rear) == Front;
    }

};

int main(){
    Kolejka k;

    std::cout<<"Czy pusta: "<<k.Empty()<<std::endl;
    k.Enqueue(5);
    std::cout<<"Czy pusta: "<<k.Empty()<<std::endl;
    std::cout<<"Element front: "<<k.FrontElem()<<std::endl;
    k.Dequeue();
    std::cout<<"Czy pusta: "<<k.Empty()<<std::endl;
    k.Enqueue(4);
    k.Enqueue(3);
    k.Enqueue(2);
    std::cout<<"Element front: "<<k.FrontElem()<<std::endl;
    k.Enqueue(1);
    std::cout<<"Element front: "<<k.FrontElem()<<std::endl;
    k.Dequeue();
    std::cout<<"Element front: "<<k.FrontElem()<<std::endl;
    k.Enqueue(6);
    std::cout<<"Element front: "<<k.FrontElem()<<std::endl;
    k.Dequeue();
    k.Dequeue();
    std::cout<<"Element front: "<<k.FrontElem()<<std::endl;
    k.Makenull();
    std::cout<<"Czy pusta: "<<k.Empty()<<std::endl;
}
