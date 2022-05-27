#ifndef LR3_NODETHREE_H
#define LR3_NODETHREE_H

#include <iostream>
#include <functional>
#include <cstring>
#include "Complex.h"
#include <cstdio>
//#include "Three.h"

using namespace std;

template<class T> class NodeThree{
    //friend class Three;
private:
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

    T GetV(){
        return value;
    }

    void RootLeftRight(int n)const{
        for(int i = 0; i < n; i++)
            cout << "  ";
        cout <<  value;
        if(left){
            left->RootLeftRight(n+1);
        }
        if(right){
            right->RootLeftRight(n+1);
        }
    }

    void RootRightLeft(int n)const{
        for(int i = 0; i < n; i++)
            cout << "  ";
        cout << value << endl;
        if(right){
            right->RootRightLeft(n+1);
        }
        if(left){
            left->RootRightLeft(n+1);
        }
    }

    void LeftRightRoot(int n)const{
        if(left){
            left->LeftRightRoot(n+1);
        }
        if(right){
            right->LeftRightRoot(n+1);
        }
        for(int i = 0; i < n; i++)
            cout << "  ";
        cout << value << endl;
    }

    void LeftRootRight(int n)const{
        if(left){
            left->LeftRootRight(n+1);
        }
        for(int i = 0; i < n; i++)
            cout << "  ";
        cout << value << endl;
        if(right){
            right->LeftRootRight(n+1);
        }
    }

    void RightLeftRoot(int n)const{
        if(right){
            right->RightLeftRoot(n+1);
        }
        if(left){
            left->RightLeftRoot(n+1);
        }
        for(int i = 0; i < n; i++)
            cout << "  ";
        cout << value << endl;
    }

    void RightRootLeft(int n)const{
        if(right){
            right->RightRootLeft(n+1);
        }
        for(int i = 0; i < n; i++)
            cout << "  ";
        cout << value << endl;
        if(left){
            left->RightRootLeft(n+1);
        }
    }

    void Add(T new_value, NodeThree<T>** node){
        if(*node == nullptr){
            *node = new NodeThree;
            (*node)->value = new_value;
            (*node)->right = (*node)->left = nullptr;
        }
        if(new_value < (*node)->value){
            if((*node)->left != nullptr){
                Add(new_value, &(*node)->left);
            }
            else{
                (*node)->left = new NodeThree;
                (*node)->left->left = (*node)->left->right = nullptr;
                (*node)->left->value = new_value;
            }
        }
        if(new_value > (*node)->value){
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

    NodeThree<T>* SubThree(NodeThree<T>** node, T subvalue){
        if ( (*node) ){
            if ( ((*node)->value) == subvalue){
                return (*node);
            }
            else {
                if (subvalue < (*node)->value) {
                    return SubThree(&(*node)->left, subvalue);
                }
                else {
                    if (subvalue > (*node)->value) {
                        return SubThree(&(*node)->right, subvalue);
                    }
                }
            }
        }
        else {
            return nullptr;
        }
    }

    void ExtractingSubThree(NodeThree<T>** node1, NodeThree<T>** node2, T subvalue){
        if(SubThree(&(*node1), subvalue) != nullptr){
            (*node2) = SubThree(&(*node1), subvalue);
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

    void Line(int key, NodeThree* node, T** res, const int* i){
        if(key  == 1){
            RootLeftRight(node, &(*res), &(*i));
        }
        if(key == 2){
            RootRightLeft(node, &(*res), &(*i));
        }
        if(key == 3){
            LeftRightRoot(node, &(*res), &(*i));
        }
        if(key == 4){
            LeftRootRight(node, &(*res), &(*i));
        }
        if(key == 5){
            RightLeftRoot(node, &(*res), &(*i));
        }
        if(key == 6){
            RightRootLeft(node, &(*res), &(*i));
        }
    }

    void Print(int key)const{
        int n = 0;
        if(key  == 1){
            RootLeftRight(n);
        }
        if(key == 2){
            RootRightLeft(n);
        }
        if(key == 3){
            LeftRightRoot(n);
        }
        if(key == 4){
            LeftRootRight(n);
        }
        if(key == 5){
            RightLeftRoot(n);
        }
        if(key == 6){
            RightRootLeft(n);
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

