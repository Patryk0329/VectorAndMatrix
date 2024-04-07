#include "nvector.h"

nvector::nvector(): data(nullptr), size(0){}

nvector::nvector(std::initializer_list<double> list) : size(list.size())
{
        data = new double[size];
        std::copy(list.begin(), list.end(), data);
}
nvector::nvector(int nmbr):size(nmbr)
{
    data = new double[size];
    for(size_t i=0;i<size;i++){
        data[i]=0;
    }
}

nvector::nvector(const nvector& other):size(other.size)
{
    data = new double[size];
    std::copy(other.data, other.data + size, data);
}

nvector::nvector(nvector&& other) noexcept : data(other.data), size(other.size)
{
        other.data = nullptr;
        other.size = 0;
}

nvector::~nvector()
{
    delete[] data;
}

size_t nvector::getsize() const{
    return size;
}

void nvector::setData(double* newData, size_t newSize)
{
        delete[] data; 
        size = newSize;
        data = new double[size];
        std::copy(newData, newData + size, data);
}

nvector nvector::operator+(const nvector& other) const
{
    if(size != other.size) throw std::length_error("Wektory mają różne wymiary.");
    nvector results_wektor;
    results_wektor.size = size;
    results_wektor.data = new double[size];
    for (size_t i = 0; i < size; ++i) {
        results_wektor.data[i] = data[i] + other.data[i];
    }
    
    return results_wektor;
}

double nvector::operator*(const nvector&other) const
{
    if(size != other.size) throw std::length_error("Wektory mają różne wymiary.");
    double results;
    for (size_t i = 0; i < size; ++i) {
        results += data[i] * other.data[i];
    }
    
    return results;
}

nvector& nvector::operator=(const nvector& other)
{
    if(this!= &other){
        delete[] data;
        size = other.size;
        data = new double[size];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

nvector& nvector::operator=(nvector&& other) noexcept 
{
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
}

 double& nvector::operator[](size_t index)
{
        if (index >= size) throw std::out_of_range("Indeks poza zakresem.");
        return data[index];
}

const double& nvector::operator[](size_t index) const
{
        if (index >= size) throw std::out_of_range("Indeks poza zakresem.");
        return data[index];
}

std::ostream& operator <<(std::ostream& os, const nvector& object )
{
    os << "[";
    for (size_t i = 0; i < object.size; ++i) {
            os << object.data[i] << (i < object.size - 1 ? ", " : "");
        }
    os << "]";

    return os;
}


