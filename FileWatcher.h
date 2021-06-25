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
    FileWatcher(string path, chrono::duration<int, milli> delay);

    void watch();
};
