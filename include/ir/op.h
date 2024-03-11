//
// Created by Y1023 on 2024/2/12.
//

#ifndef SERVER_OP_H
#define SERVER_OP_H

#include<string>
#include<vector>
#include<memory>

include "types.h"


class Op
{
	explicit Op(const OpType& op_type) : op_type_(op_type) {}
	virtual ~Op() {}

	virtual bool CheckVaild(const std::vector<TensorPtr> inputs, const std::vector<TensorPtr> outputs)
	{
		return true;
	}

	virtual bool InferShape()
	
	
private:
	OpType op_type_;
}
#endif //SERVER_OP_H
