//#include "pch.h"
#include <iostream>
#include <array>
#include <string>
#define fn auto

enum class DP_t
{
	NOT_FOUND,
	NO,
	BE
};

std::array<std::array<std::array<DP_t, 11>, 5>, 5> DP;

// 5 X 5 격자
std::array<std::array<char, 5>, 5> lattice;

//단어
std::string word;

fn _has_word_recursive(size_t index, int height, int width) ->  bool
{	
	if (word.length() == index) //다 비교함
		return true;

	if (0 <= height && height < 5 &&
		0 <= width && width < 5) //인덱스 범위 안.	
	{
		auto& current_dp_pos = DP[height][width][index];

		if (current_dp_pos == DP_t::NOT_FOUND) //DP가 없을 경우: 
			if (lattice[height][width] == ::word[index]) //비교해서 같으면
			{
				if(_has_word_recursive(index + 1, height - 1, width - 1)
					|| _has_word_recursive(index + 1, height - 1, width)
					|| _has_word_recursive(index + 1, height - 1, width + 1)
					|| _has_word_recursive(index + 1, height, width - 1)
					|| _has_word_recursive(index + 1, height, width + 1)
					|| _has_word_recursive(index + 1, height + 1, width - 1)
					|| _has_word_recursive(index + 1, height + 1, width)
					|| _has_word_recursive(index + 1, height + 1, width + 1))
				{
					current_dp_pos = DP_t::BE;
					return true;
				}
				current_dp_pos = DP_t::NO;
				return false;
			}
			else //다르면
			{
				current_dp_pos = DP_t::NO;
				return false;
			}

		else //DP가 있을 경우
			if (current_dp_pos == DP_t::BE)
				return
					(  _has_word_recursive(index + 1, height - 1, width - 1)
					|| _has_word_recursive(index + 1, height - 1, width)
					|| _has_word_recursive(index + 1, height - 1, width + 1)
					|| _has_word_recursive(index + 1, height, width - 1)
					|| _has_word_recursive(index + 1, height, width + 1)
					|| _has_word_recursive(index + 1, height + 1, width - 1)
					|| _has_word_recursive(index + 1, height + 1, width)
					|| _has_word_recursive(index + 1, height + 1, width + 1));
			else
				return false;
	}

	else //격자 범위 벗어남
		return false;
}

fn has_word_recursive() ->bool
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (_has_word_recursive(0, i, j))
				return true;
	return false;
}


#include <vector>
#include <utility>
fn main() -> decltype(int{ 44 })
{
	//테스트 케이스 처리
	int Case;
	std::cin >> Case;

	for (int i = 0; i < Case; i++)
	{
		// 격자 값 입력
		for (int i = 0; i < 5; i++)
			std::cin >> lattice[i].data();

		//단어 처리
		int words_count; //찾을 단어 수
		std::cin >> words_count;
		std::vector<std::string> words(words_count);
		for (auto& e : words)
			std::cin >> e;

		//탐색 후 출력
		for (auto&& e : words)
		{
			//DP 준비
			for (auto& arr2 : DP)
				for (auto& arr : arr2)
					for (auto& e : arr)
						e = DP_t::NOT_FOUND;

			::word = std::move(e);
			std::cout << word << ' ' << (has_word_recursive() ? "YES\n" : "NO\n");
		}	
	}
}
