//
// Created by santa on 25/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOIII_PARIDAD_H
#define ITCR_DATOSII_PROYECTOIII_PARIDAD_H


#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Paridad {
public:
    string paridad(const string&, bool paridad=true);
    string checkeo(const string&, bool paridad=true);
    void XOR_Rebuild(vector<string>&);

};




#endif //ITCR_DATOSII_PROYECTOIII_PARIDAD_H
