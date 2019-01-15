#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

// @brief Prints a single combination of teams
//
// @param[in] team1 Array containing the names of team 1
// @param[in] team2 Array containing the names of team 2
// @param[in] len Size of each array
void printSolution(const string* team1, 
       const string* team2,
       int len)
{
  cout << "\nCombination " << combo++ << endl;
  cout << "T1: ";
  for(int i=0; i < len; i++){
    cout << team1[i] << " ";
  }
  cout << endl;
  cout << "T2: ";
  for(int i=0; i < len; i++){
    cout << team2[i] << " ";
  }
  cout << endl;
}

// You may add additional functions here
void otherHalf(string* nameArray, int nameCount, string* team1,
 string* team2, int teamSize) {
  int teamIndex = 0;
  for (int i = 0; i < nameCount; i++) { //runs through all names
    bool repeat = false;
    for (int j = 0; j < teamSize; j++) { //runs through team1 array
      if (nameArray[i] == team1[j]) { //if they are the same
        repeat = true;
      }
    }
    if (!repeat) {
      team2[teamIndex] = nameArray[i];
      teamIndex++;
    }
  }
}

void comboHalf(string* nameArray, const int nameCount, const int teamSize, 
string* team1, string* team2, int i, int currentIndex) {
   if (currentIndex == teamSize) { //RECURSIVE BASE CASE
     otherHalf(nameArray, nameCount, team1, team2, teamSize);
     printSolution(team1, team2, teamSize);
   }
   else {
     for (i; i < nameCount; i++) {
       team1[currentIndex] = nameArray[i];
       comboHalf(nameArray, nameCount, teamSize, team1, team2, i+1, currentIndex+1);
     }
   }
}



int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a file of names" << endl;
    return 1;
  }

  ifstream ifile(argv[1]);
  if (ifile.fail()) {
    cout << "Error" << endl;
    return 1;
  }

  int nameCount;
  ifile >> nameCount;
  if (ifile.fail()) {
    cout << "Error" << endl;
    return 1;
  }

  string* nameArray = new string[nameCount];
  for (int i = 0; i < nameCount; i++) {
    ifile >> nameArray[i];
    if (ifile.fail()) {
      cout << "Error" << endl;
      return 1;
    }
  }

  int teamSize = nameCount/2;
  string* team1 = new string[teamSize];
  string* team2 = new string[teamSize];

  comboHalf(nameArray, nameCount, teamSize, team1, team2, 0, 0);

  //DELETING DYNAMIC MEMORY
  delete[] nameArray;
  delete[] team1;
  delete[] team2;

  return 0;
}

