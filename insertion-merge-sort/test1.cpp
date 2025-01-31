// program that generates 10 random, distinct numbers

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

bool findNumber(int number, vector<int>& generatedNumbers){
	for (int i = 0; i < generatedNumbers.size(); i++){
		if (number == generatedNumbers[i]) { return true; break; }
	}
	return false;
}

int main(){
	fstream File;
    File.open("1.txt", fstream::out);
	vector<int> generatedNumbers;
	
	srand(time(0));
	
	for (int i = 0; i < 10; i++){
		int temp = rand() % 100;
		while (findNumber(temp, generatedNumbers) == true) {
			temp = rand() % 100;
		}
		cout << temp << " ";
		File << temp << endl;
		generatedNumbers.push_back(temp);
	}
	
	File.close();
	return 0;
}