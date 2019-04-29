// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX05-String in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <random>
#include <fstream>

#include "filereader.h"

#include "gtest/gtest.h"
namespace {

    using edu::vcccd::vc::csv30::FileReader;

    using std::string;

    using namespace ::testing_internal;

    class FilesTests : public ::testing::Test {
    protected:
        static const uint64_t MAX_TESTED_SCORE = 20;
        static const uint64_t MAX_OVERALL_SCORE = 25;
        static uint64_t _testScore;

    protected:
        static void TearDownTestCase() {
            if (_testScore == MAX_TESTED_SCORE) {
                std::cout << std::endl << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << std::endl;
            } else {
                std::cout << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                          << ")" << std::endl;
            }

            std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                      << " where the remaining points" << std::endl;
            std::cout << "comes from grading related to documentation, algorithms, and other"
                      << std::endl;
            std::cout << "criteria." << std::endl << std::endl;
        }
    };

    uint64_t FilesTests::_testScore = 0;
    std::vector<std::string> _testLines = {"This is a file with text.",
                                           "This is the second line of text.",
                                           "This is yet another line of text.","Finally, the last line.",
                                           ""};

    std::vector<std::string> _testLinesLower = {"this is a file with text.",
                                                "this is the second line of text.",
                                                "this is yet another line of text.",
                                                "finally, the last line.",
                                                ""};

    std::vector<std::string> _testLinesUpper = {"THIS IS A FILE WITH TEXT.",
                                                "THIS IS THE SECOND LINE OF TEXT.",
                                                "THIS IS YET ANOTHER LINE OF TEXT.",
                                                "FINALLY, THE LAST LINE.",
                                                ""};

    TEST_F(FilesTests, Basic) {
        FileReader reader("../test.txt");
        ASSERT_EQ(5, reader.getLineCount());
        for (size_t i = 0; i < 5; i++) {
            ASSERT_EQ(_testLines[i], reader.getLines()[i]);
            ASSERT_EQ(_testLines[i], reader.getLine(i));
            ASSERT_EQ(_testLinesUpper[i], reader.toUpperCaseLine(i));
            ASSERT_EQ(_testLinesLower[i], reader.toLowerCaseLine(i));
        }
        _testScore += 15;
    }

    TEST_F(FilesTests, DeleteAndEqual) {
        FileReader reader1("../test.txt");
        FileReader reader2("../test.txt");
        ASSERT_TRUE(reader1 == reader2);

        reader2.deleteLine(2);
        ASSERT_EQ(4, reader2.getLineCount());

        ASSERT_FALSE(reader1 == reader2);

        _testScore += 5;
    }
}
