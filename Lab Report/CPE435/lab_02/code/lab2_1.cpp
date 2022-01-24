#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

// -------------------------------------------------------------------
//
//    Lab:         02 - Processes
//    Due Date:    January 26th 2022
//
//    Author:      Elena Todorovska
//
//    Description: Write a program that does the following
//                 in the order given below:
//
//
//        1. Declare and initialize a variable
//           a. name: "val"
//           b. initial value: "0"
//        2. Call fork()
//        3. In the child process
//           a. Add "2" to the value of "val"
//           b. Print "val" to console, along with the pid of the child
//        4. In the parent process
//           a. Add "5" to the value of "val"
//           b. Print "val" to console, along with the pid of the parent
//
// -------------------------------------------------------------------

int main()
{
    // 1. Declare and initialize a variable
    int val = 0;

    pid_t pid;

    // 2. Call fork()
    pid = fork();

    if (pid == 0) {
        // Child successfully created

        // 3. In the child process
        // 3.a. Add "2" to the value of "val"
        val = val + 2;

        // 3.b. Print "val" to console, along with the pid of the child
        std::cout << "\nThe child pid is: " << getpid() << " Val is: " << val << "\n" << std::endl;

        // Terminate
        exit(0);
    } else if (pid < 0) {
         // Child was not created, fork failed

         std::cout << "\nUnable to create a child process\n" << std::endl;
    } else {
        // Parent process after fork succeeds

        // 4. In the parent process
        // 4.a. Add "5" to the value of "val"
        val = val + 5;

        // 4.b. Print "val" to console, along with the pid of the parent
        std::cout << "\nThe parent pid is: " << getpid() << " Val is: " << val << "\n" << std::endl;
    }

    return 0;
}
