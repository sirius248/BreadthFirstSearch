


void loadInitialState(int arr[]);
void loadMap(char map[][DEFAULT_ROW],int column,int row);
int checker(int x);
void print_map(char map[][DEFAULT_ROW], int row, int col);
void breadth_first_search(char map[][DEFAULT_ROW], LinkedList f, int row, int col, int goalX, int goalY, Path family);


int main(){
    int initial[6];
    loadInitialState(initial);
    int row, col, startX, startY, goalX, goalY;
    col = initial[0];
    row = initial[1];
    startX = initial[2];
    startY = initial[3];
    goalX = initial[4];
    goalY = initial[5];
    char map[row][DEFAULT_ROW];
    loadMap(map,col,row);
    map[startX][startY] = '@';
    map[goalX][goalY] = '#';
    print_map(map,row,col);
    cout<<"-----------------------"<<endl;
    LinkedList frontier;
    Path family;
    frontier.AddNode(startX,startY);
    breadth_first_search(map, frontier, row, col, goalX, goalY, family);
	print_map(map,row,col);
	return 0;
}


void print_map(char map[][DEFAULT_ROW],int row, int col){
    for(int i=0; i<row; i++){
        for(int j = 0; j <col; j++){
            cout<<map[j][i];
		}
        cout<<""<<endl;
    }
}

void loadInitialState(int arr[]){
    FILE *input;
    input = fopen("/Users/vangnol/Desktop/map1.txt", "r");   //This need to change to get program run
    int i=0;
    for(i; i<6; i++){
        fscanf(input, "%d",&arr[i]);
    }
}


void loadMap(char map[][DEFAULT_ROW],int column,int row){
    FILE *input;
    input = fopen("/Users/vangnol/Desktop/map1.txt", "r");
    char str[10];
    char line[100];
    // skip the first 3 line
    int i=1;
    while(i<=6){
        fscanf(input,"%s",str);
		i++; 
	}
	char c = getc(input);

    // starting load map
    int j=0;
    int k=0;
    for(j; j<row; j++){
        fscanf(input,"%s",line);
        for(k;k<column;k++){
            map[k][j] = line[k];
        }
		k = 0; 
	}
    // load map finished
}

int checker(int x){
    if (x < 0) {
		return 0; 
	}
    else {
        return x;
	} 
}


void breadth_first_search(char m[][DEFAULT_ROW], LinkedList f, int row, int
col, int goalX, int goalY, Path family){
    m[f.start->x][f.start->y] = 'v';
    int x,y;
    x = f.start->x;
    y = f.start->y;

    if (f.start->x == goalX && f.start->y == goalY) {
        return;
	}
    if (m[x][checker(y-1)] != 'W' && m[x][checker(y-1)] !='v' && x < col && y < row) {
        f.AddNode(x, y-1);
    }
    if (m[x][checker(y+1)] != 'W' && m[x][checker(y+1)] !='v' && x < col && y < row) {
        f.AddNode(x, y+1);
    }
    if (m[checker(x-1)][y] != 'W' && m[checker(x-1)][y] !='v' && x < col && y < row) {
        family.addFront(x-1,y,x,y);
        f.AddNode(x-1, y);
    }
    if (m[checker(x+1)][y] != 'W' && m[checker(x+1)][y] !='v' && x < col && y < row) {
        f.AddNode(x+1, y);
    }

    while(f.Size() != 0){
        f.DeleteNode();
        x = f.start->x;
        y = f.start->y;
        m[x][y] = 'v';
        if (x == goalX && y == goalY) {
            return;
		}
        if (m[x][checker(y-1)] != 'W' && m[x][checker(y-1)] !='v' && x < col && y < row) {
            f.AddNode(x, y-1);
        }
        if (m[x][checker(y+1)] != 'W' && m[x][checker(y+1)] !='v' && x < col && y < row) {
            f.AddNode(x, y+1);
        }
        if (m[checker(x-1)][y] != 'W' && m[checker(x-1)][y] !='v' && x < col && y < row) {
        	   f.AddNode(x-1, y);
        }
        if (m[checker(x+1)][y] != 'W' && m[checker(x+1)][y] !='v' && x < col && y < row) {
            f.AddNode(x+1, y);
        }
    }
    family.connect_path(m);
}



