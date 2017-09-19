#include <stdio.h>
#include <stdlib.h>
//#include "node.c"

void listAdd(List *whichList,char *data){
	LNode *newNode=(LNode*)(malloc(sizeof(LNode)));
	
	newNode->ch=data;
	newNode->left=newNode->right=NULL;

	printf("NODE CREATED\n");
	if(whichList->start==NULL ){
		whichList->end=whichList->start=newNode;
		return;
	}
	whichList->end->right=newNode;
	newNode->left=whichList->end;

	whichList->end=newNode;
	printf("DATA ADDED\n");

}
void deleteList(List *list){
	LNode *current=list->start,*follow=NULL;
	while(current){
		
		follow=current;

		current=current->right;

		free(follow);
	}
	printf("Deleted list\n");
}
void listWalker(List *list){
	LNode *temp=list->start;
	while(temp){
		printf("%s\n",temp->ch );
		temp=temp->right;
	}
}
void listTestCases(){
	List *list=(List*)(malloc(sizeof(List)));
	list->start=NULL;
	listAdd(list,"hello");
	listAdd(list,"hello");listAdd(list,"hello");listAdd(list,"hello");
	listWalker(list);
}
/*int main(int argc, char const *argv[])
{
	testCases();
	return 0;
}*/