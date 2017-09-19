#include <stdio.h>
#include <stdlib.h>
//#include "node.c"
/* an implementation of a output restricted prioritized deque...*/
struct PriorityNode
{	
	Node *mainNode;
	struct PriorityNode *right,*left;
};
struct PriorityQue
{
	struct PriorityNode *head,*tail;
};
typedef struct PriorityNode PriorityNode;
typedef struct PriorityQue Pq;
int isQueueEmpty(Pq *q){
	return q->head==NULL && q->tail==NULL;
}
void appendPriorityNodes(PriorityNode *first,PriorityNode *target){
	target->right=first->right;
	target->left=first;
	first->right=target;
}
void queueWalker(Pq *q){
	if(q==NULL){
		printf("Cant walk\n");
		return;
	}
	PriorityNode *pn=q->head;
	printf("WALKING\n");
	
		while(pn){
			printf("%c \t %d\n",pn->mainNode->data->ch,pn->mainNode->data->freq );
			pn=pn->right;
		}
	printf("DONE\n");
}



/* function enques data of type Node into the queue.
*/
void enque(Pq *q,Node *mainNode){

	PriorityNode *pn=(PriorityNode*)(malloc(sizeof(PriorityNode)));
	pn->right=pn->left=NULL;
	pn->mainNode=mainNode;

	
	printf("Inserting %c %d in the que\n",mainNode->data->ch,mainNode->data->freq );
	if(isQueueEmpty(q)){
		q->head = q->tail= pn;
		return;
	}

	PriorityNode *temp=q->head;
	while(temp && pn->mainNode->data->freq >  temp->mainNode->data->freq )
		temp=temp->right;
	

	if(temp)
		if(temp==q->head){

			pn->right=q->head;
			q->head->left=pn;
			q->head=pn;

		}else{
			/* anywhere in between */
			pn->right=temp->left->right;
			pn->left=temp->left;
			temp->left->right=pn;
			temp->left=pn;
		}
	else {
		/* when temp is null ie the element inserted was greatest */
		q->tail->right=pn;
		pn->left=q->tail;
		q->tail=pn;
			
	}

}

/* function returns node at head. Must free node from the outside*/
PriorityNode* deque(Pq *q){

	if(q){
		PriorityNode *pn=q->head;
		q->head=q->head->right;
		return pn;
	}

	return NULL;


}


void* deletePriorityQueue(Pq *q){
	if(q==NULL){
		printf("Cant delete\n");
		return NULL;
	}
	PriorityNode *pn=q->head,*follow;
	printf("Deleting queue\n");
	while(pn){
		follow=pn;
		pn=pn->right;
		free(follow);
	}
	
	printf("Done with deletion\n");
	return NULL;
}

Node* getTempData(char ch,int fre){
	Node *node=(Node*)(malloc(sizeof(Node)));
	node->right=node->left=NULL;
	Data *d=(Data*)(malloc(sizeof(Data)));
	d->ch=ch;
	d->freq=fre;
	node->data=d;
	return node;
}
static void pqTestCases(){
	Pq *p=(Pq*)(malloc(sizeof(Pq)));
	p->tail=p->head=NULL;
	enque(p,getTempData('a',909));
	enque(p,getTempData('b',900));
	enque(p,getTempData('c',1000));
	enque(p,getTempData('c',10000));
	//queueWalker(p);
	enque(p,getTempData('c',800));
	enque(p,getTempData('c',950));
	enque(p,getTempData('c',10));
	enque(p,getTempData('t',789));
	int arr[]={323,55,23,58,23123,899,234};
	for(int j=0;j<10;j++)
	for(int i=0;i<6;i++)
		enque(p,getTempData('a',arr[i]));
	PriorityNode *pn=deque(p);
	Node *d=pn->mainNode;
	free(pn);
	printf("DATA In d %d\n",d->data->freq);
	queueWalker(p);

	//queueWalker(p);
}
/*int main(){

	pqTestCases();
	return 1;
}*/