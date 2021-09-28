#include "InfiniteNaturalNumbers/InfiniteNaturalNumbers.h"

#include <cstddef>
#include <cstdlib>
#include <regex>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace MathXX;

namespace
{
    unsigned long long ToULL(const std::string& i_number,
                             const std::size_t i_count,
                             const std::size_t i_index = 0)
    {
        unsigned long long result = 0;

        for (std::size_t i = 0; i < i_count; ++i) {
            result = result * 10 + (i_number[i_index + i] - '0');
        }

        return result;
    }
} // namespace

InfiniteNatural::InfiniteNatural() : m_sections(1, 1) {}

InfiniteNatural::InfiniteNatural(const unsigned long long i_value)
    : m_sections(1, 1)
{
    if (i_value == 0)
        throw std::invalid_argument("MathXX::InfiniteNatural::InfiniteNatural("
                                    "unsigned long long i_value): i_value "
                                    "cannot be 0");

    m_sections[0] = i_value;
}

InfiniteNatural::InfiniteNatural(const InfiniteNatural& i_other) noexcept
    : m_sections(i_other.m_sections)
{}

InfiniteNatural::InfiniteNatural(InfiniteNatural&& io_other) noexcept
    : m_sections(std::move(io_other.m_sections))
{}

InfiniteNatural& InfiniteNatural::operator=(
    const InfiniteNatural& i_other) noexcept
{
    m_sections = i_other.m_sections;

    return *this;
}

InfiniteNatural& InfiniteNatural::operator=(InfiniteNatural&& io_other) noexcept
{
    m_sections = std::move(io_other.m_sections);

    return *this;
}

InfiniteNatural::~InfiniteNatural() {}

[[nodiscard]] bool InfiniteNatural::operator==(
    const InfiniteNatural& i_other) const
{
    return m_sections == i_other.m_sections;
}

[[nodiscard]] bool InfiniteNatural::operator!=(
    const InfiniteNatural& i_other) const
{
    return m_sections != i_other.m_sections;
}

[[nodiscard]] bool InfiniteNatural::operator>(
    const InfiniteNatural& i_other) const
{
    if (m_sections.size() != i_other.m_sections.size())
        return m_sections.size() > i_other.m_sections.size();

    for (std::size_t i = m_sections.size(), index = i - 1; i > 0;
         --i, --index) {
        if (m_sections[index] == i_other.m_sections[index])
            continue;

        return m_sections[index] > i_other.m_sections[index];
    }

    return false;
}

[[nodiscard]] bool InfiniteNatural::operator>=(
    const InfiniteNatural& i_other) const
{
    if (m_sections.size() != i_other.m_sections.size())
        return m_sections.size() > i_other.m_sections.size();

    for (std::size_t i = m_sections.size(), index = i - 1; i > 0;
         --i, --index) {
        if (m_sections[index] == i_other.m_sections[index])
            continue;

        return m_sections[index] > i_other.m_sections[index];
    }

    return true;
}

[[nodiscard]] bool InfiniteNatural::operator<(
    const InfiniteNatural& i_other) const
{
    if (m_sections.size() != i_other.m_sections.size())
        return m_sections.size() < i_other.m_sections.size();

    for (std::size_t i = m_sections.size(), index = i - 1; i > 0;
         --i, --index) {
        if (m_sections[index] == i_other.m_sections[index])
            continue;

        return m_sections[index] < i_other.m_sections[index];
    }

    return false;
}

[[nodiscard]] bool InfiniteNatural::operator<=(
    const InfiniteNatural& i_other) const
{
    if (m_sections.size() != i_other.m_sections.size())
        return m_sections.size() < i_other.m_sections.size();

    for (std::size_t i = m_sections.size(), index = i - 1; i > 0;
         --i, --index) {
        if (m_sections[index] == i_other.m_sections[index])
            continue;

        return m_sections[index] < i_other.m_sections[index];
    }

    return true;
}

[[nodiscard]] std::string InfiniteNatural::ToString() const
{
    std::string result;

    for (const auto section : m_sections)
        result = std::to_string(section) + result;

    return result;
}

bool InfiniteNatural::SetValue(const std::string& i_number)
{
    if (!std::regex_match(i_number, m_natural_number_regex))
        return false;

    std::vector<unsigned long long> result;

    auto sections_count = i_number.size() / m_digits_per_section;

    result.reserve(sections_count);

    for (std::size_t i = 1; i <= sections_count; ++i) {
        result.emplace_back(ToULL(i_number, m_digits_per_section,
                                  i_number.size() - i * m_digits_per_section));
    }

    if (sections_count * m_digits_per_section < i_number.size()) {
        result.emplace_back(
            ToULL(i_number,
                  i_number.size() - sections_count * m_digits_per_section, 0));
    }

    m_sections = std::move(result);

    return true;
}
