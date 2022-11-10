#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define NUM_LENGTH 9
#define NUM_WAIT_INTERVAL 1

void getNUM(char num[NUM_LENGTH + 1]) {
	srand(getpid() + getppid());
	num[0] = 49 + rand() % 7;
	for(int i = 1; i < NUM_LENGTH; i++) {
	num[i] = 48 + rand() % 7; }
	num[NUM_LENGTH] = '\0'; }

int main(void) {

void sigint_handler(int sig);

while(1) {
	int pipefds[2];
	char num[NUM_LENGTH + 1];
	char buffer[NUM_LENGTH + 1];
	pipe(pipefds);
	pid_t pid = fork(); if(pid == 0) {
	getNUM(num); // render numbers
	close(pipefds[0]); // close read fd
	
	
	if (signal(SIGINT, sigint_handler)==SIG_ERR){
		perror("signal");
		exit(1);
	}
	
	write(pipefds[1], num, NUM_LENGTH + 1); 
	printf("Random Numbers in parent and delivering to child...\n");
	sleep(NUM_WAIT_INTERVAL); // delay
	exit(EXIT_SUCCESS); 
	}
	if(pid > 0) {
		wait(NULL); 
		close(pipefds[1]); 
		read(pipefds[0], buffer, NUM_LENGTH + 1); 
		close(pipefds[0]); 
		
		printf("Child obtains Numbers '%s' from parent.\n\n", buffer); } 
		}
return EXIT_SUCCESS; 

}

void sigint_handler(int sig) {
	printf("\n Operations Abort!");
}
