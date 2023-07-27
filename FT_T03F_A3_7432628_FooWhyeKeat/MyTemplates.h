//function templates
template <typename T>
double scalar_difference(T x, T y){
    return fabs(x.getScalarValue() - y.getScalarValue());
}
//comparator
template <typename T>
bool DSC(T& p1, T& p2){
    return p1 > p2;
}

template <typename T>
bool ASC(T& p1, T& p2){
    return p1 < p2;
}

