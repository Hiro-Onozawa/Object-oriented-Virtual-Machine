#ifndef DEF_SIMPLEACC_INST_NOP_H
#define DEF_SIMPLEACC_INST_NOP_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace SimpleAccumulator {
	class Nop final : public Instruction {
	public:
		Nop() = default;
		virtual ~Nop() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_SIMPLEACC_INST_NOP_H */
