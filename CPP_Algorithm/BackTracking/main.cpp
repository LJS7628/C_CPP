#include <iostream>

/// <summary>
/// 백트래킹이란 답을 찾는 도중에 막히면, 되돌아가서 다시 찾는 기법
/// DFS랑 결합해서 많이 사용하며, 다른 점이란 DFS는 정답과 상관없이 모든 경로를 탐색한다.
/// </summary>

int matrix[3][3] =
{
    {2,4,3},
    {1,3,7},
    {6,5,6}
};

char path[4] = {};
bool check[3] = {};

void dfs(int row, int score)
{
    if (row == 3)
    {

        std::cout << "Path: " << path << std::endl;

        std::cout << score << std::endl;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (check[i] == false)
        {
            path[row] = '0' + matrix[row][i];
            check[i] = true;
            dfs(row + 1, score + matrix[row][i]);
            check[i] = false;
            path[row] = 0;
        }
    }
}

int main()
{
    dfs(0, 0);

    return 0;
}
