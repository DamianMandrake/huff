
int strlen(char *ch){
	if(ch){
		int i=0;
		while(ch[i])
			i++;
		return i;
	}
}
int countFrequency(List *list,char ch){

	LNode *temp=list->start;
	int i=0;
	int counter=0;
	while(temp){
		for(i=0;i<strlen(temp->ch);i++){
			if(temp->ch[i]==ch)
				counter++;
		}
		temp=temp->right;

	}
	return counter;

}
void arrWalker(char arr[],int len){
	int i;
	printf("DISPLAYING ARR\n");
	for( i=0;i<len;i++){
		printf("%c \n",arr[i] );
	}
	printf("DONE WITH ARR\n");


}
int isInArr(char arr[],int len,char target){

	int i=0,j=len-1;
	while(i < j && (arr[i]!=target && arr[j]!=target)){
		i++;j--;
	}

	return arr[i]==target||arr[j]==target;
}
/* char arr is being passed as an argument only to obtain the list of characters for traversing the huffTree.*/
Pq* getFrequencyQueue(char *fileName,char *arr){
	int i,j,f;char ch;
	List *list=readFile(fileName);
	//char *arr;
	int arrCounter=0;
	

	if(list==NULL){
		printf("... FrequencyList couldnt be constructed\n");
		return NULL;
	}
	Pq *pq=(Pq*)(malloc(sizeof(Pq)));
	pq->head=pq->tail=NULL;
	
	//for all ascii chars
	

	arr=(char*)malloc(sizeof(char)*256);

	/* todo make the above implementation better... should make it dynamic since the probability of obtaining all 255 
	chars is very low*/

	char *s;
	LNode *temp=list->start;
	while(temp){

		for(i=0;i<strlen(temp->ch);i++){
			ch=temp->ch[i];
			if(isInArr(arr,arrCounter,ch)){
				continue;
			}
			f=countFrequency(list,ch);
			Node *huffNode=getTempData(ch,f);			
			enque(pq,huffNode);

			arr[arrCounter++]=ch;
		}

		temp=temp->right;

	}
	printf("Total characters obtained %d\n",arrCounter);


	return pq;


}
void isInArrTc(){
	char *arr=(char*)(malloc(sizeof(char)*30));
	int i=0;
	char *ch="#include <stdio";
	for(i=0;i<16;i++)
		arr[i]=ch[i];
	printf("%s\n",arr );

	printf("%c\n",arr[14] );
	printf("%d\n", isInArr(arr,16,'o'));
	
}
void fcTestCases(){
	Pq *q=getFrequencyQueue("tp.c",NULL	);
	queueWalker(q);
}
/*int main(){
	fcTestCases();
	return 1;
}*/