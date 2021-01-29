/**
 * created: 17.07.2020
 * reference: https://qiita.com/xryuseix/items/7e9b4c6f12d001a0c0db
 * sample problem: ABC007_C
**/

#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int INF = 1001001001;

// 各座標に格納したい情報を構造体にする
struct Corr
{
    int x;     // X座標
    int y;     // Y座標
    int depth; // 深さ
};

// マップ情報をもとに最短経路探索
int bfs_vector(vector<vector<int>> grid, int start_x, int start_y, int goal_x, int goal_y)
{
    // 探索済の頂点に関して距離を保存しておく
    vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), -1));
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    // 未探索地点を保存する
    queue<Corr> q;
    // スタート地点をqueueに追加する
    Corr start = {start_x, start_y, 0};
    q.push(start);
    while (!q.empty())
    {
        Corr now = q.front();
        q.pop();
        /*
            今いる座標は(x,y)=(now.x, now.y)で，深さ(距離)はnow.depthである
            ここで，今いる座標がゴール(探索対象)なのかを判定する
        */
        for (int i = 0; i < 4; ++i)
        {
            int next_x = now.x + dx[i];
            int next_y = now.y + dy[i];

            // 次に探索する場所がX座標からはみ出している場合
            if (next_x < 0 || next_x >= grid[0].size())
                continue;
            // 次に探索する場所がY座標からはみ出している場合
            if (next_y < 0 || next_y > grid.size())
                continue;
            // 次に探索する箇所が壁の場合
            if (!grid[next_y][next_x])
                continue;
            // 次に探索する箇所が探索済の場合
            if (dist[next_y][next_x] != -1)
                continue;

            dist[next_y][next_x] = now.depth + 1;
            Corr next = {next_x, next_y, now.depth + 1};
            q.push(next);
        }
    }
    return dist[goal_y][goal_x];
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    int start_x, start_y;
    int goal_x, goal_y;
    cin >> start_y >> start_x >> goal_y >> goal_x;
    --start_x;
    --start_y;
    --goal_x;
    --goal_y;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            char c;
            cin >> c;
            if (c == '.')
                grid[i][j] = 1;
        }
    }
    cout << bfs_vector(grid, start_x, start_y, goal_x, goal_y) << endl;
    return 0;
}