#ifndef DEF_SIMPLEACC_INST_ADD_H
#define DEF_SIMPLEACC_INST_ADD_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace SimpleAccumulator {
	class Add final : public Instruction {
	private:
		OVM::Register imm;

	public:
		Add() = delete;
		Add(OVM::Register imm);
		virtual ~Add() = default;

		virtual OVM::Assembly toAssembly() const override;

		virtual bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_SIMPLEACC_INST_ADD_H */
