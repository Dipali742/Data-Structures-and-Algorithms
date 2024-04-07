void subsets(vector<int>&sumarray,  int sum, vector<int>&num,int index) {

	if(index == num.size())
	{
		sumarray.push_back(sum);
		return;
	}
	
	//take
	subsets(sumarray, sum + num[index], num, index+1);

	//not_take
	subsets(sumarray, sum, num, index+1);
}

vector<int> subsetSum(vector<int> &num){
  	vector<int>sumarray;
	int sum = 0;
	subsets(sumarray, sum,num, 0);
	sort(sumarray.begin(), sumarray.end());
	return sumarray;
}
