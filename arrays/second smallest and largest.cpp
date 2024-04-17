// vector<int> getSecondOrderElements(int n, vector<int> a) {
//     int small = INT_MAX;
//     int large = INT_MIN;
//     for(int i =0;i<n;i++) {
//         small = min(small, a[i]);
//         large = max(large, a[i]);
//     }
//     int second_small = INT_MAX;
//     int second_large = INT_MIN;
//     for(int i = 0; i<n ;i++) {
//         if(a[i]>small)
//             second_small = min(second_small, a[i]);
//         if(a[i] < large)
//             second_large = max(second_large, a[i]);
//     }
//     return {second_large, second_small};
// }

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int small = a[0];
    int large = a[0];
    int second_small = INT_MAX;
    int second_large = INT_MIN;
    for(int i =0;i<n;i++) {
       if(a[i] < small) {
            second_small = small;
           small = a[i];
       } else if(a[i] != small) {
           second_small = min(a[i], second_small);
       }

        if(a[i] > large) {
           second_large = large;
           large = a[i];
        } else if(a[i] != second_large){
           second_large = max(a[i], second_large);
       }
    }
    return {second_large, second_small};
}
