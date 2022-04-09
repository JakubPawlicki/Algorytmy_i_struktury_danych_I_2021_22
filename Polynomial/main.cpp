#include <iostream>

const int max_degree = 20;

class Polynomial {
private:
    double coefficients[max_degree]{};
    unsigned int degree = 0;

    void calculateDegree() {
        int tempDegree = 0;
        for (int i = 0; i < max_degree; i++) {
            if (coefficients[i] != 0)
                tempDegree = i;
        }
        degree = tempDegree;
    }

public:
    Polynomial() {
        for (double &coefficient: coefficients)
            coefficient = 0;
    }

    int getDegree(){
        return degree;
    }

    void set(double coefficient, int degree) {
        if (degree > max_degree || degree < 0)
            std::cout << "Podano zly stopien! Operacja nie zostala wykonana." << std::endl;
        else {
            coefficients[degree] = coefficient;

            if (this->degree < degree && coefficient != 0)
                this->degree = degree;

            if (coefficient == 0)
                calculateDegree();

        }
    }

    Polynomial add(Polynomial &b) {
        Polynomial c;
        int max = (this->degree > b.degree) ? this->degree : b.degree;

        for (int i = 0; i <= max; i++)
            c.coefficients[i] = this->coefficients[i] + b.coefficients[i];

        c.calculateDegree();

        return c;
    }

    Polynomial sub(Polynomial &b) {
        Polynomial c;
        int max = (this->degree > b.degree) ? this->degree : b.degree;

        for (int i = 0; i <= max; i++)
            c.coefficients[i] = this->coefficients[i] - b.coefficients[i];

        c.calculateDegree();

        return c;
    }

    Polynomial mul(Polynomial &b) {
        Polynomial c;
        int cDegree = this->degree + b.degree;
        if (cDegree > max_degree) {
            std::cout << "Przekroczono maksymalny stopien wielomianu! Operacja nie została wykonana" << std::endl;
            return c;
        } else {
            c.degree = cDegree;

            for (int i = 0; i <= this->degree; i++)
                for (int j = 0; j <= b.degree; j++)
                    c.coefficients[i + j] += (this->coefficients[i] * b.coefficients[j]);
            return c;
        }
    }

    double horner(double x) {
        double temp = coefficients[degree];

        for (int i = degree - 1; i >= 0; i--) {
            temp = temp * x + coefficients[i];
        }

        return temp;
    }

    void print() {
        for (int i = degree; i >= 1; i--) {
            if (coefficients[i] != 0) {
                std::cout << std::showpos << coefficients[i];
                std::cout << std::noshowpos << "x^" << i;
            }
        }
        if(coefficients[0])
            std::cout << std::showpos << coefficients[0] << std::endl << std::noshowpos;
        else
            std::cout<<"\n";
    }
};

int main() {
    Polynomial p1;
    p1.set(-1, 3);
    p1.set(7, 2);
    p1.set(-1, 1);


    std::cout << p1.horner(-3) << std::endl;


}