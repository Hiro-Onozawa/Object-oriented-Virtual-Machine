#ifndef DEF_INSTRUCTION_H
#define DEF_INSTRUCTION_H

#include "common.h"

class Processor;


class Instruction {
public:
	Instruction() = default;
	virtual ~Instruction() = default;
	
	virtual OVM::Assembly toAssembly() const = 0;
	
	virtual bool Process(Processor & processor) = 0;
};

#endif /* DEF_INSTRUCTION_H */
