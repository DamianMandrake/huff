/* creates the huff tree from the pq returned by frequncyCounter*/
#include "utils/node.c"
#include "utils/fileReader.c"
#include "utils/priorityQueue.c"
#include "frequencyCounter.c"
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
/* this function pairs 2 nodes and returns a new Node which stores the maxchild in left and the min child on the right*/
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


/* this function creates a huffman tree.*/
HuffTree* createHuffTree(Pq *pq){
	Node *newRoot;
	queueWalker(pq);
	HuffTree *huffTree=(HuffTree*)(malloc(sizeof(HuffTree)));
	huffTree->root=NULL;
	Node *max=NULL,*min=NULL;

	while((min=deque(pq)) && (max=deque(pq))){
		queueWalker(pq);
		printf("MAX \n");
		printNodeData(max);
		printf("MIN\n");
		printNodeData(min);

		newRoot=clubNodes(max,min);
		enque(pq,newRoot);

	}
	/*printf("MAX \n");
		printNodeData(max);
		printf("MIN\n");
		printNodeData(min);*/


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
	HuffTree *t=createHuffTree(getFrequencyQueue("tp.c"));
	inorder(t->root);
}
int main(int argc, char const *argv[])
{
	huffTestCases();
	return 0;
}