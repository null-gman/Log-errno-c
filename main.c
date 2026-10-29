
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

const char *ANSI_RESET   = "\x1b[0m";

const char *ANSI_RED     = "\x1b[31m";
const char *ANSI_GREEN   = "\x1b[32m";
const char *ANSI_YELLOW  = "\x1b[33m";
const char *ANSI_CYAN    = "\x1b[36m";
const char *ANSI_WHITE   = "\x1b[37m";
const char *ANSI_GRAY    = "\x1b[90m";

static void print_invalid(const char *input)
{
	fprintf(stderr, "- %s[ %s ] is not errno code%s.\n",
			ANSI_GRAY, input, ANSI_RESET);
}

static int read_pipe(void)
{
	char buffer[128];
	char *start;
	char *end;
	long code;

	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
	{
		print_invalid("");
		return 1;
	}

	if (strchr(buffer, '\n') == NULL && !feof(stdin))
	{
		int ch;

		while ((ch = getchar()) != '\n' && ch != EOF)
			;

		print_invalid(buffer);
		return 1;
	}

	buffer[strcspn(buffer, "\n")] = '\0';

	start = buffer;

	while (isspace((unsigned char)*start))
		start++;

	if (*start == '\0')
	{
		print_invalid(buffer);
		return 1;
	}

	errno = 0;
	code = strtol(start, &end, 10);

	if (start == end || errno == ERANGE)
	{
		print_invalid(buffer);
		return 1;
	}

	while (isspace((unsigned char)*end))
		end++;

	if (*end != '\0' || code < 0 || code > 999)
	{
		print_invalid(buffer);
		return 1;
	}

	printf("- %s[ %ld ] %s%s%s.\n",
		   ANSI_CYAN, code,
		ANSI_GREEN, strerror((int)code), ANSI_RESET);

	return 0;
}

int main(int argc, char *argv[])
{
	/* Read errno code from stdin when -p is specified */
	if (argc >= 2 && strcmp(argv[1], "-p") == 0)
		return read_pipe();

	/* Original argument-based behavior */
	if (argc < 2)
	{
		fprintf(stderr,
				"- %smust put atleast one number as an arg!!%s\n",
		  ANSI_GRAY, ANSI_RESET);
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		char *errno_code_str = argv[i];

		if (strlen(errno_code_str) > 3 &&
			(argv[i][3] > 47 && 58 > argv[i][3]))
			goto notErrno;

		int errno_code_int = atoi(argv[i]);

		if (strncmp("0", errno_code_str, 2) == 0 ||
			errno_code_int != 0)
		{
			printf("- %s[ %d ] %s%s%s.\n",
				   ANSI_CYAN, errno_code_int,
		  ANSI_GREEN,
		  strerror(errno_code_int),
				   ANSI_RESET);
		}
		else
		{
			notErrno:
			fprintf(stderr,
					"- %s[ %s ] is not errno code%s.\n",
		   ANSI_GRAY, argv[i], ANSI_RESET);
		}
	}

	return 0;
}
