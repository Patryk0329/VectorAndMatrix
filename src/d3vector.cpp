#include "d3vector.h"

d3vector::d3vector(std::initializer_list<double> list){
        data = new double[3];
        std::copy(list.begin(), list.end(), data);
}

d3vector d3vector::operator ^(const d3vector& other) const{
    d3vector  temp_d3vector{0.,0.,0.};
    temp_d3vector.data[0] = data[1] * other.data[2] - data[2] * other.data[1];
    temp_d3vector.data[1] = -(data[0] * other.data[2] - data[2] * other.data[0]);
    temp_d3vector.data[2] = data[0] * other.data[1] - data[1] * other.data[0];

    return temp_d3vector;
}

double d3vector::operator *(const d3vector& other) const{
    return data[0]* other.data[0] + data[1] * other.data[1] + data[2] * other.data[2];
}

std::ostream& operator<<(std::ostream& os, const d3vector& other){
    os << "[" << other.data[0] << "," << other.data[1] << "," << other.data[2] << "]";
    return os;
}

