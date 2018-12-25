namespace implies_detail
{
    struct NegationHelper final { };

    constexpr bool operator||(bool x, implies_detail::NegationHelper)
    {
        return not x;
    }
}


#define implies \
    || implies_detail::NegationHelper{} ? true :
