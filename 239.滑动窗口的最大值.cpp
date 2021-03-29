#include "LeetCode.h"
#include <map>
using namespace std;
class Solution
{
public:
    class myDeque{
        struct node{
            int val;
            node* prev=nullptr;
            node* next=nullptr;
        }*head,*tail;


        void insertEmpty(int val){
            head=tail=new node{val};
        }
        public:
        myDeque(void){
            head = nullptr;
            tail=nullptr;
        }
        bool empty(){
            return head==nullptr&&tail==nullptr;
        }
        void push_back(int val){
            if(!empty()){
                node* n = new node{val,tail,nullptr};
                tail->next=n;
                tail=n;
            }else{
                insertEmpty(val);
            }
        }
        void pop_back(){
            auto last=tail;
            tail=tail->prev;
            if(tail)tail->next=nullptr;
            else{
                head=tail=nullptr;
            }
            delete last;
        }
        int back(){
            return tail->val;
        }
        int front(){
            return head->val;
        }
        void pop_front(){
            auto first = head;
            head=head->next;
            if(head)head->prev=nullptr;
            else{
                tail=head=nullptr;
            }
            delete first;
        }
    };
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        myDeque q;

        for(int i=0;i<k;i++){
            while(!q.empty()&&nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ret{nums[q.front()]};
        for(int i=k,length = nums.size();i<length;i++){
            while(!q.empty()&&nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            while(q.front()<=i-k){
                q.pop_front();
            }
            ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        int k;
        in >> str >> k;
        auto arr = getArray(str);
        arr = Solution().maxSlidingWindow(arr, k);
        print(arr);
    }
}