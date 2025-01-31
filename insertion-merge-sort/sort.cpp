#include<iostream>
#include<ctime>
#include<vector>
#include<fstream>
#include<cmath> // ceil and floor
using namespace std;

int testCounter = 1;
clock_t before, duration;

fstream file;
void read(string, vector<int>&); // reads the content of a string filename and stores it in a vector
void insertionSort(vector<int>&); // sorts the list using insertion sort, then gets the running time
void mergeSort(vector<int>&, int, int); // sorts the list using merge sort, then gets the running time
void merge(vector<int>&, int, int, int); // merges the sorted branches in the list 

int main(){
    vector<int> numset;

    read("1.txt", numset); insertionSort(numset);
    read("1.txt", numset); mergeSort(numset, 0, numset.size() - 1);
    duration = clock() - before;
    cout << "Running time of test #" << testCounter << " in Merge Sort: " << (float)duration / (CLOCKS_PER_SEC / 1000) << " seconds" << endl;
    testCounter++;

    read("2.txt", numset); insertionSort(numset);
    read("2.txt", numset); mergeSort(numset, 0, numset.size() - 1);
    duration = clock() - before;
    cout << "Running time of test #" << testCounter << " in Merge Sort: " << (float)duration / (CLOCKS_PER_SEC / 1000) << " seconds" << endl;
    testCounter++;

    read("3.txt", numset); insertionSort(numset);
    read("3.txt", numset); mergeSort(numset, 0, numset.size() - 1);
    duration = clock() - before;
    cout << "Running time of test #" << testCounter << " in Merge Sort: " << (float)duration / (CLOCKS_PER_SEC / 1000) << " seconds" << endl;
    testCounter++;

    read("4.txt", numset); insertionSort(numset);
    read("4.txt", numset); mergeSort(numset, 0, numset.size() - 1);
    duration = clock() - before;
    cout << "Running time of test #" << testCounter << " in Merge Sort: " << (float)duration / (CLOCKS_PER_SEC / 1000) << " seconds" << endl;
    testCounter++;

    return 0;
}

void read(string filename, vector<int>& numset){
    numset.erase(numset.begin(), numset.end()); // clears the content of the vector
    int data;
    file.open(filename);
    file >> data;
    numset.push_back(data);
    while (!file.eof()){
        file >> data;
        numset.push_back(data);
    }
    numset.pop_back(); // removes the dupe last element in the vector ( this is one weird way of solving the issue; i am currently half asleep solving this )
    file.close();
}

void insertionSort(vector<int>& numset){
    before = clock();
    for ( int j = 1; j < numset.size(); j++) {
        int key = numset[j];
        int i = j - 1;
        while ( i >= 0 && numset[i] > key){
            numset[i+1] = numset[i];
            i--; 
        }
        numset[i+1] = key;
    }
    duration = clock() - before;

    cout << "Running time of test #" << testCounter << " in Insertion Sort: " << (float)duration / CLOCKS_PER_SEC << " seconds" << endl;
}

void mergeSort(vector<int>& numset, int left, int right){
    before = clock();
    if ( left >= right ) return;

    int mid = left + (right - left) / 2;
    mergeSort( numset, left, mid );
    mergeSort( numset, mid + 1, right);
    merge( numset, left, mid, right);
}

void merge(vector<int>& numset, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = numset[left + i];
    for (int j = 0; j < n2; j++) R[j] = numset[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { numset[k] = L[i]; i++; }
        else { numset[k] = R[j]; j++; }
        k++;
    }

    while ( i < n1 ) {
        numset[k] = L[i];
        i++; k++;
    }

    while ( j < n2 ) {
        numset[k] = R[j];
        j++; k++;
    }
}
