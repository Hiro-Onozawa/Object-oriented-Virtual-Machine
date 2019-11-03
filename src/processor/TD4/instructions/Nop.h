#ifndef DEF_TD4_INST_NOP_H
#define DEF_TD4_INST_NOP_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class Nop final : public Instruction {
	public:
		Nop() = default;
		virtual ~Nop() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_NOP_H */
