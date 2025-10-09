#include<iostream>
using namespace std;
int main(){
	
	
	// shell sort is more efffient than insertion sort because insertion sort requires to many comparisms and shift operation//
	
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