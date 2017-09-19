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
/* this function pairs 2 nodes and returns a new Node which stores the maxchild in left and the min child on the right*/
Node* clubNodes(Node *max,Node *min){

	Node *newNode=getTempData( NULL, max->data->freq + min->data->freq);
	newNode->left=max;
	newNode->right=min;

	return newNode;

}

/* this function creates a huffman tree.*/
HuffTree* createHuffTree(char *fileName){

	Pq *pq=getFrequencyQueue(fileName);
	HuffTree *huffTree=(HuffTree*)(malloc(sizeof(HuffTree)));
	huffTree->root=NULL;
	Node *max=NULL,*min=NULL;

	while((min=deque(pq))&& (max=deque(pq))){
		Node *newRoot=clubNodes(max,min);
		enque(pq,newRoot);

	}

	huffTree->root=max;

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
	HuffTree *t=createHuffTree("tp.c");
	inorder(t->root);
}
int main(int argc, char const *argv[])
{
	huffTestCases();
	return 0;
}