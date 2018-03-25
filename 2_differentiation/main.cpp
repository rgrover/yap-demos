template <typename Function>
struct differentiator
{
    constexpr explicit differentiator(Function f, double delta = 0.001) :
        f{f}, delta{delta} {};

    auto operator()(double x) const
    {                                         //         f(x + Δ) - f(x)
        return (f(x + delta) - f(x)) / delta; // f'(x) = ---------------
                                              //                Δ
    }

    Function     f;
    const double delta = 0.001;
};

double function(double x) { return x * x; }
double x = 1;

int main()
{
    differentiator firstDerivative{function};

    return firstDerivative(x);
}

/* differentiator also satisfies the concept of Function, so we can re-apply it. */
