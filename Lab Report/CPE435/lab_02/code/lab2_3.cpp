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
//    Description: Write a program, which creates n child processes and
//                 prints their process id. The n must be even number and
//                 passed as argument (either hard coded, or user input).
//                 Otherwise, if odd, a message indicates that the number
//                 is odd and terminates the program.
//
//                 Please make sure that your implementation has one
//                 parent process and n child processes.
//
// -------------------------------------------------------------------

int main(int argc, char * argv[])
{
	int n = 0;

	pid_t pid;

    // Read n from user input
	std::cout << "\nEnter an even number (odd will exit).\n" << std::endl;
	std::cin >> n;

	if (n%2==0) {
        // Even number entered for n
	    // Create n children
		for (int i = 0; i < n; i++)
		{
			pid = fork();

			if (pid == 0)
			{
			    // Child successfully created
			    // Print the child's process id
				std::cout << "\nThe child pid is: " << getpid() << "\n" << std::endl;

				// Terminate
				exit(0);
            } else if (pid < 0) {
                 // Child was not created, fork failed

                 std::cout << "\nUnable to create a child process\n" << std::endl;
            }
		}
	} else {
        // Odd number entered for n
	    // Warn the user that n was odd...
		std::cout << "\nWarning: The number you entered is odd. Exiting...\n" << std::endl;

		// Terminate
		exit(0);
	}

    return 0;
}
