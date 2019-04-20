#include "Tree.h"

Node_t *Tree = NULL;
Node_t *Tree_Root = NULL;
bool isWorking = true;
object_t Tree_obj;

char * buffer = NULL;

void Tree_erase(Node_t *node)
{
	Node_t *child = node->child;
	while (child)
	{
		Node_t *temp = child->next;
		Tree_erase(child);
		child = temp;
	}
	node->child = NULL;
	free(node->cmd);
	node->cmd = NULL;
	free(node);
}

void Tree_RegCommand(const char *Expression, float value, callBack_t action)
{
	Grab_setIRD_Flag(false);

	Node_t *temp;

	if (Tree && Node_hasChild(Tree))
	{
		Tree = Node_getChild(Tree);
	}
	while (!Grab_getIRD_Flag())
	{
		temp = (Node_t *)malloc(sizeof(Node_t));
		temp->cmd = Grab_cmd(Expression);
		if (Grab_getIRD_Flag())
		{
			temp->val = value;
			temp->cb = action;
		}
		else
		{
			temp->val = 0;
			temp->cb = NULL;
		}
		temp->next = NULL;
		temp->child = NULL;

		if (Tree == NULL)
		{
			Tree = temp;
			Tree_Root = Tree;
		}
		else if (Node_isFound(&Tree, temp->cmd))
		{
			Tree->val = temp->val;
			Tree->cb = temp->cb;
			free(temp->cmd);
			temp->cmd = NULL;
			free(temp);
			Tree = Node_getChild(Tree);
		}
		else if (!Node_hasChild(Tree) && !(Node_isTerminal(Tree)))
		{
			Node_addChild(Tree, temp);
			Tree = Node_getChild(Tree);
		}
		else
		{
			Node_addNext(Tree, temp);
			Tree = Node_getNext(Tree);
		}
	}
	Tree = Tree_Root;
}

void Tree_ExecuteCommand()
{
	// char *cmd = NULL;
	char *temp = NULL;
	Tree = Tree_Root;
	Grab_setIRD_Flag(false);

	// Buffer_Write(Grab_cmd_FILE(stdin));
	// cmd = Buffer_Read();
	buffer = Grab_cmd_FILE(stdin);

	if (Tree && Node_hasChild(Tree))
	{
		Tree = Node_getChild(Tree);
	}
	else
	{
		printf("No commands to execute\n");
		return;
	}

	while (!Grab_getIRD_Flag())
	{
		temp = Grab_cmd(buffer);
		bool isFound = Node_isFound(&Tree, temp);
		free(temp);
		temp = NULL;

		if (isFound && Node_hasChild(Tree) && !Grab_getIRD_Flag())
		{
			Tree = Node_getChild(Tree);
		}
		else if (isFound && Node_hasCallBack(Tree))
		{
			//Node_executeCallback(Tree);
			break;
		}
		else
		{
			printf("Command %s wasn't found\n", buffer);
			break;
		}
	}

	// Buffer_Clean();
	// cmd = NULL;
	free(buffer);
	buffer = NULL;
}

void Tree_Init()
{
	Tree_obj.get = (char *)malloc(sizeof(char) * 4);
	Tree_obj.set = (char *)malloc(sizeof(char) * 4);
	strcpy((Tree_obj.get),"get");
	strcpy((Tree_obj.set),"set");

	Tree_RegCommand("ROOT", 0, NULL);
	Tree_RegCommand("shutdown", 0, &shutDown_Callback);
	Tree_RegCommand("const pi get", 3.14, &get_Callback);
	Tree_RegCommand("const pi set", 3.14, &set_Callback);
 	Tree_RegCommand("const a set", 45, &set_Callback);
	Tree_RegCommand("const a get", 0, &get_Callback);
	Tree_RegCommand("b set", 56, &set_Callback);
	Tree_RegCommand("b get", 0, &get_Callback);
}

void Tree_Run_CLI()
{
	printf("Command Line Interface has started\n");
	printf("==================================\n");
	// while (isWorking)
	// {
		Tree_ExecuteCommand();
	// }
	printf("==================================\n");
	printf("End of programm\n");
}

void Tree_DeInit()
{
	free(Tree_obj.get);
	free(Tree_obj.set);
	Tree_obj.get = NULL;
	Tree_obj.set = NULL;

	Tree_erase(Tree);
}

void set_Callback()
{
	// char *temp = Buffer_Read();
	if (!Grab_value(buffer, &(Tree->val)))
	{
		printf("Wrong argument\n");
	}
}

void get_Callback()
{
	Grab_setIRD_Flag(false);
	// char *Expression = Buffer_Read();
	Tree = Tree_Root;

	if (Tree && Node_hasChild(Tree))
	{
		Tree = Node_getChild(Tree);
	}

	while (!Grab_getIRD_Flag())
	{
		char * temp = Grab_cmd(buffer);
		if (Node_isTheSame(temp,Tree_obj.get)){
			free(temp);
			temp = NULL;
			temp = (char*) malloc(sizeof(Tree_obj.set));
			strcpy(temp, Tree_obj.set);
		}
		if ((Node_isFound(&Tree, temp)) && (Node_hasChild(Tree)))
		{
			Tree = Node_getChild(Tree);
		}
		free(temp);
		temp = NULL;
	}
	printf("%f\n", (Tree->val));
}

void shutDown_Callback()
{
	isWorking = false;
}