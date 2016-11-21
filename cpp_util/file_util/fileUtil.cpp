#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cpp_util/log/log.h"
#include "cpp_util/string_util/stringUtil.h"
#include "cpp_util/common/common.h"
#include "fileUtil.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

#define BUFFER_SIZE 1024

bool FileUtil::Read(const string& filePath, string& content) {
    FILE* pFile;
    pFile = fopen(filePath.c_str(), "r");
    if (NULL == pFile) {
        LOG_ERROR("[fopen] file:[%s] return NULL FILE", filePath.c_str());
        return false;
    }

    // obtain file size:
    fseek(pFile, 0, SEEK_END);
    size_t fileSize = ftell(pFile);
    rewind(pFile);

    // allocate memory to contain the whole file:
    char* buffer = (char*)malloc(sizeof(char) * fileSize);
    memset(buffer, '\0', sizeof(buffer));
    if (NULL == buffer) {
        LOG_ERROR("malloc size:[%u] return NULL", fileSize);
        return false;
    }

    // copy the file into the buffer:
    size_t readSize = fread(buffer, 1, fileSize, pFile);
    if (readSize != fileSize) {
        LOG_ERROR("read file readSize:[%u] not equal fileSize:[%u]", readSize, fileSize);
        return false;
    }
    content = string(buffer, readSize);
    fclose(pFile);
    free(buffer);
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

bool FileUtil::Write(const string& filePath, const string& content, bool append) {
    FILE* pFile;
    string readMode = "w";
    if (append) {
        readMode = "a"; 
    }
    pFile = fopen(filePath.c_str(), readMode.c_str());
    if (NULL == pFile) {
        LOG_ERROR("[fopen] file:[%s] return NULL FILE", filePath.c_str());
        return false;
    }
    const char* ptr = content.c_str();
    fwrite(ptr, 1, strlen(ptr), pFile);
    fclose(pFile);
    return true;
}

NAMESPACE_END(Util)
