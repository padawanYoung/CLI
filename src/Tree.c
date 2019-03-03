#include "Tree.h"

node_t * tree = NULL;
node_t * erase (node_t * root);

void treeInit() {
	char ROOT[] = "ROOT";

	tree = (node_t*) malloc(sizeof(node_t));
	tree->cmd = (char*) malloc(sizeof(char) * strlen(ROOT));
	strcpy(tree->cmd, ROOT);
	tree->cb = NULL;
	tree->val = 0;
	tree->nextNode = NULL;
	tree->prevNode = NULL;
	tree->parentNode = NULL;
	tree->childNode = NULL;
	return;
}

node_t * erase (node_t * root){
	node_t * selectedNode = NULL;
	if(tree->nextNode == NULL && tree->childNode == NULL){
		free(tree);
		return NULL;
	}
	else if(root->childNode != NULL){
		selectedNode = root->childNode;
		if (selectedNode->nextNode == NULL){
			root->childNode = selectedNode->childNode;
			free(selectedNode->cmd);
			free(selectedNode);
			return erase(root);
		}
		return erase(selectedNode);
	}
	else if (root->nextNode != NULL){
		selectedNode = root->nextNode;
		if (selectedNode->childNode == NULL) {
			root->nextNode = selectedNode->nextNode;
			free(selectedNode->cmd);
			free(selectedNode);
			return erase(root);
		}
		return erase(selectedNode);
	}
	else {
		return erase(tree);
	}
}

void treeDeinit (){
	erase (tree);
}

void regCliCommand(const char * Command, uint8_t depth, callBack action) {
	node_t * temp = NULL;
	node_t * currentNode = tree;
	uint8_t depthCounter = 0;
	if(hasChildNode(currentNode)){
		currentNode=getChildNode(currentNode);
	}
	while(depthCounter++<depth){
		temp = (node_t*) malloc(sizeof(node_t));
		temp->cmd = getString(Command);
		if(depthCounter == depth){
			temp->isTerminalNode = true;
			temp->val = getValue(Command);
			temp->cb = action;
		}else{
			temp->isTerminalNode = false;
			temp->val = 0;
			temp->cb = NULL;
		}
		temp->nextNode = NULL;
		temp->prevNode = NULL;
		temp->childNode = NULL;
		temp->parentNode = NULL;
		if(isNodeFound(&currentNode, temp)){
			currentNode->val = temp->val;
			currentNode->cb = temp->cb;
			free(temp);
			currentNode = getChildNode(currentNode);
		} else if (currentNode->isTerminalNode && temp->isTerminalNode
				&& !isTheSameNode(currentNode, temp)){
			addNextNode(currentNode, temp);
			currentNode = getNextNode(currentNode);
		} else if(!hasChildNode(currentNode)){
			addChildNode (currentNode, temp);
			currentNode = getChildNode(currentNode);
		} else {
			addNextNode(currentNode, temp);
			currentNode = getNextNode(currentNode);
		}
	}
	return;
}

void setSmth1_1Callback() {
	return;
}


void setSmth1_2Callback (){
	return;
}

void setSmth2_1Callback (){
	return;
}

void setSmth2_2Callback (){
	return;
}
