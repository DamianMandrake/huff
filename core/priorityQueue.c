#include <stdio.h>
#include <stdlib.h>
#include "node.c"
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
/* function enques data of type Node into the queue.
*/
void enque(Pq *q,Node *mainNode){

	PriorityNode *pn=(PriorityNode*)(malloc(sizeof(PriorityNode)));
	pn->right=pn->left=NULL;
	pn->mainNode=mainNode;

	if(isQueueEmpty(q)){
		q->head = q->tail= pn;
		return;
	}

	PriorityNode *temp=q->head;
	while(temp && pn->mainNode->data->freq >  temp->mainNode->data->freq )
		temp=temp->right;


	temp= temp?temp:q->tail;
	if(temp!=q->head)
		appendPriorityNodes(temp,pn);
	else{
		pn->right=q->head;
		q->head=pn;

	}
	/*if(temp){
		appendPriorityNodes(temp,pn);
	}else{
	/*this means the list has exhausted and the element inserted was the least
		simply appending to list
	 
		appendPriorityNodes(q->tail,pn);
		
	}*/


}
void queueWalker(Pq *q){
	PriorityNode *pn=q->head;
	printf("WALKING\n");
	
		while(pn){
			printf("%c \t %d\n",pn->mainNode->data->ch,pn->mainNode->data->freq );
			pn=pn->right;
		}
	printf("DONE\n");
}

void deletePriorityQueue(Pq *q){
	PriorityNode *pn=q->head,*follow;
	printf("Deleting queue\n");
	while(pn){
		follow=pn;
		pn=pn->right;
		free(follow);
	}
	q=NULL;
	printf("Done with deletion\n");

}
/* function returns node deleted*/
PriorityNode* deque();
static Node* getTempData(char ch,int fre){
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
	enque(p,getTempData('c',1000));
	queueWalker(p);
	enque(p,getTempData('c',800));
	enque(p,getTempData('c',950));
	enque(p,getTempData('c',10));
	deletePriorityQueue(p);
	p==NULL?printf("aSd\n"):printf("ASd\n");;
	queueWalker(p);
}
int main(){

	pqTestCases();
	return 1;
}