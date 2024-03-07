#ifndef function
#define function
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

void creatRandomArray(int* a, int size);
void creatSortedArray(int* a, int size);
void creatReversedArray(int* a, int size);
void writeFileTXT(int* a, int size, string algo, string state);
void creatFileCSV(ofstream& file);

#endif // !function
