'''
Author: sunflower-you m13119160579@163.com
Date: 2024-03-25 21:33:37
LastEditors: sunflower-you m13119160579@163.com
LastEditTime: 2024-03-26 21:17:00
FilePath: /compiler_server/python/manual_optimization/matmul/tile_n.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np

np.random.seed(1001)

'''
import numpy as np
np.random.seed(1001)

a = np.random.randn(3, 2)
b = np.random.rand(2, 3)
print("a:", a)
print("b:", b)

a: [[-1.08644637 -0.89606513]
 [-0.30629937 -1.33993366]
 [-1.20658558 -0.64172681]]

b: [[0.61352186 0.58045711 0.85356768]
 [0.04113054 0.48817444 0.92082616]]

'''
m = 2048
k = 30208
n = 6144

# (2048, 30208)
ff1_input = np.random.randn(m, k)
ff1_weight = np.random.rand(k, n)
print("a:", ff1_input)
print("b:", ff1_weight)


tile_n = 32
stride_n = n // tile_n
ff1_out_res_list = [None for _ in range(tile_n)]
ff1_out_tile_n_test1 = None

# test1: 所有中间结果保存，最后concat，这样存的中间结果有点多
for n_tile_id in range(tile_n):
    ff1_weight_tile_n = ff1_weight[:, n_tile_id*stride_n:(n_tile_id+1)*stride_n]
    ff1_out_res = np.matmul(ff1_input, ff1_weight_tile_n)
    ff1_out_res_list[n_tile_id] = ff1_out_res
ff1_out_tile_n_test1  = np.concatenate(ff1_out_res_list, axis=-1)
ff1_out_golden = np.matmul(ff1_input, ff1_weight)
print("test1: ff1 output golden 和 tile 是否一致：", (ff1_out_golden==ff1_out_tile_n_test1).all())


# test2：只保存中间累加的结果
ff1_out_tile_n_test2 = None
for n_tile_id in range(tile_n):
    ff1_weight_tile_n = ff1_weight[:, n_tile_id*stride_n:(n_tile_id+1)*stride_n]
    ff1_out_res = np.matmul(ff1_input, ff1_weight_tile_n)
    if n_tile_id == 0:
        ff1_out_tile_n_test2 = ff1_out_res
        continue
    ff1_out_tile_n_test2 = np.concatenate((ff1_out_tile_n_test2, ff1_out_res), axis=-1)
print("test2: ff1 output golden 和 tile 是否一致：", (ff1_out_golden==ff1_out_tile_n_test2).all())