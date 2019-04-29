//
// Created by aknight on 4/23/19.
//

#include <string>
#include <vector>

#ifndef EX06_FILES_FILEREADER_H
#define EX06_FILES_FILEREADER_H
namespace edu { namespace vcccd { namespace vc { namespace csv30 {

class FileReader {
    std::vector<std::string> _lines;

public:
    FileReader(const std::string &fileName);

    const std::vector<std::string> &getLines() const;
    size_t getLineCount() const;
    const std::string &getLine(size_t line) const;
    void deleteLine(size_t line);
    std::string toUpperCaseLine(size_t line) const;
    std::string toLowerCaseLine(size_t line) const;

    bool operator==(const FileReader &rhs);
};

}}}}
#endif //EX06_FILES_FILEREADER_H
