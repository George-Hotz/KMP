#include "kmp.h"

vector<int> init_next(string &t){
    vector<int> next = {0};
    for(int i=1; i<t.size(); i++){
        int left = 0, right = i, num = 0;
        while(left < right){
            if(t[left] == t[right]){
                num++;
            }else{
                break;
            }
            left++; right--;
        }
        next.push_back(num);
    }
    return next;
}

// 如果存在返回下标，不存在返回-1
int kmp_find(string &s, string &t){
    if(s.empty() || t.empty()){
        return -1;
    }
    vector<int> next = move(init_next(t));    //移动语义
    int s_idx = 0, t_idx = 0;
    while(s_idx < s.size()){
        if(s[s_idx] == t[t_idx]){
            s_idx++; t_idx++;
        }else if(t_idx == 0){
            s_idx++;
        }else if(t_idx != 0){
            t_idx = next[t_idx-1];
        }
        if(t_idx == t.size()){    //找到
            return s_idx - t_idx;
        }
    }
    return -1;
}



