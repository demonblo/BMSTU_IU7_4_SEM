#include <iostream>
#include <vector>
#include "set_impl.hpp"
#include "string"

using namespace std;

template <typename T>
class A {
private:
    string str{};

public:
    [[nodiscard]] auto length() const noexcept -> decltype(str.length()) {
        return str.length();
    }
};

template <>
auto A<int>::length() const noexcept -> decltype(str.length()) {
    return double(str.length());
}



int main() {
    A<int> test{};

    test.length<>()

//    try {
//        Set<int> a{1, 2, 3};
//        a += 4;
//        a.add(6);
//        a.remove(6);
//        a.remove(2);
//        a.remove(3);
//
//        int mas[] = {1, 2, 5, 4, 3, 2};
//        Set<int> b{mas, 6};
//        //cout << b.size();
////    b.clear();
//        auto it = b.begin();
//        auto itt = a.begin();
//
//        cout << *(it++);
//        cout << *++it;
//        cout << *++it;
//        //cout << *++it;
//        //cout << *it++;
//        cout << endl;
//
//        if (!it.isEnd())
//            cout << "LALLA";
//        else
//            cout << "LSKDJVHLIDK";
//        cout << endl;
//
////    for (const auto& elem : b)
////        cout << elem;
//
//        it = b.rbegin();
//        while (it != b.rend()) {
//            cout << *it-- << " ";
//        }
//
//        auto ret = a.find(2);
//
//        int *m = b.toArray();
//        delete m;
//
//        Set<int> o(b);
//        cout << endl;
//        copy(o.begin(), o.end(), std::ostream_iterator<int>(cout, " "));
//
//        Set<int> s (Set<int>{8, 9, 10});
//        cout << endl;
//        copy(o.begin(), o.end(), std::ostream_iterator<int>(cout, " "));
//
//        s = b;
//        s = Set<int>{1, 2, 3};
//
//        int l = 5;
//        s = l;
//
//        *it;
//
//        s.merge(b);
//        s.merge(Set<int>{10, 12});
//
//        s += Set<int>{13};
//        s += 0;
//        cout << endl;
//        copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
//        cout << endl;
//        Set<int> test1 = b + s;
//        test1 = b + s;
//
//        test1 = test1 * b;
//
//        Set<int> test2 = test1 * Set<int>{10, 12};
//
//        test1.subtraction({3, 4, 6});
//
//        test1 = test1 - Set<int>{4};
//
//        copy(test1.begin(), test1.end(), ostream_iterator<int>(cout, " "));
//
//
//        vector<int> arr{1, 2, 3, 5, 7, 9, 100};
//        Set<int> test3(test1.begin(), test1.end());
//    }
//    catch (setExpt& exception) {
//        cout << endl << exception.what() << endl;
//    }
    return 0;
}
