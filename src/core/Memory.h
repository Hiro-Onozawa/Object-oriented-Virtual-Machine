#ifndef DEF_MEMORY_H
#define DEF_MEMORY_H

#include "common.h"


class Memory final {
private:
	OVM::Word *mem;
	size_t size;
	
public:
	Memory() = delete;
	Memory(size_t size);
	Memory(const Memory &) = delete;
	Memory(Memory &&) = delete;
	~Memory();
	Memory & operator=(const Memory &) = delete;
	Memory & operator=(Memory &&) = delete;
	
	bool isValidAddres(OVM::Address addr) const;
	
	OVM::Word read(OVM::Address addr) const;
	bool write(OVM::Address addr, OVM::Word w);
};

#endif /* DEF_MEMORY_H */
