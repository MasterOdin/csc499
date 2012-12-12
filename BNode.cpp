#include "BNode.h"

using namespace std;

BNode::BNode()
{
	numOfP = 0;
	numOfC = 0;
	arity = 0;
}

BNode::BNode(string n, string k)
{
	key = k;
	name = n;
	numOfP = 0;
	numOfC = 0;
	arity = 0;
}

string BNode::getName()
{
	return name;
}

string BNode::getKey()
{
	return key;
}

void BNode::setParent(BNode * node)
{
	parents[numOfP++] = node;
}

void BNode::printParents()
{
	/* to do: print parents */
	for(int i = 0; i < numOfP; i++)
	{
		cout << parents[i]->getName() << endl;
	}
}

void BNode::setChild(BNode * node)
{
	children[numOfC++] = node;
	node->setParent(this);
}

void BNode::printChildren()
{
	/* to do: print children */
}

void BNode::setArity()
{
	double temp = 1;
	for(int i = 0; i < numOfP; i++)
	{
		temp *= parents[i]->arity;
	}
	arity = temp;
	ProbTable = new double[arity];
	readInProb();
}

void BNode::setArity(int a)
{
	arity = a;
	ProbTable = new double[arity];
	readInProb();
}

int BNode::getArity()
{
	return arity;
}

void BNode::readInProb()
{
	ifstream probFile;
	string temp = "data/" + key + ".txt";
	string line;
	int count = 0;
	double tmp = 0;
	probFile.open(temp.c_str());
	if(probFile.is_open())
	{
		while(probFile.good() && count < arity)
		{

			getline(probFile,line);
			tmp = (atoi(line.c_str()));
			tmp = tmp/100;
			tmp = (tmp < 0) ? 0 : tmp;
			ProbTable[count++] = tmp;
		}
	}
}

double BNode::getProbability(int n)
{
	return ProbTable[n-1];
}

double BNode::getProbability(int n[])
{
	int tmp = 1;
	int actualP = 0;
	for(int i = (numOfP-1); i >= 0; i--)
	{
		if((n[i]-1) > parents[i]->getArity())
		{
			// return negative number to indicate error in bounds
			return -1;
		}
		actualP += (n[i]-1)*tmp;
		tmp *= parents[i]->getArity();
	}

	return ProbTable[actualP];
}

BNode::~BNode()
{
	delete [] ProbTable;
}

