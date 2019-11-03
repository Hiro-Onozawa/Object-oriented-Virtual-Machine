#ifndef DEF_SIMPLEACC_INST_JEZ_H
#define DEF_SIMPLEACC_INST_JEZ_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace SimpleAccumulator {
	class Jez final : public Instruction {
	private:
		OVM::Register pc;

	public:
		Jez() = delete;
		Jez(OVM::Register pc);
		virtual ~Jez() = default;

		virtual OVM::Assembly toAssembly() const override;

		virtual bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_SIMPLEACC_INST_JEZ_H */
