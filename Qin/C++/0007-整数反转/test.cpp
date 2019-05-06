#include <iostream>
using namespace std;

bool isOverflow(int x){
	if(x > 214748364 || x < -214748364) return true;
	else return false;
}

bool isOverflow(int x,int y){
    if(x > 0 && y > 0)
    	if(x > 2147483647 - y) return true;
    if(x < 0 && y < 0)
    	if(x < -2147483648 - y) return true;
    return false;
}
int reverse(int x){
	int t,count = 0,rx = 0,count2 = 0;
	while(x){
		t = x%10;
		x /= 10;
		if(isOverflow(rx)) return 0;
		rx *= 10;
		if(isOverflow(rx,t)) return 0;
		rx += t;
	}
	return rx;
}


int main(){
	int x ;
	cin >> x;
	cout << reverse(x) << endl;
} 

