struct node{
    node *bits[2];
    int cnt[2];
    node(){
        this -> bits[0] = nullptr;
        this -> bits[1] = nullptr;
        this -> cnt[0] = 0;
        this -> cnt[0] = 0;
    }
};

node *root = new node();

void insert(int v){
    node *tmp = root;
    for(int i = 20; i >= 0; i--){
        int b = (v >> i) & 1;
        if(!tmp -> bits[b]){
            tmp -> bits[b] = new node();
        }
        tmp -> cnt[b] += 1;
        tmp = tmp -> bits[b];
    }
}

void del(int v){
    node *tmp = root;
    for(int i = 20; i >= 0; i--){
        int b = (v >> i) & 1;
        tmp -> cnt[b] -= 1;
        tmp = tmp -> bits[b];
    }
}

int mx(int v){
    node *tmp = root;
    int ans = 0;
    for(int i = 20; i >= 0; i--){
        int b = (v >> i) & 1;
        int need = 1 - b;
        if(tmp -> bits[need] and tmp -> cnt[need] != 0){
            ans |= (1 << i);
            tmp = tmp -> bits[need];
        }else{
            tmp = tmp -> bits[b];
        }
    }
    return ans;
}

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        while(j < n){
            insert(nums[j]);
            while(nums[i] * 2 < nums[j]){
                del(nums[i++]);
            }
            ans = max(ans, mx(nums[j++]));
        }
        root = new node();
        return ans;
    }
};
