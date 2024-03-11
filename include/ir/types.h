//
// Created by Y1023 on 2024/2/12.
//

#ifndef SERVER_TYPES_H
#define SERVER_TYPES_H

#include<memory>

#define MAX_DIM 6
enum DataType
{
    DT_Int8,
    DT_Uint8,
    DT_Float16,
    DT_Bfloat16,
    DT_Int16,
    DT_Uint16,
    DT_Float32,
    DT_Int32,
};


enum TensorType
{
    TT_Const,
    TT_Input,
    TT_Output,
    TT_Var,
};

struct OpType
{
    std::string name;
    int version;

    bool operator==(const OpType& right)
    {
        return (name == right.name && version == right.version);
    }

    bool operator!=(const OpType& right)
    {
        return (name != right.name || version != right.version);
    }
};


class ShapeType
{
    int dim_num;
    int dim[MAX_DIM];

    int stride[MAX_DIM];

    init(void)
    {
        dim_num = MAX_DIM;
        for (int i = 0; i < dim_num; i++)
        {
            dim[i] = 0;
            stride[i] = 0;
        }
    }

    ShapeType(const ShapeType& r)
    {
        *this = r;
    }

    ShapeType(int n0, int n1, int c0, int c1, int h, int w)
    {
        dim_num = 6;
        dim[0] = n0;
        dim[1] = n1;
        dim[2] = c0;
        dim[3] = c1;
        dim[4] = h;
        dim[5] = w;
    }

    ShapeType(int n, int c0, int c1, int h, int w)
    {
        dim_num = 5;
        dim[0] = n;
        dim[1] = c0;
        dim[2] = c1;
        dim[3] = h;
        dim[4] = w;
    }

    ShapeType(int n, int c, int h. int w)
    {
        init();
        dim_num = 4;
        dim[0] = n;
        dim[1] = c;
        dim[2] = h;
        dim[3] = w;
    }

    ShapeType(int c, int h, int w)
    {
        init();
        dim_num = 3;
        dim[0] = c;
        dim[1] = h;
        dim[2] = w;
    }

    ShapeType(int h, int w)
    {
        dim_num = 2;
        dim[0] = h;
        dim[1] = w;
    }

    ShapeType(int w)
    {
        dim_num = 1;
        dim[0] = w;
    }

    ShapeType operator=(const ShapeType& r)
    {
        dim_num = r.dim_num;
        for (int i = 0; i < dim_num; i++)
        {
            dim[i] = r.dim[i];
        }
        return *this;
    }

    bool operator==(const ShapeType& r)
    {
        if (dim_num != r.dim_num)
            return false;
        for (int i = 0; i < MAX_DIM; i++)
        {
            if (dim[i] != r.dim[i])
            {
                return false;
            }
        }
        return true;
    }

    int volum(void) const
    {
        if (dim_num == 0)
            return 0;

        int r = 1;
        for (int i = 0; i < dim_num; i++)
        {
            r *= dim[i];
        }
        return r;
    }
};


// ir
class Graph;
class Node;
class Op;
class Tensor;

using GraptPtr = std::shared_ptr<Graph>;
using NodePtr = std::shared_ptr<Node>;
using OpPtr = std::shared_ptr<Op>;
using TensorPtr = std::shared_ptr<Tensor>;


#endif //SERVER_TYPES_H
