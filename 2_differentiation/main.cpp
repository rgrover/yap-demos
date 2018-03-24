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

volatile double x = 1;

int main()
{
    differentiator firstDerivative{function};

    return firstDerivative(x);
}
