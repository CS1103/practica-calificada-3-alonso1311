#ifndef Functions_H
#define Functions_H

#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<algorithm>
#include<functional>
#include<set>

#include<boost/algorithm/string.hpp>
#include<boost/algorithm/string/split.hpp>

#include"Producto.h"

using namespace std;

string UPPER(string s) {
    std::for_each(s.begin(), s.end(), [](char & c){
	c = ::toupper(c);
    });
    return s;
}

void load_from(const string& nombreArchivo) {
    fstream file;
    file.open(nombreArchivo, ios::in);
    string fila;

    vector<string> names;
    vector<map<string, int>> propuestas;
    if(file.is_open()) {
        string nombre_empresa;
        while(getline(file, fila)) {                
            if(fila == UPPER(fila)){
                Producto p;
                nombre_empresa = fila;
                p.nombreProducto = nombre_empresa;
                names.push_back(fila);
            }

            else {
                vector<string> lineas;
                boost::split(lineas, fila, boost::is_any_of(" "));
            }

        }
        file.close();
    }

    else
        cout << "No se abrio el archivo\n";
    
}


int getMax(map<string, int> m) {
    int maximo = 0;
    for(auto it = m.cbegin(); it != m.cend(); ++it) 
        if (it ->second > maximo) 
             maximo = it->second; 
     
    return maximo;
 
}

int getMin(map<string, int> m) {
    auto bgin = m.begin();

    int minimo = bgin->second;
    for(auto it = m.cbegin(); it != m.cend(); ++it) 
        if (it ->second < minimo) 
             minimo = it->second; 
     
    return minimo;
 
}

double getProm(map<string, int> m) {
    int sumas = 0;
    int cantidad = 0;
    for(auto it = m.cbegin(); it != m.cend(); ++it) {
        sumas += it->second;
        cantidad++;
    }

    return sumas/cantidad;
}

using Comparator = function<bool(pair<string, int>, pair<string, int>)>;

void Result(int cantidad_empresas) {
    ofstream archivo("Respuesta.txt");
    for(;cantidad_empresas > 0; cantidad_empresas--) {
        map<string, int> propuesta;
        string name;
        cout << "Ingrese empresa:\n";
        cin >> name;
        cin.ignore();

        int cantidad_alias;
        cout << "Ingrese cantidad de propuestas: ";
        cin >> cantidad_alias;
        cin.ignore();
        for(int i = 0; i < cantidad_alias; i++) {
            string alias;
            int pago;
            cin >> alias >> pago;
            cin.ignore();
            propuesta[alias] = pago;    
        }
        auto compare = [](pair<string, int> p1, pair<string, int> p2) {
            return p1.second > p2.second;
        };

        set<pair<string, int>, Comparator> set_product(propuesta.begin(), propuesta.end(), compare);
    
        archivo << name << ", " << getMax(propuesta) << ", " << getProm(propuesta) << ", " << getMin(propuesta) << endl;

        for(const auto &element : set_product) {
            archivo << element.first << " " << element.second << endl;
        }
        
        archivo << endl;
    }
}




#endif //Functions_H
