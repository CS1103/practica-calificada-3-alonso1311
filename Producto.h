#ifndef Producto_H
#define Producto_H

#include<iostream>
#include<string>
#include<map>

using namespace std; 

struct Producto {
    string nombreProducto;
    map<string, int> propuesta;
};

#endif //Producto_H
