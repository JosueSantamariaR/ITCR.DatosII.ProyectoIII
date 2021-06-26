#pragma once

#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class FileWatcher {
private:
    string path;
    bool running;
    chrono::duration<int, milli> delay;
    unordered_map<std::string, std::filesystem::file_time_type> paths_;
public:
    /**
     * Crea una instancia de FileWatcher que escucha por modificaciones en un directorio
     * @param path Directorio en el que se escuchará por cambios
     * @param delay El tiempo entre cada comrpobación
     */
    FileWatcher(string path, chrono::duration<int, milli> delay);

    /**
     * Comienza a escuchar por cambios
     */
    void watch();
};
