
#include "day01.h"

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

namespace day01 {
CaloriesStats main(std::istream& is) {
  std::string line;
  std::vector<int> calories;

  while (!is.eof()) {
    auto cur_calories = 0;
    while (std::getline(is, line) && !line.empty()) {
      cur_calories += std::stoi(line);
    }

    calories.push_back(cur_calories);
  }

  std::sort(calories.begin(), calories.end(), std::greater<int>());

  CaloriesStats stats;

  stats.max_calories = calories[0];
  stats.top_three_calories =
      std::reduce(calories.begin(), calories.begin() + 3, 0, std::plus());

  return stats;
}
}  // namespace day01
