#ifndef DEF_TD4_INST_JMP_H
#define DEF_TD4_INST_JMP_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class Jmp final : public Instruction {
	private:
		OVM::Address imm;

	public:
		Jmp() = delete;
		Jmp(OVM::Address imm);
		virtual ~Jmp() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_JMP_H */
