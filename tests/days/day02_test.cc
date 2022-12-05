#include <PuzzleInputFetcher.h>
#include <day02.h>
#include <gtest/gtest.h>

#include <sstream>

TEST(Day02, SampleExactChoice) {
  std::istringstream sample("A Y\nB X\nC Z");

  auto exactChoiceScore = day02::exact_choice_strategy(sample);

  EXPECT_EQ(exactChoiceScore, 15);
}

TEST(Day02, SampleDesiredOutcome) {
  std::istringstream sample("A Y\nB X\nC Z");

  auto desiredOutcomeScore = day02::desired_outcome_strategy(sample);

  EXPECT_EQ(desiredOutcomeScore, 12);
}

TEST(Day02, RealExactChoice) {
  client::PuzzleInputFetcher fetcher;
  auto input = fetcher.FetchInput(2);

  auto exactChoiceScore = day02::exact_choice_strategy(*input);

  EXPECT_EQ(exactChoiceScore, 10816);
}

TEST(Day02, RealDesiredOutcome) {
  client::PuzzleInputFetcher fetcher;
  auto input = fetcher.FetchInput(2);

  auto desiredOutcomeScore = day02::desired_outcome_strategy(*input);

  EXPECT_EQ(desiredOutcomeScore, 11657);
}
