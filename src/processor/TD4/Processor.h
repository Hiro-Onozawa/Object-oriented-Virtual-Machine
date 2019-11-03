#ifndef DEF_TD4_PROCESSOR_H
#define DEF_TD4_PROCESSOR_H

#include "../../core/common.h"
#include "../../core/Processor.h"

class Program;

namespace TD4 {
	class Processor final : public ::Processor {
		friend class Proxy;

	private:
		OVM::Address pc;
		OVM::Byte regA;
		OVM::Byte regB;
		OVM::Byte cFlag;
		OVM::Byte in;
		OVM::Byte out;
		Program * program;

	public:
		Processor() = delete;
		Processor(size_t programSize);
		Processor(const Processor &) = delete;
		Processor(Processor &&) = delete;
		~Processor();
		Processor & operator=(const Processor &) = delete;
		Processor & operator=(Processor &&) = delete;

		void reset() override;

		bool setInstruction(OVM::Address addr, Instruction * inst) override;
		Instruction * getInstruction(OVM::Address addr) const override;

		bool step() override;

		bool setIn(OVM::Byte byte);
		OVM::Byte getOut() const;
	};
}


#endif /* DEF_TD4_PROCESSOR_H */
