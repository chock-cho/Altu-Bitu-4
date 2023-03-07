//2981 해결하지 못했습니다. (무한 루프에 빠짐)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool not_prime[1000004];
void erathos() {
	not_prime[0]=true; not_prime[1]=true;
	for(int i = 2; i*i < 1000000; i++) { //범위 안의 수에 대하여
		for(int j =2*i; j <=100000; j+=i) { //그의 배수는 소수 후보군에서 제외
			not_prime[j]=true; //소수가 아님
		}
	}
}
bool func(int n) { //상근수인지 체크해주는 함수
	int sum; bool vis[1000004]={false,};
	while(true) {
		while(n!=0) {
			sum+=((n%10)*(n%10));
			vis[sum]=true;
			n/=10;
		} 
		if(sum==1&&!vis[sum]) {
			return true;
		}
		if(vis[sum]) {
			return false;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<int> ans; //답을 저장해주는 배열
	cin >> n;
	erathos();
	for(int i =0; i <=n; i++) {
		if(!not_prime[n]) { //만약 n이 소수라면,
			if(func[n]) { //상근수인 것을 체크해준다.
				ans.push_back(n);
			}
	}
	sort(ans.begin(), ans.end());
	for(auto x: ans) {
		cout << x << "\n";
		}
	}
}