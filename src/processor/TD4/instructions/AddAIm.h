#ifndef DEF_TD4_INST_ADDAIM_H
#define DEF_TD4_INST_ADDAIM_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class AddAIm final : public Instruction {
	private:
		OVM::Byte imm;

	public:
		AddAIm() = delete;
		AddAIm(OVM::Byte imm);
		virtual ~AddAIm() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_ADDAIM_H */
