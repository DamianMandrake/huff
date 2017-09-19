#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
#include "list.c"
List* readFile(char *fileName){
	FILE *fp;List *list=(List*)(malloc(sizeof(List)));
	list->start=list->end=NULL;
	int i,j;


	fp=fopen(fileName,"r");
	if(fp==NULL){
		printf("File couldnt be read\n");
		return NULL;
	}
	printf("reading file\n");

	j=fgetc(fp);
	while(j!=EOF){
		i=1;
		char *contents=(char*)(malloc(sizeof(char)*BUFFER_SIZE));
		contents[0]=j;

		while((j=fgetc(fp))!= EOF && i<BUFFER_SIZE){
			contents[i++]=(char)j;
		}
		contents[i]='\0';

		listAdd(list,contents);

		

		

	}


	fclose(fp);
	return list;
}
static void testCases(){
	List *fileContentList=readFile("node.c");
	if(fileContentList)
		listWalker(fileContentList);
	
}
/*int main(int argc, char const *argv[])
{
	testCases();
	return 0;
}*/

