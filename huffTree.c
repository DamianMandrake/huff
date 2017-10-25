/* creates the huff tree from the pq returned by frequncyCounter*/
#include "utils/node.c"
#include "utils/fileReader.c"
#include "utils/priorityQueue.c"
#include "frequencyCounter.c"
/*	TESTING */
struct HashMap{
	int h;
};
typedef struct HashMap HashMap;
/* TESTING*/



void strcpy(char *source, int sourceLen,int offset,char *dest){
	for(int i=offset;i<sourceLen;i++)
		dest[i]=source[i];
}
char* append(char *str1,char *str2){
	/* TODO make it better... very sad implementation*/
	int a=strlen(str1),b=strlen(str2);
	char *newStr=(char*)malloc(sizeof(char)*(a+b));
	strcpy(str1,a,0,newStr);
	strcpy(str2,b,a,newStr);
	return newStr;

}
void printNodeData(Node *node){
	printf("freq %d char %c \n",node->data->freq,node->data->ch);
}
/* this function pairs 2 nodes and returns a new Node which stores the maxchild on the right and the min child on the left*/
Node* clubNodes(Node *max,Node *min){

	Node *newNode=getTempData( NULL, max->data->freq + min->data->freq);
	printf("MAX \n");
	printNodeData(max);
	printf("MIN\n");
	printNodeData(min);

	newNode->right=max;
	newNode->left=min;

	return newNode;

}

/* function adds the huffCode to a map M={char key, char *huffCode}*/
void insertInMap(HashMap *hm,char key,char *huffCode,int len){
	int i=0;
	printf("Code of %c is %s  \n",key,huffCode);
	/* TODO add the code to the map*/
	for(i=0;i<len;i++)
		printf("%c",huffCode[i] );



}
/* obtains huff codes of all characters present in the list... */
void obtainHuffCode(Node *root,char *stack,int top,HashMap *hm){
	/* when the left child exists*/
	if(root->left){
		stack[top]='0';
		obtainHuffCode(root->left,stack,top+1,hm);

	}
	/* when the right child exists*/
	if(root->right){
		stack[top]='1';
		obtainHuffCode(root->right,stack,top+1,hm);
	}



	if(root->left == root->right ){//Leaf and NULL
		stack[top]='\0';
		/*for(int i=0;i<=top;i++)
			printf("%c",stack[i] );*/
		printf("\n");
		insertInMap(hm,root->data->ch,stack,top+1);

	}	


}

/* this function creates a huffman tree given a prioriry queue.*/
HuffTree* createHuffTree(Pq *pq){
	Node *newRoot;
	queueWalker(pq);
	HuffTree *huffTree=(HuffTree*)(malloc(sizeof(HuffTree)));
	huffTree->root=NULL;
	Node *max=NULL,*min=NULL;

	while((min=deque(pq)) && (max=deque(pq))){
		newRoot=clubNodes(max,min);
		enque(pq,newRoot);

	}
	
	queueWalker(pq);

	huffTree->root=newRoot;
	printf("%c data \n",huffTree->root->left->data->ch);
	return huffTree;


}
void inorder(Node *root){
	if(root){
		printf("%d %c \n",root->data->freq,root->data->ch );
		inorder(root->left);
		inorder(root->right);
	}
}

void huffTestCases(){
	char *arr;
	HuffTree *t=createHuffTree(getFrequencyQueue("tp.c",arr));
	printf("WALKING THE TREE\n");
	inorder(t->root);
	printf("DONE wITH TREE \n");

	HashMap *hm=(HashMap*)(malloc(sizeof(HashMap)));
	char *stack=(char*)(malloc(sizeof(char )* 128));

	obtainHuffCode(t->root,stack,0,hm);





}
int main(int argc, char const *argv[])
{
	huffTestCases();
	return 0;
}