#include<bits/stdc++.h>
using namespace std;
#define int long long int
int give(int w, int x, int y, int z){
    vector<int> a = {w, x, y, z}; int diff = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i != j) diff = max(diff, a[i] - a[j]);
        }
    }
    return diff;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n1, n2, n3, n4;
    cin >> n1;
    vector<int> caps(n1);
    for(int i = 0; i < n1; i++){
        cin >> caps[i];
    }
    cin >> n2;
    vector<int> shirts(n2);
    for(int i = 0; i < n2; i++){
        cin >> shirts[i];
    }
    cin >> n3;
    vector<int> pants(n3);
    for(int i = 0; i < n3; i++){
        cin >> pants[i];
    }
    cin >> n4;
    vector<int> shoes(n4);
    for(int i = 0; i < n4; i++){
        cin >> shoes[i];
    }
    sort(caps.begin(), caps.end());
    sort(shirts.begin(), shirts.end());
    sort(pants.begin(), pants.end());
    sort(shoes.begin(), shoes.end());
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0, mn = INT_MAX, a = -1, b = -1, c = -1, d = -1;
    while (i1 < n1 and i2 < n2 and i3 < n3 and i4 < n4){
        int diff = give(caps[i1], shirts[i2], pants[i3], shoes[i4]);
        if(diff < mn){
            mn = diff;
            a = i1, b = i2, c = i3, d = i4;
        }
        if(caps[i1] <= shirts[i2] and caps[i1] <= pants[i3] and caps[i1] <= shoes[i4]){
            i1++;
        }else if(shirts[i2] <= caps[i1] and shirts[i2] <= pants[i3] and shirts[i2] <= shoes[i4]){
            i2++;
        }else if(pants[i3] <= caps[i1] and pants[i3] <= shirts[i2] and pants[i3] <= shoes[i4]){
            i3++;
        }else if(shoes[i4] <= caps[i1] and shoes[i4] <= shirts[i2] and shoes[i4] <= pants[i3]){
            i4++;
        }
    }
    cout << caps[a] << ' ' << shirts[b] << ' ' << pants[c] << ' ' << shoes[d] << '\n';
    return 0;
}
