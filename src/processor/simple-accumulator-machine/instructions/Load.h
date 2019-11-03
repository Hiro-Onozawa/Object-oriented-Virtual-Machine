#ifndef DEF_SIMPLEACC_INST_LOAD_H
#define DEF_SIMPLEACC_INST_LOAD_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace SimpleAccumulator {
	class Load final : public Instruction {
	private:
		OVM::Register imm;

	public:
		Load() = delete;
		Load(OVM::Register imm);
		virtual ~Load() = default;

		virtual OVM::Assembly toAssembly() const override;

		virtual bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_SIMPLEACC_INST_LOAD_H */
