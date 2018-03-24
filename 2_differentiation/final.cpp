double function(double x)
{
    return x * x;
}

template <typename Function>
struct differentiator
{
    constexpr explicit differentiator(Function f, double delta = 0.001) : f{f}, delta{delta} {};

    auto operator()(double x) const
    {
        return (f(x + delta) - f(x)) / delta;
    }

    Function f;
    double   delta = 0.001;
};
template <typename UnderlyingPartial>
differentiator(UnderlyingPartial) -> differentiator<UnderlyingPartial>;

volatile double x = 1;

int main()
{
    differentiator firstDerivative{function};
    differentiator secondDerivative{firstDerivative};

    return firstDerivative(x);
}
