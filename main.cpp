#include <stdio.h>
#include "BNode.h"

using namespace std;

const int NODECOUNT = 9;

int main(int argc, const char* argv[])
{
	BNode * nodeArray[NODECOUNT];

	nodeArray[0] = new BNode("Population");
	nodeArray[0]->setArity(3);

	nodeArray[1] = new BNode("Time of Day");
	nodeArray[1]->setArity(5);

	nodeArray[2] = new BNode("Lighting");
	nodeArray[2]->setArity(5);

	nodeArray[3] = new BNode("Drugs");
	nodeArray[3]->setArity(5);

	nodeArray[4] = new BNode("Location At");
	nodeArray[4]->setArity(3);

	nodeArray[5] = new BNode("Location From");
	nodeArray[5]->setArity(3);

	nodeArray[6] = new BNode("Murder");
	nodeArray[7] = new BNode("Robbery");
	nodeArray[8] = new BNode("Rape");

	for(int i = 0; i < 6; i++)
		for(int j = 6; j < 9; j++)
			nodeArray[i]->setChild(nodeArray[j]);

	nodeArray[6]->setArity();
	nodeArray[7]->setArity();
	nodeArray[8]->setArity();

	return 0;
}
