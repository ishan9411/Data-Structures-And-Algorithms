#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;

    vector<long long> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    unordered_map<long long, long long> mp;
    mp[0]++;
    long long result = 0;
    long long prefixSum = 0;

    for(int i = 0; i<n; i++){
        prefixSum += arr[i];
        result += mp[prefixSum - x];
        mp[prefixSum]++;
    }

    cout << result;
}