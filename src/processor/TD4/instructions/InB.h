#ifndef DEF_TD4_INST_INB_H
#define DEF_TD4_INST_INB_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class InB final : public Instruction {
	public:
		InB() = default;
		virtual ~InB() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_INB_H */
