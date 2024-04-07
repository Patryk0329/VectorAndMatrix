#include "narray.h"
#include <utility>

ndarray::ndarray():size(0), columns(nullptr){}

ndarray::ndarray(std::initializer_list<std::initializer_list<double>> list):size(list.size())
{
    size_t i=0;
    columns = new nvector[size];
    for(const auto& sublist: list){
        columns[i++]=nvector(sublist);
    }
}

ndarray::ndarray(const ndarray& other):size(other.size)
{
    columns=new nvector[size];
    for(size_t i=0;i<size;i++){
        std::copy(other.columns[i].data, other.columns[i].data+size, columns[i].data);
    }
}

ndarray::ndarray(ndarray&& other) noexcept:size(other.size), columns(other.columns)
{
    other.columns=nullptr;
    other.size=0;
}

ndarray::~ndarray()
{
    delete[] columns;
}

size_t ndarray::getSize() const{
    return size;
}
ndarray& ndarray::operator=(const ndarray& other)
{
    if(this!= &other){
        delete[] columns;
        size = other.size;
        columns=new nvector[size];
        for(size_t i=0;i<size;i++){
            std::copy(other.columns[i].data, other.columns[i].data+size, columns[i].data);
            //ewentualnie other.columns[i] = columns[i]
        }
    }
    return *this;
}
    
ndarray& ndarray::operator=(ndarray&& other) noexcept
{
    if (this != &other){
            delete[] columns;
            size=std::exchange(other.size, 0);
            columns = std::exchange(other.columns,nullptr);
        }
        return *this;
}

const nvector& ndarray::operator[](size_t index) const
{
    if(index>=size)
        throw std::out_of_range("Indeks poza zakresem.");
    return columns[index];
}

nvector& ndarray::operator[](size_t index)
{
    if(index>=size)
        throw std::out_of_range("Indeks poza zakresem.");
    return columns[index];
}

ndarray ndarray::operator+(const ndarray& other) const
{
    if(size!=other.size) throw std::invalid_argument("Macierze maja rozne wymiary.");
    ndarray results_macierz;
    results_macierz.size=size;
    results_macierz.columns = new nvector[size];
    for(size_t i=0;i<size;i++){
        results_macierz.columns[i]=columns[i]+other.columns[i];
    }
    return results_macierz;
}

ndarray ndarray::operator*(const ndarray& other) const
{
    if(size!=other.size) throw std::invalid_argument("Macierze maja rozne wymiary.");
    ndarray results_macierz;
    results_macierz.size=size;
    results_macierz.columns = new nvector[size];
    for(size_t i=0;i<size;i++){
        results_macierz.columns[i] = nvector(size);
        for(size_t j=0;j<size;j++){ 
            double suma=0.; 
            for(size_t k=0;k<size;k++){
                //mnozymy wiersz razy kolumne - na odwrot
                suma+=columns[k][j]*other.columns[i][k];
            }
            results_macierz[i][j]=suma;
        }
    }
    return results_macierz;
}

nvector ndarray::operator*(const nvector& other) const{
    if(size!=other.size) throw std::invalid_argument("Obiekty maja rozne wymiary.");
    nvector results_vector(size);

    for(size_t i=0;i<size;i++){
        double suma = 0;
        for(size_t j=0;j<size;j++){ 
            suma += columns[j][i] * (other[j]);
        }
      results_vector[i] = suma;
    }
    return results_vector;

}

double ndarray::trace() const
{
    double sum = 0;
    for(size_t i=0; i < size; ++i){
        sum += columns[i][i];
    }

    return sum;
}


std::ostream& operator <<(std::ostream& os, const ndarray& m)
{
     if (m.size == 0 || m.columns == nullptr) {
        os << "Macierz jest pusta";
        return os;
    }
    


    for (size_t i = 0; i < m.size; ++i) {
        os << "[";
            for (size_t j = 0; j < m.size; ++j) {
                os << m.columns[j][i];
                if(j < m.size - 1) os <<",";
            }
            os << "]" << std::endl;
        }

    return os;
}

