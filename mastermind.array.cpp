/****************************************************************************
 * 
 * Proj.02: An implementation of the Mastermind game
 *  
 * File Name: mastermind.cpp
 * Name:      Matt DeChance
 * Course:    CPTR 1CODE1
 * Date:      November 27, 2017
 * 
 */   
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
//functions
void getColors(char colors[], int CODE);
bool checkInput(char usercolors[], int CODE, int);
const bool debug = true;

int main(){
	//open output
    ofstream fout;
    fout.open ("gameboard.txt");
    if(!fout)
      cout << "Can't open file" << endl;
      
    //vairables
    const int CODE=4;
	char colors[CODE];
    char usercolors[CODE];
	int turncounter = 0;
	
	//generate randome Code
	getColors(colors,CODE);
	
	//show answers
	if(debug){
		fout << "Answers-" << "	" << colors[0] << " " << colors[1] <<
		" " << colors[2] << " " << colors[3] << endl;
	}

	//start of game
	cout << "We have our colors!" << endl;
	//gameboard
	fout << "		Welcome to Mastermind		|" <<
	endl << "————————————————————————————————————|" << endl;
	while(turncounter != 10){
		turncounter++;

		//guessing prompt
		cout << "Current try: " << turncounter << endl;
		cout << "Valid Guesses: 'R' 'B' 'Y' 'G' 'P'" << endl;
		fout << "Turn: " << turncounter << endl;
		
		//gathering and checking for valid input
		for(int i=0;i<CODE;i++){
			cout << "Color " << i +1 << ": "; 
			cin >> usercolors[i];
			if(checkInput(usercolors, CODE, i)==false){
				i=i-1;
			}
			else
				fout << "	" <<usercolors[i] << "	";
		}
		//giving pegs
		fout << "	|";
		for(int i=0;i<CODE;i++){		
			if(usercolors[i] == colors[i])
				fout << "B" << " ";
		    }
		
		    if(usercolors[0] == colors[1] || 
		   usercolors[0] == colors[2] ||
		   usercolors[0] == colors[3] ){
			   fout << "W" << " ";
		    }
		   
		   if(usercolors[1] == colors[0] ||
			  usercolors[1] == colors[2] ||
		      usercolors[1] == colors[3]){
				fout << "W" << " ";
		   }
		  
		   if(usercolors[2] == colors[0] ||
			  usercolors[2] == colors[1] ||
		 	  usercolors[2] == colors[3]){
			   fout << "W" << " ";
		   }
		   
		   if(usercolors[3] == colors[0] ||
			  usercolors[3] == colors[1] ||
			  usercolors[3] == colors[2]){
				fout << "W" << " ";
			}
			
		fout << endl;
		//WIN or LOSE
		if(usercolors[0] == colors[0] &&
		   usercolors[1] == colors[1] &&
		   usercolors[2] == colors[2] &&
		   usercolors[3] == colors[3])
		{
			cout << "You Win!";
			fout << "You win! Number of tries: " << turncounter << endl;
			break;
		}else{
			cout << "Nope." << endl;
		}

	}
	//out of turns
	if(turncounter == 10){
		cout << "You lost." << endl;
		fout << "The correct combination was-" << endl << "	" << 
		colors[0] << "		" << colors[1] <<
		"		" << colors[2] << "		" << colors[3] << endl;
		fout << "You lose, try again.";
	}
	
	fout.close();
	return 0;
}


//*******************************************
void getColors(char colors[], int CODE){
	
	srand(time(0));
	int randomint = (rand()%5)+1;

	for(int i=0;i<CODE;i++){
	randomint = (rand()%5)+1;

	 switch(randomint){
	 case 1:
		 colors[i] = 'R';
		 break;
	 case 2:
		 colors[i] = 'B';
		 break;
	 case 3:
		 colors[i] = 'Y';
		 break;
	 case 4:
		 colors[i] = 'P';
		 break;
	 case 5:
		 colors[i] = 'G';
		 break;
	 
	 }
	}
}
bool checkInput(char usercolors[],int CODE, int i){
	if(usercolors[i] == 'R' || usercolors[i] == 'B' || usercolors[i] == 'Y' ||
		usercolors[i] == 'P' || usercolors[i] == 'G'){
		return true;
	}
		return false;
}

