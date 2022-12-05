#include <PuzzleInputFetcher.h>
#include <day01.h>
#include <gtest/gtest.h>

#include <fstream>

TEST(Day01, Sample) {
  std::ifstream sample("fixtures/day01_sample.txt");

  auto stats = day01::main(sample);

  EXPECT_EQ(stats.max_calories, 24000);
  EXPECT_EQ(stats.top_three_calories, 45000);
}

TEST(Day01, Real) {
  client::PuzzleInputFetcher fetcher;
  auto data = fetcher.FetchInput(1);

  auto stats = day01::main(*data);

  EXPECT_EQ(stats.max_calories, 70613);
  EXPECT_EQ(stats.top_three_calories, 205805);
}
