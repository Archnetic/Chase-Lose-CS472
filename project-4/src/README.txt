Chase Lose
Project 4
Dr. Chen
Operating systems Readme

1. I made 2 new system calls were made to set tickets and getpinfo.

2. I needed to initialize the ticks, tickets, and pid
3. int setticket(int number)
		This will set the number of tickets per process. If the number of tickets is not defined the process will get one ticket.
		 will return 0 or 1 based on pass or fail

4. int getpinfo(struct pstat *)
		this gets the pid of each process
		will return 0 or 1 based on pass or fail)

5. any time the process forks it the new process should have the same amount of tickets as its parent

6. Needed to use the rand function to generate an random unsigned number.


