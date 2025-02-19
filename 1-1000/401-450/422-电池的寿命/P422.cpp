#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    int n;
    while(cin >> n){
        int sum = 0, maxv = -1;
        for(int i = 1; i <= n; i++){
            int t;
            cin >> t;
            sum += t;
            maxv = max(maxv, t);
        }

        if(sum - maxv < maxv) printf("%d.1lf\n", (sum-maxv)*1.0);
        else printf("%.1lf\n", sum / 2.0);
    }

	return 0;
}
