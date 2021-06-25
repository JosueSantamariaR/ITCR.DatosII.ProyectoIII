#pragma once

#include <string>
#include <iostream>
#include <filesystem>

using namespace std;
class TECFS_Disk {
private:
    string IP;
    string diskPath;
    int port;
    int diskSize;
    int blockSize;
    bool isFirstDisk;
    static int diskNumber;

    void initDisk();
public:
    TECFS_Disk(string IP, int port, string path, int diskSize, int blockSize, bool isFirstDisk = false);

    const string &getIp() const;

    const string &getDiskPath() const;

    int getPort() const;

    int getDiskSize() const;

    int getBlockSize() const;
};