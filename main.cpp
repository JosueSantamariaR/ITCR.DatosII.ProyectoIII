#include "TECFS_Disk.h"

int main() {
    TECFS_Disk disco1 = TECFS_Disk("127.0.0.1", 8080, "../RAID5", 1000, 100, true);
    TECFS_Disk disco2 = TECFS_Disk("127.0.0.1", 8080, "../RAID5", 1000, 100);
}
