#include <iostream>
using namespace std;

//Zeynep Tulya Aytekin
//201811008

void introduction(){ //Brief introduction for gameplay
	cout<<"*********************************GAMEPLAY**********************************"<<endl;
	cout<<"0 |"<<" 1 |"<<" 2 |";
	cout<<endl<<"----------"<<endl;
	cout<<"3 |"<<" 4 |"<<" 5 |";
	cout<<endl<<"----------"<<endl;
	cout<<"6 |"<<" 7 |"<<" 8 |";
	
	cout<<endl<<"Location indexes are indicated above, please enter correct indexes"<<endl;
	cout<<"***************************************************************************"<<endl;
}


void print(char arr[]){		//drawing of the game board
	cout<<endl;
	for(int i=0; i<9; i++){
		cout<<arr[i]<< " |";
		if(i==2 || i==5){
			cout<<endl<<"--------"<<endl;	
		}
	}
	cout<<endl;
}
bool draw(char arr[]){ //checks whether its a draw or not
	for(int i=0; i<9; i++){ //if none of them is winning but the array is full, then it's a draw!
			if(arr[i]==' ')
				return false;
		}
	return true;
}

bool win(char arr[]){  //checks if a winning condition has occurred or not
	if (arr[0] == arr[1] and arr[0] == arr[2] and arr[0] != ' ')
        return true;
    else if (arr[3] == arr[4] and arr[3] == arr[5] and arr[3] != ' ')
        return true;
    else if (arr[6] == arr[7] and arr[6] == arr[8] and arr[6] != ' ')
        return true;
    else if (arr[0] == arr[3] and arr[0] == arr[6] and arr[0] != ' ')
        return true;
    else if (arr[1] == arr[4] and arr[1] == arr[7] and arr[1] != ' ')
        return true;
    else if (arr[2] == arr[5] and arr[2] == arr[8] and arr[2] != ' ')
        return true;
    else if (arr[0] == arr[4] and arr[0] == arr[8] and arr[0] != ' ')
        return true;
    else if (arr[6] == arr[4] and arr[6] == arr[2] and arr[6] != ' ')
        return true;
    else
        return false;
}
void isEmpty(char arr[], int loc,char play){ //to insert 'x' and 'o's, this function controls the locations
	int wrong=1;
	for(int j=0; j<9; j++){ //checks if a wrong location index has entered
		if(loc==j)
			wrong=0;
	}
	if(wrong==1)
		goto here; //directly leads to the else part if a wrong index has entered
	if(arr[loc]==' '){
		arr[loc]=play;
		print(arr);
		if(win(arr) && play =='X'){  //every time it controls the states of the game
			cout<<endl<<"COMPUTER WINS!!"<<endl;
			exit(0);
		}
		else if(win(arr) && play=='O'){
			cout<<endl<<"PLAYER WINS!"<<endl;	
			exit(0);
		}
		else if(draw(arr)){
			cout<<endl<<"DRAW!"<<endl;
			exit(0);
		}
	}
	else{
	here:
		cout<<"This location is not valid! Please try somewhere else!!"<<endl;
		cout<<"Please enter again: ";
		int index;
		cin >> index;
		isEmpty(arr, index, play);
	}
}




bool whoWon(char arr[], char p){	  //checks who won the game
	if (arr[0] == arr[1] and arr[0] == arr[2] and arr[0] == p)
        return true;
    else if (arr[3] == arr[4] and arr[3] == arr[5] and arr[3] == p)
        return true;
    else if (arr[6] == arr[7] and arr[6] == arr[8] and arr[6] == p)
        return true;
    else if (arr[0] == arr[3] and arr[0] == arr[6] and arr[0] == p)
        return true;
    else if (arr[1] == arr[4] and arr[1] == arr[7] and arr[1] ==  p)
        return true;
    else if (arr[2] == arr[5] and arr[2] == arr[8] and arr[2] == p)
        return true;
    else if (arr[0] == arr[4] and arr[0] == arr[8] and arr[0] == p)
        return true;
    else if (arr[6] == arr[4] and arr[6] == arr[2] and arr[6] == p)
        return true;
    else
        return false;
}

int minimax(char arr[], int depth,bool isMaximizing){
	int bestScore;
	int score;
    if (whoWon(arr, 'X'))
        return 1;
    else if (whoWon(arr, 'O'))
        return -1;
    else if (draw(arr))
        return 0;
    if (isMaximizing){
        bestScore = -10;  //initialization for controls
        for (int i=0; i<9; i++){
            if (arr[i] == ' '){
                arr[i] = 'X';
                score = minimax(arr, depth + 1, false);
                arr[i] = ' ';
                if (score > bestScore)
                    bestScore = score;
        	}
    	}
       	return bestScore;
	}
    else{
        bestScore = 10; //initialization for controls
        for (int i=0; i<9; i++){
            if (arr[i] == ' '){
                arr[i] = 'O';
                score = minimax(arr, depth + 1, true);
                arr[i] = ' ';
                if (score < bestScore)
                    bestScore = score;
        	}
    	}
        return bestScore;
	}
}

void AI(char arr[]){ //for computer move 
	int score;
    int bestScore = -10;//initialization 
    int bestMove = 0;
    for(int i=0; i<9; i++){
		if(arr[i]==' '){
			arr[i]='X';
			score = minimax(arr, 0, false); //computer makes it's move with minimax algorithm
            arr[i] = ' ';
            if (score > bestScore){
                bestScore = score;
                bestMove = i;
            }
		}
	}
	isEmpty(arr, bestMove, 'X');
}

int main (void){
	
	
	char* arr = new char[9];
	cout<<"TIC-TAC-TOE \n\n";
	introduction();
	cout<<endl<<"START"<<endl;
	int index;
	for(int i=0; i<9; i++){
			arr[i]=' ';
	}
	while(!win(arr)){
		AI(arr);
		cout<<endl<<"Enter the position for 'O': ";
		cin>>index;
    	isEmpty(arr, index, 'O');
	}
	
	
}


