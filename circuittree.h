#include <vector>
#include <string>

struct CircuitElement{
	CircuitElement(cirElemType Type) {}
	enum cirElemType {R, C, Q, L, W, FLWs, FLWo, dL};
	std::string Name;
	cirElemType elemType;
	std::vector <std::string> ParNameList;
	std::vector <double> ParValList;
	std::vector <double> dV; //To store the first-order derivative
	std::vector <double> dV2;  //To store the second-order derivative;
};

struct ctNode{
	enum ctNodeType {Open,Wire,Serial,Parallel, Element};
	ctNodeType nodeType;
	std::vector <ctNode*> children;
	ctNode* parent;
	ctNode (ctNodeType Type): nodeType (Type) {parent = NULL;}
};

class CircuitTree{
	CircuitTree ();
	~CircuitTree ();
	list<ctNode*> NodeList;
};
