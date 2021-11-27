#pragma once
#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

double calcTimeAlgo(int arr[], int n, int type);
void doAlgo(int arr[], int n, int index);
long long doAlgoCount(int arr[], int n, int index);
bool isNum(char *s);
int getType(char*);
int getOrder(char*);

void printResults(int mode, string time1 = "", string time2 ="", string comparisions1 = "", string comparisions2 = "", 
    string algo1="", string algo2 = "", string input ="", string size ="", string order = "");
    
void checkRequest(char* c, double& time, long long &comparisions, int a[], int n, int type);