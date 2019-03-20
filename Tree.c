#include "Tree.h"

Node_t *tree = NULL;
bool resumeFlag=true;

void Tree_erase(Node_t *root);

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

void Tree_Init()
{
	char ROOT[] = "ROOT";

	tree = (Node_t *)malloc(sizeof(Node_t) * 1);
	tree->cmd = (char *)malloc(sizeof(char) * strlen(ROOT) + 1);
	strcpy(tree->cmd, ROOT);
	tree->cb = NULL;
	tree->val = 0;
	tree->next = NULL;
	tree->child = NULL;
}

void Tree_DeInit()
{
	Tree_erase(tree);
}

void Tree_RegCommand(const char *Command, float value, callBack_t action)
{
	Node_t *temp;
	Node_t *currentNode = tree;
	Grab_setIRD_Flag(false);
	if (Node_hasChild(currentNode))
	{
		currentNode = Node_getChild(currentNode);
	}
	while (!Grab_getIRD_Flag())
	{
		temp = (Node_t *)malloc(sizeof(Node_t));
		temp->cmd = Grab_cmd(Command);
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

		if (Node_isFound(&currentNode, temp->cmd))
		{
			currentNode->val = temp->val;
			currentNode->cb = temp->cb;
			free(temp->cmd);
			temp->cmd = NULL;
			free(temp);
			currentNode = Node_getChild(currentNode);
		}
		else if (!Node_hasChild(currentNode) && !(Node_isTerminal(currentNode)))
		{
			Node_addChild(currentNode, temp);
			currentNode = Node_getChild(currentNode);
		}
		else
		{
			Node_addNext(currentNode, temp);
			currentNode = Node_getNext(currentNode);
		}
	}
}

void Tree_ExecuteCommand()
{
	char *cmd;
	Node_t *node = tree;
	Grab_setIRD_Flag(false);

	if (Node_hasChild(node))
	{
		node = Node_getChild(node);
	}
	else
	{
		printf("No commands to execute\n");
		return;
	}

	while (!Grab_getIRD_Flag())
	{
		cmd = Grab_cmd_FILE(stdin);
		if (Node_isFound(&node, cmd))
		{
			if (!Grab_getIRD_Flag())
			{
				node = Node_getChild(node);
			}
		}
		else
		{
			printf("Command %s wasn't found\n", cmd);
			break;
		}
		free(cmd);
		cmd = NULL;
	}
	if (node->cb != NULL)
	{
		// Node_callback(&node->cb);
		(*node->cb)();
	}
	Grab_setIRD_Flag(false);
}

void Tree_Run_CLI()
{
	printf("Command Line Interface has started\n");
	printf("==================================\n");
	while (true)
	{
		Tree_ExecuteCommand();
		if (!resumeFlag){
			break;
		}
	}
	printf("==================================\n");
	printf("End of programm\n");
}

void set_Callback()
{
	printf("This is callback set_Callback\n");
}

void get_Callback()
{
	printf("This is callback get_Callback\n");
}

void shutDown_Callback()
{
	resumeFlag = false;
}