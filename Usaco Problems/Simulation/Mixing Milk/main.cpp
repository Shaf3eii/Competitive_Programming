//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//   "From the river to the sea, Palestine is Free"

// Seek knowledge from the Cradle to the Grave.

// Never Give up -- Life is too short to make mistakes and learn from them -- Learn from other's mistakes

// Remember you were always a novice when you started so never be rude to some one

// Aim Big and strive hard to get it

// One has his own set of talents and anyone can do anything so never compare yourself to anybody

#include <bits/stdc++.h>

using namespace std;
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64 long long

int main() {
    Free_Palestine
#ifndef ONLINE_JUDGE
   freopen("mixmilk.in", "r", stdin);
   freopen("mixmilk.out", "w", stdout);
#endif
    auto get_next = [](int idx)->int{
        if(idx == 2)
            return 0;
        return idx + 1;
    };
    vector<i64> C(3) , B(3);
    for(int i = 0 ; i < 3 ; ++i)
        cin >> C[i] >> B[i];

    for(int i = 1 , idx = -1 , next = 0; i <= 100 ; i++)
    {
        idx = get_next(idx);
        next = get_next(next);
        i64 add = min(B[idx] , C[next] - B[next]);
        B[idx] -= add;
        B[next] += add;
//        cout << idx << " " << next << '\n';
    }
    for(auto & i : B)
        cout << i << '\n';

    return 0;
}
