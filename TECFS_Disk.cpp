/**
  * @file TECFS_Disk.cpp
  * */
#include <dirent.h>
#include "TECFS_Disk.h"

int TECFS_Disk::diskNumber = 0;

/**
 * @brief Constructor
 * @param string IP, int por, string path, int diskSize, int blockSize, bool isFirstDisk
 * @authors Ricardo&Yordi&Josue
 */
TECFS_Disk::TECFS_Disk(string IP, int port, string path, int diskSize, int blockSize, bool isFirstDisk) {
    this->IP = IP;
    this->port = port;
    this->diskPath = path;
    this->diskSize = diskSize;
    this->blockSize = blockSize;
    this->isFirstDisk = isFirstDisk;

    DIR* dir = opendir(diskPath.c_str());
    if (dir){
        closedir(dir);
    } else if (ENOENT == errno){
        filesystem::create_directory(diskPath);
    }

    initDisk();
}
/**
 * @brief Metodo para cuando es el primer disco
 * @authors Ricardo&Yordi&Josue
 */
void TECFS_Disk::initDisk() {
    string diskDirectory = diskPath + "/Disk";
    if (isFirstDisk){
        for (auto& path: filesystem::directory_iterator(diskPath)) {
            filesystem::remove_all(path.path());
        }
        TECFS_Disk::diskNumber = 1;
    }else {
        ++diskNumber;
    }

    diskDirectory = diskDirectory + "_" + to_string(diskNumber);
    filesystem::create_directory(diskDirectory);
}
/**
 * @brief Metodo para obtener IP
 * @return IP
 * @authors Ricardo&Yordi&Josue
 */
const string &TECFS_Disk::getIp() const {
    return IP;
}
/**
 * @brief Metodo para obtener diskPath
 * @return diskPath
 * @authors Ricardo&Yordi&Josue
 */
const string &TECFS_Disk::getDiskPath() const {
    return diskPath;
}
/**
 * @brief Metodo para obtener port
 * @return port
 * @authors Ricardo&Yordi&Josue
 */
int TECFS_Disk::getPort() const {
    return port;
}
/**
 * @brief Metodo para obtener diskSize
 * @return diskSize
 * @authors Ricardo&Yordi&Josue
 */
int TECFS_Disk::getDiskSize() const {
    return diskSize;
}
/**
 * @brief Metodo para obtener blockSize
 * @return blockSize
 * @authors Ricardo&Yordi&Josue
 */
int TECFS_Disk::getBlockSize() const {
    return blockSize;
}


