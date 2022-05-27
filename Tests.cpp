#include "Tests.h"
#include <iostream>
#include <cstring>
#include <functional>
#include "NodeThree.h"
#include "Three.h"
#include "Complex.h"

using namespace std;

void AddTesting(Three<int> &root, Three<cmp> cmp_root, cmp v1, cmp v2, cmp v3){
  if(root.SearchElem(4) && (root.SearchElem(2)) && (root.SearchElem(5))){
      cout << "AddTesting<int> - OK\n";
  }
  else{
      cout << "AddTesting<int> - NO\n";
  }
    if(cmp_root.SearchElem(v1) && (cmp_root.SearchElem(v3)) && (cmp_root.SearchElem(v2))){
        cout << "AddTesting<cmp> - OK\n";
    }
    else{
        cout << "AddTesting<cmp> - NO\n";
    }
}

void SearchElemTesting(Three<int> &root, Three<cmp> cmp_root, cmp v1, cmp v2, cmp v3){
    if(root.SearchElem(4) && (root.SearchElem(5)) && (root.SearchElem(2))){
        cout << "SearchElemTesting<int> - OK\n";
    }
    else{
        cout << "SearchElemTesting<int> - NO\n";
    }
    if(cmp_root.SearchElem(v1) && (cmp_root.SearchElem(v2)) && (cmp_root.SearchElem(v3))){
        cout << "SearchElemTesting<cmp> - OK\n";
    }
    else{
        cout << "SearchElemTesting<cmp> - NO\n";
    }
}

void GetLengthTesting(Three<int> &root, Three<cmp> cmp_root){
    if(root.GetLength() == 5){
        cout << "GetLengthTesting<int> - OK\n";
    }
    else{
        cout << "GetLengthTesting<int> - NO\n";
    }
    if(cmp_root.GetLength() == 3){
        cout << "GetLengthTesting<cmp> - OK\n";
    }
    else{
        cout << "GetLengthTesting<cmp> - NO\n";
    }
}

void GetTesting(Three<int> &root, Three<cmp> cmp_root, cmp v1){
    if(root.Get() == 4){
        cout << "GetTesting<int> - OK\n";
    }
    else{
        cout << "GetTesting<int> - NO\n";
    }
    if(cmp_root.Get() == v1){
        cout << "GetTesting<cmp> - OK\n";
    }
    else{
        cout << "GetTesting<cmp> - NO\n";
    }
}

void ExtractingSubThreeTesting(Three<int> &root, Three<int> &sub_root){
    root.ExtractingSubThree(sub_root, 2);
}

//void map()
//void where()
//void concat()

int F1Int1(int x){
    return x*x;
}
cmp F1Int2(cmp x){
    cmp y = x*x;
    x = y;
    return x;
}

bool F2Otr(int x){
    if(x < 0){
        return true;
    }
    else{
        return false;
    }
}
bool F2Sr(cmp x){
    cmp y(4,2);
    if(x > y){
        return true;
    }
    else{
        return false;
    }
}

void ThreeTesting(){
    Three<int> root;
    Three<int> root2;
    Three<cmp> cmp_root;
    Three<cmp> cmp_root2;
    cmp v1(5, 3), v2(7, 1), v3(3, 2);
    cmp v21(16, 30), v22(48, 14), v23(5, 12);
    Three<int> map_root;
    Three<int> res_root;
    Three<int> sub_root;
    Three<int> where_root1;
    Three<int> where_root2;
    Three<int> where_root3;
    Three<cmp> where1;
    Three<cmp> where2;
    Three<cmp> where3;
    //===================== <int>
    root.Add(4);
    root.Add(5);
    root.Add(2);
    //===================== <int2>
    root2.Add(7);
    root2.Add(6);
    root2.Add(8);
    //===================== <complex>
    cmp_root.Add(v1);
    cmp_root.Add(v2);
    cmp_root.Add(v3);
    //===================== <complex2>
    cmp_root2.Add(v21);
    cmp_root2.Add(v22);
    cmp_root2.Add(v23);
    //===================== <where1>
    where_root1.Add(-2);
    where_root1.Add(-1);
    where_root1.Add(-3);
    //===================== <where2>
    where_root2.Add(3);
    where_root2.Add(5);
    where_root2.Add(-2);
    where_root2.Add(-1);
    where_root2.Add(-3);
    //===================== <cmp where1>
    where1.Add(v1); //5 3
    where1.Add(v2); //7 1
    where1.Add(v3); //3 2
    where1.Add(v22); //48 14
    where1.Add(v23); //5 12
    //===================== <cmp where2>
    where2.Add(v1);
    where2.Add(v2);
    where2.Add(v22);
    where2.Add(v23);
    //===================== <sub three>
    //root.Add(3);
    //root.Add(1);
    //===================== <map>
    res_root.Add(16);
    res_root.Add(25);
    res_root.Add(4);
    //===================== Anything func tests
    AddTesting(root, cmp_root, v1, v2, v3);
    SearchElemTesting(root, cmp_root, v1, v2, v3);
    GetLengthTesting(root, cmp_root);
    GetTesting(root, cmp_root, v1);
    //===================== Maps tests
    root.Map(F1Int1);
    if(root == res_root){
        cout << "MapTesting<int> - OK\n";
    }
    else{
        cout << "MapTesting<int> - NO\n";
    }
    cmp_root.Map(F1Int2);
    if(cmp_root == cmp_root2){
        cout << "MapTesting<cmp> - OK\n";
    }
    else{
        cout << "MapTesting<cmp> - NO\n";
    }
    //===================== Where tests
    where_root2.Where(F2Otr, where_root3);
    if(where_root3 == where_root1){
        cout << "WhereTesting<int> - OK\n";
    }
    else{
        cout << "WhereTesting<int> - NO\n";
    }
    where1.Where(F2Sr, where3);
    if(where3 == where2){
        cout << "WhereTesting<cmp> - OK\n";
    }
    else{
        cout << "WhereTesting<cmp> - NO\n";
    }
    //===================== Concat tests
    //root.Concat(root2);
    //string key = "RootLeftRight";
    //root2.Print(key);
    //ExtractingSubThreeTesting(root, sub_root);
}

void Tests(){
    cout << "Start testing Three:\n\n";
    ThreeTesting();
}