#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
using namespace std;

// -------------------------------------------------------------------
//
//    Lab:         02 - Processes
//    Due Date:    January 26th 2022
//
//    Author:      Elena Todorovska
//
//    Description: Write a program that demonstrates these concepts:
//
//        1. Orphan Process
//        2. Zombie Process
//        3. Sleeping Beauty Process
//
// -------------------------------------------------------------------

int main()
{
    pid_t zombie;
    pid_t orphan;

    zombie = fork();
    if (zombie > 0) {
        // Parent process
        // Wait, NOT for the child to finish
        sleep(50);
    } else if (zombie < 0) {
        // Child was not created, fork failed
        std::cout << "\nUnable to create a child process\n" << std::endl;
    } else {
        // Child successfully created
        // Terminate
        exit(0);
    }

    orphan = fork();
    if (orphan > 0) {
        // Parent process
        std::cout << "\nParent process\n" << std::endl;
    } else if (orphan < 0) {
        // Child was not created, fork failed
        std::cout << "\nUnable to create a child process\n" << std::endl;
    } else {
        // Child successfully created
        std::cout << "\nChild process\n" << std::endl;
        // Wait
        sleep(30);
    }

    return 0;
}
