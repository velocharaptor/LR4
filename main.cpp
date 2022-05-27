#include <iostream>
#include <cstring>
#include "NodeThree.h"
#include "Three.h"
#include "Tests.h"
#include "Complex.h"

//#define RootLeftRight a
//#define RootRightLeft b
//#define LeftRightRoot c
//#define LeftRootRight d
//#define RightLeftRoot e
//#define RightRootLeft f

using namespace std;

int main() {
    int number = 0, flag = 0, flag1 = 0, flag2 = 0;
    int n, key = 0;
    int x;
    cmp y;
    Three<int> root;
    Three<int> root2;
    Three<int> concat_root3;
    Three<cmp> cmp_root;
    Three<cmp> cmp_root2;
    Three<cmp> cmp_concat_root3;
    while (flag != 1) {
        cout << "Binary Tree - Possible actions:\n"
                "-1.Int.\n"
                "-2.Complex.\n"
                "-3.Tests.\n"
                "-4.Exit.\n"
                "=>";
        cin >> number;
        switch (number) {
            case 1:
                flag1 = 0;
                cout << "Enter length three:";
                cin >> n;
                cout << "Enter elem:\n";
                for(int i = 0; i < n; i++){
                    cout << "[" << i << "]:";
                    cin >> x;
                    root.Add(x);
                }
                while(flag1 != 1) {
                    cout << "\nPossible actions:\n"
                            "-1.Get length.\n"
                            "-2.Get value root.\n"
                            "-3.Add node three.\n"
                            "-4.Search elem.\n"
                            "-5.Map.\n"
                            "-6.Where.\n"
                            "-7.Concat.\n"
                            "-8.Print.\n"
                            "-9.Exit.\n"
                            "=>";
                    cin >> number;
                    switch (number) {
                        case 1:
                            cout << "Length: " << root.GetLength() << endl;
                            break;
                        case 2:
                            cout << "Root: " << root.Get() << endl;
                            break;
                        case 3:
                            cout << "Enter elem: ";
                            cin >> x;
                            root.Add(x);
                            break;
                        case 4:
                            cout << "Enter elem: ";
                            cin >> x;
                            if(root.SearchElem(x)){
                                cout << "Elem " << x << " is finding.\n";
                            }
                            else{
                                cout << "Elem " << x << " isn't finding\n";
                            }
                            break;
                        case 5:
                            root.Map(F1Int1);
                            break;
                        case 6:
                            root.Where(F2Otr, root2);
                            root2.Print(4);
                            break;
                        case 7:
                            cout << "Enter length second three:";
                            cin >> n;
                            cout << "Enter elem:\n";
                            for(int i = 0; i < n; i++){
                                cout << "[" << i << "]:";
                                cin >> x;
                                concat_root3.Add(x);
                            }
                            root.Concat(concat_root3);
                            cout << "Concat tree:\n";
                            concat_root3.Print(4);
                            break;
                        case 8:
                            cout << "Choose a bypass option:\n"
                                    "-1.RootLeftRight\n"
                                    "-2.RootRightLeft\n"
                                    "-3.LeftRightRoot\n"
                                    "-4.LeftRootRight\n"
                                    "-5.RightLeftRoot\n"
                                    "-6.RightRootLeft\n"
                                    "=>";
                            cin >> key;
                            root.Print(key);
                            break;
                        case 9:
                            cout << "Exit.\n";
                            flag1 = 1;
                            break;
                        default:
                            cout << "Input Error\n";
                            break;
                    }
                }
                break;
            case 2:
                flag2 = 0;
                cout << "Enter length three:";
                cin >> n;
                cout << "Enter elem:\n";
                for(int i = 0; i < n; i++){
                    cout << "[" << i << "]:";
                    cin >> y;
                    cmp_root.Add(y);
                }
                while (flag2 != 1) {
                    cout << "Possible actions:\n"
                            "-1.Get length.\n"
                            "-2.Get value root.\n"
                            "-3.Add node three.\n"
                            "-4.Search elem.\n"
                            "-5.Map.\n"
                            "-6.Where.\n"
                            "-7.Concat.\n"
                            "-8.Print.\n"
                            "-9.Exit.\n"
                            "=>";
                    cin >> number;
                    switch (number) {
                        case 1:
                            cout << "Length: " << cmp_root.GetLength() << endl;
                            break;
                            break;
                        case 2:
                            cout << "Root: " << cmp_root.Get() << endl;
                            break;
                        case 3:
                            cout << "Enter elem: ";
                            cin >> y;
                            cmp_root.Add(y);
                            break;
                        case 4:
                            cout << "Enter elem: ";
                            cin >> y;
                            if(cmp_root.SearchElem(y)){
                                cout << "Elem " << y << " is finding.\n";
                            }
                            else{
                                cout << "Elem " << y << " isn't finding\n";
                            }
                            break;
                        case 5:
                            cmp_root.Map(F1Int2);
                            break;
                        case 6:
                            cmp_root.Where(F2Sr, cmp_root2);
                            cmp_root2.Print(4);
                            break;
                        case 7:
                            cout << "Enter length second three:";
                            cin >> n;
                            cout << "Enter elem:\n";
                            for(int i = 0; i < n; i++){
                                cout << "[" << i << "]:";
                                cin >> y;
                                cmp_concat_root3.Add(y);
                            }
                            cmp_root.Concat(cmp_concat_root3);
                            cout << "Concat tree:\n";
                            cmp_concat_root3.Print(4);
                            break;
                        case 8:
                            cout << "Choose a bypass option:\n"
                                    "-1.RootLeftRight\n"
                                    "-2.RootRightLeft\n"
                                    "-3.LeftRightRoot\n"
                                    "-4.LeftRootRight\n"
                                    "-5.RightLeftRoot\n"
                                    "-6.RightRootLeft\n"
                                    "=>";
                            cin >> key;
                            cmp_root.Print(key);
                            break;
                        case 9:
                            cout << "Exit.\n";
                            flag2 = 1;
                            break;
                        default:
                            cout << "Input Error\n";
                            break;
                    }
                }
                break;
            case 3:
                Tests();
                break;
            case 4:
                cout << "Exit.\n";
                flag = 1;
                break;
            default:
                cout << "Input Error.\n";
        }
    }
    return 0;
}
