// =====================================================================================
// 
//       Filename:  약수의곱.cpp
//        Created:  2017년 06월 13일 01시 31분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long n;
int main(){
	scanf("%lld", &n);
	long long ans=1;
	for(long long i=1;i*i<=n;i++){
		if(n%i==0){
			ans*=i;
			ans%=mod;
			if(i!=n/i){
				ans*=n/i;
				ans%=mod;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

