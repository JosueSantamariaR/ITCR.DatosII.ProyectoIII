#include <dirent.h>
#include "TECFS_Disk.h"

int TECFS_Disk::diskNumber = 0;

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

const string &TECFS_Disk::getIp() const {
    return IP;
}

const string &TECFS_Disk::getDiskPath() const {
    return diskPath;
}

int TECFS_Disk::getPort() const {
    return port;
}

int TECFS_Disk::getDiskSize() const {
    return diskSize;
}

int TECFS_Disk::getBlockSize() const {
    return blockSize;
}


