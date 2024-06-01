/*
Given a garden of size m*n with various types of crops, plant the crops in such a way that there is a path connecting all crops of the same type. 
This path can be formed by moving either horizontally or vertically. Total number of crops will always be equal to size of garden.

Example :
5 potatoes, 3 bananas, 4 onions
m = 3, n = 4

one of the possible arrangments :
P P P P
B B B P
O O O O
*/

vector<vector<string>>fillGarden(unordered_map<string, int>crops, int m, int n) {
    vector<vector<string>>garden(m, vector<string>(n, ""));
    auto it = crops.begin();
    for(int i = 0; i < m; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < n ; j++) {
                garden[i][j] = it->first;
                it->second--;
                if(it->second == 0)
                  it++;
            }
        } else {
            for(int j = n-1; j >= 0 ; j--) {
                garden[i][j] = it->first;
                it->second--;
                if(it->second == 0)
                  it++;
            }
        }
    }
    return garden;
}
