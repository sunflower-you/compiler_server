import numpy as np

np.random.seed(1001)

m = 2048
k = 30208
n = 6144

tile_m = 512
m_stride = m // tile_m

feature_map = np.random.randn(m, k)
weight = np.random.randn(k, n)


# feature_map = np.arange(6).reshape(3,2).astype(np.float32)
# print(feature_map)
# weight = np.arange(6).reshape(2,3).astype(np.float32)
# print(weight)

# m = 3
# k = 2
# n = 3

# tile_m = 3
# m_stride = m // tile_m


matmul_np_golden = np.matmul(feature_map, weight)
print(matmul_np_golden)

matmul_tile_m_concat = None
for tile_m_id in range(tile_m):
    feature_map_tile_m= feature_map[tile_m_id*m_stride:(tile_m_id+1)*m_stride, :]
    matmul_tile_m = np.matmul(feature_map_tile_m, weight)
    if tile_m_id == 0:
        matmul_tile_m_concat = matmul_tile_m
        continue
    matmul_tile_m_concat = np.concatenate((matmul_tile_m_concat, matmul_tile_m), axis=0)
print((matmul_tile_m_concat == matmul_np_golden).all())