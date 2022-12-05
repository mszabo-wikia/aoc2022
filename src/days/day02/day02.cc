#include "day02.h"

#include <string>

#include "Shape.h"

namespace day02 {
int exact_choice_strategy(std::istream& is) {
  std::string line;
  auto score = 0;

  while (std::getline(is, line)) {
    auto enemyShape = Shape::of(line[0]);
    auto ourShape = Shape::of(line[2]);

    score += ourShape.innateScore() + ourShape.scoreAgainst(enemyShape);
  }

  return score;
}

int desired_outcome_strategy(std::istream& is) {
  std::string line;
  auto score = 0;

  while (std::getline(is, line)) {
    auto enemyShape = Shape::of(line[0]);
    auto ourShape = Shape::ofOutcome(enemyShape, line[2]);

    score += ourShape.innateScore() + ourShape.scoreAgainst(enemyShape);
  }

  return score;
}
}  // namespace day02
