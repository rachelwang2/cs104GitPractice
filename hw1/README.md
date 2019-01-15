#NAME: Rachel Wang
#EMAIL: wangrach@usc.edu

#CS104 Homework 1

##Included:

1. `hw1.txt`: text file with answers to problems 1 and 2
2. `hw1p4.pdf`: PDF file with answer to problem 4
3. `wsearch.cpp`: word search program (problem 5); code is compiled with parameters "g++ -g -Wall -std=c++11"; must provide TWO command line arguments (text file and target word)
4. `teams.cpp`: team combination program (problem 6); code is compiled with parameters "g++ -g -Wall -std=c++11"; must provide ONE command line argument (teams text file)

>Word Search Program:

	For the readGrid function, my code used stringstreams in conjunction with the getline command to take in each gridline, and then incorporated a while loop to push the individual letters into the vector<Vector<char> > grid. 
	For the findWordHelper function, I operated with base cases of:
	* The current location has an invalid row or column index, therefore returning false
	* The current index of the string matches the size of the word (given that arrays begin indexing at 0 the code was currWordIndex+1 == word.size())
	The function only returns true if the final letter is correct. If the recursive call is not a base case AND the current location matches the letter in question, my code returns the boolean result of a recursive call with the delta and index incremented.

>Teams Program:

	My approach to solving the combination problem was to generate all possible configurations for one team, and then generate the second team based on the remaining names. Therefore, I had two void functions, one called "comboHalf" that recursed down, and another called "otherHalf" that was called immediately before printing.
	My recursive base case is if the currentIndex matched the teamSize, or if the team is complete. If the call is not the base case, then my program iterates through a for loop the size of the name array that generates all the possible names for that index. Within this for loop, a recursive call is made that increases the index number of the team.