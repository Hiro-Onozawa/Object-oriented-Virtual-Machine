#ifndef DEF_INSTRUCTION_H
#define DEF_INSTRUCTION_H

#include "common.h"

class Processor;
class Memory;


class Instruction {
public:
	Instruction() = default;
	virtual ~Instruction() = default;
	
	virtual OVM::Assembly toAssembly() const = 0;
	
	virtual bool Process(Processor & processor) = 0;
	
protected:
	// util
	static OVM::Register & pc(Processor & processor);
	static const OVM::Register & pc(const Processor & processor);
	static OVM::Register & sp(Processor & processor);
	static const OVM::Register & sp(const Processor & processor);
	static OVM::Register & acc(Processor & processor);
	static const OVM::Register & acc(const Processor & processor);
	static Memory & heap(Processor & processor);
	static const Memory & heap(const Processor & processor);
	static Memory & stack(Processor & processor);
	static const Memory & stack(const Processor & processor);
};

class Nop final : public Instruction {
public:
	Nop() = default;
	virtual ~Nop() = default;
	
	virtual OVM::Assembly toAssembly() const override;
	
	virtual bool Process(Processor &processor) override;
};

class Push final : public Instruction {
public:
	Push() = default;
	virtual ~Push() = default;
	
	virtual OVM::Assembly toAssembly() const override;
	
	virtual bool Process(Processor &processor) override;
};

class Pop final : public Instruction {
public:
	Pop() = default;
	virtual ~Pop() = default;
	
	virtual OVM::Assembly toAssembly() const override;
	
	virtual bool Process(Processor &processor) override;
};

class Print final : public Instruction {
public:
	Print() = default;
	virtual ~Print() = default;
	
	virtual OVM::Assembly toAssembly() const override;
	
	virtual bool Process(Processor &processor) override;
};

class Jez final : public Instruction {
private:
	OVM::Register pc;
	
public:
	Jez() = delete;
	Jez(OVM::Register pc);
	virtual ~Jez() = default;
	
	virtual OVM::Assembly toAssembly() const override;
	
	virtual bool Process(Processor &processor) override;
};

class Add final : public Instruction {
private:
	OVM::Register imm;
	
public:
	Add() = delete;
	Add(OVM::Register imm);
	virtual ~Add() = default;
	
	virtual OVM::Assembly toAssembly() const override;
	
	virtual bool Process(Processor &processor) override;
};

class Load final : public Instruction {
private:
	OVM::Register imm;
	
public:
	Load() = delete;
	Load(OVM::Register imm);
	virtual ~Load() = default;
	
	virtual OVM::Assembly toAssembly() const override;
	
	virtual bool Process(Processor &processor) override;
};

#endif /* DEF_INSTRUCTION_H */
