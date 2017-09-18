#include <"node.c">
void listAdd(List *whichList,char *data){
	LNode newNode=(LNode*)(malloc(sizeof(LNode)));
	
	newNode->ch=NULL;
	newNode->left=newNode->right=NULL;

	if(whichList->start==NULL ){
		whichList->end=whichList->start=newNode;
		return;
	}
	whichList->end ->right=newNode;
	newNode->left=whichList->end;
	whichList->end=newNode;

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
		temp=temp->ch;
	}
}