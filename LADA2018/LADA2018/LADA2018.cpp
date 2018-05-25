#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int weight;
	vector<int> neighbors;
};


int main()
{
	int n = 0; cin >> n;
	Node *List = new Node[n];
	int idx = 0;
	while(cin >> idx) {
		int val = 0; cin >> val;
		List[idx].neighbors.push_back(val);
	}

	system("pause");
	return 0;
}