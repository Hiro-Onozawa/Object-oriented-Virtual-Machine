#ifndef DEF_TD4_INST_ADDBIM_H
#define DEF_TD4_INST_ADDBIM_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class AddBIm final : public Instruction {
	private:
		OVM::Byte imm;

	public:
		AddBIm() = delete;
		AddBIm(OVM::Byte imm);
		virtual ~AddBIm() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_ADDBIM_H */
