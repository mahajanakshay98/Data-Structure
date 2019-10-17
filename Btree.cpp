#include <iostream>
using namespace std;
#include <iomanip>

class Binary
{
	struct Node
	{
		Node* left;
		Node* right;
		int value;

		Node(int value)
			:left(nullptr),right(nullptr),value(value)
		{
		}
	};

	Node *root;

	Node* addnode(Node *node,int value)
	{
		if(nullptr == node)
			return new Node(value);
		if(value > node->value)
			node->right = addnode(node->right,value);
		else
			node->left = addnode(node->left,value);
		return node;
	}

	Node* removenode(Node* node, int value)
	{
		if(nullptr == node)
		{
			return node;
		}
		if(value > node->value)
		{
			node->right = removenode(node->right,value);
		}
		else if(value < node->value)
		{
			node->left = removenode(node->left,value);
		}
		else
		{
			if(value == node->value)
			{
				if(node->left == nullptr && node->right == nullptr)
				{
					delete node;
					return nullptr; ///***
				}
				if(node->left == nullptr && node->right != nullptr)
				{
					Node *temp = node->right;
					delete node;
					return temp;
				}
				if(node->left != nullptr && node->right == nullptr)
				{
					Node* temp = node->left;
					delete node;
					return temp;
				}
				Node* successor = node->right;
				while(successor->left)
				{
					successor= successor->left;
				}
				node->value = successor->value;
				node->right =removenode(node->right,successor->value);
			}

		}
		return node;
	}


	void printDebug(Node *node)
	{
		static int level = 0;
		if(node)
		{
			level++;
			printDebug(node->right);
			cout << setw(level*4) << "" <<node->value <<endl;
			printDebug(node->left);
			level--;
		}
	}

public:
	Binary():
		root(nullptr)
	{
	}
	void add(int value)
	{
		root = addnode(root,value);
	}

	void print ()
	{
		printDebug(root);
	}

	void remove(int num)
	{
		root = removenode(root,num);
	}
	

};

int main()
{
	int num;
	Binary b;
	while (cout <<"Enter the values of trees (0 to exit)",
		cin >> num,num)
	{
		b.add(num);
		b.print();

	}


	while (cout <<"Enter the values to Remove (0 to exit)",
		cin >> num,
		num)
	{
		b.remove(num);
		b.print();

	}
}