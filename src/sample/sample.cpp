#define USE_SIMPLE_ACCUMULATOR

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
