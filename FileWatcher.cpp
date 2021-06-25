#include "FileWatcher.h"

FileWatcher::FileWatcher(string path, chrono::duration<int, milli> delay) {
    this->path = path;
    this->delay = delay;
    this->running = true;

    for(auto &file : std::filesystem::recursive_directory_iterator(path)) {
        paths_[file.path().string()] = std::filesystem::last_write_time(file);
    }
}

void FileWatcher::watch() {
    cout<<"hola" <<endl;

    for(auto &file : std::filesystem::recursive_directory_iterator(path)) {
        auto lastWriteTime = std::filesystem::last_write_time(file);

        if (!paths_.contains(file.path().string())) {
            paths_[file.path().string()] = lastWriteTime;



            cout << "archivo creado" << endl;
        }

    }

    this_thread::sleep_for(delay);
    watch();
}