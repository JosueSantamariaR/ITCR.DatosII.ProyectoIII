/*
  * @file Server.cpp
  * */
#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <json/json.h>
#include <json/value.h>
#include <iostream>
#include <cassert>


#define consoleLog(message) std::cout<<message<<std::endl;

#define PORT 2508

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
 * Procesa el mensaje enviado desde el cliente y llama a los algoritmos según su contenido
 * @param mensaje El mensaje envido por el cliente
 * @return El resultado del algoritmo llamado
 */
std::string procesarMensaje(std::string mensaje) {
      Json::Value objetoJson = stringToJson(mensaje);
      std::string data = objetoJson.get("r", "ValueError").asString();

  }
/**
 * @brief Metodo principal para la comunicación de los sockets
 * @authors Ricardo&Yordi&Josue
 */
int main(){
    int server_fd = 0, connfd = 0;    //related with the server
    struct sockaddr_in address;
    int opt = 1;
    char* respuesta;

    //uint8_t buf[158], i;

    //memset(&buf, '0', sizeof(buf));
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    char buff[500];
    ssize_t r;

    while(true){
        connfd = accept(server_fd, (struct sockaddr*)NULL, NULL);
        r = read(connfd, buff, 500);
        if (r == -1)
        {
            perror("read");
            return EXIT_FAILURE;
        }
        else if (r == 0) {
            continue;
        }
        printf("READ: %s\n", buff);
        std::string texto = procesarMensaje(buff);
        respuesta= &texto[0];
        send(connfd , respuesta , strlen(respuesta) , 0 );
        memset(respuesta, 0, sizeof(respuesta));
        memset(buff, 0, sizeof(buff));
    }
}
