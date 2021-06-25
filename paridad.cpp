/*
  * @file paridad.cpp
  * */
#include "paridad.h"


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


}
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

        }else{
            return variable+string ("0");
        }