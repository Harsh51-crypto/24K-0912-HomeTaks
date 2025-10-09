#include<iostream>
using namespace std;
int main(){
	
	
	// if our smaller elements are on right most side then we prefer shell sort because it works according to gap while bubble sort compare the adjcent element in array //
   // for our sample input [32, 25, 40, 12,18, 50, 28]  shell sort is more effiecnt //
   
	
	int n;
	cin>>n;
		
	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];	
	}
	
	for(int i=0;i<n;++i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	for(int gap=n/2;gap>=1;gap=gap/2){
		
		for(int j=gap;j<n;++j){
			for(int i=j-gap;i>=0;i-=gap){
				if(arr[i]<arr[gap+i]){
					break;
				}
				else{
					swap(arr[i],arr[gap+i]);
				}
			}
		}
	
	}
	
	for(int i=0;i<n;++i){
		cout<<arr[i]<<" ";
	}
	
	
	return 0;
	
}