#include "Tests.h"
#include <iostream>
#include <cstring>
#include <functional>
#include "NodeThree.h"
#include "Three.h"
#include "Complex.h"

using namespace std;

void AddTesting(Three<int> &root, Three<cmp> &cmp_root, cmp v1, cmp v2, cmp v3){
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

void SearchElemTesting(Three<int> &root, Three<cmp> &cmp_root, cmp v1, cmp v2, cmp v3){
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

void GetLengthTesting(Three<int> &root, Three<cmp> &cmp_root){
    if(root.GetLength() == 3){
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

void GetTesting(Three<int> &root, Three<cmp> &cmp_root, cmp v1){
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

void ExtractingSubThreeTesting(Three<int> &sub_root1, Three<int> &sub_root, Three<cmp> &cmp_sub_root, Three<cmp> &cmp_sub_root1, cmp v1, cmp v2, cmp v3, cmp v21){
    sub_root1.ExtractingSubThree(sub_root, 7);
    if(sub_root.SearchElem(7) && (sub_root.SearchElem(6)) && (sub_root.SearchElem(8)) && !sub_root.SearchElem(2)){
        cout << "ExtractingSubThreeTesting<int> - OK\n";
    }
    else{
        cout << "ExtractingSubThreeTesting<int> - NO\n";
    }
    cmp_sub_root.ExtractingSubThree(cmp_sub_root1, v1);
    if(cmp_sub_root1.SearchElem(v1) && (cmp_sub_root1.SearchElem(v2)) && (cmp_sub_root1.SearchElem(v3)) && !cmp_sub_root1.SearchElem(v21)){
        cout << "ExtractingSubThreeTesting<cmp> - OK\n";
    }
    else{
        cout << "ExtractingSubThreeTesting<cmp> - NO\n";
    }
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
    Three<int> root3;
    Three<int> sub_root1;
    Three<int> concat_root2;
    Three<cmp> cmp_root;
    Three<cmp> cmp_root2;
    Three<cmp> cmp_concat_root2;
    Three<cmp> cmp_root3;
    Three<cmp> cmp_sub_root;
    Three<cmp> cmp_sub_root1;
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
    //===================== <int3>
    root3.Add(7);
    root3.Add(6);
    root3.Add(8);
    root3.Add(4);
    root3.Add(5);
    root3.Add(2);
    //===================== <int concat>
    concat_root2.Add(7);
    concat_root2.Add(6);
    concat_root2.Add(8);
    //===================== <complex>
    cmp_root.Add(v1);
    cmp_root.Add(v2);
    cmp_root.Add(v3);
    //===================== <complex2>
    cmp_root2.Add(v21);
    cmp_root2.Add(v22);
    cmp_root2.Add(v23);
    //===================== <complex3>
    cmp_root3.Add(v21);
    cmp_root3.Add(v22);
    cmp_root3.Add(v23);
    cmp_root3.Add(v1);
    cmp_root3.Add(v2);
    cmp_root3.Add(v3);
    //===================== <complex concat>
    cmp_concat_root2.Add(v21);
    cmp_concat_root2.Add(v22);
    cmp_concat_root2.Add(v23);
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
    //===================== <sub three int>
    sub_root1.Add(4);
    sub_root1.Add(2);
    sub_root1.Add(5);
    sub_root1.Add(7);
    sub_root1.Add(6);
    sub_root1.Add(8);
    //===================== <sub three cmp>
    cmp_sub_root.Add(v21);
    cmp_sub_root.Add(v22);
    cmp_sub_root.Add(v23);
    cmp_sub_root.Add(v1);
    cmp_sub_root.Add(v2);
    cmp_sub_root.Add(v3);
    //===================== <map>
    res_root.Add(16);
    res_root.Add(25);
    res_root.Add(4);
    //===================== Anything func tests
    AddTesting(root, cmp_root, v1, v2, v3);
    SearchElemTesting(root, cmp_root, v1, v2, v3);
    GetLengthTesting(root, cmp_root);
    GetTesting(root, cmp_root, v1);
    // ===================== Concat tests
    root.Concat(concat_root2);
    if(concat_root2 == root3){
        cout << "ConcatTesting<int> - OK\n";
    }
    else{
        cout << "ConcatTesting<int> - NO\n";
    }
    cmp_root.Concat(cmp_concat_root2);
    if(cmp_concat_root2 == cmp_root3){
        cout << "ConcatTesting<cmp> - OK\n";
    }
    else{
        cout << "ConcatTesting<cmp> - NO\n";
    }
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
    //===================== Sub Three
    ExtractingSubThreeTesting(sub_root1, sub_root, cmp_sub_root, cmp_sub_root1, v1, v2, v3, v21);
}

void Tests(){
    cout << "Start testing Three:\n\n";
    ThreeTesting();
    cout << "\n";
}
