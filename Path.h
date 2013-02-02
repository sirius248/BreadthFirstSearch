//Long Nguyen

class Path{
public:
struct node {
        int x;
        int y;
        node *next;
        node *parent;
    };

    typedef node* nodeptr;
    nodeptr head;

	Path(){
		head = NULL; 
	}

    void addFront(int x, int y, int xp, int yp);
    void connect_path(char map[][DEFAULT_ROW]);
};