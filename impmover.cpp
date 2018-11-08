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
		int instances;	//The number of problems in the file
		int n;	//The size of the current problem
		int i;
		int j;
        
		string str;

		getline(inputFile, str);

		istringstream str2(str);

		str2 >> instances;

		//cout << instances;

		for (i = 0; i < instances; i++)
		{
			getline(inputFile, str);

			istringstream str3(str);

			str3 >> n;

			cout << endl << n << endl;

			vector<int> vec; //Vec will contain the current original problem

			while (getline(inputFile, str))	//Stores the current original problem into vector vec
			{
				istringstream str4(str);
				int num;

				while (str4 >> num)
				{
					vec.push_back(num);
					//cout << num << " ";
				}

				//cout << endl;

				if (str4.peek() != '\n')
					break;

				cout << endl;
			}
			int arr[n]={0};

			for (j = 0; j < vec.size(); j++) //This for loops just prints vec to make sure our current original problem was stored into our vector properly
			{
				cout << vec.at(j) << " ";
			}

			int k;
			int z;
			int current; //The current value we're at in the vector
			int count;

			cout << endl;

			vector<vector<int>> vecStore; //A vector of vectors acting as our direct map

			for (k = 0; k < n; k++)	//For all values starting at index 0 of Vec
			{
				vector<int> vecSequence; //Will store the current possibility into a vector vecSequence

				current = vec.at(k);

				vecSequence.push_back(current);	//Pushes the current value into our vector vecSequence

				count = 1; //Count starts at 1 because we'll always have at least 1 box in our vector as a possibility


				for (z = k + 1; z < n; z++) //For all values of Vec after our current k
				{
					if (vec.at(z) <= current)
					{
						current = vec.at(z); //Update current if vec.at(z) is less than or equal to current
						vecSequence.push_back(current); //Pushes the current value into our vector vecSequence
						count++;
					}
				}
				//Here we would store count into our direct map
                arr[k]=count;
				//cout << count << endl;

				cout << " " << endl;

				for (j = 0; j < vecSequence.size(); j++) //This for loop prints the current possibility stored in vecSequence
				{
					cout << vecSequence.at(j) << " ";
				}
				cout<<"count is = "<<arr[k];

				vecStore.push_back(vecSequence); //We would store vecSequence (vector with current possiblity) into vecStore (direct map), which will contain the vectors for all possibilities
			}
			int max =0;
			for (int x=0; x<n; x++)
			{
			     if(max < arr[i])
                    {
                        max = arr[i];
                    }
			}
			
			cout<<"\n the maximum number of boxes taken is ="<<max;
			cout<<"\n";
			//Here we would need to iterate through our direct map and return the largest count
		}

	}

	inputFile.close();

	cin.get();
	cin.get();

}