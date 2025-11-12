#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename Func>
void iter(T* arr, const int len, Func f)
{
    for (int i = 0; i < len; ++i) {
        f(arr[i]);
    }
}


#endif 