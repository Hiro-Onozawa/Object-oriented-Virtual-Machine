#ifndef DEF_TD4_INST_MOVAIM_H
#define DEF_TD4_INST_MOVAIM_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class MovAIm final : public Instruction {
	private:
		OVM::Byte imm;

	public:
		MovAIm() = delete;
		MovAIm(OVM::Byte imm);
		virtual ~MovAIm() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_MOVAIM_H */
