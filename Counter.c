#include "Counter.h"
uint32_t counter;
void Counter_increase(){
	counter++;
}
void Counter_decrease(){
	counter--;
}
void Counter_set(uint32_t value){
	counter=value;
}
void Counter_reset(){
	counter=0;
}
uint32_t Counter_get(){
	return counter;
}

