#include <stdio.h>
#include "BNode.h"

using namespace std;

const int NODECOUNT = 9;

int main(int argc, const char* argv[])
{
	BNode * nodeArray[NODECOUNT];

	nodeArray[0] = new BNode("Population","population");
	nodeArray[0]->setArity(3);
	nodeArray[1] = new BNode("Lighting","lighting");
	nodeArray[1]->setArity(5);
	nodeArray[2] = new BNode("Time of Day","timeOfDay");
	nodeArray[2]->setArity(5);
	nodeArray[3] = new BNode("Drugs","drugs");
	nodeArray[3]->setArity(5);
	nodeArray[4] = new BNode("Location At","locAt");
	nodeArray[4]->setArity(6);
	nodeArray[5] = new BNode("Location From","locFrom");
	nodeArray[5]->setArity(6);
	nodeArray[6] = new BNode("Murder","murder");

	nodeArray[7] = new BNode("Robbery","robbery");

	nodeArray[8] = new BNode("Rape","rape");

	for(int i = 0; i < 6; i++)
		for(int j = 6; j < 9; j++)
			nodeArray[i]->setChild(nodeArray[j]);

	nodeArray[6]->setArity();
	nodeArray[7]->setArity();
	nodeArray[8]->setArity();


	/*cout << "Murder: " << nodeArray[6]->getArity() << endl;
	nodeArray[6]->printParents();
	cout << "Robbery: " << nodeArray[7]->getArity() << endl;
	nodeArray[7]->printParents();
	cout << "Rape: " << nodeArray[8]->getArity() << endl;
	nodeArray[8]->printParents();*/

	int array[6];
	for(int i = 0; i < 6; i++)
	{
		array[i] = 1;
	}
	//cout << "Probability of Murder with (P=1,Light=1,ToD=1,Drugs=1,Lat=1,Lfrom=1) = " << nodeArray[6]->getProbability(array) << endl;


	for(int i = 0; i < 10; i++)
	{
		cout << nodeArray[6]->getProbability(array) << endl;
		array[5]++;
	}

	array[0] = 2;
	array[1] = 4;
	array[2] = 5;
	array[3] = 5;
	array[4] = 3;
	array[5] = 1;

	cout << nodeArray[6]->getProbability(array) << endl;
	cout << nodeArray[0]->getProbability(2) << endl;

	return 0;
}
