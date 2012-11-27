#ifndef BNODE_H
#define BNODE_H
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAXP = 6;
const int MAXC = 6;

class BNode
{
	public:
		/* Default Constructor */
		BNode();
		/* Constructor - Sets name with string parameter */
		BNode(string,string);
		string getName();
		string getKey();
		void setParent(BNode *);
		void printParents();
		void setChild(BNode *);
		void printChildren();
		void setArity();
		int getArity();
		void setArity(int);
		void readInProb();
		double getProbability(int);
		~BNode();

	protected:
		BNode * parents[MAXP];
		BNode * children[MAXC];
		int numOfP;
		int numOfC;
		int arity;
		double * ProbTable;
		string name;
		string key;
	private:
};

#endif // BNODE_H
