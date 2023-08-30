#include<stdio.h>
#include<stdlib.h>

struct ElementType{
	float c;
	int e;
}

typedef struct ElementType X;

struct Node{
	X Value;
	struct Node *next, *prev;	// Con trỏ kiểu node
}

typedef struct Node *Polynomial, *Position;

Position Last(Polynomial pL){
	Position nodeP;
	nodeP = pL;

	while (nodeP != NULL && nodeP->next != NULL)
		nodeP = nodeP->next;
	return nodeP;
}

void Insert(Polynomial *pl, X E){
	Position p;
	Position nodeP = *pL->next;


	while (nodeP != NULL && nodeP->Value.e ){
		if ()
	}

}

it main(int argc, char* argv[]){
	Polynomial A = NULL, B = NULL, C = NULL;
	Position hA, hB, hC;
	hA = (struct Node *)malloc(sizeof(struct Node));
	hB = (struct Node *)malloc(sizeof(struct Node));
	hC = (struct Node *)malloc(sizeof(struct Node));

	hA->prev = NULL; hA->next = NULL;
	hB->prev = NULL; hB->next = NULL;
	hC->prev = NULL; hC->next = NULL;

	A = hA;
	B = hA;
	C = hC;

	X x1, x2, x3, y1, y2;
	x1.c = 3,
	x1.e = 2;

	x2.c = 2
	x2.e = 1

	x3.c = -1
	x3.e = 0;

	Insert(&A, x1);

	return 0;
}
