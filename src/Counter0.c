#include "Counter0.h"
uint32_t counter0;
void increaseCounter0(){
	counter0++;
}
void decreaseCounter0(){
	counter0--;
}
void setCounter0(uint32_t value){
	counter0=value;
}
void resetCounter0(){
	counter0=0;
}
uint32_t getCounter0(){
	return counter0;
}

