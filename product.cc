#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>

#define A_LENGTH 7
#define B_LENGTH 6
#define C_LENGTH 2
#define Q_LENGTH 14
#define ALPHA_LENGTH 3
#define FINA_LENGTH 4
#define FINB_LENGTH 3
#define FINC_LENGTH 1
#define FINCNOT_LENGTH 1
using namespace std;

int A [A_LENGTH] = {0, 1, 2, 3, 4, 5, 6};
int B [B_LENGTH] = {0, 1, 2, 3, 4, 5};
int C [C_LENGTH] = {0, 1};
string Q [Q_LENGTH];

int delA[A_LENGTH][ALPHA_LENGTH] = {
	{1,2,3},
	{1,4,4},
	{5,2,5},
	{6,6,5},
	{1,4,4},
	{5,2,5},
	{6,6,3},	
};

int delB[B_LENGTH][ALPHA_LENGTH]= {
	{1,2,0},
	{1,3,4},
	{1,2,3},
	{3,3,3},
	{4,4,4},
	{5,5,5},
};

int delC[C_LENGTH][ALPHA_LENGTH]={
	{0,1,0},
	{1,0,1}
};

int finA[FINA_LENGTH] = {0,1,2,3};
int finB[FINB_LENGTH] = {3,4,5};
int finC[FINC_LENGTH] = {0};
int finCNOT[FINCNOT_LENGTH] = {1};

void printElement(string t, const int& width)
{
	const char separator    = ' ';
	cout << left << setw(width) << setfill(separator) << t << "|";
}


void printIntersection(){
	cout << "F = { " << endl;
	//Determine new states
	for(int i=0;i<FINA_LENGTH;i++){
		for(int j=0;j<FINCNOT_LENGTH;j++){
			cout << "(a" + to_string(finA[i]) + ", c" + to_string(finCNOT[j]) + ")" << ", ";
		}
		cout << endl;
	}
	cout << "}" << endl;
}


void printUnion(){
	cout << "F = { " << endl;
	//F1 x Q2
	for(int i=0;i<FINC_LENGTH;i++){
		for(int j=0;j<C_LENGTH;j++){
			cout << "(c" + to_string(finC[i]) + ", d" + to_string(C[j]) + ")" << ", ";
		}
		cout << endl;
	}

	//Q1 x F2
	for(int i=0;i<C_LENGTH;i++){
		for(int j=0;j<FINC_LENGTH;j++){
			cout << "(c" + to_string(C[i]) + ", d" + to_string(finCNOT[j]) + ")" << ", ";
		}
		cout << endl;
	}
	cout << "}" << endl;
}

int main(){

	cout << "Q = { " << endl;
	//Determine new states
	int counter = 0;
	for(int i=0;i<C_LENGTH;i++){
		for(int j=0;j<C_LENGTH;j++){
			Q[counter]= "(c" + to_string(C[i]) + ", d" + to_string(C[j]) + ")";
			cout << Q[counter]<< ", ";
		}
		cout << endl;
	}

	cout << "}" << endl;
	
	
	
    	const int nameWidth     = 10;
    	const int numWidth      = 10;

	cout << "Transition Function: " <<endl;

	//Determine Transition Function
	printElement("",nameWidth);
	for(int i=0;i<3;i++){
		printElement(to_string(i), numWidth);	
	}
	cout << endl;
	for(int i=0;i<C_LENGTH;i++){
		for(int j=0;j<C_LENGTH;j++){
			printElement("(c" + to_string(C[i]) + ", d" + to_string(C[j]) + ") ", nameWidth);
			for(int k=0;k<3;k++){
				printElement("(c" + to_string(delC[i][k]) + ", d" + to_string(delC[j][k]) + ") ", numWidth);
			}
			cout << endl;
		}
	}

	//Print Final States
	printUnion();

}
