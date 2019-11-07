#include <iostream>
#include<string>
#include"Functions.h"

using namespace std;

int main() {
    int number_bussiness;
    cout << "Ingrese cantidad de empresas:\n";
    cin >> number_bussiness;
    cin.ignore();
    Result(number_bussiness);

    return 0;
}
