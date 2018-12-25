#ifdef NDEBUG
    #undef NDEBUG
#endif

#include <operator/implies.hpp>

#include <cassert>
#include <initializer_list>


void assert_propositional_calculus_axioms(bool a, bool b, bool c)
{
    assert(a implies b implies a);
    assert((a implies b) implies (a implies b implies c) implies (a implies c));
    assert(a implies b implies a and b);
    assert(a and b implies a);
    assert(a and b implies b);
    assert(a implies a or b);
    assert(b implies a or b);
    assert((a implies c) implies (b implies c) implies (a or b implies c));
    assert((a implies b) implies (a implies not b) implies not a);
    assert(not not a implies a);
}


int main()
{
    for (bool a : { true, false })
    {
        for (bool b : { true, false })
        {
            for (bool c : { true, false })
            {
                assert_propositional_calculus_axioms(a, b, c);
            }
        }
    }
}
