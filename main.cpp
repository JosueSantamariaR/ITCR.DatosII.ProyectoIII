#include "TECFS_Disk.h"
#include "FileWatcher.h"

int main() {
    TECFS_Disk disco1 = TECFS_Disk("127.0.0.1", 8080, "../RAID5", 1000, 100, true);
    TECFS_Disk disco2 = TECFS_Disk("127.0.0.1", 8080, "../RAID5", 1000, 100);
    TECFS_Disk disco3 = TECFS_Disk("127.0.0.1", 8080, "../RAID5", 1000, 100);
    TECFS_Disk disco4 = TECFS_Disk("127.0.0.1", 8080, "../RAID5", 1000, 100);
    TECFS_Disk disco5 = TECFS_Disk("127.0.0.1", 8080, "../RAID5", 1000, 100);
    TECFS_Disk disco6 = TECFS_Disk("127.0.0.1", 8080, "../RAID5", 1000, 100);

    FileWatcher fileWatcher = FileWatcher(disco1.getDiskPath(), chrono::milliseconds(1000));
    fileWatcher.watch();
}
