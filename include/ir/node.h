//
// Created by Y1023 on 2024/2/12.
//

#ifndef SERVER_NODE_H
#define SERVER_NODE_H

#include<string>
#include<vector>

#include "types.h"

using namespace std;

class Node
{
public:
    Node(const std::string& name, NodePtr& node_type) : name_(name), node_type_(node_type) {}
    virtual ~Node(void) {}

    virtual TensorPtr SetInputTensor(int id, const TensorPtr& input);
    virtual TensorPtr SetOutputTensor(int id, const TensorPtr& output);

    virtual TensorPtr GetInputTensor(int id) const;
    virtual TensorPtr GetOutputTensor(int id) const;

    virtual int GetInputNumber(void) const
    {
        return input_tensors_.size();
    }

    virtual int GetOutputNumber(void) const
    {
        return output_tensors_;
    }

    virtual void SetInputTensorList(const std::vector<TensorPtr>& input_tensors)
    {
        input_tensors_ = input_tensors;
    }

    virtual std::vector<NodePtr> GetInputTensorList(void) const
    {
        return input_tensors_;
    }

    virtual void SetOutputTensorList(const std::vector<NodePtr>& output_tensors)
    {
        output_tensors_ = output_tensors;
    }

    virtual std::vector<TensorPtr> GetOutputTensorList(void) const
    {
        return output_tensors_;
    }

    virtual bool CheckVaild(void);


    std::string GetName(void) const 
    {
        return name_;
    }

    void SetIndex(const int id)
    {
        idx_ = id;
    }

    int GetIndex(void) const
    {
        return idx_;
    }

    void SetNodeType(const NodePtr node_type)
    {
        node_type_ = node_type;
    }

    NodePtr GetNodeType(void) const
    {
        return node_type_;
    }

    void SetOp(const OpPtr op)
    {
        op_ = op;
    }

    OpPtr GetOp(void) const
    {
        return op_;
    }


private:
    string name_;  // node name
    int idx_;  // node id
    NodePtr node_type_;  // node type,
    OpPtr op_;  // op
    std::vector<TensorPtr> input_tensors_;
    std::vector<TensorPtr> output_tensors_;
}
#endif //SERVER_NODE_H
