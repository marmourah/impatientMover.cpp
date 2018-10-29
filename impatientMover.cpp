# impatientMover.cpp
Algorithms Group Project 2

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int x;

	//Read input file
	ifstream inputFile;
	inputFile.open("input.txt");

	if (!inputFile) {
		cout << "The file does not exist.";
	}

	else {
		int instances;
		int n;
		int i;
		int j;

		string str;

		getline(inputFile, str);

		istringstream str2(str);

		str2 >> instances;

		cout << instances;

		for (i = 0; i < instances; i++)
		{
			getline(inputFile, str);

			istringstream str3(str);

			str3 >> n;

			cout << endl << n << endl;

			vector<int> vec;

			while (getline(inputFile, str))
			{
				istringstream str4(str);
				int num;

				while (str4 >> num)
				{
					vec.push_back(num);
					cout << num << " ";
				}

				cout << endl;

				if (str4.peek() != '\n')
					break;

				cout << endl;
			}

			for (j = 0; j < vec.size(); j++)
			{
				cout << vec.at(j) << " ";
			}

			int k;
			int z;
			int current;
			int count;

			cout << endl;

			vector<vector<int>> vecStore; //Direct Map

			for (k = 0; k < n; k++)
			{
				vector<int> vecSequence;

				count = 1;

				current = vec.at(k);

				vecSequence.push_back(current);

				for (z = k + 1; z < n; z++)
				{
					if (vec.at(z) < current) //Less than, or less than/equal to??
					{
						current = vec.at(z);
						vecSequence.push_back(current);
						//count++;
					}
				}
				//Here we would store count into our direct map
				//cout << count << endl;

				cout << " " << endl;

				for (j = 0; j < vecSequence.size(); j++)
				{
					cout << vecSequence.at(j) << " ";
				}

				vecStore.push_back(vecSequence);
			}
			//Here we would need to iterate through our direct map and return the largest count
		}

	}

	inputFile.close();

	cin.get();
	cin.get();

}
