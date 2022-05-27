#ifndef LR3_NODETHREE_H
#define LR3_NODETHREE_H

#include <iostream>
#include <functional>
#include <cstring>
#include "Complex.h"

using namespace std;

template<class T> class NodeThree{
protected:
    //T value;
    //NodeThree* left;
    //NodeThree* right;
public:
    T value;
    NodeThree* left;
    NodeThree* right;

    NodeThree(){
        left = right = nullptr;
    }

    T Get(){
        return value;
    }

    void RootLeftRight()const{
        cout << value << endl;
        if(left){
            left->RootLeftRight();
        }
        if(right){
            right->RootLeftRight();
        }
    }

    void RootRightLeft()const{
        cout << value << endl;
        if(right){
            right->RootRightLeft();
        }
        if(left){
            left->RootRightLeft();
        }
    }

    void LeftRightRoot()const{
        if(left){
            left->LeftRightRoot();
        }
        if(right){
            right->LeftRightRoot();
        }
        cout << value << endl;
    }

    void LeftRootRight()const{
        if(left){
            left->LeftRootRight();
        }
        cout << value << endl;
        if(right){
            right->LeftRootRight();
        }
    }

    void RightLeftRoot()const{
        if(right){
            right->RightLeftRoot();
        }
        if(left){
            left->RightLeftRoot();
        }
        cout << value << endl;
    }

    void RightRootLeft()const{
        if(right){
            right->RightRootLeft();
        }
        cout << value << endl;
        if(left){
            left->RightRootLeft();
        }
    }

    void Add(T new_value, NodeThree<T>** node){
        if(*node == nullptr){
            *node = new NodeThree;
            (*node)->value = new_value;
            (*node)->right = (*node)->left = nullptr;
        }
        if((*node)->value > new_value){
            if((*node)->left != nullptr){
                Add(new_value, &(*node)->left);
            }
            else{
                (*node)->left = new NodeThree;
                (*node)->left->left = (*node)->left->right = nullptr;
                (*node)->left->value = new_value;
            }
        }
        if((*node)->value < new_value){
            if((*node)->right != nullptr){
                Add(new_value, &(*node)->right);
            }
            else{
                (*node)->right = new NodeThree;
                (*node)->right->right = (*node)->right->left = nullptr;
                (*node)->right->value = new_value;
            }
            }
    }

    bool SearchElem(T elem, NodeThree<T>* &node){
        if(node){
            if(node->value < elem){
                return SearchElem(elem, node->right);
            }
            else
            {
                if(node->value > elem){
                    return SearchElem(elem, node->left);
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }

    NodeThree<T>* SubThree(NodeThree<T> **node, T subvalue){
        if ( (*node) ){
            if ( ((*node)->value) == subvalue){
                return (*node);
            }
            else {
                if (value < (*node)->value) {
                    return SubThree(&(*node)->left, subvalue);
                } else {
                    if (value > (*node)->value) {
                        return SubThree(&(*node)->right, subvalue);
                    }
                }
            }
        }
        return nullptr;
    }

    void ExtractingSubThree(NodeThree<T>** node1, NodeThree<T>** node2, T subvalue){
        if(SubThree(&(*node1), subvalue) != nullptr){
            (*node2) = SubThree(&(*node1), value);
        }
    }

    bool Resemblance(NodeThree<T>** node1, NodeThree<T>** node2){
        if((*node1) == (*node2)){
            return true;
        }
        return (((*node1)->value == (*node2)->value ) && Resemblance(&(*node1)->left,&(*node2)->left) && Resemblance(&(*node1)->right,&(*node2)->right));
    }

    void RootLeftRight(NodeThree<T>* node, T** res, int* i){
        if(node){
            (*res)[(*i)++] = node->value;
            if(node->left){
                node->left->RootLeftRigth(node->left, &(*res), &(*i));
            }
            if(node->right){
                node->right->RootLeftRight(node->right, &(*res), &(*i));
            }
        }
    }

    void RootRightLeft(NodeThree<T>* node, T** res, int* i){
        if(node){
            (*res)[(*i)++] = node->value;
            if(node->right){
                node->right->RootRightLeft(node->right, &(*res), &(*i));
            }
            if(node->left){
                node->left->RootRightLeft(node->left, &(*res), &(*i));
            }
        }
    }

    void LeftRightRoot(NodeThree<T>* node, T** res, int* i){
        if(node){
            if(node->left){
                node->left->LeftRightRoot(node->left, &(*res), &(*i));
            }
            if(node->right){
                node->right->LeftRightRoot(node->right, &(*res), &(*i));
            }
            (*res)[(*i)++] = node->value;
        }
    }

    void LeftRootRight(NodeThree<T>* node, T** res, int* i){
        if(node){
            if(node->left){
                node->left->LeftRootRight(node->left, &(*res), &(*i));
            }
            (*res)[*(i)++] = node->value;
            if(node->right){
                node->right->LeftRootRight(node->right, &(*res), &(*i));
            }
        }
    }

    void RightLeftRoot(NodeThree<T>* node, T** res, int* i){
        if(node){
            if(node->right){
                node->right->RightLeftRoot(node->right, &(*res), &(*i));
            }
            if(node->left){
                node->left->RightLeftRoot(node->left, &(*res), &(*i));
            }
            (*res)[*(i)++] = node->value;
        }
    }

    void RightRootLeft(NodeThree<T>* node, T** res, int* i){
        if(node){
            if(node->right){
                node->right->RightRootLeft(node->right, &(*res), &(*i));
            }
            (*res)[*(i)++] = node->value;
            if(node->left){
                node->left->RightRootLeft(node->left, &(*res), &(*i));
            }
        }
    }

    void Line(string &key, NodeThree* node, T** res, int* i){
        if(key  == "RootLeftRight"){
            RootLeftRight(node, &(*res), &(*i));
        }
        if(key == "RootRightLeft"){
            RootRightLeft(node, &(*res), &(*i));
        }
        if(key == "LeftRightRoot"){
            LeftRightRoot(node, &(*res), &(*i));
        }
        if(key == "LeftRootRight"){
            LeftRootRight(node, &(*res), &(*i));
        }
        if(key == "RightLeftRoot"){
            RightLeftRoot(node, &(*res), &(*i));
        }
        if(key == "RightRootLeft"){
            RightRootLeft(node, &(*res), &(*i));
        }
    }

    void Print(string &key)const{
        if(key  == "RootLeftRight"){
            RootLeftRight();
        }
        if(key == "RootRightLeft"){
            RootRightLeft();
        }
        if(key == "LeftRightRoot"){
            LeftRightRoot();
        }
        if(key == "LeftRootRight"){
            LeftRootRight();
        }
        if(key == "RightLeftRoot"){
            RightLeftRoot();
        }
        if(key == "RightRootLeft"){
            RightRootLeft();
        }
    }

    void FreeNodeThree(NodeThree<T>** node){
        if(*node){
            FreeNodeThree(&(*node)->left);
            FreeNodeThree(&(*node)->right);
            delete *node;
        }
    }
};

#endif //LR3_NODETHREE_H
