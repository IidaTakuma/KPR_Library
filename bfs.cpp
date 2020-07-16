/**
 * created: 17.07.2020
 * reference: 
**/

#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int INF = 1001001001;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<int>> score(h, vector<int>(w, INF));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    queue<P> qe;              // 今後の探索箇所を格納する
    qe.push(make_pair(0, 0)); // スタート地点を入れる
    score[0][0] = 0;          // スタート地点のコストを0にする
    while (!qe.empty())
    {
        P now = qe.front();
        qe.pop();
        // 上下左右を探索する
        int xs[4] = {1, -1, 0, 0};
        int ys[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            P next = make_pair(now.first + xs[i], now.second + ys[i]);
            // グリッドの範囲内かを判定する
            if (next.first < 0 || next.second < 0 || next.first >= h || next.second >= w)
            {
                continue;
            }
            // 壁ではないかを確認する
            if (grid[next.first][next.second] == '#')
            {
                continue;
            }
            // 移動先のコストが移動前より低ければスキップする
            if (score[now.first][now.second] >= score[next.first][next.second] + 1)
            {
                continue;
            }
            // 移動先が未探索であれば今後の探索箇所に追加する
            if (score[next.first][next.second] != INF)
            {
                score[next.first][next.second] = score[now.first][now.second] + 1;
                continue;
            }

            //DEBUG: cout << next.first << ':' << next.second << endl;
            score[next.first][next.second] = score[now.first][now.second] + 1;
            qe.push(next);
        }
    }
    // ゴールに辿り着けないかを判定する
    if (score[h - 1][w - 1] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << score[h - 1][w - 1] << endl;
    }
    return 0;
}