#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Node  {
	int weight;

	vector<Node> neighbours;

	void addNeighbour(Node child) {
		this->neighbours.push_back(child);
	}
};

struct Tree {
	Node* root;
	vector<Node> nodes;

	void print(Node* root) {
		if (root == NULL)
			return;

		cout << root.weight;

		for(Node child : root.neighbours) {
			print(child);
		}
	}

	void construct(pair<int, int> edges [], int N) {
		for(int i = 0; i < N; i++) 
		{
			pair<int, int> edge = edges[i];
			
		}
	}
};


int main(int argc, char const *argv[])
{
	// parsing input
	int N;
	cin >> N;

	pair<int, int> edges [N - 1];

	for(int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1;
		cin >> n2;

		edges[i] = pair<int, int>(n1, n2);	
	}

	int q;
	cin >> q;
	int queries[q]; 

	for(int i = 0; i < q; i++) {
		cin >> queries[i];
	}

	// create tree from input
	Tree t;
	t.construct(edges, N - 1);    

	cout << "Tree Weights";

	return 0;
}
