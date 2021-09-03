//Coding Assignment #3
Your name: Yryskeldi Emilbek uulu
Question 1: Value of variable in child is 100. When both affest the same variable, variable's value is changed independently, so if parent changes it, child doesn't see the effect
Question 2: Yes, both can access the same descriptor returned by open(), and when they both write at the same time, then output will be random
Question 3: I used the sleep() function with an argument of 2 to avoid using the wait() function
Question 4: I think there's so many variants of the same call because though the main system call exec() replaces the current running process with a new process, the many variants allow us to change arguments for this process
Question 5: Wait() returns the child's process ID if it's inside the parent process definition. If it's inside the child process definition, then wait() returns -1.
Question 6: Whilst wait() doesn't allow to specify which exact process to wait for to finish, the waitpid() allows to specify which specific process to wait for
Question 7: When closing the descriptor, the output will not be printed by the child process
