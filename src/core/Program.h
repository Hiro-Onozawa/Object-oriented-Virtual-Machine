#ifndef DEF_PROGRAM_H
#define DEF_PROGRAM_H

#include "common.h"

class Instruction;


class Program final {
private:
	Instruction **insts;
	size_t size;
	
public:
	Program() = delete;
	Program(size_t size);
	Program(const Program &) = delete;
	Program(Program &&) = delete;
	~Program();
	Program & operator=(const Program &) = delete;
	Program & operator=(Program &&) = delete;
	
	bool isValidAddres(OVM::Address addr) const;
	
	bool set(size_t addr, Instruction * inst);
	Instruction * get(OVM::Address addr) const;
};

#endif /* DEF_PROGRAM_H */
