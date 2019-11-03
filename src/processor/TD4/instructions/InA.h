#ifndef DEF_TD4_INST_INA_H
#define DEF_TD4_INST_INA_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class InA final : public Instruction {
	public:
		InA() = default;
		virtual ~InA() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_INA_H */
