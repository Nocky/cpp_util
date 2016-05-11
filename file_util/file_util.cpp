#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include "file_util/file_util.h"
#include "string_util/string_util.h"

using namespace std;
namespace Util {

bool FileUtil::Read(const string& filePath, string& content) {
    int fd = open(filePath.c_str(), O_RDONLY);
    // return value
    // -1: open file faile
    // 0~255: open file success
    content = "";
    if (fd == -1) {
        return false;
    }
    char buffer[1024*1024];
    while (read(fd, buffer, sizeof(buffer) > 0)) {
        content += string(buffer); 
    }
    content = StringUtil::Trim(content, '\n');
    // return value
    // 0: close success
    // other: close fail
    if (close(fd) != 0) {
        return false;
    }
    return true;
}

bool FileUtil::Read(const string& filePath, vector<string>& lineVec) {
    string content = "";
    lineVec.clear();
    if (!Read(filePath, content)) {
        return false;
    }
    return StringUtil::Split(content, lineVec, "\n");
}

} //namespace Util
