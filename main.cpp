#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int args, char **argv)
{
	ifstream inFile;
	inFile.open(argv[1]);
	ofstream outFile1(argv[2], ifstream::trunc);
	ofstream outFile2(argv[3], ifstream::trunc);
	int size = 0;
	string data;

	while(inFile >> data)
		if(size < atoi(data.c_str()))
			size = atoi(data.c_str());
	inFile.close();
	int* Bucket_Arry = new int[size+1];

	for(int i = 0; i <= size; i++)
		Bucket_Arry[i] = 0;
	
	inFile.open(argv[1]);

	for(int i = 0; i <= size; i++)
		outFile1 << Bucket_Arry[i] << " ";
	outFile1 << endl << endl;

	while(inFile >> data)
	{
		Bucket_Arry[atoi(data.c_str())]++;
		for(int i = 0; i <= size; i++)
			outFile1 << Bucket_Arry[i] << " ";
		outFile1 << endl << endl;
	}

	int index = 0;

	while(index <= size)
	{
		for(int i = 0; i < index; i++)
		{
			if(Bucket_Arry[index] > 0)
				outFile2 << index << " ";
			Bucket_Arry[index]--;
		}
		index++;
	}

	inFile.close();
	outFile1.close();
	outFile2.close();

	return 0;
}