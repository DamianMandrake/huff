#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
#include "list.c"
List* readFile(char *fileName){
	FILE *fp;List *list=(List*)(malloc(sizeof(List)));
	list->start=list->end=NULL;
	int i=1;
	char j;

	printf("READING\n");
	while(i){
		i=0;
		char *contents=(char*)(malloc(sizeof(char)*BUFFER_SIZE));
		printf("BUFFER CREATED\n");
		while((j=fgetc(fp))!= EOF && i<BUFFER_SIZE){
			contents[i++]=j;
		}
		contents[i-1]='\0';

		if(j==EOF)
			return list;

		listAdd(list,contents);

	}


	fclose(fp);
	return list;
}
static void testCases(){
	
	listWalker(readFile("node.c"));
}
int main(int argc, char const *argv[])
{
	testCases();
	return 0;
}

