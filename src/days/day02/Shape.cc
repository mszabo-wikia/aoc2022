#include "Shape.h"

namespace day02 {
Shape Shape::of(char c) noexcept {
  if (c == 'A' || c == 'X') {
    return Shape(Shape::kRock);
  }

  if (c == 'B' || c == 'Y') {
    return Shape(Shape::kPaper);
  }

  // implies Shape::kScissors
  return Shape(Shape::kScissors);
}

Shape Shape::ofOutcome(const Shape& enemyShape, char desiredOutcome) noexcept {
  constexpr char kLoss = 'X';
  constexpr char kDraw = 'Y';

  if (desiredOutcome == kLoss) {
    return Shape(enemyShape.defeatsType_);
  } else if (desiredOutcome == kDraw) {
    return Shape(enemyShape.type_);
  } else {
    // implies win
    return Shape(enemyShape.losesToType_);
  }
}

Shape::Shape(Type type) noexcept : type_(type) {
  if (type == Shape::kRock) {
    losesToType_ = Shape::kPaper;
    defeatsType_ = Shape::kScissors;
  } else if (type == Shape::kPaper) {
    losesToType_ = Shape::kScissors;
    defeatsType_ = Shape::kRock;
  } else {
    // implies Shape::kScissors
    losesToType_ = Shape::kRock;
    defeatsType_ = Shape::kPaper;
  }
}

int Shape::innateScore() const noexcept {
  if (type_ == Shape::kRock) {
    return 1;
  }

  if (type_ == Shape::kPaper) {
    return 2;
  }
  // implies Shape::kScissors
  return 3;
}

int Shape::scoreAgainst(Shape other) const noexcept {
  if (type_ == other.type_) {
    return kDrawScore;
  }

  if (defeatsType_ == other.type_) {
    return kWinScore;
  }

  return kLossScore;
}

}  // namespace day02
