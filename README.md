# KPR_Library

[tottokodaichans](https://atcoder.jp/users/tottokodaichans)の競技プログラミングのライブラリです．

## 目次

### ユーティリティ

| 名前   | プログラム                                                   | 説明 |
| ------ | ------------------------------------------------------------ | ---- |
| mint | [modint.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/modint.cpp) |      |
| ModPow | [mod_pow.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/mod_pow.cpp) | 高速な累乗計算(繰り返し二乗法) |

### データ構造

| 名前 | プログラム | 説明 |
| ---- | ---------- | ---- |
|UnionFind|[union_find.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/union_find.cpp)||
|Binary Indexed Tree|[bit.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/bit.cpp)|O(logN)で区間和を取得,要素の変更を行う|
|Segment Tree|[segment_tree.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/segment_tree.cpp)|O(logN)で区間に対してクエリを実行，要素の変更を行う|

### 数学

#### 最大公約数・最小公倍数

| 名前 | プログラム                                                   | 説明       |
| ---- | ------------------------------------------------------------ | ---------- |
| gcd  | [gcd.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/gcd.cpp) | 最大公約数 |
| lcm  | [lcm.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/lcm.cpp) | 最小公倍数 |

#### 組み合わせ

| 名前        | プログラム                                                   | 説明                        |
| ----------- | ------------------------------------------------------------ | --------------------------- |
| Combination | [combination.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/combination.cpp) | 組み合わせ計算 |
| Combination Mod | [combination_mod.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/combination_mod.cpp) | Mod Pにおける組み合わせ計算 |
| Binomial Coefficient | [binomial_coefficient.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/binomial_coefficient.cpp) | 組み合わせ計算 / 階乗 |

#### 素数

| 名前          | プログラム                                                   | 説明       |計算量|
| ------------- | ------------------------------------------------------------ | ---------- | ----- |
| Factorization | [factorization.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/factorization.cpp) | 素因数分解 |O(√N)|
| Eratosthenesの篩 | [eratosthenes.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/eratosthenes.cpp) | 素数列挙 |O(NlogNlogN)|

### 経路探索

| 名前           | プログラム                                                   | 説明             |
| -------------- | ------------------------------------------------------------ | ---------------- |
| ダイクストラ法 | [dijkstra.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/dijkstra.cpp) | 単一始点経路探索 |
| ワーシャルフロイド | [warshall_floyd.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/warshall_floyd.cpp) | 全点間経路探索 |

### グラフ

| 名前              | プログラム                                                   | 説明 | 計算量 |
| ----------------- | ------------------------------------------------------------ | ---- | ------ |
| トポロジカルソート | [topological_sort.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/topological_sort.cpp)|||
| 深さ優先探索(DFS) | [dfs.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/dfs.cpp) |      | O(N+M) |

### 文字列

| 名前 | プログラム | 説明 |
| ---- | ---------- | ---- |
| 文字列分割 | [string_utility.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/string_utility.cpp) |      |
| ローリングハッシュ| [rolling_hash.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/rolling_hash.cpp) ||

### 幾何

| 名前 | プログラム | 説明 |
| ---- | ---------- | ---- |
| 線分の交差判定 | [is_cross.cpp](https://github.com/IidaTakuma/KPR_Library/blob/master/is_cross.cpp ||



### Tips
[浮動少数点の誤差について](https://qiita.com/mod_poppo/items/910b5fb9303baf864bf7)
