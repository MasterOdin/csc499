#ifndef BNODE_H
#define BNODE_H
#include <string>
using namespace std;

const int MAXP = 6;
const int MAXC = 6;

class BNode
{
	public:
		BNode();
		BNode(string);
		void setParent(BNode *);
		void setChild(BNode *);
		void setArity();
		void setArity(int);
		~BNode();

	protected:
		BNode * parents[MAXP];
		BNode * children[MAXC];
		int numOfP;
		int numOfC;
		int arity;
		double * ProbTable;
		string name;
	private:
};

#endif // BNODE_H
