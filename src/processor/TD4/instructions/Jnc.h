#ifndef DEF_TD4_INST_JNC_H
#define DEF_TD4_INST_JNC_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class Jnc final : public Instruction {
	private:
		OVM::Address imm;

	public:
		Jnc() = delete;
		Jnc(OVM::Address imm);
		virtual ~Jnc() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_JNC_H */
