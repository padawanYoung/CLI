#ifndef COUNTER_H_
#define COUNTER_H_
#include <stdint.h>
void Counter_increase();
void Counter_decrease();
void Counter_set(uint32_t value);
void Counter_reset();
uint32_t Counter_get();
#endif /* COUNTER_H_ */
