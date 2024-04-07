#ifndef D3VECTOR_H
#define D3VECTOR_H

#include <nvector.h>
#include <iostream>

class d3vector{
    public:
    d3vector(); //Konstukror domyślny
    d3vector(std::initializer_list<double> list); // Konstruktor z initializer_list
    d3vector operator ^(const d3vector& other) const; //Operator mnożenia wektorowego
    double operator *(const d3vector& other) const; //Operator mnożenia skalarnego

    friend std::ostream& operator<<(std::ostream& os, const d3vector& other); // Operator wstawiania do strumienia

private:
    double *data; //wskaźnik na tablicę (wektor)

};

#endif