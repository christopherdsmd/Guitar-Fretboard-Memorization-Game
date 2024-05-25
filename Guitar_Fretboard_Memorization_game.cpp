#include <iostream>
#include <string>
#include <cctype>       /* toupper */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

//converts cin inputs to always be uppercase  
string toUpperCase(string str) {
    for (size_t i = 0; i < str.size(); ++i) {
        str[i] = toupper(str[i]);
    }
    return str;
}

//print string names
void printString(int i)	
{
            switch(i) {
                case 1:
                    cout << "1st String" << endl;
                    break;
                case 2: 
                    cout << "2nd String" << endl;
                     break;
                case 3:
                    cout << "3rd  String" << endl;
                     break;
                case 4:
                    cout << "4th  String" << endl;
                     break;
                case 5:
                    cout << "5th  String" << endl;
                    break;
                case 6: 
                    cout << "6th  String" << endl;
                    break;
            }
}


void printFrets(int i)  //print proper fret names   
{
            switch(i) {
                case 1:
                    cout << "Fret Open" << endl;
                    break;
                case 2: 
                    cout << "Fret 3" << endl;
                     break;
                case 3:
                    cout << "Fret 5" << endl;
                     break;
                case 4:
                    cout << "Fret 7" << endl;
                     break;
                case 5:
                    cout << "Fret 9?" << endl;
                    break;
                case 6: 
                    cout << "Fret 12?" << endl;
                    break;
            }
}

int main() {
    // Random number generator 1-6 (corresponds to each string)
    srand(time(NULL)); // Seed random number generator
    // Debug: cout << "random num = " << randNum << endl;
    
    // Correct answers for guitar fretboard
    string fret_answers[6][6] = {
        {"E", "G", "A", "B", "C#", "E"},
        {"B", "D", "E", "F#", "G#", "B"},
        {"G", "A#", "C", "D", "E", "G"},
        {"D", "F", "G", "A", "B", "D"},
        {"A", "C", "D", "E", "F#", "A"},
        {"E", "G", "A", "B", "C#", "E"}
    };
    
    // Game quiz switch statement
    string user_Ans; // User's answer variable
   
 bool game = true;
while(game) {
    bool winLose = true;
    int randNum = rand() % 6 + 1;	//set random number generator 1-6 for strings
            printString(randNum --);
            for (int i = 1; i <= 6; ++i) { // Loop through frets 1 to 6
            
               printFrets(i);
                cin >> user_Ans;
                user_Ans = toUpperCase(user_Ans);
                
                if(user_Ans == fret_answers[randNum][i - 1]) {
                    cout << "Correct!" << endl;
                } else {
                    cout << "Incorrect. The correct answer is " << fret_answers[randNum][i - 1] << "." << endl;
                    winLose = false;
                }
            }


    //win lose message
    if(winLose) {
        cout << "\nYou Win!" << endl;
    } else {
        cout << "\nYou Lose" << endl;
    }
    
        //print string answers
        for (int i = 0; i < 6; ++i) {
        cout << fret_answers[randNum][i] << " ";
        }
		

//play again ?
int playagain;
cout << "\n \nPlay again ? \n1 = Yes\n2 = No" << endl;
cin >> playagain;

if(playagain == 2) {
    exit(0);
}
}
 return 0;
}
