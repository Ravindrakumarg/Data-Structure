#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node()
	{
		left = nullptr;
		right = nullptr;
	}
	Node(int _data)
	{
		left = nullptr;
		right = nullptr;
		data = _data;
	}
};
Node * findSmallestNode(Node * temp);
class Tree
{
public:
	Node* root;
	Tree() { root = nullptr; }
	void insert_node(int data);
	int search_node(int data);
	Node* delete_node(Node* root, int data);
	void display_tree_inorder(Node*);
	void display_tree_preorder(Node*);
	void display_tree_postorder(Node*);
};

void Tree::insert_node(int data)
{
	Node* node = new Node(data);
	if (root == nullptr)
	{
		root = node;
	}
	else
	{
		Node *temp = root;
		while (1)
		{
			if (temp->data < data)
			{
				if (temp->right == nullptr)
				{
					temp->right = node;
					break;
				}
				temp = temp->right;
			}
			else
			{
				if (temp->left == nullptr)
				{
					temp->left = node;
					break;
				}
				temp = temp->left;
			}
		}
	}
}

Node* Tree::delete_node(Node * root, int data)
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;
	else
	{
		if (!search_node(data))
		{
			if (root->data >= data)
				root->left = delete_node(root->left, data);
			else if (root->data < data)
				root->right = delete_node(root->right, data);
			else
			{
				if (root->right == NULL)
				{
					Node *temp = root->left;
					delete root;
					return temp;
				}
				else if (root->left == NULL)
				{
					Node *temp = root->right;
					delete root;
					return temp;
				}
				else if (root->left == NULL && root->right == NULL)
				{
					delete root;
					return nullptr;
				}
				else
				{
					Node *node = findSmallestNode(root->right);
					root->data = node->data;
					root->right = delete_node(root->right, node->data);
				}
			}
		}
		else
		{
			cout << "Data to be delete not found" << endl;
		}
	}
	return root;
}

Node * findSmallestNode(Node * temp)
{
	Node *node = temp;
	while (node->left != nullptr)
		node = node->left;

	return node;
}

int Tree::search_node(int _data)
{
	if (root == nullptr)
		cout << "Tree is empty." << endl;
	else
	{
		Node *temp = root;
		while (temp != nullptr && temp->data != _data)
		{
			if (temp->data == _data)
				break;
			else if (temp->data < _data)
				temp = temp->right;
			else
				temp = temp->left;
		}

		if (temp != nullptr)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	return -1;
}

void Tree::display_tree_inorder(Node * root)
{
	if (root == nullptr)
		return;
	display_tree_inorder(root->left);
	cout << root->data << " ";
	display_tree_inorder(root->right);
}

void Tree::display_tree_preorder(Node* root)
{
	if (root == nullptr)
		return;
	cout << root->data << " ";
	display_tree_preorder(root->left);
	display_tree_preorder(root->right);
}

void Tree::display_tree_postorder(Node* root)
{
	if (root == nullptr)
		return;
	display_tree_postorder(root->left);
	display_tree_postorder(root->right);
	cout << root->data << " ";
}

int main()
{
	Tree *tree = new Tree();
	int chioce, data;
	cout << "1.Insert 2.Delete 3.Search 4.Display 0.Exit";
	while (1)
	{
		cout << endl << "Enter your choice: ";
		cin >> chioce;
		switch (chioce)
		{
		case 1:
			cout << endl << "Enter data: ";
			cin >> data;
			tree->insert_node(data);
			break;
		case 2:
			cout << endl << "Enter data you want to delete: ";
			cin >> data;
			tree->root = tree->delete_node(tree->root, data);
			break;
		case 3:
			cout << "Enter the number you want to search: ";
			cin >> data;
			if (!tree->search_node(data))
				cout << "Data found" << endl;
			else
				cout << "Data not found" << endl;
			break;
		case 4:
			cout << "InOrder: ";
			tree->display_tree_inorder(tree->root);
			cout << "\nPreOrder: ";
			tree->display_tree_preorder(tree->root);
			cout << "\nPostOrder: ";
			tree->display_tree_postorder(tree->root);
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << endl << "Kindly enter correct option:";
		}
	}
	return 0;
}
