#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct letter_node
{
	char letter;
	struct letter_node *left;
	struct letter_node *right;
};

typedef struct letter_node Node;

Node *create_node(Node *node, char letter)
{
	if(letter != ' ')
	{
		if(node == NULL)
		{
			Node *new_node = (Node*) malloc(sizeof(Node));
			new_node->letter = letter;
			new_node->left = NULL;
			new_node->right = NULL;
			node = new_node;
			printf("%c", letter);
		}
		else
		{
			if(letter <= node->letter)
			{
				node->left = create_node(node->left, letter);
			}
			else
			{
				node->right = create_node(node->right, letter);
			}
		}
	}
	return node;
}

Node *create_tree(char *string)
{
	Node *tree = NULL;
	if(string == NULL)
	{
		printf("String nula!");
	}
	else
	{
		int count = 0;
		for(count = 0; count < strlen(string); count++){
			tree = create_node(tree, string[count]);
		}
	}
	return tree;
}


void print_tree(Node *tree){
	if(tree == NULL){
		printf("Erro");
		return;
	}
	if(tree->left != NULL){
		print_tree(tree->left);
	}if(tree->right != NULL){
		print_tree(tree->right);
	}
	printf("%c", tree->letter);
}

void imprime(Node *node){
	if(node == NULL)
		return;
	printf("%c", node->letter);
	imprime(node->left);
	imprime(node->right);
}

int main()
{
	char *sample = "engenharia";
	Node *tree = create_tree(sample);
	printf("\n");
	print_tree(tree);
	printf("\n");
	imprime(tree);
	printf("\n");
	free(tree);
	return 0;
}
