#include <iostream>
#include <fstream>
#include <stdint.h>
#include <assert.h>
#include "file_util.h"
#include "string_util.h"

using namespace std;
namespace Util {

bool FileUtil::Read(const string& filePath, string& content) {
    ifstream ifs(filePath.c_str());
    if (!ifs.is_open()) {
        return false;
    } 
    content = "";
    string line = "";
    while (getline(ifs, line)) {
        content = content + string(line) + "\n";
    }
    content = StringUtil::Trim(content, '\n'); 
    ifs.close();
    return true;
}

} //end namespace Util
