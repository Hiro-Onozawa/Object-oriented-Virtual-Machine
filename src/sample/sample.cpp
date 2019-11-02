#include "../core/common.h"
#include "../core/Instruction.h"
#include "../core/Processor.h"

int main(void) {
	Processor proc(1024, 1024, 32);
	proc.setInstruction(1, new Load(100));
	proc.setInstruction(2, new Push());
	proc.setInstruction(3, new Pop());
	proc.setInstruction(4, new Print());
	proc.setInstruction(5, new Add(static_cast<OVM::Register>(-1)));
	proc.setInstruction(6, new Push());
	proc.setInstruction(7, new Jez(10));
	proc.setInstruction(8, new Load(0));
	proc.setInstruction(9, new Jez(3));
	
	while(proc.step()) ;
	
	return 0;
}
