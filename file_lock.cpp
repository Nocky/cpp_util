#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <file_lock.h>

using namespace std;
namespace Util {

FileLock::FileLock(const string& fileName) 
    :mFd(-1) {
    assert(fileName != "");
    // open file
    // success -> return file descriptor
    // fail -> return -1
    mFd = open(fileName.c_str(), O_RDWR | O_CREAT, 0644);
    assert(mFd != -1);
}

FileLock::~FileLock() {
    // close file descriptor
    // success -> return 0
    // fail -> return -1
    assert(close(mFd) == 0);
}

bool FileLock::LUnock(bool lock, string& errorMessage) {
    assert(mFd != -1);
    errno = 0;
    struct flock f;
    memset(&f, 0, sizeof(f));
    // lock: true -> file write lock, F_WRLCK
    // lock: false -> delete file lock, F_UNLCK
    f.l_type = (lock ? F_WRLCK : F_UNLCK);
    // lock whole file
    f.l_whence = SEEK_SET;
    f.l_start = 0;
    f.l_len = 0;
    int ret = fcntl(mFd, F_SETLK, &f);
    if (ret == -1) {
        errorMessage = strerror(errno);
        return false;
    }
    return true;
}

bool FileLock::Lock(string& errorMessage) {
    return LUnock(true, errorMessage);
}

bool FileLock::UnLock(string& errorMessage) {
    return LUnock(false, errorMessage);
}

}// end Util namespace
