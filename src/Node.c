
#include "Node.h"

bool  hasParentNode (node_t * node){
	if(node->parentNode != NULL){
		return true;
	}else{
		return false;
	}
}

bool  hasChildNode (node_t * node){
	if(node->childNode != NULL){
		return true;
	}else{
		return false;
	}
}

bool hasPrevNode (node_t * node){
	if(node->prevNode != NULL){
		return true;
	}else{
		return false;
	}
}

bool hasNextNode (node_t * node){
	if(node->nextNode != NULL){
		return true;
	}else{
		return false;
	}
}

node_t * getParentNode (node_t * node){
	if(hasParentNode(node)){
		return node->parentNode;
	}else{
		return NULL;
	}
}

node_t * getChildNode (node_t * node){
	if(hasChildNode (node)){
		return node->childNode;
	}else{
		return NULL;
	}
}

node_t * getPrevNode(node_t * node) {
	if (hasPrevNode(node)) {
		return node->prevNode;
	} else {
		return NULL;
	}
}

node_t * getNextNode(node_t * node) {
	if (hasNextNode(node)) {
		return node->nextNode;
	} else {
		return NULL;
	}
}

void addChildNode (node_t* node, node_t* child){
	child->parentNode = node;
	node->childNode = child;
}

void addNextNode (node_t* node, node_t* nextNode){
	nextNode->prevNode = node;
	node->nextNode = nextNode;
}

bool isTheSameNode (node_t * node, node_t * template){
	if(strcmp(node->cmd, template->cmd) == 0){
		return true;
	}else{
		return false;
	}
}

bool isNodeFound (node_t ** node, node_t * template){
	bool keepGoing;
	do {
		keepGoing = false;
		if (isTheSameNode(*node, template)) {
			return true;
		}else if(hasNextNode(*node)){
			keepGoing = true;
			*node = getNextNode(*node);
		}
	} while (keepGoing);
	return false;
}
