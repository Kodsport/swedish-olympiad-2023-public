#include <bits/stdc++.h>
using namespace std;

map<string,int> M;
vector<string> nums = {".***..", "*.....", "*.*...", "**....", "**.*..", "*..*..", "***...", "****..", "*.**..", ".**..."};

int parse(){
    int n;
    cin >> n;
    vector<string> digits(n, "");
    for(int row = 0; row < 3; row++){
        for(int c1 = 0; c1 < n; c1++){
            string s;
            cin >> s;
            digits[c1] += s;
        }
    }
    int ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ans *= 10;
        ans += M[digits[c1]];
    }
    return ans;
}

void print_ans(int ans){
    vector<string> digits;
    if(ans == 0)digits.push_back(nums[0]);
    while(ans > 0){
        digits.push_back(nums[ans%10]);
        ans /= 10;
    }
    reverse(digits.begin(), digits.end());
    for(int row = 0; row < 3; row++){
        for(int c1 = 0; c1 < digits.size(); c1++){
            cout << digits[c1][2*row] << digits[c1][2*row+1] << " ";
        }cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int c1 = 0; c1 < 10; c1++){
        M[nums[c1]] = c1;
    }
    int a = parse();
    int b = parse();
    print_ans(a+b);

    return 0;
}