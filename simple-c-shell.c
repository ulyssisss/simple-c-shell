/*
  * simple-c-shell.c
  * 
  * Copyright (c) 2013 Juan Manuel Reyes
  * 
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  * 
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  * 
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>
#include "util.h"

#define LIMIT 256 // max number of tokens for a command
#define MAXLINE 1024 // max number of characters from user input

/**
 * Function used to initialize our shell. We used the approach explained in
 * http://www.gnu.org/software/libc/manual/html_node/Initializing-the-Shell.html
 */
void multitext(void) {
	int i, x;
	printf("How many text files do you want to create? : ");
	scanf("%d", &x);
	for (i = 1; i <= x; i++) {
		char filename[15];
		sprintf(filename, "text%d", i);
		strcat(filename, ".txt");
		int fd = open(filename, O_RDWR | O_CREAT, 0700);

		if (fd == -1) {
			perror("open() fail");
		}
		else {
			lseek(fd, 0, SEEK_SET);
			close(fd);
		}
	}
}


void calculate(void) {
	double num1 = 0;
	double num2 = 0;
	double value = 0;
	char a = 0;

	printf("Please enter the formula : ");
	scanf("%lf %c %lf", &num1, &a, &num2);

	switch (a) {  //Set case according to the value of char a
	case '+': //If the value of char a is +, + operation is performed.
		value = num1 + num2;
		printf("%lf %c %lf = %lf", num1, a, num2, value);
		break;
	case '-': //If the value of char a is -, - operation is performed.
		value = num1 - num2;
		printf("%lf %c %lf = %lf", num1, a, num2, value);
		break;
	case '*':  //If the value of char a is *, * operation is performed.
		value = num1 * num2;
		printf("%lf %c %lf = %lf", num1, a, num2, value);
		break;
	case '/':  //If the value of char a is /, / operation is performed.
		printf("%lf/%lf = %lf", num1, num2, (double)num1 / num2);
		break;
	default:
		printf("Cannot be calculated");
		break;
	}
	printf("\n");
}

void rockgame(void)
{
	int user, com;
	srand((int)time(NULL));

	com = rand() % 3;
	printf(" Please select one of the three options.\n1.Scissors\n2.Rock\n3.Paper\n");
	scanf("%d", &user);

	if (user == 1)
	{
		if (com == 1)
		{
			printf("Computer: Scissors\nUser: Scissors\nDraw.\n");
		}
		else if (com == 2)
		{
			printf("Computer: Rock\nUser: Scissors\nLose.\n");
		}
		else
		{
			printf("Computer: Paper\nUser: Scissors\nWin.\n");
		}
	}

	if (user == 2)
	{
		if (com == 1)
		{
			printf("Computer: Scissors\nUser: Rock\nWin.\n");
		}
		else if (com == 2)
		{
			printf("Computer: Rock\nUser: Rock\nDraw.\n");
		}
		else
		{
			printf("Computer: Paper\nUser: Rock\nLose.\n");
		}
	}

	if (user == 3)
	{
		if (com == 1)
		{
			printf("Computer: Scissors\nUsers: Paper\nLose\n");
		}
		else if (com == 2)
		{
			printf("Computer: Rock\nUser: Paper\nWin.\n");
		}
		else
		{
			printf("Computer: Paper\nUser: Paper\nDraw\n");
		}
	}
}


// current time
void nowtime(void)
{
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	printf("Greenwich Mean Time : %d hour %d minute\n", time_->tm_hour, time_->tm_min);
}

//Seoul/Tokyo Time
void repubkor(void)
{
	int repubkor;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	repubkor = time_->tm_hour + 9; //Seoul/Tokyo Time
	if (repubkor > 24)//If more than 24
		repubkor -= 9;//Parallax application
	printf("Seoul/Tokyo Current Time : %d hour %d minute\n", repubkor, time_->tm_min);
}

//Canada time
void canada(void)
{
	int canada;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	canada = time_->tm_hour - 5; //Canada time
	if (canada < 0)//If less than 0 
		canada += 5;//Parallax application
	printf("Canada Current Time : %d hour %d minute\n", canada, time_->tm_min);
}

//New york time
void newyork(void)
{
	int newyork;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	newyork = time_->tm_hour - 5; //New york time
	if (newyork < 0)//If less than 0 
		newyork += 5;//Parallax application
	printf("New York Current Time : %d hour %d minute\n", newyork, time_->tm_min);
}

//Los Angeles Time
void ros(void)
{
	int ros;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	ros = time_->tm_hour - 8; //Los Angeles Time
	if (ros < 0)//If less than 0 
		ros += 8;//Parallax application
	printf("Los Angeles Current Time : %d hour %d minute\n", ros, time_->tm_min);
}

//Sydney current time
void sydney(void)
{
	int sydney;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	sydney = time_->tm_hour + 11; //Sydney current time
	if (sydney > 24)//If more than 24
		sydney -= 11;//Parallax application
	printf("Sydney Current Time : %d hour %d minute\n", sydney, time_->tm_min);
}

//Hong Kong Current Time
void hongkong(void)
{
	int hongkong;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	hongkong = time_->tm_hour + 8; //Hong Kong Current Time
	if (hongkong > 24)//If more than 24
		hongkong -= 8;//Parallax application
	printf("Hong Kong Current Time : %d hour %d minute\n", hongkong, time_->tm_min);
}

//Shanghai current time
void china(void)
{
	int china;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	china = time_->tm_hour + 8; //Shanghai current time
	if (china > 24)//If more than 24
		china -= 8;//Parallax application
	printf("Shanghai Current Time : %d hour %d minute\n", china, time_->tm_min);
}

//Taiwan current time
void taiwan(void)
{
	int taiwan;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	taiwan = time_->tm_hour + 8; //Taiwan current time
	if (taiwan > 24)//If more than 24
		taiwan -= 8;//Parallax application
	printf("Taiwan current time : %d hour %d minute\n", taiwan, time_->tm_min);
}

//Bangkok current time
void bangkok(void)
{
	int bangkok;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	bangkok = time_->tm_hour + 7; //Bangkok current time
	if (bangkok > 24)//If more than 24
		bangkok -= 7;//Parallax application
	printf("Bangkok Current Time : %d hour %d minute\n", bangkok, time_->tm_min);
}

//Paris current time
void paris(void)
{
	int paris;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	paris = time_->tm_hour + 1; //Paris current time
	if (paris > 24)//If more than 24
		paris -= 1;//Parallax application
	printf("Paris current time : %d hour %d minute\n", paris, time_->tm_min);
}

void init(){
		// See if we are running interactively
        GBSH_PID = getpid();
        // The shell is interactive if STDIN is the terminal  
        GBSH_IS_INTERACTIVE = isatty(STDIN_FILENO);  

		if (GBSH_IS_INTERACTIVE) {
			// Loop until we are in the foreground
			while (tcgetpgrp(STDIN_FILENO) != (GBSH_PGID = getpgrp()))
					kill(GBSH_PID, SIGTTIN);             
	              
	              
	        // Set the signal handlers for SIGCHILD and SIGINT
			act_child.sa_handler = signalHandler_child;
			act_int.sa_handler = signalHandler_int;			
			
			/**The sigaction structure is defined as something like
			
			struct sigaction {
				void (*sa_handler)(int);
				void (*sa_sigaction)(int, siginfo_t *, void *);
				sigset_t sa_mask;
				int sa_flags;
				void (*sa_restorer)(void);
				
			}*/
			
			sigaction(SIGCHLD, &act_child, 0);
			sigaction(SIGINT, &act_int, 0);
			
			// Put ourselves in our own process group
			setpgid(GBSH_PID, GBSH_PID); // we make the shell process the new process group leader
			GBSH_PGID = getpgrp();
			if (GBSH_PID != GBSH_PGID) {
					printf("Error, the shell is not process group leader");
					exit(EXIT_FAILURE);
			}
			// Grab control of the terminal
			tcsetpgrp(STDIN_FILENO, GBSH_PGID);  
			
			// Save default terminal attributes for shell
			tcgetattr(STDIN_FILENO, &GBSH_TMODES);

			// Get the current directory that will be used in different methods
			currentDirectory = (char*) calloc(1024, sizeof(char));
        } else {
                printf("Could not make the shell interactive.\n");
                exit(EXIT_FAILURE);
        }
}

/**
 * Method used to print the welcome screen of our shell
 */
void welcomeScreen() {
	printf("\n\t============================================\n");
	printf("\t               Simple C Shell\n");
	printf("\t--------------------------------------------\n");
	printf("\t             Licensed under GPLv3:\n");
	printf("\t============================================\n");
	printf("\n\n");
	printf("\t               Function of this program\n");
	printf("\t============================================\n");
	printf("\t                     If you write\n");
	printf("\t        ""\x1b[36m""out""\x1b[0m""  = can get out this shell program\n");
	printf("\t        ""\x1b[36m""clear""\x1b[0m""  = can clear interface\n");
	printf("\t        ""\x1b[36m""color""\x1b[0m""  = can change shell prompt color\n");
	printf("\t        ""\x1b[36m""currentdirectory""\x1b[0m""  = can see current directory\n");
	printf("\t        ""\x1b[36m""changedirectory""\x1b[0m""  = can change directory\n");
	printf("\t        ""\x1b[36m""create""\x1b[0m""  = can make a new file\n");
	printf("\t        ""\x1b[36m""input""\x1b[0m""  = can put some strings in your file\n");
	printf("\t        ""\x1b[36m""check""\x1b[0m""  = can check the contents inside\n");
	printf("\t        ""\x1b[36m""delete""\x1b[0m""  = can delete file\n");
	printf("\t        ""\x1b[36m""calculate""\x1b[0m""  = can calculate formula\n");
	printf("\t        ""\x1b[36m""rockgame""\x1b[0m""  = can play Rock Scissor Paper game\n");
	printf("\t        ""\x1b[36m""multitext""\x1b[0m""  = Create multiple text files at once\n");
	printf("\t        ""\x1b[36m""worldtime""\x1b[0m""  = can see world timeline\n");
	printf("\t        ""\x1b[36m""quicktime""\x1b[0m""  = can check time quickly\n");
	printf("\t        ""\x1b[36m""quickslot""\x1b[0m""  = can check shortcut key\n");
	printf("\t        ""\x1b[36m""timer""\x1b[0m""  = can run the timer\n\n");
	printf("\t        If you want to check these details once again, enter ""\x1b[36m""manual""\x1b[0m""\n\n");
}

/**
 * SIGNAL HANDLERS
 */

/**
 * signal handler for SIGCHLD
 */
void signalHandler_child(int p){
	/* Wait for all dead processes.
	 * We use a non-blocking call (WNOHANG) to be sure this signal handler will not
	 * block if a child was cleaned up in another part of the program. */
	while (waitpid(-1, NULL, WNOHANG) > 0) {
	}
	printf("\n");
}

/**
 * Signal handler for SIGINT
 */
void signalHandler_int(int p){
	// We send a SIGTERM signal to the child process
	if (kill(pid,SIGTERM) == 0){
		printf("\nProcess %d received a SIGINT signal\n",pid);
		no_reprint_prmpt = 1;			
	}else{
		printf("\n");
	}
}

/**
 *	Displays the prompt for the shell
 */
void shellPrompt(){
	// We print the prompt in the form "<user>@<host> <cwd> >"
	char hostn[1204] = "";
	gethostname(hostn, sizeof(hostn));
	printf("%s@%s %s > ", getenv("LOGNAME"), hostn, getcwd(currentDirectory, 1024));
}

/**
 * Method to change directory
 */
int changeDirectory(char* args[]){
	// If we write no path (only 'changedirectory'), then go to the home directory
	if (args[1] == NULL) {
		chdir(getenv("HOME")); 
		return 1;
	}
	// Else we change the directory to the one specified by the 
	// argument, if possible
	else{ 
		if (chdir(args[1]) == -1) {
			printf(" %s: no such directory\n", args[1]);
            return -1;
		}
	}
	return 0;
}

/**
 * Method used to manage the environment variables with different
 * options
 */ 
int manageEnviron(char * args[], int option){
	char **env_aux;
	switch(option){
		// Case 'environ': we print the environment variables along with
		// their values
		case 0: 
			for(env_aux = environ; *env_aux != 0; env_aux ++){
				printf("%s\n", *env_aux);
			}
			break;
		// Case 'setenv': we set an environment variable to a value
		case 1: 
			if((args[1] == NULL) && args[2] == NULL){
				printf("%s","Not enought input arguments\n");
				return -1;
			}
			
			// We use different output for new and overwritten variables
			if(getenv(args[1]) != NULL){
				printf("%s", "The variable has been overwritten\n");
			}else{
				printf("%s", "The variable has been created\n");
			}
			
			// If we specify no value for the variable, we set it to ""
			if (args[2] == NULL){
				setenv(args[1], "", 1);
			// We set the variable to the given value
			}else{
				setenv(args[1], args[2], 1);
			}
			break;
		// Case 'unsetenv': we delete an environment variable
		case 2:
			if(args[1] == NULL){
				printf("%s","Not enought input arguments\n");
				return -1;
			}
			if(getenv(args[1]) != NULL){
				unsetenv(args[1]);
				printf("%s", "The variable has been erased\n");
			}else{
				printf("%s", "The variable does not exist\n");
			}
		break;
			
			
	}
	return 0;
}
/**
* Method for launching a program. It can be run in the background
* or in the foreground
*/ 
void launchProg(char **args, int background){	 
	 int err = -1;
	 
	 if((pid=fork())==-1){
		 printf("Child process could not be created\n");
		 return;
	 }
	 // pid == 0 implies the following code is related to the child process
	if(pid==0){
		// We set the child to ignore SIGINT signals (we want the parent
		// process to handle them with signalHandler_int)	
		signal(SIGINT, SIG_IGN);
		
		// We set parent=<pathname>/simple-c-shell as an environment variable
		// for the child
		setenv("parent",getcwd(currentDirectory, 1024),1);	
		
		// If we launch non-existing commands we end the process
		if (execvp(args[0],args)==err){
			printf("Command not found");
			kill(getpid(),SIGTERM);
		}
	 }
	 
	 // The following will be executed by the parent
	 
	 // If the process is not requested to be in background, we wait for
	 // the child to finish.
	 if (background == 0){
		 waitpid(pid,NULL,0);
	 }else{
		 // In order to create a background process, the current process
		 // should just skip the call to wait. The SIGCHILD handler
		 // signalHandler_child will take care of the returning values
		 // of the childs.
		 printf("Process created with PID: %d\n",pid);
	 }	 
}
 
/**
* Method used to manage I/O redirection
*/ 
void fileIO(char * args[], char* inputFile, char* outputFile, int option){
	 
	int err = -1;
	
	int fileDescriptor; // between 0 and 19, describing the output or input file
	
	if((pid=fork())==-1){
		printf("Child process could not be created\n");
		return;
	}
	if(pid==0){
		// Option 0: output redirection
		if (option == 0){
			// We open (create) the file truncating it at 0, for write only
			fileDescriptor = open(outputFile, O_CREAT | O_TRUNC | O_WRONLY, 0600); 
			// We replace de standard output with the appropriate file
			dup2(fileDescriptor, STDOUT_FILENO); 
			close(fileDescriptor);
		// Option 1: input and output redirection
		}else if (option == 1){
			// We open file for read only (it's STDIN)
			fileDescriptor = open(inputFile, O_RDONLY, 0600);  
			// We replace de standard input with the appropriate file
			dup2(fileDescriptor, STDIN_FILENO);
			close(fileDescriptor);
			// Same as before for the output file
			fileDescriptor = open(outputFile, O_CREAT | O_TRUNC | O_WRONLY, 0600);
			dup2(fileDescriptor, STDOUT_FILENO);
			close(fileDescriptor);		 
		}
		 
		setenv("parent",getcwd(currentDirectory, 1024),1);
		
		if (execvp(args[0],args)==err){
			printf("err");
			kill(getpid(),SIGTERM);
		}		 
	}
	waitpid(pid,NULL,0);
}

/**
* Method used to manage pipes.
*/ 
void pipeHandler(char * args[]){
	// File descriptors
	int filedes[2]; // pos. 0 output, pos. 1 input of the pipe
	int filedes2[2];
	
	int num_cmds = 0;
	
	char *command[256];
	
	pid_t pid;
	
	int err = -1;
	int end = 0;
	
	// Variables used for the different loops
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	
	// First we calculate the number of commands (they are separated
	// by '|')
	while (args[l] != NULL){
		if (strcmp(args[l],"|") == 0){
			num_cmds++;
		}
		l++;
	}
	num_cmds++;
	
	// Main loop of this method. For each command between '|', the
	// pipes will be configured and standard input and/or output will
	// be replaced. Then it will be executed
	while (args[j] != NULL && end != 1){
		k = 0;
		// We use an auxiliary array of pointers to store the command
		// that will be executed on each iteration
		while (strcmp(args[j],"|") != 0){
			command[k] = args[j];
			j++;	
			if (args[j] == NULL){
				// 'end' variable used to keep the program from entering
				// again in the loop when no more arguments are found
				end = 1;
				k++;
				break;
			}
			k++;
		}
		// Last position of the command will be NULL to indicate that
		// it is its end when we pass it to the exec function
		command[k] = NULL;
		j++;		
		
		// Depending on whether we are in an iteration or another, we
		// will set different descriptors for the pipes inputs and
		// output. This way, a pipe will be shared between each two
		// iterations, enabling us to connect the inputs and outputs of
		// the two different commands.
		if (i % 2 != 0){
			pipe(filedes); // for odd i
		}else{
			pipe(filedes2); // for even i
		}
		
		pid=fork();
		
		if(pid==-1){			
			if (i != num_cmds - 1){
				if (i % 2 != 0){
					close(filedes[1]); // for odd i
				}else{
					close(filedes2[1]); // for even i
				} 
			}			
			printf("Child process could not be created\n");
			return;
		}
		if(pid==0){
			// If we are in the first command
			if (i == 0){
				dup2(filedes2[1], STDOUT_FILENO);
			}
			// If we are in the last command, depending on whether it
			// is placed in an odd or even position, we will replace
			// the standard input for one pipe or another. The standard
			// output will be untouched because we want to see the 
			// output in the terminal
			else if (i == num_cmds - 1){
				if (num_cmds % 2 != 0){ // for odd number of commands
					dup2(filedes[0],STDIN_FILENO);
				}else{ // for even number of commands
					dup2(filedes2[0],STDIN_FILENO);
				}
			// If we are in a command that is in the middle, we will
			// have to use two pipes, one for input and another for
			// output. The position is also important in order to choose
			// which file descriptor corresponds to each input/output
			}else{ // for odd i
				if (i % 2 != 0){
					dup2(filedes2[0],STDIN_FILENO); 
					dup2(filedes[1],STDOUT_FILENO);
				}else{ // for even i
					dup2(filedes[0],STDIN_FILENO); 
					dup2(filedes2[1],STDOUT_FILENO);					
				} 
			}
			
			if (execvp(command[0],command)==err){
				kill(getpid(),SIGTERM);
			}		
		}
				
		// CLOSING DESCRIPTORS ON PARENT
		if (i == 0){
			close(filedes2[1]);
		}
		else if (i == num_cmds - 1){
			if (num_cmds % 2 != 0){					
				close(filedes[0]);
			}else{					
				close(filedes2[0]);
			}
		}else{
			if (i % 2 != 0){					
				close(filedes2[0]);
				close(filedes[1]);
			}else{					
				close(filedes[0]);
				close(filedes2[1]);
			}
		}
				
		waitpid(pid,NULL,0);
				
		i++;	
	}
}
			
/**
* Method used to handle the commands entered via the standard input
*/ 
int commandHandler(char* args[]) {
	int i = 0;
	int j = 0;

	int fileDescriptor;
	int standardOut;

	int aux;
	int background = 0;

	char* args_aux[256];

	// We look for the special characters and separate the command itself
	// in a new array for the arguments
	while (args[j] != NULL) {
		if ((strcmp(args[j], ">") == 0) || (strcmp(args[j], "<") == 0) || (strcmp(args[j], "&") == 0)) {
			break;
		}
		args_aux[j] = args[j];
		j++;
	}

	// 'out' command quits the shell
	if (strcmp(args[0], "out") == 0 || strcmp(args[0], "o") == 0)
		exit(0);

	// 'currentdirectory' command prints the current directory
	else if (strcmp(args[0], "currentdirectory") == 0 || strcmp(args[0], "curd") == 0 || strcmp(args[0], "currentd") == 0)
	{
		if (args[j] != NULL) {
			// If we want file output
			if ((strcmp(args[j], ">") == 0) && (args[j + 1] != NULL)) {
				fileDescriptor = open(args[j + 1], O_CREAT | O_TRUNC | O_WRONLY, 0600);
				// We replace de standard output with the appropriate file
				standardOut = dup(STDOUT_FILENO); 	// first we make a copy of stdout
													// because we'll want it back
				dup2(fileDescriptor, STDOUT_FILENO);
				close(fileDescriptor);
				printf("%s\n", getcwd(currentDirectory, 1024));
				dup2(standardOut, STDOUT_FILENO);
			}
		}
		else {
			printf("%s\n", getcwd(currentDirectory, 1024));
		}
	}

	// 'clear' command clean prompt screen
	else if (strcmp(args[0], "clear") == 0 || strcmp(args[0], "cl") == 0 || strcmp(args[0], "0") == 0)
		system("clear");

	// 'create' command to create file
	else if (strcmp(args[0], "create") ==0 || strcmp(args[0], "cr") == 0 || strcmp(args[0], "1") == 0)
	{
		char s1[20];
			int choose;
			printf("\nstart writing.\n");
			printf("write your title\n\n");
			scanf("%s", &s1);
			printf("\nis it %s?\n\n", s1);
			printf("if you want, press 1\n");
			printf("or not, press 2 to stop\n\n");
			scanf("%d", &choose);
			printf("\n");
		if (choose == 1)
		{
			printf("create start\n");
			FILE* fp = fopen(s1, "wt");
			if (fp = NULL)
			{
				puts("there is no file.\n");
				return -1;
			}
			else
				puts("file has been created.\n");
			return 0;;
		}
		else if (choose == 2)
			printf("create fail\n");

	}

	//'input' command to insert some contents into file
	else if (strcmp(args[0], "input") == 0 || strcmp(args[0], "inp") == 0 || strcmp(args[0], "2") == 0)
	{
		char s1[20];
		char s2[100];
		int choose;
		printf("\nstart writing.\n");
		printf("write your title\n\n");
		scanf("%s", s1);
		printf("\nyou will write in %s\n\n", s1);
		FILE* fp = fopen(s1, "w+");
		printf("please start writing: ");
		while (1)
		{
			scanf(" %[^\n]", s2);
			printf("\nyou write\n\n");
			printf("%s\n\n", s2);
			printf("If it's right, press 1\n");
			printf("Or, if it's wrong, press 2\n\n");
			scanf("%d", &choose);
			if (choose == 1)
			{
				printf("\nSave the file\n");
				fputs(s2, fp);
				fclose(fp);
				break;
			}
			else if (choose == 2)
			{
				printf("Please rewrite it\n");
				printf("Start: ");
			}
		}
		printf("close input function\n\n");
	}

	//'timer' command run the timer.
	else if (strcmp(args[0], "timer") == 0)
	{
		int sec;
		int min;
		int real_min;
		int stop=0;
		int cycle;
		int sum=0;
		int j = 1;
		int choose;
		printf("Start timer\n");
		printf("How many seconds are you going to set up? (Please enter in seconds)\n");
		scanf("%d", &sec);
		printf("How long are you going to run it?\n\n");
		printf("If you want sec time, press 1\n");
		printf("If you want min time, press 2\n");
		scanf("%d", &choose);
		if (choose == 1)
		{
			printf("put some sec what you want\n");
			scanf("%d", &min);
			printf("\nThis timer outputs the contents in %d seconds intervals for %d sec.\n", sec, min);

		}
		if (choose == 2)
		{
			printf("put some min what you want\n");
			scanf("%d", &min);
			printf("\nThis timer outputs the contents in %d seconds intervals for %d minutes.\n", sec, min);
			min = min * 60;
		}
		cycle = min / sec;
		while (cycle != j)
		{
			sleep(sec);
			sum = sum+sec;
			printf("%d second has been passed\n", sum);
			j++;
		}
		printf("The timer is terminated.\n");
		printf("A total of %d sec have passed.\n", min);
		printf("error range +- %d sec\n\n", sec);
		printf("It has been printed out a total of %d times.\n", j);
	}

	//'check' command can check the contents inside
	else if (strcmp(args[0], "check") == 0 || strcmp(args[0], "che") == 0 || strcmp(args[0], "3") == 0)
	{
		char s1[30];
		char buffer[30];
		FILE* fp;
		int choose;
		printf("\nstart checking your file\n");
		while (1)
		{
			printf("please write your title\n\n");
			scanf("%s", s1);
			printf("\n");
			fp = fopen(s1, "r");
			fgets(buffer, sizeof(buffer), fp);
			printf("Inside the file, there are\n\n");
			printf("\e[1;34m          [\e[0m");
			printf("% s", buffer);
			printf("\e[1;34m]\e[0m\n\n");
			fclose(fp);
			printf("\n if you want continue, press 1\n");
			printf(" Or if you want to close the function, press 2\n\n");
			scanf("%d", &choose);
			if (choose == 2)
			{
				printf("closed check function\n\n");
				break;
			}
			else if (choose == 1)
			{
				printf("checking function will be restart\n\n");
			}
		}
		return 0;
	}

	//'delete' command to delete some file
	else if (strcmp(args[0], "delete") == 0 || strcmp(args[0], "del") == 0 || strcmp(args[0], "4") == 0)
	{
		char s1[20];
		int s2;
		printf("\nstart delete.\n");
		printf("input filename\n\n");
		scanf("%s", &s1);
		printf("Are you sure to earse it?\n\n");
		printf("if you want, press 1\n");
		printf("or not, press 2 to stop\n\n");
		scanf("%d", &s2);
		printf("\n\n");
		if (s2 == 1)
		{
			printf("\x1b[31myou still have 10 second\n\n");
			printf("if you don't want to erase, please end this programe\n\n");
			sleep(10);

			printf("\x1b[0mstart delete\n");
			FILE* fp;
			int result = remove(s1);
			if (result == 0)
			{
				printf("delete completed\n\n");
			}
			else
			{
				printf("delete failed\n\n");
				printf("please retried function\n\n");
			}
		}
		else if (s2 == 2)
			printf("end delete programm\n\n");
	}

	//'multitext' command generate a number of empty text files
	else if (strcmp(args[0], "multitext") == 0)
	  {
	  multitext();
	  }

	 //'rockgame' command play rock-paper-scissors.
	else if (strcmp(args[0], "rockgame") == 0)
	  {
	  rockgame();
	  }

	//'calculate' command run the calculator.
	else if (strcmp(args[0], "calculate") == 0)
	  {
	  calculate();
	  }

	//'manual' command to check some manuals about this shell prompt
	else if (strcmp(args[0], "manual") == 0)
	{
		int choose;
		printf("\nIf you want to see a function of ""\x1b[36m""interface""\x1b[0m"", press 1\n");
		printf("If you want to see a function of ""\x1b[36m""file I/O""\x1b[0m"", press 2\n");
		printf("If you want to see a function of ""\x1b[36m""time""\x1b[0m"", press 3\n");
		printf("If you want to see them all, press 4\n");
		scanf("%d", &choose);
		if (choose == 1)
		{
			printf("\n\t                           Function of interface\n");
			printf("\t        ""\x1b[36m""out""\x1b[0m""  = can get out this shell program\n");
			printf("\t        ""\x1b[36m""clear""\x1b[0m""  = can clear interface\n");
			printf("\t        ""\x1b[36m""color""\x1b[0m""  = can change shell prompt color\n");
			printf("\t        ""\x1b[36m""currentdirectory""\x1b[0m""  = can see current directory\n");
			printf("\t        ""\x1b[36m""changedirectory""\x1b[0m""  = can change directory\n\n");
		}
		if (choose == 2)
		{
			printf("\n\t                           Function of file I/O\n");
			printf("\t        ""\x1b[36m""create""\x1b[0m""  = can make a new file\n");
			printf("\t        ""\x1b[36m""multitext""\x1b[0m""  = can generate a number of empty text files\n");
			printf("\t        ""\x1b[36m""input""\x1b[0m""  = can put some strings in your file\n");
			printf("\t        ""\x1b[36m""check""\x1b[0m""  = can check the contents inside\n");
			printf("\t        ""\x1b[36m""delete""\x1b[0m""  = can delete file\n\n");
		}
		if (choose == 3)
		{
			printf("\n\t                           Function of time\n");
			printf("\t        ""\x1b[36m""worldtime""\x1b[0m""  = can see world timeline\n");
			printf("\t        ""\x1b[36m""quicktime""\x1b[0m""  = can check time quickly\n");
			printf("\t        ""\x1b[36m""timer""\x1b[0m""  = can run the timer\n\n");
		}
		if (choose == 4)
		{
			printf("\n\t                           All function\n");
			printf("\t        ""\x1b[36m""out""\x1b[0m""  = can get out this shell program\n");
			printf("\t        ""\x1b[36m""clear""\x1b[0m""  = can clear interface\n");
			printf("\t        ""\x1b[36m""color""\x1b[0m""  = can change shell prompt color\n");
			printf("\t        ""\x1b[36m""currentdirectory""\x1b[0m""  = can see current directory\n");
			printf("\t        ""\x1b[36m""changedirectory""\x1b[0m""  = can change directory\n");			
			printf("\t        ""\x1b[36m""create""\x1b[0m""  = can make a new file\n");
			printf("\t        ""\x1b[36m""input""\x1b[0m""  = can put some strings in your file\n");
			printf("\t        ""\x1b[36m""check""\x1b[0m""  = can check the contents inside\n");
			printf("\t        ""\x1b[36m""delete""\x1b[0m""  = can delete file\n");
			printf("\t        ""\x1b[36m""calculate""\x1b[0m""  = can calculate formula\n");
			printf("\t        ""\x1b[36m""rockgame""\x1b[0m""  = can play Rock Scissor Paper game\n");
			printf("\t        ""\x1b[36m""multitext""\x1b[0m""  = Create multiple text files at once\n");
			printf("\t        ""\x1b[36m""worldtime""\x1b[0m""  = can see world timeline\n");
			printf("\t        ""\x1b[36m""quicktime""\x1b[0m""  = can check time quickly\n");
			printf("\t        ""\x1b[36m""quickslot""\x1b[0m""  = can check shortcut key\n");
			printf("\t        ""\x1b[36m""timer""\x1b[0m""  = can run the timer\n\n");
			printf("\t        If you want to check these details once again, enter ""\x1b[36m""manual""\x1b[0m""\n\n");
		}
	}

	// 'quickslot' command to find shortcut key
	else if (strcmp(args[0], "quickslot") == 0)
	{
		printf("\n\t                           Shortcut Key\n");
		printf("\t        ""\x1b[36m""out""\x1b[0m""  -> o\n");
		printf("\t        ""\x1b[36m""clear""\x1b[0m"" -> cl || number 0 \n");
		printf("\t        ""\x1b[36m""color""\x1b[0m"" -> col\n");
		printf("\t        ""\x1b[36m""currentdirectory""\x1b[0m""  -> curd || currentd\n");
		printf("\t        ""\x1b[36m""changedirectory""\x1b[0m""  -> cd || changedir\n");
		printf("\t        ""\x1b[36m""create""\x1b[0m"" -> cr || number 1\n");
		printf("\t        ""\x1b[36m""input""\x1b[0m"" -> inp || number 2\n");
		printf("\t        ""\x1b[36m""check""\x1b[0m"" -> che || number 3\n");
		printf("\t        ""\x1b[36m""delete""\x1b[0m"" -> del || number 4\n");
		printf("\t        ""\x1b[36m""worldtime""\x1b[0m"" -> wtime || number 5\n");
		printf("\t        ""\x1b[36m""quicktime""\x1b[0m"" -> qtime\n\n");
	}

	//'worldtime' command to see world time.
	else if (strcmp(args[0], "worldtime") == 0 || strcmp(args[0], "wtime") == 0|| strcmp(args[0], "5") == 0)
	{
		nowtime();
		repubkor();
		newyork();
		ros();
		canada();
		bangkok();
		hongkong();
		china();
		taiwan();
		paris();
		sydney();
	}

	//'quicktime' command to check time quickly
	else if (strcmp(args[0], "quicktime") == 0 || strcmp(args[0], "qtime") == 0)
	{
		int choose;
		printf("\n\t                           What time would you like to see?\n\n");
		printf("\t        ""\x1b[36m""Nowtime""\x1b[0m""  -> press 1\n");
		printf("\t        ""\x1b[36m""Republic of Korea""\x1b[0m""  -> press 2\n");
		printf("\t        ""\x1b[36m""Newyork""\x1b[0m""  -> press 3\n");
		printf("\t        ""\x1b[36m""Ros Angeles""\x1b[0m""  -> press 4\n");
		printf("\t        ""\x1b[36m""Canada""\x1b[0m""  -> press 5\n");
		printf("\t        ""\x1b[36m""Bangkok""\x1b[0m""  -> press 6\n");
		printf("\t        ""\x1b[36m""Hongkong""\x1b[0m""  -> press 7\n");
		printf("\t        ""\x1b[36m""China""\x1b[0m""  -> press 8\n");
		printf("\t        ""\x1b[36m""Taiwan""\x1b[0m""  -> press 9\n");
		printf("\t        ""\x1b[36m""paris""\x1b[0m""  -> press 10\n");
		printf("\t        ""\x1b[36m""Sydney""\x1b[0m""  -> press 11\n");
		scanf("%d", &choose);
		if (choose == 1)
		{
			nowtime();
		}
		if (choose == 2)
		{
			repubkor();
		}
		if (choose == 3)
		{
			newyork();
		}
		if (choose == 4)
		{
			ros();
		}
		if (choose == 5)
		{
			canada();
		}
		if (choose == 6)
		{
			bangkok();
		}
		if (choose == 7)
		{
			hongkong();
		}
		if (choose == 8)
		{
			china();
		}
		if (choose == 9)
		{
			taiwan();
		}
		if (choose == 10)
		{
			paris();
		}
		if (choose == 11)
		{
			sydney();
		}
	}

	//'color' command to change shell prompt color
	else if (strcmp(args[0], "color") == 0|| strcmp(args[0], "col") == 0)
	{
	int choose;
	printf("\n\t                           You can change shell prompt color\n\n");
	printf("\n\t                           What color do you want to change it to?\n\n");
	printf("\t                                   ""\x1b[31m""Red""\x1b[0m" "  -> press 1\n");
	printf("\t                                   ""\x1b[32m""Green""\x1b[0m""  -> press 2\n");
	printf("\t                                   ""\x1b[33m""Yellow""\x1b[0m""  -> press 3\n");
	printf("\t                                   ""\x1b[34m""Blue""\x1b[0m""  -> press 4\n");
	printf("\t                                   ""\x1b[37m""White""\x1b[0m""  -> press 5\n");
	printf("\t                                   ""\x1b[37;1m""Bright White""\x1b[0m""  -> press 6\n");
	scanf("%d", &choose);
	if (choose == 1)
	{
		printf("\n\t                                   ""\x1b[31m""It will change to red.\n\n");
	}
	if (choose == 2)
	{
		printf("\n\t                                   ""\x1b[32m""It will change to green.\n\n");
	}
	if (choose == 3)
	{
		printf("\n\t                                   ""\x1b[33m""It will change to yellow.\n\n");
	}
	if (choose == 4)
	{
		printf("\n\t                                   ""\x1b[34m""It will change to blue.\n\n");
	}
	if (choose == 5)
	{
		printf("\n\t                                   ""\x1b[37m""It will change to white.\n\n");
	}
	if (choose == 6)
	{
		printf("\n\t                                   ""\x1b[37;1m""It will change to bright white.\n\n");
	}
	}

	//'changeDirectory' command to change directory.
	else if (strcmp(args[0],"changedirectory") == 0|| strcmp(args[0], "cd") == 0|| strcmp(args[0], "changedir") == 0)
		changeDirectory(args);
	
	// 'environ' command to list the environment variables
	else if (strcmp(args[0],"environ") == 0){
		if (args[j] != NULL){
			// If we want file output
			if ( (strcmp(args[j],">") == 0) && (args[j+1] != NULL) ){
				fileDescriptor = open(args[j+1], O_CREAT | O_TRUNC | O_WRONLY, 0600); 
				// We replace de standard output with the appropriate file
				standardOut = dup(STDOUT_FILENO); 	// first we make a copy of stdout
													// because we'll want it back
				dup2(fileDescriptor, STDOUT_FILENO); 
				close(fileDescriptor);
				manageEnviron(args,0);
				dup2(standardOut, STDOUT_FILENO);
			}
		}else{
			manageEnviron(args,0);
		}
	}
	// 'setenv' command to set environment variables
	else if (strcmp(args[0],"setenv") == 0) manageEnviron(args,1);
	// 'unsetenv' command to undefine environment variables
	else if (strcmp(args[0],"unsetenv") == 0) manageEnviron(args,2);
	else{
		// If none of the preceding commands were used, we invoke the
		// specified program. We have to detect if I/O redirection,
		// piped execution or background execution were solicited
		while (args[i] != NULL && background == 0){
			// If background execution was solicited (last argument '&')
			// we exit the loop
			if (strcmp(args[i],"&") == 0){
				background = 1;
			// If '|' is detected, piping was solicited, and we call
			// the appropriate method that will handle the different
			// executions
			}else if (strcmp(args[i],"|") == 0){
				pipeHandler(args);
				return 1;
			// If '<' is detected, we have Input and Output redirection.
			// First we check if the structure given is the correct one,
			// and if that is the case we call the appropriate method
			}else if (strcmp(args[i],"<") == 0){
				aux = i+1;
				if (args[aux] == NULL || args[aux+1] == NULL || args[aux+2] == NULL ){
					printf("Not enough input arguments\n");
					return -1;
				}else{
					if (strcmp(args[aux+1],">") != 0){
						printf("Usage: Expected '>' and found %s\n",args[aux+1]);
						return -2;
					}
				}
				fileIO(args_aux,args[i+1],args[i+3],1);
				return 1;
			}
			// If '>' is detected, we have output redirection.
			// First we check if the structure given is the correct one,
			// and if that is the case we call the appropriate method
			else if (strcmp(args[i],">") == 0){
				if (args[i+1] == NULL){
					printf("Not enough input arguments\n");
					return -1;
				}
				fileIO(args_aux,NULL,args[i+1],0);
				return 1;
			}
			i++;
		}
		args_aux[i] = NULL;
		launchProg(args_aux,background);
		
		 //'out', 'currentdirectory' , 'clear'.

	}
return 1;
}

/**
* Main method of our shell
*/ 
int main(int argc, char *argv[], char ** envp) {
	char line[MAXLINE]; // buffer for the user input
	char * tokens[LIMIT]; // array for the different tokens in the command
	int numTokens;
		
	no_reprint_prmpt = 0; 	// to prevent the printing of the shell
							// after certain methods
	pid = -10; // we initialize pid to an pid that is not possible
	
	// We call the method of initialization and the welcome screen
	init();
	welcomeScreen();
    
    // We set our extern char** environ to the environment, so that
    // we can treat it later in other methods
	environ = envp;
	
	// We set shell=<pathname>/simple-c-shell as an environment variable for

	// the child
	setenv("shell",getcwd(currentDirectory, 1024),1);
	
	// Main loop, where the user input will be read and the prompt

	// will be printed
	while(TRUE){
		// We print the shell prompt if necessary
		if (no_reprint_prmpt == 0) shellPrompt();
		no_reprint_prmpt = 0;
		
		// We empty the line buffer
		memset ( line, '\0', MAXLINE );

		// We wait for user input
		fgets(line, MAXLINE, stdin);
	
		// If nothing is written, the loop is executed again
		if((tokens[0] = strtok(line," \n\t")) == NULL) continue;
		
		// We read all the tokens of the input and pass it to our
		// commandHandler as the argument
		numTokens = 1;
		while((tokens[numTokens] = strtok(NULL, " \n\t")) != NULL) numTokens++;
		
		commandHandler(tokens);
		
	}          

	exit(0);
}