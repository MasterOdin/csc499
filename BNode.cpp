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

void BNode::setParent(BNode * node)
{
	parents[numOfP++] = node;
}

void BNode::setChild(BNode * node)
{
	children[numOfC++] = node;
	node->setParent(this);
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

void BNode::readInProb()
{
	ifstream probFile;
	string temp = "data/" + key + ".txt";
	string line;
	int count = 0;
	int tmp = 0;
	probFile.open(temp.c_str());
	if(probFile.is_open())
	{
		while(probFile.good() && count < arity)
		{
			getline(probFile,line);
			tmp = (atoi(line.c_str()))/100;
			tmp = (tmp < 0) ? 0 : tmp;
			ProbTable[count++] = tmp;
		}
	}
}

BNode::~BNode()
{
	delete [] ProbTable;
}

