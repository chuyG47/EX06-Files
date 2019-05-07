//
// Created by aknight on 4/23/19.
//

#include "filereader.h"
#include <fstream>

namespace edu { namespace vcccd { namespace vc { namespace csv30 {
    FileReader::FileReader(const std::string &fileName) {

        std::ifstream fin(fileName);

        while (!fin.eof()) {
            std::string line;
            std::getline(fin, line);
            _lines.push_back(line);
        }
    }

    const std::vector<std::string> &FileReader::getLines() const {
        return _lines;
    }

    size_t FileReader::getLineCount() const {
        return _lines.size();
    }

    const std::string &FileReader::getLine(size_t line) const {
        return _lines[line];
    }

    void FileReader::deleteLine(size_t line) {
       _lines.erase( _lines.begin ()+line);
    }

    std::string FileReader::toUpperCaseLine(size_t lineNo) const {
        auto l = _lines[lineNo];
        for (char &c : l) {
            c = toupper(c);

        }
        return l;
    }

    std::string FileReader::toLowerCaseLine(size_t lineNo) const {
        auto l = _lines[lineNo];
        for (char &c : l) {
            c = tolower(c);

        }
         return l;
    }

    bool FileReader::operator==(const FileReader &rhs) {
        if (getLineCount() != rhs.getLineCount()) {
            return false;
        }
        for (int i = 0; i < getLineCount(); i++) {
            if (getLine(i) != rhs.getLine(i)) {
                return false;
            }

            return true;
        }
    }
}}}}
