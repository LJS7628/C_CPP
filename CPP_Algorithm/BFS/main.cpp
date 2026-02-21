#include <iostream>
#include <queue>

/// <summary>
/// BFS는 너비 우선 탐색으로, 그래프에서 목적지를 찾을 때, 노드가 갈 수 있는 모든 방향을 순차적으로 탐색한다.
/// 큐를 사용해서 방문한 노드가 갈 수 있는 모든 방향을 저장하고 순차적으로 꺼내며 경로를 탐색한다.
/// </summary>


struct Node
{
    int data;
    int level;
    int path[10] = {};
};

int map[5][5] =
{
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}
};

std::queue<Node> queue;
char value[10] = "BQWER";

int main()
{
    queue.push({ 0, 0, {1,0,0,0,0,0,0,0,0,0} });    // 시작노드: B(0)

    while (!queue.empty())
    {
        Node now = queue.front();
        if (value[now.data] == 'R')    // 목표 노드 R에 도달
        {
            //std::cout << now.path[0] << now.path[1] << now.path[2] << now.path[3] << now.path
            for (size_t i = 0; i < 5; i++)
            {
                if (now.path[i] == 1)
                {
                    std::cout << value[i];
                }
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < 5; i++)
        {
            if (map[now.data][i] == 0)    // 연결되지 않으면 건너뛰기
                continue;
            if (now.path[i] == 1)         // 이미 방문한 노드면 건너뛰기
                continue;

            Node next = now;              // 현재 노드 정보 복사
            next.data = i;                // 다음 노드로 설정
            next.level = now.level + 1;   // 레벨 증가
            next.path[i] = 1;             // 경로에 추가

            queue.push(next);
        }
        queue.pop();
    }

    return 0;
}
