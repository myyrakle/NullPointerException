// VS_Algospot.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct Clock
{
private:
	int hour = 0;
public:
	operator int() const
	{
		return hour;
	}

	void increase3Hours()
	{
		if (hour == 12)
			hour = 0;

		hour += 3;
	}
	void decrease3Hours()
	{
		if (hour == 3)
			hour = 15;

		hour -= 3;
	}

	friend std::istream& operator>>(std::istream& is, Clock& clock)
	{
		std::cin >> clock.hour;
		return is;
	}
};

const int CLOCK_COUNT = 16;
std::vector<Clock> clocks(CLOCK_COUNT);

bool __(Clock& clock) { return clock == 12; }
bool all_12()
{
	return std::all_of(
		clocks.begin(),
		clocks.end(),
		__
	);
}

 using ints = std::vector<int>;
 std::vector<ints> switch_table{
     ints{0,1,2},
     ints{3,7,9,11},
     ints{4,10,14,15},
     ints{0,4,5,6,7},
     ints{6,7,8,10,12},
     ints{0,2,14,15},
     ints{3,14,15},
     ints{4,5,7,14,15},
     ints{1,2,3,4,5},
     ints{3,4,5,9,13}
 };

 void push_switch(int index)
 {
	 for (int e : switch_table[index])
		 clocks[e].increase3Hours();
 }

 const int NO = 9999999;

 int foo(int switch_index)
 {
	 if (switch_index == switch_table.size())
		 return all_12() ? 0 : NO;

	 int count = NO;
	 for (int i = 0; i < 4; i++)
	 {
		 count = std::min(count, i+foo(switch_index + 1));
		 push_switch(switch_index);
	 }

	 return count;	
 }

int main()
{
	int test_case;
	std::cin>>test_case;

	for(int i=0; i<test_case; i++)
	{
	    for(Clock& clock: clocks)
	        std::cin>>clock;

		int result = foo(0);
		std::cout << (result==NO ? -1 : result) << '\n';
	}
}
