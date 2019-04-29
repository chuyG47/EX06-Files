//
// Created by aknight on 4/23/19.
//

#include "filereader.h"
#include <fstream>

namespace edu { namespace vcccd { namespace vc { namespace csv30 {
    FileReader::FileReader(const std::string &fileName) {
        // Put your code here
    }

    const std::vector<std::string> &FileReader::getLines() const {
        // Put your code here
    }

    size_t FileReader::getLineCount() const {
        // Put your code here
        return 0;
    }

    const std::string &FileReader::getLine(size_t line) const {
        // Put your code here
        return "";
    }

    void FileReader::deleteLine(size_t line) {
        // Put your code here
    }

    std::string FileReader::toUpperCaseLine(size_t lineNo) const {
        // Put your code here
        return "";
    }

    std::string FileReader::toLowerCaseLine(size_t lineNo) const {
        // Put your code here
        return "";
    }

    bool FileReader::operator==(const FileReader &rhs) {
        // Put your code here
        return true;
    }
}}}}

