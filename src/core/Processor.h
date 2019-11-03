#ifndef DEF_PROCESSOR_H
#define DEF_PROCESSOR_H

#include "common.h"

class Instruction;


class Processor {
public:
	Processor() = default;
	Processor(const Processor &) = delete;
	Processor(Processor &&) = delete;
	virtual ~Processor() = default;
	Processor & operator=(const Processor &) = delete;
	Processor & operator=(Processor &&) = delete;
	
	virtual void reset() = 0;
	
	virtual bool setInstruction(OVM::Address addr, Instruction * inst) = 0;
	virtual Instruction * getInstruction(OVM::Address addr) const = 0;
	
	virtual bool step() = 0;
};

#endif /* DEF_PROCESSOR_H */
