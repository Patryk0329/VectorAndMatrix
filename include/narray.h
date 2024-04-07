// narray.h
#ifndef NARRAY_H
#define NARRAY_H

#include "nvector.h"
#include <initializer_list>
#include <iostream>

class ndarray {
public:
    // Konstruktory
    ndarray(); // Domyślny konstruktor
    ndarray(std::initializer_list<std::initializer_list<double>> list); // Konstruktor z initializer_list
    ndarray(const ndarray& other); // Konstruktor kopiujący
    ndarray(ndarray&& other) noexcept; // Konstruktor przenoszący

    // Destruktor
    ~ndarray();

    // Operatory
    ndarray& operator=(const ndarray& other); // Operator przypisania kopiującego
    ndarray& operator=(ndarray&& other) noexcept; // Operator przypisania przenoszącego
    ndarray operator+(const ndarray& other) const; // Operator dodawania macierzy
    ndarray operator*(const ndarray& other) const; //Operator mnożenia macierzy
    nvector& operator[](size_t index); // Operator indeksujący zwracający wektor (kolumnę)
    const nvector& operator[](size_t index) const; // Operator indeksujący zwracający wektor (kolumnę) dla stałych obiektów
    nvector operator*(const nvector& other) const; //Operator mnożenia macierz * wektor

    size_t getSize() const; // Zwraca rozmiar macierzy (n)

    double trace() const; //Zwraca ślad macierzy

    friend std::ostream& operator<<(std::ostream& os, const ndarray& m); // Operator wstawiania do strumienia

private:
    nvector* columns; // Wskaźnik na tablicę kolumn (wektorów)
    size_t size; // Rozmiar macierzy (n x n)
};

#endif // NMACIERZ_H
