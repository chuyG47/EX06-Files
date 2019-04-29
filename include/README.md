## Exercise: Files (25 Points)

The project name of this exercise is **Files**.

The purpose of this assignment is for you to write code that reads data from a file. 

The first thing you will need to do is accept the invitation to this assignment
from GitHub Classroom. You can click [here](https://classroom.github.com/a/aKz-Pr13) to accept the invitation. 

Be sure that you accept the invitation first and use the URL from
the your new project when you clone it in Intellij.

### Problem Description

From our conversations in class, we have discussed how to use the `std::fstream` to read files. In this
assignment you'll apply that knowledge to the `FileReader` class.i

This class will read all the lines from a file, store each line in a vector, and then allow users of the class
to return individual lines as well as change their case or even delete them. In addition, this class will be able
to determine if two objects of the same class are equal. Two `FileReader` instances are equal if they contain the
same number of lines, and if each line contains the same characters.

In this assignment, you will implement the functionality mentioned above in `filereader.cc`. If you wish to see the declarations
for all the shapes used in this assignment, look in `filereader.h`.

### Getting Started

You only need to update the **filereader.cc** file for this assignment.
Where ever you see the comment `// Put your code here`, replace that comment with the appropriate code. 
  
##### filereader.h

**filereader.h** is provided for you and should require no changes.  

##### Implementation

Next you'll add your code to the implementation, separately from the declaration, in the **filereader.cc** file, which is provided.

Where ever you see the comment `// Put your code here`, replace it with your own code.

The following table describes each function, what it returns, what input parameters it takes and what the result
of calling the function should do. Make sure that your code follows this contract, as it will be tested in the
unit tests that your run to determine your score

| Method Name       | Return Type & meaning                              | Input Parameters        | What it does                                                   | 
|-------------------|----------------------------------------------------|-------------------------|----------------------------------------------------------------|
| `FileReader`      | N/A                                                | `std::string &filename` | Constructs an instance and reads lines from file `filename`    |
| `getLines`        | `vector<std::string> &` with each line of the file | None                    | Returns all the lines of the file in the order they were read. |
| `getLineCount`    | `size_t` with the number of lines in the file      | None                    | Returns the number of lines in the file                        |
| `getLine`         | `std::string` containing line indicated            | `size_t line`           | Returns a string at line `line`, where line numbers start at 0.|
| `deleteLine`      | None                                               | `size_t line`           | Deletes the line indicated by `line`                           |
| `toUpperCaseLine` | `std::string` containing line indicated            | `size_t line`           | Returns the indicated line with each character in upper case.  |
| `toLowerCaseLine` | `std::string` containing line indicated            | `size_t line`           | Returns the indicated line with each character in lower case.  |
| `operator ==`     | `bool` indicating equality of `FileReader`s        | `const FileReader &rhs` | Returns true if every line is equal, false otherwise.          |

Where you see `// Put your code here`, your are going to add your code to make the functions work as
needed. 
 
#### main()

If you want to test this code yourself, without using the unit tests, which I recommend for at least the first few projects, then you will need to create a `main()` function in a file named `main.cc` in the `src` directory. It is very important that you name it exactly this way, or things might not compile properly.

Again, in this project, a basic `main` is provided in **main.cc**

Your `main` function should look something like this:

```cpp
#include "filereader.h"

int main() {
  // Put your code here that creates a FileReaders instance and calls several of its methods.
  
  return 0;
}
```

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `Files | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It should look something like this:

```bash
/home/user/ex06-files/bin/Files
Lines in file: 5

Process finished with exit code 0
```
Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `Files_GTest` and press the 
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
/home/user/CSV30/EX06-Files/bin/Files_GTest
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from FilesTests
[ RUN      ] FilesTests.Basic
[       OK ] FilesTests.Basic (0 ms)
[ RUN      ] FilesTests.DeleteAndEqual
[       OK ] FilesTests.DeleteAndEqual (0 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 2 tests from FilesTests (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 2 tests.

Process finished with exit code 0
```

Remember, You should also see your score for this
assignment minus code styling points which I will add later.


### Submitting the code for this project
Before submitting your code the first time, you will need to add a webhook to this project to trigger 
the build in the cloud. This process is simple, and only required once per assignment. First, go to 
the **Settings** tab at the top of this page. It's right next to **Insights**. Then along the left 
side select **Webhooks**. On the Webhooks page click **Add Webhook** and copy http://209.129.49.16:8080/github-webhook/ 
into the **Payload URL** input box and then click **Add Webhook**. That's it. Now you can commit and 
push your code using the `Git` entry in the project menu. Every time you push code now, a new build 
will test your latest changes. The results are pasted to the #build channel in slack.
