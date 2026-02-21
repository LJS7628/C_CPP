#include <iostream>

/// <summary>
///  플루드 필은 주어진 시작점으로 부터 연결된 영역들을 찾는 알고리즘으로 
/// 그림판 채우기, 지뢰찾기에서 지로가 없는 모든 셀을 찾아주는 기능들에 활용되었다.
/// </summary>


char map[9][10] =
{
	"#########",
	"#...#...#",
	"#...#...#",
	"#..#....#",
	"###...###",
	"#....#..#",
	"#...#...#",
	"#...#...#",
	"#########"
};

void printMap()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

void FloodFill(int x, int y)
{
	if (map[y][x] == '.')
	{
		map[y][x] = '@';

		FloodFill(x, y + 1);
		FloodFill(x - 1, y);
		FloodFill(x, y - 1);
		FloodFill(x + 1, y);
	}
}

int main()
{
	printMap();

	std::cout << "==========================" << std::endl;
	FloodFill(4, 4);

	printMap();


	return 0;
}