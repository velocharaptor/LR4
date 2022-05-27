#ifndef LR3_THREE_H
#define LR3_THREE_H

#include <iostream>
#include <cstring>
#include <functional>
#include "NodeThree.h"
#include "Complex.h"

using namespace std;

template<class T> class Three{
private:
    NodeThree<T>* root = nullptr;
    size_t length = 0;

    void map(NodeThree<T>* node, function<T(T)> f1){
        if(node){
            node->value = f1(node->value);
            map(node->left, f1);
            map(node->right, f1);
        }
    }

    void where(Three<T> &a, NodeThree<T>* node, function<bool(T)> f2){
        if(node){
            if(f2(node->value)){
                a.Add(node->value);
            }
            where(a, node->left, f2);
            where(a, node->right, f2);
        }
    }

    void concat(NodeThree<T>** node1, NodeThree<T>** node2){
        if(*node1){
            (*node2)->Add((*node1)->GetV(), &(*node2));
            concat(&(*node1)->left, &(*node2));
            concat(&(*node1)->right, &(*node2));
        }
    }
public:
    Three(){
        root = nullptr;
        length = 0;
    }

    size_t GetLength(){
        return length;
    }

    T Get(){
        return root->GetV();
    }

    void GetString(string &key, T** res){
        if(root){
            int i = 0;
            root->Line(key, root, &(*res), &i);
        }
    }

    void Add(T new_value){
        root->Add(new_value, &root);
        length++;
    }

    bool SearchElem(T elem){
        if(root->SearchElem(elem, root)){
            return true;
        }
        else{
            return false;
        }
    }

    void Map(function<T(T)> f1){
        map(root, f1);
    }

    void Where(function<bool(T)> f2, Three<T> &a){
        where(a, root, f2);
    }

    void Concat(Three<T> &a){
        concat(&root, &a.root);
    }

    void ExtractingSubThree(Three<T> &a, T value){
        if(root){
            root->ExtractingSubThree(&root, &a.root, value);
        }
    }

    void Print(int key)const{
        if(root){
            root->Print(key);
        }
    }

    bool operator==(Three<T> &a){
        if(root->Resemblance(&root, &a.root)){
            return true;
        }
        else{
            return false;
        }
    }

    ~Three(){
        if(root){
            root->FreeNodeThree(&root);
        }
    }
};

#endif //LR3_THREE_H
