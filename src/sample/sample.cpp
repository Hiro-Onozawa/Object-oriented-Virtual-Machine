// #define USE_SIMPLE_ACCUMULATOR
#define USE_TD4

#ifdef USE_SIMPLE_ACCUMULATOR
#include "../core/common.h"
#include "../processor/simple-accumulator-machine/Instructions.h"
#include "../processor/simple-accumulator-machine/SimpleAccumulator.h"

int main(void) {
	SimpleAccumulator::Processor proc(1024, 1024, 32);
	proc.setInstruction(1, new SimpleAccumulator::Load(100));
	proc.setInstruction(2, new SimpleAccumulator::Push());
	proc.setInstruction(3, new SimpleAccumulator::Pop());
	proc.setInstruction(4, new SimpleAccumulator::Print());
	proc.setInstruction(5, new SimpleAccumulator::Add(static_cast<OVM::Register>(-1)));
	proc.setInstruction(6, new SimpleAccumulator::Push());
	proc.setInstruction(7, new SimpleAccumulator::Jez(10));
	proc.setInstruction(8, new SimpleAccumulator::Load(0));
	proc.setInstruction(9, new SimpleAccumulator::Jez(3));
	
	while(proc.step()) ;
	
	return 0;
}
#endif /* USE_SIMPLE_ACCUMULATOR */

#ifdef USE_TD4
#include "../core/common.h"
#include <iostream>
#include <Windows.h>
#include "../processor/TD4/Instructions.h"
#include "../processor/TD4/Processor.h"

int main(void) {
	OVM::Byte m = 2;
	OVM::Byte n = 3;
	OVM::Byte in = 5;

	TD4::Processor proc(16);
	proc.setInstruction(0x0, new TD4::InB());
	proc.setInstruction(0x1, new TD4::AddAIm(1));
	proc.setInstruction(0x2, new TD4::AddBIm(1));
	proc.setInstruction(0x3, new TD4::Jnc(1));
	proc.setInstruction(0x4, new TD4::AddAIm(0xF));
	proc.setInstruction(0x5, new TD4::AddAIm(m));
	proc.setInstruction(0x6, new TD4::Jnc(8));
	proc.setInstruction(0x7, new TD4::Jmp(0xA));
	proc.setInstruction(0x8, new TD4::AddBIm(n));
	proc.setInstruction(0x9, new TD4::Jmp(5));
	proc.setInstruction(0xA, new TD4::OutB());
//	proc.setInstruction(0xB, new TD4::Jmp(0xB));
	proc.setIn(in);

	std::cout << "Input : "
		<< "m = " << static_cast<uint32_t>(m) << ", "
		<< "n = " << static_cast<uint32_t>(n) << ", "
		<< "IN = " << static_cast<uint32_t>(in) << std::endl;
	while (proc.step()) Sleep(80);

	std::cout << "Output : " << static_cast<uint32_t>(proc.getOut()) << std::endl;

	return 0;
}
#endif /* USE_TD4 */
