#include <iostream>

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Posortowana rosnąco
int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; //Posortowana malejąco
int c[] = {10, 4, 7, 3, 2, 5, 0, 1, 9, 16}; //Losowe wartości
int n = 10;

void insertion_sort(int a[]) {
    int operacje_dominujace = 0, k_while = 0;

    for (int index = 1; index < n; index++) {
        int value = a[index];
        int index_2 = index - 1;


        k_while = 0;
        while (value < a[index_2] && index_2 + 1 > 0) {
            a[index_2 + 1] = a[index_2];
            index_2--;
            //if(k_while != 0)
            //operacje_dominujace++;
            k_while++;
        }
        operacje_dominujace++;
        a[index_2 + 1] = value;
    }

    std::cout << "Liczba operacji dominujacych: " << operacje_dominujace << std::endl;
}

int main() {

    //std::cout<<"[a-1]="<<a[-2]<<std::endl;

    insertion_sort(a);
    insertion_sort(b);
    insertion_sort(c);

    for (int val: a)
        std::cout << val << " ";

    std::cout << std::endl;

    for (int val: b)
        std::cout << val << " ";

    std::cout << std::endl;

    for (int val: c)
        std::cout << val << " ";

    return 0;
}
