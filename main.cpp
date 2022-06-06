#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>

int numOfBrackets = 0;

long long factorial(int n){
    long long factor = 1;
    for (size_t i = 2; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}

//n-factorial decomposition
std::vector<int> FDecomp(int n, long long m) {
    int i = 0;
    std::vector<int> d;
    d.push_back(0);
    long long q = m;
    while (q > 0) {
        ++i;
        d.push_back(q%i);
        q /=i;
    }
    ++i;
    while (i < n) {
        d[i] = 0;
        i++;
    }
    return d;
}

void PLex(int n) {
    if (!n) {
        std::cout << "0";
        return;
    }
    std::vector<int> a;
    for (int j = 0; j <= n; j++) { a.push_back(j);}
    int i = 1;
    while (i) {
        for (int j = 1; j <= n; j++) {std::cout << a[j] << " ";}
        std::cout << std::endl;
        i = n-1;
        while (a[i] >= a[i+1]) { --i;}
        int j = n;
        while (a[j] <= a[i]) { --j;}
        std::swap(a[i], a[j]);
        int k = i + 1;
        j = n;
        while (k < j) {
            std::swap(a[k],a[j]);
            ++k;
            --j;
        }
    }
}

void generationOfAllPermutationsByEhrlichSwaps(int n) {
    std::vector<int> a, b, c;
    c.push_back(0);
    for (size_t i = 0; i < n; ++i) {
        a.push_back(i+1);
        b.push_back(i);
        c.push_back(0);
    }
    int k = 0, j = 0;
    while (true) {
        for(size_t i = 0; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
        k = 1;
        while (c[k] == k) {
            c[k] = 0;
            ++k;
        }
        if (k == n) {
            break;
        } else {
            ++c[k];
        }
        std::swap(a[0], a[b[k]]);
        j = 1; --k;
        while (j < k) {
            std::swap(a[j], a[k]);
            ++j; --k;
        }
    }
}

//Generation all binary vectors with length n
void GreyBinCode(int n) {
    std::vector<int> vect;
    for (size_t i = 0; i < n; ++i) {
        vect.push_back(0);
    }
    vect.push_back(0);
    int j = 0;
    while (true) {
        for (size_t i = 0; i < n; ++i) {
            std::cout << vect[n - i - 1];
        }
        std::cout << std::endl;
        vect[n] = 1 - vect[n];
        if (vect[n] == 1) {
            j = 0;
        } else {
            for (size_t i = 1; i <= n; ++i) {
                if (vect[i-1] == 1) {
                    j = i;
                    break;
                }
            }
        }
        if (j == n) {
            break;
        } else {
            vect[j] = 1 - vect[j];
        }
    }
}

void GreyBinCodeWithoutCycles(int n) {
    std::vector<int> a;
    std::vector<int> F;
    for (size_t i = 0; i < n; ++i) {
        a.push_back(0);
        F.push_back(i);
    }
    F.push_back(n);
    int j = 0;
    while(true) {
        for (size_t i = 0; i < n; ++i) {
            std::cout << a[n-i-1];
        }
        std::cout << std::endl;
        j = F[0];
        F[0] = 0;
        if (j == n) {
            break;
        }
        F[j] = F[j+1];
        F[j+1] = j+1;
        a[j] = 1 - a[j];
    }
}

void VLex(int n) {
    std::vector<bool> boolVector;
    for (size_t i = 0; i <= n; ++i) {
        boolVector.push_back(false);
    }
    while(!boolVector[n]) {
        for (int i = n-1; i >= 0; --i) {
            std::cout << boolVector[i];
        }
        std::cout << std::endl;
        int i = 0;
        while (boolVector[i]){
            boolVector[i] = false;
            ++i;
        }
        boolVector[i] = true;
    }
}

//end of bin vectors algorithms

void CombinationsInLexicalOrder(int n, int t) {
    std::vector<int> c;
    c.push_back(0);
    for (size_t i = 1; i <= t; ++i) {
        c.push_back(i-1);
    }
    c.push_back(n);
    c.push_back(0);
    int j = 0;
    while (true) {
        for (size_t i = 1; i <= t; ++i) {
            std::cout << c[i] << " ";
        }
        std::cout << std::endl;
        j = 1;
        while ((c[j] + 1) == c[j+1]) {
            c[j] = j - 1;
            ++j;
        }
        if (j > t) {
            break;
        } else {
            ++c[j];
        }
    }
}

void CombinationsByGreyCode(int n, int t) {
    std::vector<int> c;
    c.push_back(0);
    for (size_t i = 1; i <= t; ++i) {
        c.push_back(i-1);
    }
    c.push_back(n);
    int j = 0;
    while (true) {
        r2:
        for (size_t i = t; i >= 1; --i) {
            std::cout << c[i] << " ";
        }
        std::cout << std::endl;
        if (t % 2) {
            if ((c[1] + 1) < c[2]) {
                ++c[1];
                goto r2;
            } else {
                j = 2;
                goto r4;
            }
        } else {
            if (c[1] > 0) {
                --c[1];
                goto r2;
            } else {
                j = 2;
                goto r5;
            }
        }
        r4:
        if (c[j] >= j) {
            c[j] = c[j-1];
            c[j-1] = j-2;
            goto r2;
        } else {
            ++j;
        }
        r5:
        if ((c[j] + 1) < c[j+1]) {
            c[j-1] = c[j];
            ++c[j];
            goto r2;
        }
        ++j;
        if (j <= t) {
            goto r4;
        }
        else {
            break;
        }
    }
}

bool nextSetWithoutRepetitions(std::vector<int>& a, int n, int m) {
    int k = m;
    for (int i = k-1; i >= 0; --i) {
        if (a[i] < (n - k + i + 1)) {
            ++a[i];
            for (int j = i + 1; j < k; ++j) {
                a[j] = a[j-1] + 1;
            }
            return true;
        }
    }
    return false;
}

void combinationsWithoutRepetitions(int n, int m) {
    std::vector<int> array;
    for (int i = 0; i < n; ++i) {
        array.push_back(i+1);
    }
    for (size_t i = 0; i < m; ++i){
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
    if (n >= m) {
        while (nextSetWithoutRepetitions(array, n, m)) {
            for (size_t i = 0; i < m; ++i){
                std::cout << array[i] << "\t";
            }
            std::cout << std::endl;
        }
    }
}

bool nextSetWithRepetitions(std::vector<int>& a, int n, int m) {
    int j = m - 1;
    while ((a[j] == n) && (j >= 0)) {
        j--;
    }
    if (j < 0) { return false; }
    if (a[j] >= n) { --j; }
    ++a[j];
    if (j == (m-1)) { return true;}
    for (int k = j + 1; k < m; ++k) {
        a[k] = a[j];
    }
    return true;
}

void combinationsWithRepetitions (int n, int m) {
    std::vector<int> array;
    for (size_t i = 0; i < std::max(n,m); ++i) {
        array.push_back(1);
    }
    for (size_t i = 0; i < m; ++i){
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
    while(nextSetWithRepetitions(array,n,m)) {
        for (size_t i = 0; i < m; ++i){
            std::cout << array[i] << "\t";
        }
        std::cout << std::endl;
    }
}

void swap(std::vector<int>& a, int i, int j) {
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

bool nextSetArrangementWithoutRepetitions(std::vector<int>& a, int n, int m) {
    int j = 0;
    do  // повторяем пока не будет найдено следующее размещение
    {
        j = n - 2;
        while (j != -1 && a[j] >= a[j + 1]) j--;
        if (j == -1)
            return false; // больше размещений нет
        int k = n - 1;
        while (a[j] >= a[k]) { k--; }
        std::swap(a[j], a[k]);
        int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
        while (l < r) {
            swap(a, l++, r--);
        }
    } while (j > m - 1);
    return true;
}

void arrangementWithoutRepetitions(int n, int m) {
    if (!m) {
        std::cout << "0";
        return;
    }
    std::vector<int> a;
    for (size_t i = 0; i < n; ++i) {
        a.push_back(i+1);
    }
    for (size_t i = 0; i < m; ++i){
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;
    while (nextSetArrangementWithoutRepetitions(a,n,m)) {
        for (size_t i = 0; i < m; ++i){
            std::cout << a[i] << "\t";
        }
        std::cout << std::endl;
    }
}

bool nextSetArrangementWithRepetitions(std::vector<int>& a, int n, int m) {
    int j = m - 1;
    while (j >= 0 && a[j] == n) j--;
    if (j < 0) return false;
    if (a[j] >= n) j--;
    a[j]++;
    if (j == m - 1) return true;
    for (int k = j + 1; k < m; k++)
        a[k] = a[j];
    return true;
}

void arrangementWithRepetitions(int n, int m) {
    std::vector<int> a;
    for (size_t i = 0; i < std::max(n,m); ++i) {
        a.push_back(1);
    }
    for (size_t i = 0; i < m; ++i){
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;
    while(nextSetArrangementWithRepetitions(a,n,m)) {
        for (size_t i = 0; i < m; ++i){
            std::cout << a[i] << "\t";
        }
        std::cout << std::endl;
    }
}

void generateBracketSequence(int n, std::string s, int op_br, int cl_br) {
    if (op_br + cl_br == 2 * n) {
        std::cout << s << std::endl;
        ++numOfBrackets;
    }
    if (op_br < n) {
        generateBracketSequence(n, s + '(', op_br + 1, cl_br);
    }
    if (op_br - cl_br > 0) {
        generateBracketSequence(n, s + ')', op_br, cl_br + 1);
    }
}


int main() {
    //CombinationsByGreyCode(6, 3);
    //auto a = FDecomp(10,5);
    //for (int i = 0; i < a.size(); ++i) {
    //    std::cout << a[i];
    //}
    //std::cout << 123;
    return 0;
}
