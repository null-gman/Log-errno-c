#include <stdio.h>
#include <string.h>
#include <errno.h>

const char *ANSI_RESET   = "\x1b[0m";
const char *ANSI_RED     = "\x1b[31m";
const char *ANSI_GREEN   = "\x1b[32m";
const char *ANSI_YELLOW  = "\x1b[33m";
const char *ANSI_BLUE    = "\x1b[34m";
const char *ANSI_MAGENTA = "\x1b[35m";
const char *ANSI_CYAN    = "\x1b[36m";
const char *ANSI_WHITE   = "\x1b[37m";
const char *ANSI_GRAY    = "\x1b[90m";

int charToNum(const char CHAR)
{
	switch(CHAR){
		case '0':
			return 0;
		case '1':
		  return 1;
		case '2':
		  return 2;
		case '3':
		  return 3;
		case '4':
		  return 4;
		case '5':
		  return  5;
		case '6':
		  return 6;
		case '7':
		  return 7;
		case '8':
		  return 8;
		case '9':
		  return 9;
		default:
		  return -1;
	}
}

int power(const int num , const int repet){
	if(num == 0){
		return 0;
	}else if (num < 0 ){
		return -1;
	}
	int res = 1;
	for(int i =0 ; i < repet ; i++){
		res *= num;
	}
	return res;
}

int toNumber(const char * string){

	int len = strlen(string);
	int order = len - 1;
	int res = 0;

	for(int i = 0;i < len;i++)
	{
	    int num = charToNum(string[i]);
		res += num * power(10, order);
		order --;
	}

	return  res;
}


int isNum(const char * string ){

	size_t len = strlen(string);

	for(size_t i = 0;i < len ;i++)
	{
		if(string[i] > 57 || string[i] < 48)
		{
			return 0;
		}
	}

	return 1;
}


int main(int argc , char * argv[])
{
	if(argc < 2)
	{
		fprintf(stderr , "- %smust put atleast one number as an arg!!%s\n",ANSI_GRAY,ANSI_RESET);
		return 1;
	}

	for (int i = 1; i < argc ;i++){
		if(isNum(argv[i]) == 1)	{
			int errno_code = toNumber(argv[i]);
			printf("- %s[ %s ] %s%s%s.\n",ANSI_CYAN,argv[i],ANSI_YELLOW, strerror(errno_code) ,ANSI_RESET);
		}else{
			printf("- %s[ %s ] is not errno code%s.\n",ANSI_RED,argv[i],ANSI_RESET);
			return 1;
		}
	}

	return 0;
}
