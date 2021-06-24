
#pragma once

#include <iostream>
#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <json/json.h>
#include <json/value.h>


#define PORT 2508

/**
 * Clase cliente para la comunicación con el servidor
 */
class Client{
public:
    /**
     * Constructor del cliente
     */
    Client(){}

    /**
     * Convierte un objeto de tipo JSON a string
     * @param objetoJson El objeto JSON a convertir
     * @return Un string en formato JSON
     */
    std::string jsonToString(Json::Value objetoJson) {
        Json::FastWriter writer;
        std::string jsonString = writer.write(objetoJson);
        std::cout << jsonString << std::endl;  //Pa probar
        return jsonString;
    }

    /**
     * Convierte un string a un objeto de tipo JSON
     * @param jsonString Un string en formato JSON que represente un objeto
     * @return El objeto en formato JSON
     */
    Json::Value stringToJson(std::string jsonString) {
        Json::Reader reader;
        Json::Value jsonObject;
        bool parsingSuccessful = reader.parse(jsonString, jsonObject, false);
        if (!parsingSuccessful){
            perror("stringToJson");
        }
        return jsonObject;
    }

    /**
     * Procesa la respuesta del servidor ante una solicitud del cliente
     * @param respuesta La respuesta enviada por el servidor
     * @return La respuesta del servidor dependiendo del algoritmo utilizado
     */
    std::string procesarRespuesta(std::string respuesta) {
        Json::Value objetoJson = stringToJson(respuesta);
        std::string algoritmo = objetoJson.get("algoritmo", "ErrorEnAlgoritmo").asString();

    }
    /**
     * Envía una solicitud al servidor
     * @param mensaje Un string con el mensaje que se desea enviar
     * @return La respuesta del servidor procesada
     */
    std::string enviar(std::string mensaje) {

        int sock = 0, valread;
        struct sockaddr_in serv_addr;
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
            printf("\n Socket creation error \n");
            return "-1";
        }
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);

        if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) < 0){
            printf("\nInvalid address/ Address not supported \n");
            return "-1";
        }
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
            printf("\nConnection Failed \n");
            return "-1";
        }

        char temp_buff[500];

        if (strcpy(temp_buff, mensaje.c_str()) == NULL)
        {
            perror("strcpy");
            return "strcpy";
        }

        if (write(sock, temp_buff, strlen(temp_buff))==-1){
            perror("write");
            return "write";
        }
        memset(temp_buff, 0, sizeof(temp_buff));
        valread = read( sock , temp_buff, 1024);
        printf("%s\n",temp_buff );
        std::string textoRecibido = temp_buff;
        textoRecibido = procesarRespuesta(textoRecibido);
        memset(temp_buff, 0, sizeof(temp_buff));
        return textoRecibido;
    }
};
