#include "../../xark/src/xark.h"
//TODO create header for this file

#define XARK_MEM_INIT_MODULE_ARRAY_SIZE 100


struct XARK_STACK {
	int item;//This is item'th element of stack
	int pointer;//an int containing the address of the value of this element in the stack
	struct XARK_STACK *previous;//pointer to previous stack element(unless item=0)
} XARK_STACK;

struct XARK_STACK *XARK_STACK_PUSH(struct XARK_STACK *stack, int pointer){
	struct XARK_STACK *element = malloc(sizeof(struct XARK_STACK));
	//assert(element != NULL);

	if (stack != NULL){
		element->item = stack->item + 1;
		element->previous = stack;
	} else {
		element->item = 0;
		element->previous = NULL;
	}

	element->pointer = pointer;

	return element;


} 


struct XARK_STACK *XARK_STACK_POP(struct XARK_STACK *stack){
//assert(stack != NULL);
//we will need to free things here at some point
	return stack->previous;


}

struct XARK_FUNCTION * XARK_MEM_FUNCTION_ARRAY_ALLOC(int XARK_FUNCTION_ARRAY_LENGTH){
	struct XARK_FUNCTION * xark_function_array= malloc(XARK_FUNCTION_ARRAY_LENGTH * sizeof(XARK_FUNCTION));
	return xark_function_array;
}
