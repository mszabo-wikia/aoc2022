#ifndef SRC_DAYS_DAY02_SHAPE_H
#define SRC_DAYS_DAY02_SHAPE_H

namespace day02 {
class Shape {
 public:
  enum Type { kRock, kPaper, kScissors };

  // Returns a Shape instance as inferred from the given character.
  static Shape of(char c) noexcept;

  // Returns a Shape instance that fulfills the desired match outcome (win, loss
  // or draw) when matched against the given enemy shape.
  static Shape ofOutcome(const Shape& enemyShape, char desiredOutcome) noexcept;

  // Returns the innate score of this Shape as predetermined by its type.
  int innateScore() const noexcept;

  // Evaluates whether this Shape would win, lose or draw against the given
  // other shape and returns an appropriate score.
  int scoreAgainst(Shape other) const noexcept;

 private:
  constexpr static int kWinScore = 6;
  constexpr static int kLossScore = 0;
  constexpr static int kDrawScore = 3;

  explicit Shape(Type type) noexcept;

  Type type_;
  Type losesToType_;
  Type defeatsType_;
};
}  // namespace day02
#endif
