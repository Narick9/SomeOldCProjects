#include <io.h>		// for dup2()
#include <stdio.h>	// for FILE, fprintf()
#include <errno.h>	// for errno
#include <string.h>	// for strerror()
#include <unistd.h>	// for execl(), getopt()

void error(char msg[])
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char* argv[])
{
	char* input_str = NULL;
	char* output_str = NULL;

	char ch;
	while ((ch = getopt(argc, argv, "i:o:")) != EOF) {
		switch (ch) {
		case 'i':
			input_str = optarg;
			break;
		case 'o':
			output_str = optarg;
			break;
		default:
			error("Unknow parameter");
		}
	}

	argc -= optind;
	argv += optind;

	FILE* input;
	if (input_str == NULL) {		// ���� �� ���� ��������� ��������� ������
		input_str = argv[0];		// ����� getopt � argv ����� ������ ��������� �.�. 
		argv++;						// ���������� ��������� �������� ������
	}
	if (input_str) {				// ���� ���-�� ��-���� �����
		if ( !(input = fopen(input_str, "r")) )
			error("Failed to found input file");
		if ( dup2(fileno(input), 0) == -1 )
			error("Failed to dericted stdin");
	}								// ���� ���, �� ����������� ���� �� ����������
		
	FILE* output;					// ����� �� �����
	if (output_str == NULL) {
		output_str = argv[0];
	}
	if (output_str) {
		if ( !(output = fopen(output_str, "w")) )
			error("Failed to found input file");
		if ( dup2(fileno(output), 1) == -1 )
			error("Failed to dericted stdout");
	}

	if ( execl("./text_translator", "./text_translator", NULL) == -1 )
		error("Failed to transfer process to 'text_translator'");

	return 1;
}