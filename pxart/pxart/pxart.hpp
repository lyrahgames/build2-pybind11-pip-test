#pragma once
#include <random>

namespace pxart {

template <typename real>
inline auto monte_carlo_pi(size_t n) {
  std::mt19937 rng{std::random_device{}()};
  std::uniform_real_distribution<real> uniform{0, 1};
  size_t count = 0;
  for (size_t i = 0; i < n; ++i) {
    const auto x = uniform(rng);
    const auto y = uniform(rng);
    count += (x * x + y * y < 1);
  }
  return real(4) * count / n;
}

}  // namespace pxart