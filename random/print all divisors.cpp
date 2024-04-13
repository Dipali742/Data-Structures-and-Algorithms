int* printDivisors(int n, int &size){
    int* arr = (int*)malloc(sizeof(int) * (n / 2 + 1));
    size = 0;
    for(int i = 1; i<= n/2 ;i++) {
        if(n % i == 0) {
            arr[size] = i;
            size++;
        }
    }
    arr[size] = n;
    size++;
    return arr;
}

int* printDivisors(int n, int &size){
    int* arr = (int*)malloc(sizeof(int) * (n / 2 + 1));
    size = 0;
    for(int i = 1; i*i<=n ;i++) {
        if(n % i == 0) {
            arr[size] = i;
            size++;
            if(n/i != i) {
                arr[size] = n/i;
                size++;
            }
        }
    }
    sort(arr, arr + size);
    return arr;
}
