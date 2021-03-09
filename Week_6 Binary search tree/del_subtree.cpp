// Ilya Dubitskiy
// Week_6_task_4_ver_1






#include <vector>

#include "edx-io.hpp"


class my_node
{
public:
	long key;
	long numb_of_el;

	my_node* left;
	my_node* right;
	my_node* parent;

	my_node(long key = -1, my_node* left = NULL, my_node* right = NULL, long numb_of_el = 0, my_node* parent = NULL);

};

my_node::my_node(long k, my_node* l, my_node* r, long nu_el, my_node* p) :key(k), left(l), right(r), numb_of_el(nu_el), parent(p)
{}

long max_depth(my_node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		long left = max_depth(node->left);
		long right = max_depth(node->right);

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

my_node* get_node(my_node* curr_node, long key)
{
	if (curr_node == NULL || curr_node->key == key)
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

long nodes_numb(my_node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		long left = nodes_numb(node->left);
		long right = nodes_numb(node->right);

		//io << "__" << left + right + 1;
		return left + right + 1;
	}
}

long del_subtree(my_node* curr_node, long key, long tree_size)
{
	my_node* curr_subtree = get_node(curr_node, key);
	
	long subtree_size = 0;


	if (curr_subtree == NULL)
	{
		//io << "__" << subtree_size <<"__key__" << key;
		return  tree_size - subtree_size;
	}
	else
	{
		subtree_size = nodes_numb(curr_subtree);

		if (curr_subtree->parent->left == curr_subtree)
		{
			curr_subtree->parent->left = NULL;
		}
		else if (curr_subtree->parent->right == curr_subtree)
		{
			curr_subtree->parent->right = NULL;
		}

		curr_subtree = NULL;
		return tree_size - subtree_size;
	}

}




int main()
{


	//clock_t t;
	//t = clock();

	long node_numb = 0;
	long del_numb = 0;
	long key;

	io >> node_numb;

	std::vector<my_node> tree(node_numb + 1);

	long left = 0;
	long right = 0;
	long tree_size = 0;
	
	tree_size = node_numb;

	for (long i = 1; i <= node_numb; i++)
	{
		io >> tree[i].key;
		io >> left;
		io >> right;


		if (i == 1)
		{
			tree[1].parent = NULL;
		}
		if (left != 0 && right != 0)
		{
			tree[i].left = &tree[left];
			tree[i].right = &tree[right];

			tree[i].left->parent = &tree[i];
			tree[i].right->parent = &tree[i];
		}
		else if (left == 0 && right != 0)
		{
			tree[i].left = NULL;
			tree[i].right = &tree[right];

			tree[i].right->parent = &tree[i];
		}
		else if (left != 0 && right == 0)
		{
			tree[i].left = &tree[left];
			tree[i].right = NULL;

			tree[i].left->parent = &tree[i];
		}
		else if (left == 0 && right == 0)
		{
			tree[i].left = NULL;
			tree[i].right = NULL;
		}
	}

	//io << tree[1].key << "\n";
	io >> del_numb;



	for (long i = 0; i < del_numb; i++)
	{
		io >> key;
		tree_size =  del_subtree(&tree[1],  key, tree_size);
		io << tree_size << "\n";

		
	}
	
		

	//io << "\nNumb of elements in tree: " << nodes_numb(&tree[1]) << "\n";


	return 0;

}
