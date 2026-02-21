#include <iostream>
#include <algorithm>
#include <vector>

/// <summary>
/// MST란 그래프에서 최소비용으로 모든 구간을 연결한 트리로 사이클이 존재하면 안된다.
/// 크루스칼은 MST를 구하는 알고리즘으로 가중치 값을 기준으로 정렬한 후 Union Find를
/// 이용해서 구한다. (* 새 요소가 그룹에 포함되어 있지 않다면 포함시키고 포함되었다면 무시)
/// </summary>

struct Node
{
	char v1;
	char v2;
	int cost;
};

std::vector<Node> graph =
{
	{'A', 'B', 6},
	{'A', 'C', 4},
	{'A', 'D', 5},
	{'C', 'B', 1},
	{'C', 'D', 3},
	{'C', 'E', 7},
	{'E', 'B', 3},
	{'E', 'D', 1}
};

int n = 8; //간선의 갯수

// 오른 차순으로 정렬
bool compare(Node a, Node b)
{
	return a.cost < b.cost;
}

int org[200] = {};

// 부모 찾기
int findParent(int now)
{
   
    if (org[now] == 0)
    {
        return now;
    }

    int ret = findParent(org[now]);
    org[now] = ret;
    return ret;
}


int unionOrg(int v1, int v2)
{
    int p1 = findParent(v1); // v1의 루트 찾기
    int p2 = findParent(v2); // v2의 루트 찾기

    // 부모가 같다면 같은 집합(사이클 방지)
    if (p1 == p2)
    {
        return 0;
    }

    // p1의 부모를 p2로 설정하여 두 집합을 병합
    org[p1] = p2;
    return 1;
}

int main()
{
    std::sort(graph.begin(), graph.end(), compare);

    int cnt = 0;   // 선택된 간선의 개수
    int sum = 0;   // 최소 비용의 총합

    for (size_t i = 0; i < graph.size(); i++)
    {
        // 두 노드를 연결했을 때 사이클이 생기지 않는 경우에만 선택
        if (unionOrg(graph[i].v1, graph[i].v2))
        {
            sum += graph[i].cost; // 비용 누적
            cnt++;                // 간선 개수 증가
        }
    }

    // MST의 성질: 간선의 개수는 (전체 노드의 개수 - 1)개여야 함
    if (cnt == 4 /* 노드의 개수 - 1 */)
    {
        std::cout << sum << std::endl;
    }

    return 0;
}

