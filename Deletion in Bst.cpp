#include <iostream>
using namespace std;
struct bst
{
	int data;
	bst *left;
	bst *right;
};
bst *Findmin(bst *);
bst *root = NULL;
void insert()
{
	cout << "Enter node data " << endl;
	bst *newnode = new bst;
	cin >> newnode->data;
	newnode->left = newnode->right = NULL;
	if (root == NULL)
	{
		root = newnode;
	}
	else
	{
		bst *temp = root;
		while (temp != NULL)
		{
			if (newnode->data < temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = newnode;
					break;
				}
				else
				{
					temp = temp->left; // left aur neechay jao 

				}

			}
			else if (newnode->data > temp->data)
			{
				if (temp->right == NULL)
				{
					temp->right = newnode;
					break;
				}
				else
				{
					temp = temp->right; // right aur neechay jao 

				}

			}
			else
			{
				cout << "DUPLICATE DATA " << endl;
				break;
			}

		}
	}
}
bst *Delete(bst *root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	else if (data < root->data)
	{
		root->left = Delete(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = Delete(root->right, data);
	}
	else if (root->left == NULL && root->right == NULL)
	{
		bst *temp = root;
		root = NULL;
		delete temp;
	}
	else if (root->left == NULL)
	{
		bst *temp = root;
		root = root->right;
		delete temp;
	}
	else if (root->right == NULL)
	{
		bst *temp = root;
		root = root->left;
		delete temp;
	}
	else
	{
		bst *temp = Findmin(root->right);
		root->data = temp->data;
		root->right = Delete(root->right, temp->data);
	}

	return root;
}
bst *Findmin(bst *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}
void inorder(bst *temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{// inorder                               // preorder : 2,1,3  //post: 1,3,2 
		
		inorder(temp->left);                      // 1
		cout << temp->data << " ";             // 2
		inorder(temp->right);                     // 3
	}

}
void preorder(bst *temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{// inorder                               // preorder : 2,1,3  //post: 1,3,2 
		cout << temp->data << " ";                 
		preorder(temp->left);                      
		preorder(temp->right);                    
	}

}
void postorder(bst *temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{// inorder                               // preorder : 2,1,3  //post: 1,3,2 
		
		postorder(temp->left);
		postorder(temp->right);
		cout << temp->data << " ";
	}

}
// Recursive function to search in given BST
void *search(bst* root, int key, bst* parent)
{
	// if key is not present in the key
	if (root == nullptr)
	{
		cout << "Key Not found";
		return nullptr;
	}

	// if key is found
	if (root->data == key)
	{
		if (parent == nullptr)
			cout << "The node with key " << key << " is root node";

		else if (key < parent->data)
			cout << "Given key is left node of node with key "
			<< parent->data;

		else cout << "Given key is right node of node with key "
			<< parent->data;
		return nullptr;

	}

	// if given key is less than the root node, recur for left subtree
	// else recur for right subtree

	if (key < root->data)
	{
		return search(root->left, key, root);
	}
	else
	{
		return search(root->right, key, root);
	}

}
int height(bst* root)
{
	// Base case: empty tree has height 0
	if (root == nullptr)
		return 0;

	// recur for left and right subtree and consider maximum depth
	return 1 + (height(root->left), height(root->right));
}
int main()
{
	int x, y,z;
	cout << "How many nodes :" << endl;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		insert();
	}
	cout << "In which order you want to show data:" << endl;
	cout << "1) Preorder 2) Inorder 3) Post order" << endl;
	cin >> z;
	if (z == 1)
	{
		preorder(root);
	}
	else if (z == 2)
	{
		inorder(root);
	}
	else if(z == 3)
	{
		postorder(root);
	}
	cout << "Enter the number you want to delete:" << endl;
	cin >> y;
	Delete(root,y);
	inorder(root);
	cout << endl;
	system("pause");

}


