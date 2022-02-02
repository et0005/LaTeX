#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

// -------------------------------------------------------------------
//
//    Lab:         02 - Processes
//    Due Date:    January 26th 2022
//
//    Author:      Elena Todorovska
//
//    Description: Write a program that does the following in the order
//                 given below:
//
//        1. Create a new process, name: "child1"
//        2. The parent (of "child1") should print its pid and wait
//           for the termination of "child1"
//        3. The "child1" process should:
//           a. Call a function that subtracts two numbers passed in
//           b. Print the result of that operation to console, along
//              with the pid of the process that is printing
//           c. Create a new process, name: "child2"
//           d. Wait for "child2" to complete
//           e. Upon completion of "child2", call a function that
//              multiplies two numbers passed in as arguments
//           f. Print the result of that operation to console, along
//              with the pid of the process that is printing
//           g. Terminate
//        4. Meanwhile, the "child2" process should:
//           a. Call a function that adds two numbers passed in
//           b. Print the result of that operation to console, along
//              with the pid of the process that is printing
//           c. Terminate
//        5. The waiting parent process should resume, and terminate
//
// -------------------------------------------------------------------

void subtract(int a, int b)
{
    int difference = a - b;

    // 3.b. Print the result of that operation to console, along with the pid of the process that is printing
    std::cout << "\nSubtraction Result is: " << difference << ". Pid is: " << getpid() << "\n" << std::endl;
    //return difference;
}

void add(int a, int b)
{
    int sum = a + b;

    // 4.b. Print the result of that operation to console, along with the pid of the process that is printing
    std::cout << "\nAddition Result is: " << sum << ". Pid is: " << getpid() << "\n" << std::endl;
    //return sum;
}

void multiply(int a, int b)
{
    int mult = a * b;

    // 3.f. Print the result of that operation to console, along with the pid of the process that is printing
    std::cout << "\nMultiplication Result is: " << mult << ". Pid is: " << getpid() << "\n" << std::endl;
    //return mult;
}

int main()
{
    int a = 0;
    int b = 0;

    pid_t child1;
    pid_t child2;

    // Read a from user input
	std::cout << "\nEnter a number.\n" << std::endl;
	std::cin >> a;

    // Read b from user input
    std::cout << "\nEnter a number.\n" << std::endl;
    std::cin >> b;

    // 1. Create a new process, name: "child1"
    child1 = fork();

    if (child1 == 0) {
        // Child1 successfully created

        // 3.a. Call a function that subtracts two numbers passed in
        subtract(a, b);

        // 3.c. Create a new process, name: "child2"
        child2 = fork();

        if (child2 == 0) {
            // Child2 successfully created

            // 4.a. Call a function that adds two numbers passed in
            add(a, b);

            // 4.c. Terminate
            exit(0);
        } else if (child2 < 0) {
            // Child was not created, fork failed

            std::cout << "\nUnable to create a child process\n" << std::endl;
        } else {
            // Parent (Child1) process after fork succeeds

            // 3.d. Wait for child process
            waitpid(-1, &child2, 0);

            // 3.e. Upon completion of "child2", call a function that multiplies two numbers passed in
            multiply(a, b);

            // 3.g. Terminate
            exit(0);
        }
    } else if (child1 < 0) {
         // Child was not created, fork failed

         std::cout << "\nUnable to create a child process\n" << std::endl;
    } else {
        // Parent process after fork succeeds

        // 2. The parent (of "child1") should print its pid and wait for the termination of "child1"
        std::cout << "\nThe parent pid is: " << getpid() << "\n" << std::endl;

        // Wait for child process
        waitpid(-1, &child1, 0);

        // 5. Terminate
        exit(0);
    }

    return 0;
}
