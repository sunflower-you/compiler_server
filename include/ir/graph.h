//
// Created by Y1023 on 2024/2/12.
//


#pragma once


#ifndef SERVER_GRAPH_H
#define SERVER_GRAPH_H

#include <vector>
#include <string>
#include <memory>
#include <utility>

#include "types.h"

class Graph {
public:
    Graph(std::string name) : name_(name) {};
    
    void SetName(std::string name)
    {
        name_ = name;
    }

    std::string GetName(void)
    {
        return name_;
    }

    void SetNodeList(std::vector<NodePtr> node_list)
    {
        node_list_ = node_list;
    }

    std::vector<NodePtr> GetNodeList(void)
    {
        return node_list_;
    }

    void SetInputs(std::vector<TensorPtr> inputs)
    {
        inputs_ = inputs;
    }

    std::vector<TensorPtr> GetInputs(void)
    {
        return inputs_;
    }

    void SetOutputs(std::vector<TensorPtr> outputs)
    {
        outputs_ = outputs;
    }

    std::vector<TensorPtr> GetOutputs(void)
    {
        return outputs_;
    }

private:
    std::string name_;
    std::vector<NodePtr> node_list_;
    std::vector<TensorPtr> inputs_;
    std::vector<TensorPtr> outputs_;
    
};

#endif //SERVER_GRAPH_H
