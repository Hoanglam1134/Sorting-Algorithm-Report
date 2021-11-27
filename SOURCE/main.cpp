#include <iostream>
#include "constants.h"
#include "sort.h"
#include "sort_with_count.h"
#include "func.h"
#include "DataGenerator.h"

int main(int argc, char *argv[])
{
	int n = 0;
	if (argc != 5 && argc != 6)
	{
		cout << "Wrong command !!";
		return 0;
	}
	if (strcmp(argv[1], "-a") == 0)
	{
		if (!isNum(argv[3]))
		{
			// xu ly command 1
			ifstream is(argv[3]);
			if(!is) return 0;
			ofstream os("output.txt");
			is >> n;
			os << n << endl;
			int *a = new int[n];
			for (int i = 0; i < n; i++)
				is >> a[i];
			int type = getType(argv[2]);
			double time = -1;
			long long comparisions = -1;
			checkRequest(argv[4], time, comparisions, a, n, type);
			for (int i = 0; i < n; i++)
				os << a[i] << ' ';
			printResults(1, to_string(time), "", to_string(comparisions), "", argv[2], "", argv[3], to_string(n));
			is.close();
			os.close();
			delete[] a;
		}
		else if (argc == 6)
		{
			// xu ly command 2
			n = atoi(argv[3]);
			ofstream input("input.txt");
			ofstream os("output.txt");
			os << n << endl;
			int *a = new int[n];
			int type = getType(argv[2]);
			int order = getOrder(argv[4]);
			GenerateData(a, n, order);
			input << n << endl;
			for (int i = 0; i < n; i++)
			{
				input << a[i] << ' ';
			}
			long long comparisions = -1;
			double time = -1;
			checkRequest(argv[5], time, comparisions, a, n, type);
			for (int i = 0; i < n; i++)
				os << a[i] << ' ';
			printResults(1, to_string(time), "", to_string(comparisions), "", argv[2], "", "", argv[3], argv[4]);
			delete[] a;
			os.close();
			input.close();
		}
		else
		{
			// xu ly command 3
			int type = getType(argv[2]);
			n = atoi(argv[3]);
			int *a = new int[n];
			long long comparisions = -1;
			double time = -1;
			cout << "ALGORITHM MODE\n";
			cout << "Algorithm: " << argv[2] << endl;
			cout << "Input size: " << argv[3] << endl;
			for (int i = 0; i < 4; i++)
			{
				string name = "input_" + to_string(i + 1) + ".txt";
				ofstream input(name);
				input << n << endl;
				GenerateData(a, n, i);
				for (int i = 0; i < n; i++)
					input << a[i] << ' ';
				checkRequest(argv[4], time, comparisions, a, n, type);
				cout << "Input order: " << dataType[i] << endl;
				cout << "----------------------------\n";
				cout << "Running time (if required): ";
				if (time != -1)
					cout << time << "ms";
				cout << "\nComparisions (if required): ";
				if (comparisions != -1)
					cout << comparisions;
				cout << "\n\n";
				input.close();
			}
			delete[] a;
		}
	}
	else
	{
		if (argc == 5)
		{
			// xu ly command 1
			int size;
			int algo1 = getType(argv[2]);
			int algo2 = getType(argv[3]);
			ifstream is(argv[4]);
			if(!is) return 0;
			is >> size;
			int *a = new int[size];
			int *a1 = new int[size];
			int *a2 = new int[size];
			int *a3 = new int[size];
			for (int i = 0; i < size; i++){
				is >> a[i];
				a1[i] = a2[i] = a3[i] =a[i];
			}
			double time1 = calcTimeAlgo(a, size, algo1);
			double time2 = calcTimeAlgo(a1, size, algo2);
			long long comp1 = doAlgoCount(a2, size, algo1);
			long long comp2 = doAlgoCount(a3, size, algo2);
			printResults(2, to_string(time1), to_string(time2), to_string(comp1), to_string(comp2), argv[2], argv[3], argv[4], to_string(size));
			delete[] a,a1,a2,a3;
			is.close();
		}
		else
		{
			// xu ly command 2
			ofstream input("input.txt");
			int algo1 = getType(argv[2]);
			int algo2 = getType(argv[3]);
			int size = atoi(argv[4]);
			int order = getOrder(argv[5]);
			int *a = new int[size];
			int *a1 = new int[size];
			int *a2 = new int[size];
			int *a3 = new int[size];
			GenerateData(a, size, order);
			input << size << endl;
			for (int i = 0; i < size; i++){
				input << a[i] << ' ';
				a1[i] = a2[i] = a3[i] =a[i];
			}
			double time1 = calcTimeAlgo(a, size, algo1);
			double time2 = calcTimeAlgo(a1, size, algo2);
			long long comp1 = doAlgoCount(a2, size, algo1);
			long long comp2 = doAlgoCount(a3, size, algo2);
			printResults(2, to_string(time1), to_string(time2), to_string(comp1), to_string(comp2), argv[2], argv[3], "", to_string(size), argv[5]);
			delete[] a, a1, a2, a3;
			input.close();
		}
	}
}