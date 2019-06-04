#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <complex>

using namespace std;

const complex<double> M_PI_2_i = complex<double>(0.0, 1.0) * 2.0 * M_PI;

enum FFT_VERSION
{
    NORMAL,
    INVERSE
};

template<FFT_VERSION version>
struct root_of_unity
{
    static complex<double> value (int n)
    {
        return exp<double> (M_PI_2_i * (double)n);
    }
};

template<>
struct root_of_unity<NORMAL>
{
    static complex<double> value (int n)
    {
        return exp<double> (M_PI_2_i / (double)n);
    }
};

template<>
struct root_of_unity<INVERSE>
{
    static complex<double> value (int n)
    {
        return exp<double> (M_PI_2_i * (double)(n-1) / (double)n);
    }
};


template<FFT_VERSION v>
void fft_rec(vector<complex<double> > &y)
{
    int n = y.size();
    if(n <= 1) return;
    
    vector<complex<double> > y0,y1;

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            y0.push_back(y[i]);
        else
            y1.push_back(y[i]);
    }

    fft_rec<v>(y0);
    fft_rec<v>(y1);

    complex<double> omegaN = root_of_unity<v>::value(n);
    complex<double> omega(1.0, 0.0);

    for(int k = 0; k < n/2; k++)
    {
        y[k] = y0[k] + omega*y1[k];
        y[k+n/2] = y0[k] - omega*y1[k];
        omega *= omegaN;
    }
}

template <FFT_VERSION v>
void fft(vector<complex<double> > &a)
{
    int n = a.size();
    int newN = 1;
    if(n > 1) while(newN < n) newN <<= 1;
    a.resize(newN);
    fft_rec<v>(a);

    if(v == INVERSE)
    {
        int d = a.size();
        for(unsigned i = 0; i < a.size(); i++)
            a[i] /= d;
    }
}

void polynomial_multiply(vector<complex<double> > &a, vector<complex<double> > &b)
{
    int sz = max(a.size(), b.size())*2;
    a.resize(sz);
    b.resize(sz);
    fft<NORMAL>(a);
    fft<NORMAL>(b);

    for(unsigned i = 0; i < a.size(); i++)
        a[i] *= b[i];

    fft<INVERSE>(a);
}

void square_polynomial(vector<complex<double> > &a)
{
    a.resize(2*a.size());
    fft<NORMAL>(a);
    for(unsigned i = 0; i < a.size(); i++)
        a[i] *= a[i];

    fft<INVERSE>(a);
}

int main()
{
}
