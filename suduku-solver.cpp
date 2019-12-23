#include<iostream>

using namespace std;

class Board{
	int arr[9][9] ;  
public:
	Board(){
		cout<<"Please enter the values row wise\n\n";
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>arr[i][j];
			}
		}

		// arr = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
  //                     {5, 2, 0, 0, 0, 0, 0, 0, 0},  
  //                     {0, 8, 7, 0, 0, 0, 0, 3, 1},  
  //                     {0, 0, 3, 0, 1, 0, 0, 8, 0},  
  //                     {9, 0, 0, 8, 6, 3, 0, 0, 5},  
  //                     {0, 5, 0, 0, 9, 0, 6, 0, 0},  
  //                     {1, 3, 0, 0, 0, 0, 2, 5, 0},  
  //                     {0, 0, 0, 0, 0, 0, 0, 7, 4},  
  //                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};

		cout<<"The entered board is\n\n";
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<arr[i][j]<<' ' ;
			}
			cout<<endl;
		}

	}

	bool inRow(int r , int i){
		for(int j=0;j<9;j++){
			// if(j==r)	continue;
			if(arr[r][j] == i)	return true;
		}
		return false;
	}

	bool inCol(int c , int i){
		for(int j=0;j<9;j++){
			// if(j==r)	continue;
			if(arr[j][c] == i)	return true;
		}
		return false;
	}

	bool inBox(int r,int c,int i){
		for(int j=(r/3)*3;j<(r/3)*3+3;j++){
			for(int k=(c/3)*3;k<(c/3)*3+3;k++){
				if(arr[j][k] == i)	return true;
			}
		}
		return false;
	}

	bool chkSafeState(int r,int c,int i){

		if(inRow(r,i))	return false;
		if(inCol(c,i))	return false;
		if(inBox(r,c,i))return false;


		return true;
	}

	bool findUnassigned(int& r , int& c){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(arr[i][j] == 0){
					r=i;c=j;
					return true;
				}
			}
		}
		return false;
	}

	void print(){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<arr[i][j]<<' ';

			}
			cout<<endl;
		}
	}

	bool solve(){
		int r , c;
		if(this->findUnassigned(r,c) == false)	return true;

		for(int i=0;i<9;i++){
			if(!this->chkSafeState(r,c,i+1))	continue;

			arr[r][c] = i+1;
			
			if(this->solve())	return true;
			arr[r][c] = 0;
		}
		return false;

	}

};

int menu(){
	cout<<"1or2\n\n";
	int ch;
	cin>>ch;
	return ch;
}

int main(){
	int flag = 1;

	while(flag){
		int var = -1;
		var = menu();
		switch(var){
			case 1: {
				Board board ;
				bool t = board.solve();
				if(t){
					cout<<"Solution is \n";
					board.print();
					cout<<"\n\n\n";
				}
				else{
					cout<<"Not Solvable\n\n\n";
				}
				// free(board);
				break;
			}
			case 2: {
				flag = 0;
				break;
			}
		}
	}

	return 0;
}