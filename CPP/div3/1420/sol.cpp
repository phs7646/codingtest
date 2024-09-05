#include<iostream>
#include<vector>
#include<queue> 
#define INF 1e9
#define MAXV 101*101*2
using namespace std;
typedef pair<int,int> pp;
pp moves[] = {{1,0},{0,1},{-1,0},{0,-1}};

//정점 분할 필요..!
//정점은 2NM개
int N,M;
int MAXNODE;
bool isValid(int i,int j) {return i >= 0 && i < N && j >= 0 && j < M;}
//in : ((i*M)+j)*2
int pair_in(int i,int j) {return ((i*M)+j)*2;}
//out : ((i*M)+j)*2+1
int pair_out(int i,int j) {return pair_in(i,j)+1;};
typedef class Edge {
public:
    int from;
    int to;
    int capacity;
    int flow;
    Edge* opponent;
    Edge(int a,int b,int c,int d) : from(a),to(b),capacity(c),flow(d) {}
} Edge;

bool wall[100][100];
int ky,kx;
int hy,hx;

vector<Edge*> adj[MAXV];

void buildEdge(int i,int j,int ni,int nj) {
    int a_in = pair_in(i,j);
    int a_out = a_in+1;
    int b_in = pair_in(ni,nj);
    int b_out = b_in+1;
    //add edge a out -> b in
    Edge* e1 = new Edge(a_out,b_in,INF,0);
    Edge* e2 = new Edge(b_in,a_out,0,0);
    e1->opponent = e2;
    e2->opponent = e1;
    adj[a_out].push_back(e1);
    adj[b_in].push_back(e2);
    //add edge b out -> a in
    Edge* e3 = new Edge(b_out,a_in,INF,0);
    Edge* e4 = new Edge(a_in,b_out,0,0);
    e3->opponent = e4;
    e4->opponent = e3;
    adj[b_out].push_back(e3);
    adj[a_in].push_back(e4);
}

int main() {
    cin >> N >> M;
    MAXNODE = N*M*2;
    //input wall
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            char c; cin >> c;
            if(c == '#') wall[i][j] = true;
            else if(c == 'K') {
                ky = i; kx = j;
            } else if(c == 'H') {
                hy = i; hx = j;
            }
        }
    }
    //붙어 있는 경우 예외처리
    if(abs(ky-hy) + abs(kx-hx) == 1) {
        cout << -1;
        return 0;
    }

    //build edge list
    
    //in-vertice in&out
    for(int i = 0;i < MAXNODE;i+=2) {
        //i -> i+1
        Edge* go = new Edge(i,i+1,1,0);
        Edge* back = new Edge(i+1,i,0,0);
        go->opponent = back;
        back->opponent = go;
        adj[i].push_back(go);
        adj[i+1].push_back(back);
    }

    //inter-vertice out->in
    vector<vector<bool>> visited(N,vector<bool>(M));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            visited[i][j] = true;
            if(wall[i][j]) continue;
            for(pp move : moves) {
                int ni = i + move.first;
                int nj = j + move.second;
                if(!isValid(ni,nj) || visited[ni][nj] || wall[ni][nj]) continue;
                //add edge between (i,j) , (ni,nj)
                buildEdge(i,j,ni,nj);
            }
        }
    }

    //mfmc
    int source = pair_out(ky,kx);
    int sink = pair_in(hy,hx);
    int total = 0;
    while(true) {
        //find route
        vector<int> before(MAXNODE,-1);
        before[source] = source;
        queue<int> q; q.emplace(source);
        vector<Edge*> memo(MAXNODE);
        while(!q.empty()) {
            if(before[sink] != -1) break;
            int cur = q.front(); q.pop();
            for(Edge* next : adj[cur]) {
                if(before[next->to] == -1 && next->capacity - next->flow > 0) {
                    before[next->to] = cur;
                    q.emplace(next->to);
                    memo[next->to] = next;
                }
            }
        } //bfs end
        
        if(before[sink] == -1) break; //no route found

        //calculate maximum amount of route
        int amount = INF;
        int cur = sink;
        while(cur != source) {
            Edge* e = memo[cur];
            amount = min(amount,e->capacity - e->flow);
            cur = before[cur];
        }

        //record flow
        cur = sink;
        while(cur != source) {
            Edge *e = memo[cur];
            e->flow += amount;
            e->opponent->flow -= amount;
            cur = before[cur];
        }
        total += amount;
    }

    cout << total;
    return 0;
}