// Ilya Dubitskiy
// Week_7_task_3_ver_1


#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <time.h>
#include <cmath>

#include <iomanip>


#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <stack>

#define COUNT 10  

int if_exit_rec = 0;
int if_exit_rec_del = 0;

//#include "edx-io.hpp"

long str_numb_2 = 0;

class my_node
{
public:
	long key;
	long height;
	long balance;

	my_node* left;
	my_node* right;
	my_node* parent;
	//my_node* parent;

	my_node(long key = -1, my_node * left = nullptr, my_node * right = nullptr, long height = -1, long balance = -100, my_node* parent = nullptr);

};

my_node::my_node(long k, my_node* l, my_node* r, long h, long b, my_node* p) :key(k), left(l), right(r), height(h), balance(b), parent(p)
{}

void print2DUtil(my_node* root, int space)
{
	
	if (root == NULL)
		return;

	
	space += COUNT;

	
	print2DUtil(root->right, space);

	std::cout << std::endl;
	for (int i = COUNT; i < space; i++)
		std::cout << " ";
	std::cout << root->key << "\n";

	
	print2DUtil(root->left, space);
}


void print2D(my_node* root)
{
	
	print2DUtil(root, 0);
}

long calc_height(my_node* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	else
	{
		long left = calc_height(node->left);
		long right = calc_height(node->right);

		if (left > right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}

long calc_height_and_init(my_node* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	else
	{
		long left = calc_height_and_init(node->left);
		long right = calc_height_and_init(node->right);

		if (left > right)
		{
			node->height = left + 1;
			return left + 1;
		}
		else
		{
			node->height = right + 1;
			return right + 1;
		}
	}
}

void init_balance(my_node* tree, long node_numb)
{
	for (long i = 1; i <= node_numb; i++)
	{
		if (tree[i].right == nullptr && tree[i].left == nullptr)
		{
			tree[i].balance = 0;
		}
		else if (tree[i].right != nullptr && tree[i].left == nullptr)
		{
			tree[i].balance = tree[i].right->height + 1;
		}
		else if (tree[i].right == nullptr && tree[i].left != nullptr)
		{
			tree[i].balance = -1 - tree[i].left->height;
		}
		else
		{
			tree[i].balance = tree[i].right->height - tree[i].left->height;
		}
	}
}

my_node* get_node(my_node* curr_node, long key)
{
	if (curr_node == nullptr || curr_node->key == key)
	{
		return curr_node;
	}
	else if (curr_node->key > key)
	{
		return get_node(curr_node->left, key);
	}
	else if (curr_node->key < key)
	{
		return get_node(curr_node->right, key);
	}

}

long height_of_node(my_node* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	return node->height;
}

long get_balance(my_node* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	return height_of_node(node->right) - height_of_node(node->left);
}




my_node* left_turn(my_node* node)
{
	if (node->right->balance == 1)
	{
		my_node* A = node;
		my_node* B = node->right;
		my_node* X = node->left;
		my_node* Y = node->right->left;
		my_node* Z = node->right->right;

		B->parent = A->parent;
		A->parent = B;
		if (Y != nullptr)
		{
			Y->parent = A;
		}

		A->right = Y;
		B->left = A;

		A->balance = 0;
		B->balance = 0;

		return B;

	}
	else if (node->right->balance == 0)
	{
		my_node* A = node;
		my_node* B = node->right;
		my_node* X = node->left;
		my_node* Y = node->right->left;
		my_node* Z = node->right->right;

		B->parent = A->parent;
		A->parent = B;
		if (Y != nullptr)
		{
			Y->parent = A;
		}

		A->right = Y;
		B->left = A;

		A->balance = 1;
		B->balance = -1;

		return B;
	}
	else if (node->right->balance == -1)
	{
		if (node->right->left->balance == -1)
		{
			my_node* A = node;
			my_node* B = node->right;
			my_node* W = node->left;
			my_node* Z = node->right->right;
			my_node* C = node->right->left;
			my_node* X = node->right->left->left;
			my_node* Y = node->right->left->right;

			C->parent = A->parent;
			A->parent = C;
			B->parent = C;
			if (X != nullptr)
			{
				X->parent = A;
			}
			if (Y != nullptr)
			{
				Y->parent = B;
			}

			A->right = X;
			B->left = Y;
			C->left = A;
			C->right = B;

			A->balance = 0;
			B->balance = 1;
			C->balance = 0;

			return C;
		}
		else if (node->right->left->balance == 0)
		{
			my_node* A = node;
			my_node* B = node->right;
			my_node* W = node->left;
			my_node* Z = node->right->right;
			my_node* C = node->right->left;
			my_node* X = node->right->left->left;
			my_node* Y = node->right->left->right;

			C->parent = A->parent;
			A->parent = C;
			B->parent = C;
			if (X != nullptr)
			{
				X->parent = A;
			}
			if (Y != nullptr)
			{
				Y->parent = B;
			}

			A->right = X;
			B->left = Y;
			C->left = A;
			C->right = B;

			A->balance = 0;
			B->balance = 0;
			C->balance = 0;

			return C;
		}
		else if (node->right->left->balance == 1)
		{
			my_node* A = node;
			my_node* B = node->right;
			my_node* W = node->left;
			my_node* Z = node->right->right;
			my_node* C = node->right->left;
			my_node* X = node->right->left->left;
			my_node* Y = node->right->left->right;

			C->parent = A->parent;
			A->parent = C;
			B->parent = C;
			if (X != nullptr)
			{
				X->parent = A;
			}
			if (Y != nullptr)
			{
				Y->parent = B;
			}

			A->right = X;
			B->left = Y;
			C->left = A;
			C->right = B;

			A->balance = -1;
			B->balance = 0;
			C->balance = 0;

			return C;
		}

	}
}

my_node* right_turn(my_node* node)
{
	if (node->left->balance == -1)
	{
		my_node* B = node;
		my_node* A = node->left;
		my_node* delta = node->right;
		my_node* alpha = node->left->left;
		my_node* gamma = node->left->right;


		A->parent = B->parent;
		B->parent = A;
		if (gamma != nullptr)
		{
			gamma->parent = B;
		}

		A->right = B;
		B->left = gamma;

		A->balance = 0;
		B->balance = 0;

		return A;
	}
	else if (node->left->balance == 0)
	{
		my_node* B = node;
		my_node* A = node->left;
		my_node* delta = node->right;
		my_node* alpha = node->left->left;
		my_node* gamma = node->left->right;


		A->parent = B->parent;
		B->parent = A;
		if (gamma != nullptr)
		{
			gamma->parent = B;
		}

		A->right = B;
		B->left = gamma;

		A->balance = 1;
		B->balance = -1;

		return A;
	}
	else if (node->left->balance == 1)
	{
		if (node->left->right->balance == 1)
		{
			my_node* B = node;
			my_node* A = node->left;
			my_node* C = node->left->right;
			my_node* eps = node->right;
			my_node* alpha = node->left->left;
			my_node* gamma = node->left->right->left;
			my_node* delta = node->left->right->right;

			C->parent = B->parent;
			A->parent = C;
			B->parent = C;
			if (gamma != nullptr)
			{
				gamma->parent = A;
			}
			if (delta != nullptr)
			{
				delta->parent = B;
			}

			C->left = A;
			C->right = B;
			A->right = gamma;
			B->left = delta;

			A->balance = -1;
			B->balance = 0;
			C->balance = 0;

			return C;

		}
		else if (node->left->right->balance == 0)
		{
			my_node* B = node;
			my_node* A = node->left;
			my_node* C = node->left->right;
			my_node* eps = node->right;
			my_node* alpha = node->left->left;
			my_node* gamma = node->left->right->left;
			my_node* delta = node->left->right->right;

			C->parent = B->parent;
			A->parent = C;
			B->parent = C;
			if (gamma != nullptr)
			{
				gamma->parent = A;
			}
			if (delta != nullptr)
			{
				delta->parent = B;
			}

			C->left = A;
			C->right = B;
			A->right = gamma;
			B->left = delta;

			A->balance = 0;
			B->balance = 0;
			C->balance = 0;

			return C;

		}
		else if (node->left->right->balance == -1)
		{
			my_node* B = node;
			my_node* A = node->left;
			my_node* C = node->left->right;
			my_node* eps = node->right;
			my_node* alpha = node->left->left;
			my_node* gamma = node->left->right->left;
			my_node* delta = node->left->right->right;

			C->parent = B->parent;
			A->parent = C;
			B->parent = C;
			if (gamma != nullptr)
			{
				gamma->parent = A;
			}
			if (delta != nullptr)
			{
				delta->parent = B;
			}

			C->left = A;
			C->right = B;
			A->right = gamma;
			B->left = delta;

			A->balance = 0;
			B->balance = 1;
			C->balance = 0;

			return C;

		}
	}

}



/* Print nodes at a given level */
void printGivenLevel(my_node* node, long level)
{
	if (node == NULL)
		return;
	if (level == 1)
	{
		if (node->left != nullptr && node->right != nullptr)
		{
			std::cout << node->key << " " << str_numb_2 + 1 << " " << str_numb_2 + 2 << "\n";
			str_numb_2 += 2;
			//return str_numb;
		}
		else if (node->left == nullptr && node->right != nullptr)
		{
			std::cout << node->key << " " << 0 << " " << str_numb_2 + 1 << "\n";
			str_numb_2++;
			//return str_numb;
		}
		if (node->left != nullptr && node->right == nullptr)
		{
			std::cout << node->key << " " << str_numb_2 + 1 << " " << 0 << "\n";
			str_numb_2++;
			//return str_numb;
		}
		if (node->left == nullptr && node->right == nullptr)
		{
			std::cout << node->key << " " << 0 << " " << 0 << "\n";
			//return str_numb;
		}
	}
	else if (level > 1)
	{
		printGivenLevel(node->left, level - 1);
		printGivenLevel(node->right, level - 1);
	}
}



/* Function to print level
order traversal a tree*/
void printLevelOrder(my_node* root)
{
	long h = calc_height(root) + 1;
	long i;
	for (i = 1; i <= h; i++)
		printGivenLevel(root, i);
}


void print_tree(my_node* node, long str_numb)
{

	if (node == nullptr)
	{
		return;
	}

	if (node->left != nullptr && node->right != nullptr)
	{
		std::cout << node->key << " " << str_numb + 1 << " " << str_numb + 2 << "\n";
		str_numb += 2;
	}
	else if (node->left == nullptr && node->right != nullptr)
	{
		std::cout << node->key << 0 << " " << str_numb + 1 << "\n";
		str_numb++;
	}
	if (node->left != nullptr && node->right == nullptr)
	{
		std::cout << node->key << " " << str_numb + 1 << " " << 0 << "\n";
		str_numb++;
	}
	if (node->left == nullptr && node->right == nullptr)
	{
		std::cout << node->key << " " << 0 << " " << 0 << "\n";
	}

	if (str_numb % 2 != 0)
	{
		print_tree(node->left, str_numb);
	}
	else
	{
		print_tree(node->right, str_numb);
	}

}

my_node* insert_node(my_node* root, my_node* new_node, std::stack<long> left_right_stack)
{


	if (root == nullptr)
	{
		return new_node;
	}

	if (new_node->key < root->key)
	{
		left_right_stack.push(-1);
		root->left = insert_node(root->left, new_node, left_right_stack);

	}
	else if (new_node->key > root->key)
	{
		left_right_stack.push(1);
		root->right = insert_node(root->right, new_node, left_right_stack);
	}
	else
	{
		return root;
	}

	if (if_exit_rec == 1)
	{
		return root;
	}

	if (left_right_stack.top() == -1)
	{
		root->balance -= 1;
		left_right_stack.pop();

		if (root->balance == 0)
		{
			if_exit_rec = 1;
		}
	}
	else if (left_right_stack.top() == 1)
	{
		root->balance += 1;
		left_right_stack.pop();
		if (root->balance == 0)
		{
			if_exit_rec = 1;
		}
	}

	if (root->balance == 2)
	{
		root = left_turn(root);
		if (root->balance == 0)
		{
			if_exit_rec = 1;
		}
	}
	if (root->balance == -2)
	{
		root = right_turn(root);
		if (root->balance == 0)
		{
			if_exit_rec = 1;
		}
	}

	return root;
}

my_node* find_max_subtree(my_node* node)
{
	my_node* curr = node;

	while (curr->right != nullptr)
	{
		curr = curr->right;
	}

	return curr;
}

my_node* del_node(my_node* root, long target_key, std::stack<long> left_right_stack)
{

	if (root == nullptr)
	{
		return root;
	}
	
	if (target_key < root->key)
	{
		left_right_stack.push(-1);
		root->left = del_node(root->left, target_key, left_right_stack);
	}
	else if (target_key > root->key)
	{
		left_right_stack.push(1);
		root->right = del_node(root->right, target_key, left_right_stack);
	}
	else
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			root = nullptr;
		}
		else if (root->left == nullptr)
		{
			my_node* right_child = root->right;

			root = right_child;
			
			return root;
			//left_right_stack.push(0);
		}
		else
		{
			left_right_stack.push(-1);
			my_node* R = find_max_subtree(root->left);
			long R_key = R->key;
			root->key = R_key;
			root->left = del_node(root->left, R_key, left_right_stack);
		}
	}

	if (root == nullptr)
	{
		return root;
	}

	if (if_exit_rec_del == 1)
	{
		return root;
	}

	if (!left_right_stack.empty())
	{
		if (left_right_stack.top() == -1)
		{
			root->balance += 1;
			left_right_stack.pop();

			if (root->balance == 1 || root->balance == -1)
			{
				if_exit_rec_del = 1;
			}
		}
		else if (left_right_stack.top() == 1)
		{
			root->balance -= 1;
			left_right_stack.pop();
			if (root->balance == 1 || root->balance == -1)
			{
				if_exit_rec_del = 1;
			}
		}
	}

	if (root->balance == 2)
	{
		root = left_turn(root);
		if (root->balance == 1 || root->balance == -1)
		{
			if_exit_rec_del = 1;
		}
	}
	if (root->balance == -2)
	{
		root = right_turn(root);
		if (root->balance == 1 || root->balance == -1)
		{
			if_exit_rec_del = 1;
		}
	}

	return root;

}

int main()
{
	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());


	long oper_numb = 0;
	char oper_type = 0;
	long key = 0;
	my_node* root = nullptr;
	//my_node* new_node_ptr = nullptr;;

	

	std::cin >> oper_numb;

	std::vector<my_node> new_node_vect(oper_numb);

	for (long i = 0; i < oper_numb; i++)
	{

		std::cin >> oper_type;

		if (oper_type == 'A')
		{
			std::cin >> key;
			std::stack<long> left_right_stack;

			if_exit_rec = 0;

			if (root != nullptr)
			{
				my_node* if_node_exists = get_node(root, key);
				if (if_node_exists == nullptr)
				{
					new_node_vect[i] =  my_node(key, nullptr, nullptr, 0, 0, nullptr);

					root = insert_node(root, &new_node_vect[i], left_right_stack);
				}
				if (root != nullptr)
				{
					std::cout << root->balance << "\n";
				}
				else
				{
					std::cout << 0 << "\n";
				}
			}
			else
			{
				new_node_vect[i] = my_node(key, nullptr, nullptr, 0, 0, nullptr);

				root = insert_node(root, &new_node_vect[i], left_right_stack);
				if (root != nullptr)
				{
					std::cout << root->balance << "\n";
				}
				else
				{
					std::cout << 0 << "\n";
				}
			}


		}
		else if (oper_type == 'D')
		{
			std::cin >> key;
			std::stack<long> left_right_stack_del;

			if_exit_rec_del = 0;

			
			if (root != nullptr)
			{
				my_node* if_node_exists = get_node(root, key);
				if (if_node_exists != nullptr)
				{
					root = del_node(root, key, left_right_stack_del);
				}

				if (root != nullptr)
				{
					std::cout << root->balance << "\n";
				}
				else
				{
					std::cout << 0 << "\n";
				}
			}
			else
			{
				std::cout << 0 << "\n";
			}
		}
		else if (oper_type == 'C')
		{
			std::cin >> key;

			my_node* curr_el = get_node(root, key);
			
			if (curr_el == nullptr)
			{
				std::cout << "N" << "\n";
			}
			else
			{
				std::cout << "Y" << "\n";
			}
		}


	}



	//calc_height_and_init(&tree[1]);
	//init_balance(&tree[0], node_numb);


	//std::stack<long> left_right_stack;
	//std::stack<long> left_right_stack_del;
	//my_node* new_node = &my_node(target_key, nullptr, nullptr, 0, 0, nullptr);
	//my_node* new_root = insert_node(&tree[1], new_node, left_right_stack);
	//my_node* new_root = del_node(&tree[1], target_key, left_right_stack_del);
	//node_numb -= 1;

	std::cout << "\n\n\n\n\n";
	print2D(root);



	str_numb_2 = 1;
	std::cout << "\n\n\n\n\n";
	//std::cout << node_numb << "\n";
	printLevelOrder(root);


	return 0;

}