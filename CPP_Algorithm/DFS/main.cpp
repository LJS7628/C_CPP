#include <iostream>

/// <summary>
/// DFS는 
/// DFS랑 결합해서 많이 사용하며, 다른 점이란 DFS는 정답과 상관없이 모든 경로를 탐색한다.
/// </summary>


char value[10] = "ZADCEB";
int visited[10] = { };
int map[6][6] =
{
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0},
    {1, 1, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 1},
    {0, 1, 0, 1, 1, 0}
};

int cnt = 0;
char path[10] = {};

bool flag = false;
void dfs(int now, int level)
{
    if (now == 5)                    // 목표 노드(E)에 도달
    {
        flag = true;
        cnt++;
        std::cout << path << std::endl;    // 경로 출력
        return;
    }

    for (size_t i = 0; i < 6; i++)
    {
        if (map[now][i] == 1 && visited[i] == 0)    // 연결되고 미방문
        {
            visited[i] = 1;                // 방문 처리
            path[level + 1] = value[i];      // 경로에 추가
            dfs(i, level + 1);             // 재귀 호출
            path[level + 1] = 0;           // 백트래킹: 경로 제거
            visited[i] = 0;                // 백트래킹: 방문 해제
        }
    }
}

int main()
{
    visited[0] = 1;        // 시작점 방문 처리
    path[0] = value[0];    // 시작점을 경로에 추가
    dfs(0, 0);

    return 0;
}
