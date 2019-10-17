#include <iostream>
#include <vector>
#include <array>

enum Color
{
	White=0, Black=1
};

struct Board
{
	std::vector<std::vector<int>> board;
	size_t white_count = 0; //흰칸 개수

	//각 모양의 상대 좌표
	const int COVER_TYPES[4][3][2] = {
		{ {0,0}, {1,0}, {0,1} },
		{ {0,0}, {0,1}, {1,1} },
		{ {0,0}, {1,0}, {1,1} },
		{ {0,0}, {1,0}, {1,-1} }
	};

	bool set_then_is_valid(int y, int x, int type, int delta)
	{
		bool is_ok = true;

		for (int i = 0; i < 3; ++i)
		{
			const int n_y = y + COVER_TYPES[type][i][0];
			const int n_x = x + COVER_TYPES[type][i][1];
			if (n_y < 0 || n_y >= board.size() || 
				n_x < 0 || n_x >= board[0].size()) //하나만 어긋나도 false
				is_ok = false;
			else if ((board[n_y][n_x] += delta) > 1) //이미 겹친 곳에 또 겹쳐도 false
				is_ok = false;
		}

		return is_ok;
	}

	Board(int height, int width) : board(height, std::vector<int>(width, Color::White))
	{}
	void fill()
	{
		for (auto& e_row : board)
		{
			for (auto& e : e_row)
			{
				char temp;
				std::cin >> temp;

				if (temp == '.')
					white_count++;

				e = temp == '#' ? Color::Black : Color::White;
			}
		}
	}

	int do_cover()
	{
		int y = -1;
		int x = -1;

		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
				if (board[i][j] == Color::White)
				{
					y = i;
					x = j;
					break;
				}
			if (y != -1)
				break;
		}

		//베이스
		if (y == -1)
			return 1;

		int result = 0;
		for (int type = 0; type < 4; type++)
		{
			//덮음
			if (set_then_is_valid(y, x, type, 1))
				result += do_cover();

			//치움
			set_then_is_valid(y, x, type, -1);
		}

		return result;
	}

	size_t get_result()
	{
		if (white_count % 3 != 0)
			return 0;

		return do_cover();
	}

	//debuging only
	void view() const
	{
		std::cout << "start" << std::endl;
		for (const auto& e_row : board)
		{
			for (const auto& e : e_row)
				std::cout << (e == Color::Black ? '#' : '.');
			std::cout << std::endl;
		}
		std::cout << "end" << std::endl;
	}
};

int main()
{
	int C;
	std::cin >> C;

	for (int i = 0; i < C; i++)
	{
		int H, W;
		std::cin >> H >> W;
		auto board = Board(H, W);
		board.fill();
		std::cout << board.get_result() << '\n';
	}
}