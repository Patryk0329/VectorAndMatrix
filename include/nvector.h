#ifndef NVECTOR_H
#define NVECTOR_H

#include <initializer_list>
#include <iostream>
#include <stdexcept>


class nvector
{
    private:
        double *data;
        size_t size;
    public:
    
    //Konstruktor domyślny
    nvector();
    //konstruktor tworzacy wektory 0
    nvector(int nmbr);

    //Konstruktor z initializer list
    nvector(std::initializer_list<double> list);

    //Konstuktor kopiujący 
    nvector(const nvector& other);

    //Konstruktor przenoszący
    nvector(nvector&& other) noexcept;
    
    //Destruktor
    ~nvector();

    //Funkcja zwracająca rozmiar wektora
    size_t getsize() const;

    //Funkcja ustawiajaca wartosci do wektora
    void setData(double* newData, size_t newSize);

    //Operator dodawania
    nvector operator+(const nvector& other) const;

    //Operator mnożenia
    double operator*(const nvector& other) const;

    //Przeciążenie operatora przypisania kopiującego
    nvector& operator =(const nvector& other);

    //Przeciążenie operatora przypisania przenoszącego
    nvector& operator =(nvector&& other) noexcept;

    //Przeciążenie operatorów indeksowania
    const double& operator[](size_t index) const;
    double& operator[](size_t index);

    //Przeciążenie operatora <<
    friend std::ostream& operator <<(std::ostream& os, const nvector& object );
    friend class ndarray;

};



#endif