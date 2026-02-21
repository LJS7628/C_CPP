#include <iostream>
#include <vector>
#include <queue>
#include <tuple> // 또는 <utility> (std::pair 사용)

/// <summary>
///  다익스트라는 재귀호출을 사용하지 않고 최소비용을 구하는 알고리즘으로 
///  지하철, 버스의 최단 경로를 찾는 기능이나 네트워크의 최단 경로 연결
///  게임 캐릭터의 길찾기 알고리즘으로 사용된다.
/// </summary>


#define NOT 999999
#define INF 987654321

// 그래프 데이터 (인접 행렬 유지)
int map[4][4] = {
    {0,   50,  NOT, 20 },
    {NOT, 0,   5,   NOT},
    {NOT, NOT, 0,   NOT},
    {NOT, 10,  25,  0  }
};

int result[4]; // 최단 거리 테이블

void dijkstra(int start)
{
    // 1. 최단 거리 테이블 초기화 (무한대)
    for (int i = 0; i < 4; i++) {
        result[i] = INF;
    }

    // 2. 우선순위 큐 선언 (Min-Heap: 비용이 작은 것이 위로)
    // 자료형: <비용, 정점번호> pair
    std::priority_queue<std::pair<int, int>
        , std::vector<std::pair<int, int>>
        , std::greater<std::pair<int, int>>> pq;

    // 3. 시작 노드 초기화
    result[start] = 0;
    pq.push({ 0, start }); // {비용, 노드}

    while (!pq.empty())
    {
        // 비용이 가장 적은 노드 꺼내기
        int currentCost = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // 현재 꺼낸 비용이 이미 기록된 최소 비용보다 크다면 스킵 (이미 처리된 경로)
        if (currentCost > result[currentNode])
            continue;

        // 인접 노드 확인 (인접 행렬이므로 0~3 반복)
        for (int nextNode = 0; nextNode < 4; nextNode++)
        {
            // 연결되어 있지 않거나 자기 자신인 경우 패스
            if (map[currentNode][nextNode] == NOT
                || map[currentNode][nextNode] == 0)
                continue;

            int nextCost = currentCost + map[currentNode][nextNode];

            // 더 적은 비용으로 갈 수 있다면 갱신 후 큐에 삽입
            if (nextCost < result[nextNode])
            {
                result[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }

    // 결과 출력
    std::cout << "=== 최단 거리 결과 ===" << std::endl;
    char nodes[] = { 'A', 'B', 'C', 'D' };
    for (int i = 0; i < 4; i++)
    {
        // 경로가 없는 경우 처리
        if (result[i] == INF)
            std::cout << nodes[start] << " -> " << nodes[i] << ": 갈 수 없음" << std::endl;
        else
            std::cout << nodes[start] << " -> " << nodes[i] << ": " << result[i] << "만원" << std::endl;
    }
}

int main()
{
    dijkstra(0); // 0번 노드(A)에서 시작
    return 0;
}