#include<bits/stdc++.h>
using namespace std;

struct LinkedNode;
struct VertexNode{
    char name;
    VertexNode* next;
    LinkedNode* h;
    
    VertexNode(char n){
        name = n;
        next = NULL;
        h = NULL;
    }
};

struct LinkedNode{
    VertexNode* ngbr;
    LinkedNode* next;

    LinkedNode(VertexNode* v){
        ngbr = v;
        next = NULL;
    }
};

VertexNode* getVertexId(char ch, VertexNode* G){
    VertexNode* temp = G;

    while(temp != NULL){
        if(temp->name == ch){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

VertexNode* createVerList(vector<char>& ver){
    VertexNode* G = new VertexNode(ver[0]);
    VertexNode* temp = G;

    for(int i = 1; i<ver.size(); i++){
        temp->next = new VertexNode(ver[i]);
        temp = temp->next;
    }

    return G;
}

void createNgbrList(VertexNode* G, vector<vector<char>>& ngbr){
    VertexNode* temp = G;

    for(vector<char>& ng : ngbr){
        LinkedNode* head = NULL;
        LinkedNode* tail = NULL;
        for(char ch : ng){
            VertexNode* ver = getVertexId(ch, G);
            LinkedNode* newNode = new LinkedNode(ver);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = tail->next;
            }
        }
        temp->h = head;
        temp = temp->next;
    }
}

bool isAdj(VertexNode* G, char n1, char n2){
    VertexNode* temp = getVertexId(n1, G);

    if(temp == NULL) return false;

    LinkedNode* l = temp->h;

    while(l != NULL){
        if(l->ngbr->name == n2){
            return true;
        }
        l = l->next;
    }
    return false;
}

void preOrder(VertexNode* G, unordered_set<VertexNode*>& visited, vector<vector<char>>& ngbr){
    if(G == NULL) return;

    cout << G->name << " ";  //do it at last to make this post Order(Topological Sort)
    visited.insert(G);

    vector<char> adj = ngbr[G->name - 'a'];

    for(char ch : adj){
        VertexNode* ver = getVertexId(ch, G);
        if(visited.find(ver) == visited.end()){
            preOrder(ver, visited, ngbr);
        }
    }
}

int main(){
    vector<char> ver = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

    VertexNode* G  = createVerList(ver);

    vector<vector<char>> ngbr = {{'b', 'c', 'd'}, {'a', 'c', 'e', 'f'}, {'a', 'b', 'g', 'h'}, {'a', 'i'}, {'b', 'f'}, {'b', 'e'}, {'c'}, {'c'}, {'d'}};

    createNgbrList(G, ngbr);

    cout << isAdj(G, 'b', 'h') << endl;

    unordered_set<VertexNode*> visited;
    preOrder(G, visited, ngbr);  //right now works for only one connected component

}