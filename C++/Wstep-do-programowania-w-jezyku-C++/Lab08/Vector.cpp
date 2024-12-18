#include "Vector.h"

Vector::Vector(int dimension)
   : dim(dimension) {
    if(dim < 1)
        dim = 1;
    x = new double[dim];
}

Vector::Vector(const Vector & v){
    dim = v.dim;
    x = new double[dim];
    for(int i = 0; i<dim; i++){
        x[i] = v.x[i];
    }

}
Vector & Vector::operator=(const Vector & v){
    if(dim != v.dim){
       delete[] x;
       dim = v.dim;
       x = new double[dim];
    }
    for(int i = 0; i<dim; i++){
        x[i] = v.x[i];
    }
}
 Vector::~Vector(){
    std::cout << "removing vector : " << *this << std::endl;
    delete[] x;
 }
std::ostream & operator<< (std::ostream & out, const Vector & v) {
    out << "(";
    for(int i = 0; i < v.dim-1; ++i){
        out << v.x[i] << ", ";
    }
    out << v.x[v.dim-1] << ")";
    return out;
}
