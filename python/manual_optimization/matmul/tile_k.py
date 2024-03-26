import numpy as np

np.random.seed(1001)

m = 2048
k = 30208
n = 6144

tile_k = 32
k_stride = k // tile_k
print(k_stride)

feature_map = np.random.randn(m, k)
weight = np.random.randn(k, n)

# feature_map = np.arange(6).reshape(3,2).astype(np.float32)
# print(feature_map)
# weight = np.arange(6).reshape(2,3).astype(np.float32)
# print(weight)

# m = 3
# k = 2
# n = 3

# tile_k = 2
# k_stride = k // tile_k



matmul_golden = np.matmul(feature_map, weight)



accum_add_matmul = None
for tile_id in range(tile_k):
    feature_map_tile_k = feature_map[:, tile_id*k_stride:(tile_id+1)*k_stride]
    weight_tile_k = weight[tile_id*k_stride:(tile_id+1)*k_stride, :]

    matmul_tile_k = np.matmul(feature_map_tile_k, weight_tile_k)
    if tile_id == 0:
        accum_add_matmul = matmul_tile_k
        continue

    accum_add_matmul += matmul_tile_k

print(f"matmul k维度拆成 {tile_k} 分，结果是否一致：", (matmul_golden == accum_add_matmul).all())

print(f"matmul k维度拆成 {tile_k} 分，结果是否一致：", np.max(np.abs((matmul_golden-accum_add_matmul))))
print()