#include <iostream>

class Vector {
    int dim;    // dimension of an array (size of vector)
    double *x;  // an array of coordinates
 public:
    explicit Vector(int dimension = 1);

    // access to coordinates: index start with 1
    double at(int index) const {return x[index-1]; }
    double & at(int index) {return x[index-1]; }

    // define :
    // * destructor that frees memory
     ~Vector();
    // * copy constructor
    Vector(const Vector & v);
    // * copy assignment operator
     Vector & operator=(const Vector & v);
    // Vector & operator=(int n){ x[0] = n; }

    // friend function declaration
    friend std::ostream & operator<< (std::ostream & out, const Vector & v);

};
