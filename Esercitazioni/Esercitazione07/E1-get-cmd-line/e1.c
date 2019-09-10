#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void get_cmd_line(char* argv[]){
	char* buf = (char*)malloc(1024);
	fgets(buf,1024,stdin);
	const char end[4] = "\t\n";
	char* tok = strtok(buf, end);
	int i = 0;
	while(tok){
		argv[i] = (char*)malloc(1024);
		strcpy(argv[i], tok);
		i++;
		tok = strtok(NULL, end);
		if(i > 62){break;}
	}argv[i] = NULL;
}

