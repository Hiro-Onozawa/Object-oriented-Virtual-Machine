#ifndef DEF_SIMPLE_ACCUMULATOR_H
#define DEF_SIMPLE_ACCUMULATOR_H

#include "../../core/common.h"
#include "../../core/Processor.h"

class Program;
class Memory;

namespace SimpleAccumulator {
	class Processor final : public ::Processor {
		friend class Proxy;

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

		void reset() override;

		bool setInstruction(OVM::Address addr, Instruction * inst) override;
		Instruction * getInstruction(OVM::Address addr) const override;

		bool step() override;
	};
}


#endif /* DEF_SIMPLE_ACCUMULATOR_H */
