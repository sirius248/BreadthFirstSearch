

void Path::addFront(int x, int y, int xp, int yp){
    nodeptr n;
    n = new node;
    n->x = x;
    n->y = y;
    n->next = NULL;

    if(head ==NULL){
        head = n;
        n->parent == NULL;

    }else{
        n->next = head;
        head = n;
        nodeptr temp1;
        temp1 = head;
        while(temp1->next != NULL){
            if(temp1->x == xp && temp1->y == yp){
                n->parent = temp1;
                break;
            }
        } 
    }
}


void Path::connect_path(char map[][DEFAULT_ROW]){
    while(head->next != NULL){
        map[head->parent->x][head->parent->y] = 'p';
        head = head->next;
    }
}

