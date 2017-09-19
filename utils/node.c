struct Data {
	int freq;
	char ch;

};
struct Node {
	struct Data *data;
	struct Node *left,*right;
};
struct Stack{
	struct Node *top;

};
struct HuffTree
{
	struct Node *root; 
};
struct ListNode
{
	char *ch; 
	struct ListNode *left,*right;
};
struct List
{
	struct ListNode *start,*end;
};
typedef struct Data Data;
typedef struct Node Node;
typedef struct PriorityQue Pq;
typedef struct HuffTree Ht;
typedef struct Stack St;
typedef struct ListNode LNode;
typedef struct List List;

