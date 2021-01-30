# KPR_Library

Competitive Programming Library of [tottokodaichans](https://atcoder.jp/users/tottokodaichans)

## Contents

### Data Type

| Name | Source | Description | Order |
| ---- | ------ | ----------- | ----- |
| mint | [modint.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/modint.cpp) |||

### Data Structure

| Name | Source | Description | Order |
| ---- | ------ | ----------- | ----- |
| UnionFind | [union_find.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/data_structure/union_find.cpp) |||
| Binary Indexed Tree | [bit.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master//data_structure/bit.cpp) | 区間和を取得,要素の変更を実行 | O(logn) / Query |
| Segment Tree | [ segment_tree.cpp ](https://github.com/IidaTakuma/KPR_Library/blob/master//data_structure/segment_tree.cpp) | 区間へのクエリ，要素の変更を実行 | O(logn) / Query |

### Math Utility

#### GCD・LCM

| Name | Source | Description | Order |
| ---- | ------ | ----------- | ----- |
| gcd | [gcd.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/math_utility/gcd.cpp) | 最大公約数 |
| lcm | [lcm.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/math_utility/lcm.cpp) | 最小公倍数 |

#### Combination

| Name | Source | Description | Order |
| ---- | ------ | ----------- | ----- |
| Combination Mod | [combination_mod.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/math_utility/combination_mod.cpp) | Mod Pにおける組み合わせ計算 |
| Binomial Coefficient | [binomial_coefficient.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/math_utility/binomial_coefficient.cpp) | 組み合わせ計算 / 階乗 |
| ModPow | [mod_pow.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/math_utility/mod_pow.cpp) | 高速な累乗計算(繰り返し二乗法) |

#### Prime Number

| Name | Source | Description | Order |
| ---- | ------ | ----------- | ----- |
| Factorization | [factorization.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/math_utility/factorization.cpp) | 素因数分解 |O(√N)|
| Sieve of Eratosthenes | [eratosthenes.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/math_utility/eratosthenes.cpp) | 素数列挙 |O(NlogNlogN)|

### Graph Unitlity

| Name | Source | Description | Order |
| ---- | ------ | ----------- | ----- |
| Dijkstra | [dijkstra.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/graph_utility/dijkstra.cpp) | Single Source Shortest Path ||
| Warshall Floyd | [warshall_floyd.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/graph_utility/warshall_floyd.cpp) |||
| Topological Sort | [topological_sort.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/graph_utility/topological_sort.cpp)|||
| Hamilton | [hamilton.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/graph_utility/hamilton.cpp) || O(2^n * n^2) |
| DFS | [dfs.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/graph_utility/dfs.cpp) | Depth First Search | O(N+M) |
| BFS | [bfs.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/graph_utility/bfs.cpp) | Breadth First Search | O(N+M) |

### String Utility

| Name | Source | Description | Order |
| ---- | ------ | ----------- | ----- |
| Split String | [split_string.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/string_utility/split_string.cpp) |||
| Rolling Hash | [rolling_hash.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/string_utility/rolling_hash.cpp) |||

### Geometry

| Name | Source | Description | Order |
| ---- | ------ | ----------- | ----- |
| Segment Cross | [is_cross.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/geometry/is_cross.cpp) | Judgement of Intersection of line segment ||
| Geometry 2D | [geometry_2d.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/geometry/geometry_2d.cpp) |||

### Tips
[浮動少数点の誤差について](https://qiita.com/mod_poppo/items/910b5fb9303baf864bf7)
