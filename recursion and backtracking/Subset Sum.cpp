bool recursive_subset(vector<int>&a, int index, int target) {
    if(target == 0)
        return true;
    if(index >= a.size() && target != 0) {
        return false;
    }
    bool take = false;
    if(a[index] <= target)
       take = recursive_subset(a, index+1, target - a[index]);
    bool not_take = recursive_subset(a, index+1, target);
    return take || not_take;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return recursive_subset(a, 0, k);
}
