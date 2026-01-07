#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& bases, int target){
    int s = 0;
    int e = bases.size() - 1;
    int ans = -1;

    while(s <= e){
        int mid = s + (e-s)/2;

        if(bases[mid] > target){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> bases;
    bases.push_back(arr[0]);

    for(int i = 1; i<n; i++){
        int cube = arr[i];
        int upperBound = binarySearch(bases, cube);
        if(upperBound == -1){
            bases.push_back(cube);
        }else{
            bases[upperBound] = cube;
        }
    }
    cout << bases.size();
}