/**
  * @file paridad.cpp
  * */
#include "paridad.h"

/**
 * @brief Metodo para revisar los valores de paridad
 * @param string& variable, bool paridad
 * @authors Ricardo&Yordi&Josue
 */
string Paridad::checkeo(const string& variable, bool paridad) {

    bool tempParidad=false;
    for (int i = 0; i < variable.size()-1; ++i) {
        int temp = (int) ((unsigned char) variable[i]);
        if (temp % 2 == 1) {
            tempParidad = !tempParidad;
        }
        temp=temp >> (1);

        if (temp % 2 == 1) {
            tempParidad = !tempParidad;
        }
        temp=temp >> (1);

        if (temp % 2 == 1) {
            tempParidad = !tempParidad;
        }
        temp=temp >> (1);

        if (temp % 2 == 1) {
            tempParidad = !tempParidad;
        }

        temp=temp >> (1);

        if (temp % 2 == 1) {
            tempParidad = !tempParidad;
        }

        temp=temp >> (1);

        if (temp % 2 == 1) {
            tempParidad = !tempParidad;
        }

        temp=temp >> (1);

        if (temp % 2 == 1) {
            tempParidad = !tempParidad;
        }

        temp=temp >> (1);

        if (temp % 2 == 1) {
            tempParidad = !tempParidad;
        }
    }
    if(variable.substr(variable.size()-1,1)==std::string("1")){
        tempParidad = !tempParidad;
    }
    if(tempParidad==evenParity){
        return std::string("-2");
    }
    return variable.substr(0,variable.size()-1);
}
/**
 * @brief Metodo para generar paridad segun los datos pasados
 * @param string& variable, bool paridad
 * @authors Ricardo&Yordi&Josue
 */
string Paridad::paridad(const string& variable, bool paridad) {
    for(temp:variable){
        unsigned int temp2=(unsigned int)((unsigned char)a)M;
        if(temp2%2==1){
            paridad=!paridad;
        }temp2=temp2>>(1);
        if(temp2%2==1){
            paridad=!paridad;
        }temp2=temp2>>(1);
        if(temp2%2==1){
            paridad=!paridad;
        }temp2=temp2>>(1);
        if(temp2%2==1){
            paridad=!paridad;
        }temp2=temp2>>(1);
        if(temp2%2==1){
            paridad=!paridad;
        }temp2=temp2>>(1);
        if(!paridad){
            return  variable+string("1");

        }else {
            return variable + string("0");
        }
    }
}
/**
 * @brief Metodo para reconstruir informaciòn mendiante xor
 * @param vector<string> &var
 * @authors Ricardo&Yordi&Josue
 */

void Paridad::XOR_Rebuild(vector<string> &var) {
    unsigned long tamano=var[0].size();
    string compXOR("",tamano);
    while (tamano>0){
        char temp=var[0][tamano-1];
        for (int i=1;i<var.size();++i){
            temp=(char)(temp^var[i][size-1]);
        }
        compXOR.data()[size-1]=temp;
        tamano--;
    }
    var.push_back(compXOR);

}