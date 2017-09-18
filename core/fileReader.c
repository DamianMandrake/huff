#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
#include "list.c"
List* readFile(char *fileName){
	File *fp;List *fContents=(List*)(malloc(sizeof(List)));
	fContents->
	int i=1;
	char j;

	while(i){
		i=0;
		char *contents=(char*)(malloc(sizeof(char)*BUFFER_SIZE+1));
		while((j=fgetc())!= EOF && i<BUFFER_SIZE){
			contents[i++]=j;
		}
		contents[i]='\0';

		if(j==EOF)
			return list;

		listAdd(list,contents);

	}


	fclose(fp);
	return fContents;
}
void testCases(){
	
	listWalker(readFile("node.c"));
}
int main(int argc, char const *argv[])
{
	testCases();
	return 0;
}

