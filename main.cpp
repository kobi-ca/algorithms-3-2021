#include <iostream>
#include <optional>
#include <string_view>
#include "fmt/format.h"
#include "range/v3/all.hpp"

namespace {
    auto is_vowel = [](auto c) noexcept {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u' || c == 'y';
    };
}

namespace try1 {
    std::optional<char> third_last_vowel(std::string_view input) noexcept {
        auto counter{0U};
        // cannot use range for loop since we need crbegin/crend
        for (auto it = input.crbegin(); it != input.crend(); ++it) {
            if (!is_vowel(*it)) continue;
            ++counter;
            if (counter == 3) return *it;
        }
        return std::nullopt;
    }
}

namespace try2 {
    std::optional<char> third_last_vowel(std::string_view input) noexcept {
        const auto pred = [&, counter{0}](auto c) mutable noexcept {
            if (is_vowel(c)) return ++counter == 3;
            return false;
        };
        const auto it = std::find_if(input.crbegin(), input.crend(), pred);
        if (it != input.crend()) return *it;
        return std::nullopt;
    }
}

namespace try3 {
    std::optional<char> third_last_vowel(std::string_view input) noexcept {
        auto result = input | ranges::views::reverse | ranges::views::filter(is_vowel) | ranges::views::drop(2);
        const auto ret = *result.begin();
        return ret;
    }
}

void print(const std::optional<char> result) {
    if (result) {
        std::clog << fmt::format("{}", *result) << '\n';
    }
}

int main() {
    using namespace std::literals;
    const auto input = "Hi, Hello world"sv;
    {
        const auto result = try1::third_last_vowel(input);
        print(result);
    }
    {
        const auto result = try2::third_last_vowel(input);
        print(result);
    }
    {
        const auto result = try3::third_last_vowel(input);
        print(result);
    }
    return 0;
}
