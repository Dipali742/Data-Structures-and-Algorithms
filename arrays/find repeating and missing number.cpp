vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n = a.size();
    int suma = 0;
    int suma2 = 0;
    int expected_suma = 0;
    int expected_suma2 = 0;
    for(int i = 0; i<n;i++) {
        suma+=a[i];
        suma2+=a[i]*a[i];
        expected_suma+=i+1;
        expected_suma2+=(i+1)*(i+1);
    }
    // cout<<suma<<" "<<suma2<<" "<<expected_suma<<" "<<expected_suma2<<endl;
   //expected_suma2 - suma2 = x^2 - y^2 = (x-y)(x+y)

    int xminusy = (expected_suma-suma);
    int x2minusy2 = (expected_suma2 - suma2);
    int xplusy = x2minusy2/xminusy;
    
    int x = (xminusy + xplusy)/2;
    int y = xplusy-x;

    return {y, x};
}
