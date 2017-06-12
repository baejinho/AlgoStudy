// =====================================================================================
// 
//       Filename:  쩨곱쩨곱.cpp
//        Created:  2017년 06월 13일 01시 36분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll _pow(ll a, ll b){
	if(!b)
		return 1;
	ll temp=_pow(a, b/2);
	temp=(temp*temp)%mod;
	if(b&1)
		return (temp*a)%mod;
	return temp;
}
int n;
int arr[100000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(int i=n-2;i>=0;i--)
		arr[i]=_pow(arr[i], arr[i+1]);
	printf("%d\n", arr[0]);
	return 0;
}

