#include "common.h"
#include <iostream>
#include <sstream>
#include "Instruction.h"
#include "Processor.h"
#include "Memory.h"

OVM::Register & Instruction::pc(Processor & processor)
{
	return processor.pc;
}

const OVM::Register & Instruction::pc(const Processor & processor)
{
	return processor.pc;
}

OVM::Register & Instruction::sp(Processor & processor)
{
	return processor.sp;
}

const OVM::Register & Instruction::sp(const Processor & processor)
{
	return processor.sp;
}

OVM::Register & Instruction::acc(Processor & processor)
{
	return processor.acc;
}

const OVM::Register & Instruction::acc(const Processor & processor)
{
	return processor.acc;
}

Memory & Instruction::heap(Processor & processor)
{
	return *processor.heap;
}

const Memory & Instruction::heap(const Processor & processor)
{
	return *processor.heap;
}

Memory & Instruction::stack(Processor & processor)
{
	return *processor.stack;
}

const Memory & Instruction::stack(const Processor & processor)
{
	return *processor.stack;
}

OVM::Assembly Nop::toAssembly() const
{
	return OVM::Assembly("NOP");
}

bool Nop::Process(Processor & processor)
{
	++pc(processor);
	return true;
}

OVM::Assembly Push::toAssembly() const
{
	return OVM::Assembly("PUSH");
}

bool Push::Process(Processor & processor)
{
	++sp(processor);
	const bool result = stack(processor).write(static_cast<OVM::Address>(sp(processor)), acc(processor));
	++pc(processor);
	return result;
}

OVM::Assembly Pop::toAssembly() const
{
	return OVM::Assembly("POP");
}

bool Pop::Process(Processor & processor)
{
	acc(processor) = stack(processor).read(static_cast<OVM::Address>(sp(processor)));
	--sp(processor);
	++pc(processor);
	return true;
}

OVM::Assembly Print::toAssembly() const
{
	return OVM::Assembly("PRINT");
}

bool Print::Process(Processor & processor)
{
	std::cout << acc(processor) << std::endl;
	++pc(processor);
	return true;
}

Jez::Jez(OVM::Register pc)
	: pc(pc)
{
}

OVM::Assembly Jez::toAssembly() const
{
	std::ostringstream oss;
	oss << "JEZ " << pc;
	return OVM::Assembly(oss.str());
}

bool Jez::Process(Processor & processor)
{
	if (acc(processor) == 0) Instruction::pc(processor) = pc;
	else ++Instruction::pc(processor);
	return true;
}

Add::Add(OVM::Register imm)
	: imm(imm)
{
}

OVM::Assembly Add::toAssembly() const
{
	std::ostringstream oss;
	oss << "ADD " << imm;
	return OVM::Assembly(oss.str());
}

bool Add::Process(Processor & processor)
{
	acc(processor) += imm;
	++pc(processor);
	return true;
}

Load::Load(OVM::Register imm)
	: imm(imm)
{
}

OVM::Assembly Load::toAssembly() const
{
	std::ostringstream oss;
	oss << "LOAD " << imm;
	return OVM::Assembly(oss.str());
}

bool Load::Process(Processor & processor)
{
	acc(processor) = imm;
	++pc(processor);
	return true;
}
