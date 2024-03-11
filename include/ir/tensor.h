//
// Created by Y1023 on 2024/2/12.
//

#ifndef SERVER_TENSOR_H
#define SERVER_TENSOR_H

#include<string>
#include<vector>

#include "types.h"

using namespace std;

class Tensor
{
public:
    Tensor(const string name) : name_(name) {}

    string GetName(void)
    {
        return name_;
    }

    void SetDataType(const DataType data_type)
    {
        data_type_ = data_type;
    }

    DataType GetDataType(void)
    {
        return data_type_;
    }

    void SetTensorType(cosnt TensorType tensor_type)
    {
        tensor_type_ = tensor_type;
    }

    TensorType GetTensorType(void)
    {
        return tensor_type_;
    }

    void SetShapeType(const ShapeType shape_type)
    {
        shape_type_  = shape_type;
    }

    ShapeType GetShapeType(void)
    {
        return shape_type_;
    }

    void SetProducer(const NodePtr producer)
    {
        producer_ = producer;
    }

    NodePtr GetProducer(void)
    {
        return producer_;
    }

    void SetConsumers(vector<NodeWeakPtr> consumers)
    {
        consumers_ = consumers;
    }

    vector<NodeWeakPtr> GetConsumers(void)
    {
        return consumers_;
    }

    void SetQuantType(const QuantType quant_type)
    {
        quant_type_ = quant_type
    }

    QuantType GetQuantType(void)
    {
        return quant_type_;
    }

    void SetQuantMode(const QuantMode quant_mod)
    {
        quant_mode_ = quant_mod;
    }

    QuantMode GetQuantMode(void)
    {
        return quant_mode_;
    }

    void SetScale(const vector<float> scale)
    {
        scale_ = scale
    }

    float GetScale(void)
    {
        return scale_[0];
    }

    void SetZeroPoint(const vector<int> zero_point)
    {
        zero_point_ = zero_point;
    }

    int GetZeroPoint(void)
    {
        return zero_point_[0];
    }

    void SetMax(const vector<float> max)
    {
        max_ = max;
    }

    float GetMax(void)
    {
        return max_;
    }

    void SetMin(const vector<flaot> min)
    {
        min_ = min;
    }

    float GetMin(void)
    {
        return min_;
    }

private:
    // tensor name
    string name_;
    // tensor data type
    DataType data_type_;
    // tensor type
    TensorType tensor_type_;
    // tensor shape type
    ShapeType shape_type_;
    // tensor quant type
    QuantType quant_type_;
    // tensor quant mode
    QuantMode quant_mode_;

    // quant params
    vector<float> scale_;
    vector<int> zero_point_;
    vector<float> max_;
    vector<float> min_;

    // tensor producer node
    NodePtr producer_;
    // tensor consumers node list
    vector<NodeWeakPtr> consumers_;
}

#endif //SERVER_TENSOR_H
