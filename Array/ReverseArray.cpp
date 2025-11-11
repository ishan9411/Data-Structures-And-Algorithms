//Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

void reverseArray(vector<int> &arr , int m) {
    int i = m+1;
    int j = arr.size()-1;

    while (i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

}