//Proszę nie modyfikować pliku main. Jeśli nazwy Państwa klas są inne to proszę użyć słowa kluczowego typedef by uzgodnić nazwy.
//
//Zaprogramowane wcześniej klasy reprezentujące n-wymiarowe wektory i macierze uzupełnij o metody/operatory umożliwiające 
//wykonanie poniższych operacji. Na podstawie klasy n-wymiarowego wektora stwórz klasę 3-wymiarowego wektora wzbogaconą o operator
//obliczania iloczynu wektorowego, oznaczonego poniżej symbolem ^.
//Poprawna implementacja powinna prowadzić do outputu takiego jak ten zamieszczony poniżej.

#include <iostream>
#include "nvector.h"
#include "narray.h"
#include "d3vector.h"

int main() {

    ndarray a1 {{1.,2.,3.},{2.,3.,4.},{4.,0.,6.}};
    std::cout<<"a1:\n"<<a1<<std::endl;
    ndarray a2 {{1.,1.,1.},{1.,0.,1.},{1.,1.,1.}};
    std::cout<<"a2:\n"<<a2<<std::endl;

    std::cout<<"a1+a2:\n"<<a1+a2<<std::endl;
    std::cout<<"a1*a2:\n"<<a1*a2<<std::endl;

    std::cout<<"Ślad: "<<(a1*a2).trace()<<std::endl;
    std::cout<<"Ślad: "<<(a2*a1).trace()<<std::endl;
    a2[1][1]=1;
    std::cout<<"a2:\n"<<a2<<std::endl;

    nvector v0 {1,2,3,4,5,5,6,6,7,8,8};
    std::cout<<"v0: "<<v0<<std::endl;
    nvector v1 {1.,2.,3.};
    std::cout<<"v1: "<<v1<<std::endl;
    std::cout<<"a2*v1: "<< a2*v1<<std::endl;
    nvector v2 {1.,2.,0.};

    d3vector d1 {1.,2.,3.};
    d3vector d2 {1.,2.,0.};
    
    std::cout<<"(d1xd2): "<<(d1^d2)<<std::endl;
    std::cout<<"(d1xd2)*d1: "<<(d1^d2)*d1<<std::endl;
    std::cout<<"(d1xd2)*d2: "<<(d1^d2)*d2<<std::endl;
    
   return 0;
}

//a1:
//[[1,2,3],
//[2,3,4],
//[4,0,6]]
//a2:
//[[1,1,1],
//[1,0,1],
//[1,1,1]]
//a1+a2:
//[[2,3,4],
//[3,3,5],
//[5,1,7]]
//a1*a2:
//[[9,6,9],
//[11,8,11],
//[13,12,13]]
//Ślad: 30
//Ślad: 30
//a2:
//[[1,1,1],
//[1,1,1],
//[1,1,1]]
//v0: [1,2,3,4,5,5,6,6,7,8,8]
//v1: [1,2,3]
//a2*v1: [6,6,6]
//(d1xd2): [-6,3,0]
//(d1xd2)*d1: 0
//(d1xd2)*d2: 0
