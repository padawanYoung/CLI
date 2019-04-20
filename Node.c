
#include "Node.h"

bool Node_hasCallBack(Node_t *node)
{
	return (node->cb != NULL);
}

void Node_executeCallback(Node_t *node)
{
	(*node->cb)();
}

bool Node_hasChild(Node_t *node)
{
	return (node->child != NULL);
}

bool Node_hasNext(Node_t *node)
{
	return (node->next != NULL);
}

Node_t *Node_getChild(Node_t *node)
{
	if (Node_hasChild(node))
	{
		return node->child;
	}
	else
	{
		return NULL;
	}
}

Node_t *Node_getNext(Node_t *node)
{
	if (Node_hasNext(node))
	{
		return node->next;
	}
	else
	{
		return NULL;
	}
}

void Node_addChild(Node_t *node, Node_t *child)
{
	node->child = child;
}

void Node_addNext(Node_t *node, Node_t *nextNode)
{
	node->next = nextNode;
}

bool Node_isTheSame(const char *cmd, const char *template)
{
	if (strcmp(cmd, template) == 0)
	{
		return true;
	}
	return false;
}

bool Node_isFound(Node_t **node, char const *commandName)
{
	while (node && (*node))
	{
		if (Node_isTheSame((*node)->cmd, commandName))
		{
			return true;
		}
		else if (Node_hasNext(*node))
		{
			*node = Node_getNext(*node);
			continue;
		}
		break;
	}
	return false;
}

bool Node_isTerminal(Node_t *node)
{
	if (node->cb != NULL)
	{
		return true;
	}
	return false;
}
