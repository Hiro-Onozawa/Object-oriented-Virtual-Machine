#ifndef DEF_TD4_INST_OUTIM_H
#define DEF_TD4_INST_OUTIM_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class OutIm final : public Instruction {
	private:
		OVM::Byte imm;

	public:
		OutIm() = delete;
		OutIm(OVM::Byte imm);
		virtual ~OutIm() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_OUTIM_H */
