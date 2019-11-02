#ifndef DEF_PROCESSOR_H
#define DEF_PROCESSOR_H

#include "common.h"

class Program;
class Instruction;


class Processor final {
	friend Instruction;
	
private:
	OVM::Register pc;
	OVM::Register sp;
	OVM::Register acc;
	Program * program;
	Memory * heap;
	Memory * stack;
	
public:
	Processor() = delete;
	Processor(size_t heapSize, size_t stackSize, size_t programSize);
	Processor(const Processor &) = delete;
	Processor(Processor &&) = delete;
	~Processor();
	Processor & operator=(const Processor &) = delete;
	Processor & operator=(Processor &&) = delete;
	
	void reset();
	
	bool setInstruction(OVM::Address addr, Instruction * inst);
	
	Instruction * getCurrentInstruction() const;
	
	bool step();
};

#endif /* DEF_PROCESSOR_H */
