#ifndef DEF_TD4_INST_MOVBIM_H
#define DEF_TD4_INST_MOVBIM_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class MovBIm final : public Instruction {
	private:
		OVM::Byte imm;

	public:
		MovBIm() = delete;
		MovBIm(OVM::Byte imm);
		virtual ~MovBIm() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_MOVBIM_H */
