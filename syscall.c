#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
	size_t length;
	int lenstring;
	char buf[100];
	
	strcpy(buf, "Hello this is program demoing a system call");
	lenstring = strlen(buf);
	
	length = write(1, buf, lenstring);
	
	return 0;
}
