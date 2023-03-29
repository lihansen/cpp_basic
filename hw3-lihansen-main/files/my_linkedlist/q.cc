#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.


SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v){
    ListNode *p = new ListNode(0);
    this->head_ = p;

    for(auto elem: v){
        p->next = new ListNode(elem);
        p = p->next;
    }
    this->size_ = v.size();
    this->head_ = this->head_->next;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs){
    ListNode *p1 = new ListNode(0);
    this->head_ = p1;
    ListNode *p2 = rhs.const_head();
    int count = 0;
    while (p2){
        p1->next = new ListNode(p2->val);
        p1 = p1->next;
        p2 = p2->next;
        count ++;
    }
    this->head_ = this->head_->next;
    this->size_ = count;
}

bool SinglyLinkedList::empty(){
    return (this->size() == 0);
    // return (this->head_->next == NULL);
}

int SinglyLinkedList::size(){
    return this->size_;
}

ListNode *SinglyLinkedList::head(){
    return this->head_;
}

void SinglyLinkedList::push_back(int i){
    ListNode *p = this->head_;
    while(p->next){
        p = p->next;
    }
    p->next = new ListNode(i);
    this->size_ ++;

}

bool SinglyLinkedList::pop_back(){
    if (this->size_ == 0){
        return false;
    }
    if (this->size_ ==1){
        this->head_ = nullptr;
        this->size_ = 0;
        return true;
    }else{
        ListNode *p = this->head();
        while(p->next->next){
            p = p->next;
        }
        p->next = p->next->next;
        this->size_--;
        return true;

    }

}

int SinglyLinkedList::back(){
    if (this->empty()){
        return -1;
    }

    ListNode *p = this->GetBackPointer();
    return p->val;
}

ListNode *SinglyLinkedList::GetBackPointer(){
    ListNode *p = this->head_;
    while (p->next)
    {
        p = p->next;
    }
    return p;
}

ListNode * SinglyLinkedList::GetIthPointer(int i ){
    if (i < 0 or i>this->size()){
        return nullptr;
    }
    ListNode *p = this->head_;

    for (int j = 0; j < i;j++){
        p = p->next;
    }

    return p;
}

int& SinglyLinkedList::operator[](int i){
    if (i < 0 or i>this->size()){
        return this->error_code;
    }
    return this->GetIthPointer(i)->val;
}


void SinglyLinkedList::print(){
    ListNode *p = this->head_;
    while(p){
        std::cout<< p->val << std::endl;
        p = p->next;
    }
}

std::vector<int> SinglyLinkedList::convert_to_vector(){
    ListNode *p = this->head_;
    std::vector<int> v = {};
    // v.insert(v.begin(), p->val);
    while(p){ 
        v.push_back(p->val);
        p = p->next;
    }
    return v;
}


ListNode *SinglyLinkedList::erase(int i){
    if (i < 0 or i>this->size()){
        return nullptr;
    }
    if (i == 0){
        this->head_ = this->head_->next;
        this->size_--;
        return this->head_;
    }else{

    ListNode *p = this->head_;
    for (int j = 0; j< i-1;j++){
        p = p->next;
    }
    p->next = p->next->next;
    // this->head_ = p->next;
    return p;
    }
}

void SinglyLinkedList::remove_duplicates(){
    std::vector <int> v = {this->head_->val};
    ListNode *p = this->head_;
    while(p->next){
        bool exist = false;
        for (int i = 0; i < int(v.size()); i++)
        {
            if (v[i] == p->next->val){
                exist = true;
                break;
            }
        }


        if (exist){
            p->next = p->next->next;
            this->size_--;
        }else{
            v.push_back(p->next->val);
            p = p->next;

        }

    }
}

ListNode *SinglyLinkedList::const_head() const{
    return this->head_;
}
