// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 3e5 + 5 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {1 , 1 , 1 , -1 , -1 , -1 , 0 , 0} ,
    dy[] = {-1 , 0 , 1 , -1 , 0 , 1 , -1 , 1};


//Binary Search Tree (BST)
class Node {
public:
    int Data;
    Node *Left , *Right;

    Node () {
        Data = 0;
        Left = NULL;
        Right = NULL;
    }
};

class BST {
public:
    Node *Root;

    BST () {
        Root = NULL;
    }


    Node *Insert (Node *Current_node , int Item) {
        if (Current_node == NULL) {
            Node *New_Node = new Node();

            New_Node -> Data = Item;
            New_Node -> Left = NULL;
            New_Node -> Right = NULL;


            Current_node = New_Node;
        }

        else if (Item < (Current_node -> Data)){
            Current_node -> Left = Insert ((Current_node -> Left) , Item);
        }

        else {
            Current_node -> Right = Insert ((Current_node -> Right) , Item);
        }

        return Current_node;
    }


    void Insert (int Item) {
        Root = Insert(Root , Item);
    }


    Node *Search (Node *Current_node , int Item) {
        if (Current_node == NULL) {
            return NULL;
        }

        else if ((Current_node -> Data) == Item) {
            return Current_node;
        }

        else if (Item < (Current_node -> Data)) {
            return Search((Current_node -> Left) , Item);
        }

        else {
            return Search((Current_node -> Right) , Item);
        }
    }


    bool Search (int Item) {
        Node *Result = Search (Root , Item);

        if (Result == NULL) {
            return false;
        }

        else {
            return true;
        }
    }


    Node *Find_Minimum (Node *Current_node) {
        if (Current_node == NULL) {
            return NULL;
        }

        else if ((Current_node -> Left) == NULL) {
            return Current_node;
        }

        else {
            return Find_Minimum(Current_node -> Left);
        }
    }


    Node *Find_Maximum (Node *Current_node) {
        if (Current_node == NULL) {
            return NULL;
        }

        else if ((Current_node -> Right) == NULL) {
            return Current_node;
        }

        else {
            return Find_Maximum(Current_node -> Right);
        }
    }


    Node *Delete (Node *Current_node , int Item) {
        if (Current_node == NULL) {
            return NULL;
        }

        if (Item < (Current_node -> Data)) {
            Current_node -> Left = Delete ((Current_node -> Left) , Item);
        }

        else if (Item > (Current_node -> Data)) {
            Current_node -> Right = Delete ((Current_node -> Right) , Item);
        }

        else {
            if ((Current_node -> Left == NULL) && (Current_node -> Right == NULL)) {
                Current_node = NULL;
            }

            else if ((Current_node -> Left == NULL) && (Current_node -> Right != NULL)) {
                Current_node -> Data = Current_node -> Right -> Data;

                delete Current_node -> Right;

                Current_node -> Right = NULL;
            }

            else if ((Current_node -> Left != NULL) && (Current_node -> Right == NULL)) {
                Current_node -> Data = Current_node -> Left -> Data;

                delete Current_node -> Left;

                Current_node -> Left = NULL;
            }

            else {
                Node *Max = Find_Maximum(Current_node -> Left);

                Current_node -> Data = Max -> Data;

                Current_node -> Left = Delete(Current_node -> Left , Max -> Data);
            }
        }

        return Current_node;
    }


    int Find_Minimum () {
        Node *Min = Find_Minimum(Root);

        if (Min == NULL) {
            return NULL;
        }

        else {
            return (Min -> Data);
        }
    }

    int Find_Maximum () {
        Node *Max = Find_Maximum(Root);

        if (Max == NULL) {
            return NULL;
        }

        else {
            return (Max -> Data);
        }
    }

    //Root -> Left -> Right
    void Pre_Order (Node *Current_node) {
        if (Current_node == NULL) {
            return;
        }

        cout << Current_node -> Data << "    ";
        Pre_Order(Current_node -> Left);
        Pre_Order(Current_node -> Right);
    }


    //Left -> Root -> Right
    void In_Order (Node *Current_node) {
        if (Current_node == NULL) {
            return;
        }

        In_Order(Current_node -> Left);
        cout << Current_node -> Data << "    ";
        In_Order(Current_node -> Right);
    }


    //Right -> Root -> Left
    void Post_Order (Node *Current_node) {
        if (Current_node == NULL) {
            return;
        }

        Post_Order(Current_node -> Left);
        Post_Order(Current_node -> Right);
        cout << Current_node -> Data << "    ";
    }


    void Special_Insert (int Item , string s , bool &flag) {
        Node *cur = new Node();
        Node *tmp = Root;

        cur -> Data = Item;

        bool add = true;

        for (int i = 0 ; i < s.length() - 1 ; i++) {
            if (s[i] == 'L') {
                if ((tmp -> Left) != NULL) {
                    tmp = tmp -> Left;
                }
                else {
                    flag = false; return;
                }
            }

            else {
                if ((tmp -> Right) != NULL) {
                    tmp = tmp -> Right;
                }
                else {
                    flag = false; return;
                }
            }
        }

        int sz = s.length() - 1;
        if (s[sz] == 'L') {
            if (tmp -> Left != NULL) {
                flag = false; return;
            }
            else {
                tmp -> Left = cur;
            }
        }

        else {
            if (tmp -> Right != NULL) {
                flag = false; return;
            }
            else {
                tmp -> Right = cur;
            }
        }
    }

};
vector <int> fnl;

void bfs (Node *cur) {
    if (cur == NULL) return;

    queue <Node*> q; q.push(cur);


    while (!q.empty()) {
        Node *tmp = q.front(); q.pop();

        fnl.push_back(tmp -> Data);

        if ((tmp -> Left) != NULL) q.push(tmp -> Left);
        if ((tmp -> Right) != NULL) q.push(tmp -> Right);
    }
}

void solve () {
    string s;

    while (cin >> s) {
        if (s == "00") break;
        if (s == "()") {
            cout << "not complete" << '\n'; continue;
        }

        vector <string> arr; arr.push_back(s);
        while (cin >> s) {
            if (s == "()") break;

            arr.push_back(s);
        }

        vector <pair <int , string>> tmp;

        bool can = false;
        for (auto i : arr) {
            string a = "" , b = "";
            bool flag = true;

            for (auto j : i) {
                if (j == ',') {
                    flag = false; continue;
                }
                if (j == '(' || j == ')') continue;

                if (flag) a += j;
                if (!flag) b += j;
            }

            int num = stoi(a);
            if (b == "") can = true;

            tmp.push_back({num , b});
        }

        if (!can) {
            cout << "not complete" << '\n'; continue;
        }

        auto com = [=](pair <int , string> a , pair <int , string> b) -> bool {
            return a.second.size() < b.second.size();
        };

        sort(all(tmp) , com);

        BST bt; bool frst = true;
        for (auto [a , b] : tmp) {
            if (frst) {
                bt.Insert(a); frst = false;
                continue;
            }

            bt.Special_Insert(a , b , can);
        }

        if (!can) {
            cout << "not complete" << '\n';
            for (auto [a , b] : tmp) {
                Node *del = bt.Delete(bt.Root , a);
            }

            continue;
        }

        bfs(bt.Root);
        for (int i = 0 ; i < fnl.size() ; i++) {
            cout << fnl[i];
            if (i != fnl.size() - 1) cout << " ";
        }

        cout << '\n';
        for (auto [a , b] : tmp) {
            Node *del = bt.Delete(bt.Root , a);
        }

        fnl.clear();
        continue;
    }

}

int main() {
    ABo_ZeiD; // i'm backkkkkk;

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);
//    pre();

    int t = 1;
//    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
//        if (i != t) {
//            cout << '\n';
//        }
    }


    return 0;
}
