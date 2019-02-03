#include <iostream>

using namespace std;

struct LinkNode{
    LinkNode *link;
    int data;
    LinkNode(LinkNode *ptr = nullptr){link = ptr;}
    LinkNode(const int &x, LinkNode *ptr = nullptr){data = x; link = ptr;}
};

class LinkList{
private:
    LinkNode *first;
public:
    LinkList(){first = new LinkNode;} //构造函数
    LinkList(const int &x){first = new LinkNode; first->data = x;}//带参数的构造函数
    LinkList(LinkList &ll);//复制构造函数
    ~LinkList(){makeEmpty();}          //析构函数
    void makeEmpty();       //清空
    int Length()const;       //获得链表长度
    LinkNode *getHead()const{return first;}  //获得头部
    bool Search(const int &x); //搜索值为x的结点
    bool Locate(const int &x, int &i);//定位值为x的元素，确定其为第几个元素
    bool getData(const int &i, int &x);//获得第i个元素的值x
    bool setData(const int &i, const int &x);//改变第i个元素的值为x
    bool Insert(const int &i, const int &x);//在第i项插入新值x
    bool Remove(const int &i);//移除链表第i项
    bool isEmpty()const;//空？
    bool isFull()const{return false;}//满？
    void Input(const int *array, const int &arraySize);//输入
    void Output();//输出
    LinkList & operator = (LinkList &ll);//重载
};

LinkList :: LinkList(LinkList &ll){
    int value = 0;
    LinkNode *srcptr = ll.getHead();
    LinkNode *destptr = new LinkNode;
    destptr = first;
    while(srcptr != nullptr){       //逐个结点被复制
        value = srcptr->link->data;
        destptr->link = new LinkNode(value);
        destptr = destptr->link;
        srcptr = srcptr->link;
    }
    destptr->link = nullptr;
}
bool LinkList :: isEmpty()const{
    if(first == NULL){
        return true;
    }
    else{
        return false;
    }
}

void LinkList :: makeEmpty(){
    LinkNode *temp;
    while(first != nullptr){
        temp = first;
        first = first->link;
        delete []temp;
    }
}

int LinkList :: Length()const{
    LinkNode *current;
    current = first;
    int count = 0;
    while(current != nullptr){
        ++count;
        current = current->link;
    }
    return count;
}

void LinkList :: Input(const int *array, const int &arraySize){
    cout<<"the input is : ";
    for(int i = 0; i < arraySize; ++i){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    LinkNode *current = first;
    for(int i = 0; i < arraySize; ++i){
        LinkNode *temp = new LinkNode(array[i]);
        current->link = temp;
        current = temp;        
    }
}

void LinkList :: Output(){
    LinkNode *current = first;
    cout<<"the output is : ";
    while(current->link != nullptr){
        cout<<current->link->data<<" ";
        current = current->link;
    }
    cout<<endl;
}

bool LinkList :: Search(const int &x){
    LinkNode *current = first->link;
    while(current != nullptr){
        if(current->data == x){
            return true;
        }
        current = current->link;
    }
    return false;
}

bool LinkList :: Locate(const int &x, int &i){
    LinkNode *current = first->link;
    int count = 0;
    while(current != nullptr){
        ++count;
        if(current->data == x){
            i = count;
            return true;
        }
        current = current->link;
    }
    i = -1;
    return false;
}

bool LinkList :: getData(const int &i, int &x){
    LinkNode *current = first->link;
    int count = 0;
    while(current != nullptr){
        ++count;
        if(i == count){
            x = current->data;
            return true;
        }
        current = current->link;
    }
    x = -1;
    return false;
}

bool LinkList :: setData(const int &i, const int &x){
    LinkNode *current = first->link;
    int count = 0;
    while(current != nullptr){
        ++count;
        if(i == count){
            current->data = x;
            return true;
        }
    }
    return false;
}

bool LinkList :: Insert(const int &i, const int &x){
    LinkNode *current = first;
    int count = 0;
    while(current != nullptr){
        ++count;
        if(i == count){
            LinkNode *newNode = new LinkNode(x);
            LinkNode *temp;
            temp = current->link;
            current->link = newNode;
            newNode->link = temp;
            return true;
        }
        current = current->link;
    }
    return false;
}

bool LinkList :: Remove(const int &i){
    LinkNode *current = first, *temp;
    int count = 0;
    while(current != nullptr){
        ++count;
        if(i == count){
            temp = current->link;
            current->link = current->link->link;
            delete temp;
            return true;
        }
        current = current->link;
    }
    return false;
}

LinkList & LinkList :: operator = (LinkList &ll){
    int value = 0;
    LinkNode *scrptr = first;
    LinkNode *destptr = first;
    while(scrptr->link != nullptr){
        value = scrptr->link->data;
        destptr->link = new LinkNode(value);
        scrptr = scrptr->link;
    }
    return *this;
}
int main(){
    int array[] = {59,66,78,96,41,53,62};
    int value = 0;
    int array_size = sizeof(array)/sizeof(int);
    LinkList ll(array_size);
    ll.Input(array, array_size);
    ll.Output();
    return 0;
}
