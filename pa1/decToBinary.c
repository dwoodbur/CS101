#include "myinclude.h"
#include "intstack.h"
/* Author : Dylan Woodbury, using given header/ADT files */
int main()
	{
	int num, saveNum;
    /* Make an empty stack */
	StackHndl Stack;
	Stack = NULL;
	Stack = NewStack ();

	printf("Input a non-negative decimal integer to convert to binary:\n> ");
	scanf("%d", &num);
	saveNum = num;

	if(num == 0) /* edge case */
		Push (Stack, 0);
	/* Creates binary digits left to right, halving num each iteration */
	while(num > 0)
		{
		if(num % 2 == 1)
			Push (Stack, 1);
		else
			Push (Stack, 0);
		num = num / 2;
		}
    	/* Print stack of binary */
	printf("Decimal %d is ", saveNum);
	while(!IsEmpty(Stack) )
		{
		printf("%d", Top(Stack) );
		Pop (Stack);
		}
	printf(" in binary.\n");

	FreeStack(&Stack);





	return(0);
	}
