#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

const char *ANSI_RESET   = "\x1b[0m";

const char *ANSI_RED     = "\x1b[31m";
const char *ANSI_GREEN   = "\x1b[32m";
const char *ANSI_YELLOW  = "\x1b[33m";
const char *ANSI_CYAN    = "\x1b[36m";
const char *ANSI_WHITE   = "\x1b[37m";
const char *ANSI_GRAY    = "\x1b[90m";



int main(int argc , char * argv[])
{
	//if user didn't input any errno code
	if(argc < 2)
	{
		fprintf(stderr, "- %smust put atleast one number as an arg!!%s\n",ANSI_GRAY,ANSI_RESET);
		return 1;
	}

	//loop of all argv after <binary name>
	for (int i = 1; i < argc ;i++){	
		char* errno_code_str = argv[i]; 
		int errno_code_int = atoi(argv[i]); //if failed will return 0

		if(strncmp("0",errno_code_str,2) == 0 || errno_code_int != 0)
			printf("- %s[ %s ] %s%s%s.\n",
				ANSI_CYAN,argv[i],
				ANSI_YELLOW,
				strerror(errno_code_int),
				ANSI_RESET);
		else 
			printf("- %s[ %s ] is not errno code%s.\n",ANSI_RED,argv[i],ANSI_RESET);
	}


	return 0;
}
