//Long Nguyen


class LinkedList
{
public:
struct node {
        int x;
        int y;
        node *next;
};
    typedef node* nodeptr;
    nodeptr start;
    nodeptr end;
    int count;

public:

    LinkedList(){
      start = NULL;
      end   = start;
   }

   void AddNode(int x, int y);
   void DeleteNode();
   int Size();
};