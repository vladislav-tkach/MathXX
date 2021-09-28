#ifndef MATHXX_INFINITE_NATURAL_NUMBERS_H
#define MATHXX_INFINITE_NATURAL_NUMBERS_H

#include "InfiniteNaturalNumbers/InfiniteNaturalNumbers.API.h"

#include <regex>
#include <string>
#include <vector>

namespace MathXX
{
    class INFINITENATURALNUMBERS_API InfiniteNatural
    {
    public:
        InfiniteNatural();
        explicit InfiniteNatural(unsigned long long i_value);
        InfiniteNatural(const InfiniteNatural& i_other) noexcept;
        InfiniteNatural(InfiniteNatural&& io_other) noexcept;

        InfiniteNatural& operator=(const InfiniteNatural& i_other) noexcept;
        InfiniteNatural& operator=(InfiniteNatural&& io_other) noexcept;

        ~InfiniteNatural();

        [[nodiscard]] bool operator==(const InfiniteNatural& i_other) const;
        [[nodiscard]] bool operator!=(const InfiniteNatural& i_other) const;
        [[nodiscard]] bool operator>(const InfiniteNatural& i_other) const;
        [[nodiscard]] bool operator>=(const InfiniteNatural& i_other) const;
        [[nodiscard]] bool operator<(const InfiniteNatural& i_other) const;
        [[nodiscard]] bool operator<=(const InfiniteNatural& i_other) const;

        /*[[nodiscard]] InfiniteNatural operator+(
            const InfiniteNatural& i_other) const;*/

        /*InfiniteNatural& operator++();
        InfiniteNatural operator++(int);
        InfiniteNatural& operator--();
        InfiniteNatural operator--(int);*/

        [[nodiscard]] std::string ToString() const;
        bool SetValue(const std::string& i_number);

    private:
        static constexpr auto m_digits_per_section = 19;
        static inline const auto m_natural_number_regex =
            std::regex("[1-9]\\d*");

        std::vector<unsigned long long> m_sections;
    };
} // namespace MathXX

#endif
