/*
Problem Statement:
Given a matrix containing only 0s and 1s, determine if there exists a path from the top-left corner (0,0) to the bottom-right corner (n-1, n-2) such that:

The number of 0s and 1s encountered along the path is equal.
The path can visit each cell multiple times.
The path can only move to adjacent cells (up, down, left, right) that are within the bounds of the matrix.

time complexity = O(N*(N-1))
*/

#include<bits/stdc++.h>

using namespace std;


bool isSafe(int row, int column, int n) {
	return row < n && row >= 0 && column >= 0 && column < n-1;
}

bool visitOnce(vector<vector<int>>&matrix, int zeroes, int ones, int i, int j, bool adjZeroes, bool adjOnes) {
	if(matrix[i][j] == 0) {
		matrix[i][j] += 2;
		zeroes++;
	} else {
		matrix[i][j] += 2;
		ones++;
	}
	if(i == matrix.size()-1 && j == i-1) {
		if(zeroes == ones)
			return true;
		return false;
	}

	vector<vector<int>>indices {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};

	for(int k = 0; k < 4 ;k++) {
		int row = i + indices[k][0];
		int column = j + indices[k][1];

		if(isSafe(row, column, matrix.size())) {
			
			if(matrix[i][j] - 2 == matrix[row][column]) {
				if(matrix[row][column] == 1)
					adjOnes = true;
				else
					adjZeroes = true;
			}

			if(adjOnes && adjZeroes)
				return true;
			if((matrix[row][column] == 0 || matrix[row][column] == 1)) {
				if(visitOnce(matrix, zeroes, ones, row, column, adjZeroes, adjOnes)) 
				return true;
				matrix[row][column] -= 2;
			}
			
		}
	}

	return false;
}


int main() {
	
	vector<vector<int>>matrix {
		{0, 1, 1},
		{1, 0, 1},
		{1, 1, 1},
		{1, 1, 1}
	};

	if(visitOnce(matrix, 0, 0, 0, 0, false, false))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
