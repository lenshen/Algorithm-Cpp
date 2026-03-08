#include<iostream>
#include<random>

using namespace std;

const int N = 15;

struct ListNode{
    int v;
    ListNode *next;
    ListNode(): v(0), next(nullptr){}
    ListNode(int x): v(x), next(nullptr){}
    ListNode(int x ,ListNode *next): v(x), next(next){} 
};

ListNode *InsertionSort(ListNode *head){
    ListNode* dummy = new ListNode(0);
    ListNode *cur = head;
    
    while(cur != nullptr){
        ListNode *prev = dummy;
        while(prev->next && prev->next->v <= cur->v){
            prev = prev->next;
        }
        ListNode *temp = cur->next;
        cur->next = prev->next;
        prev->next = cur;
        cur = temp;
    }
    
    ListNode *stored = dummy->next;
    delete dummy;
    return stored;
}

class LinkList{
    private:  
        ListNode* head;
    public:
        LinkList(){
            head = nullptr;
        }
        ~LinkList(){
            ListNode *cur = head;
            while(cur){
                ListNode *t = cur->next;
                delete cur;
                cur = t;
            }
        }
        void append(int x){
            ListNode *cur = new ListNode(x);
            if(head == nullptr)
                head = cur;
            else{
                ListNode *t = head;
                while(t->next)
                    t = t->next;
                t->next = cur;
            }
            return;
        }
        void GR(){ 
            random_device rd; 
            mt19937 gen(rd()); 
            uniform_int_distribution<int> dis(-100, 1000); 
        
            for(int i = 0; i < N; i++){
                int x = dis(gen); 
                append(x);            
            }
            print();
            return;
        }
        void print(){
            ListNode *cur = head;
            while(cur){
                cout << cur->v <<" -> ";
                cur = cur->next;
            }
            cout <<"nullptr"<<"\n";
            return;
        }
        void ISort(){
            head = InsertionSort(head);
            cout<<"排序後: "<<"\n";
            print();
        }
};

void test(){
    LinkList myl;
    cout<<"排序前: "<<"\n";
    myl.GR();
    myl.ISort();
}

int main()
{
    test();
    return 0;
}
