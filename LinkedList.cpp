//Long Nguyen

#include "LinkedList.h"


void LinkedList::AddNode(int x, int y)
{
    nodeptr n, nTmp;
    n = new node;
    n->x = x;
    n->y = y;
    n->next = NULL;
    count++;

    if( start == NULL )
    {
		start = n;
		end = start; 
	}else{
		end->next = n;
		nTmp = end;
		end  = nTmp->next;
	}
}

void LinkedList::DeleteNode()
{
    nodeptr curr;
    if( start != NULL )
    {
        curr = start;
        start = start->next;
        delete curr;
        count--;
	} 
}

int LinkedList::Size(){
    return count;
}

