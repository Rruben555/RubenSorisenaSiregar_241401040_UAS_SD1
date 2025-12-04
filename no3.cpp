// #include <bits/stdc++.h>
// using namespace std;

// typedef pair<int, int> iPair;

// string kota(int o){
//     switch (o){
//         case 0: 
//             return "Medan";
//             break;
//         case 1: 
//             return "Tebing Tinggi";
//             break;
//         case 2: 
//             return "Brastagi";
//             break;
//         case 3: 
//             return "Pematangsiantar";
//             break;
//         case 4: 
//             return "Sidikalang";
//             break;
//         case 5: 
//             return "Parapat";
//             break;
//         default:
//             return "Tidak ditemukan";
//     }
// }

// void dijkstra(int V, vector<vector<iPair>> &adj, int src) {
//     //menyimpan jarak terpendek
//     vector <int> dist(V, INT_MAX);
//     priority_queue<iPair, vector<iPair>, greater<iPair>>pq;

//     dist[src]=0;
//     pq.push({0,src});//(jarak,simpul)

//     //loop djikstra
//     while(!pq.empty()){
//         int u=pq.top().second;
//         int d=pq.top().first;
//         pq.pop();

//         //jika jarak yang diambil bukan terkecil
//         if(d>dist[u]) continue;

//         //periksa semua tetangga dari simpul u
//         for(auto edge : adj[u]){
//             int v= edge.first;//vertex tetangga
//             int w= edge.second; //bobot dari u ke v

//             //jika jarak mmelalui u lebih kecil, update jarak ke v
//             if (dist[u]+w<dist[v]){
//                 dist[v]=dist[u]+w;
//                 pq.push({dist[v],v});
//             }
//         }
//     }

//     // Tampilkan hasil akhir
//     cout << "Vertex\tDistance from X\n";
//     for (int i = 0; i < V; i++) {
//         string city=kota(i);
//         cout << city << "\t" << dist[i] << endl;
//     }
// }

// int main() {
//     int V = 6; // X, E, G, H, F, Y
//     vector<vector<iPair>> adj(V);

//     // Menambahkan edge sesuai graf 
//     adj[0].push_back({1, 70}); // X–E 
//     adj[0].push_back({2, 60}); // X–F
//     adj[1].push_back({3, 50}); // E–G
//     adj[2].push_back({4, 90}); // G–Y
//     adj[2].push_back({3, 80}); // H–Y
//     adj[3].push_back({5, 45}); // F–Y
//     adj[3].push_back({4, 65}); // F–Y
//     adj[4].push_back({5, 120}); 


//     adj[1].push_back({0, 70}); // X–E 
//     adj[1].push_back({0, 60}); // X–F
//     adj[3].push_back({1, 50}); // E–G
//     adj[4].push_back({2, 90}); // G–Y
//     adj[3].push_back({2, 80}); // H–Y
//     adj[5].push_back({3, 45}); // F–Y
//     adj[4].push_back({3, 65}); // F–Y
//     adj[5].push_back({4, 120}); 

//     // Karena graf tidak berarah, tambahkan sisi baliknya juga


//     dijkstra(V, adj, 0); // 0 = X
//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 6

//Kucing BFS & DFS

class Graph {
private:
    vector<vector<int>> graph = {
        {0,1,1,0,0,0},
        {1,0,0,1,0,0},
        {1,0,0,1,0},
        {0,1,1,0,1},
        {0,0,0,1,0}
    };

    vector<vector<int>> weight = {
        {0,5,2,0,0},
        {5,0,0,4,0},
        {2,0,0,1,0},
        {0,4,1,0,3},
        {0,0,0,3,0}
    };
    
    string daftar[MAX]={
        "Medan",
        "Tebing Tinggi",
        "Brastagi",
        "Pematang Siantar",
        "Sidikalang"
        "Parapat"
    };
    int journey=0;

public:
    int charint(char n){//covert data char ke int
        switch(n){
            case 'A': return 0;
            case 'B': return 1;
            case 'C': return 2;
            case 'D': return 3;
            case 'E': return 4;
            case 'F': return 5;
            default: cout<<"Tidak Valid"; return -1;
        }
    }

    char intchar(int x){//convert data int ke char
        switch(x){
            case 0: return 'A';
            case 1: return 'B';
            case 2: return 'C';
            case 3: return 'D';
            case 4: return 'E';
            case 5: return 'F';
            default: cout<<"Tidak Valid"; return '?';
        }
    }

    bool adjvalid(int location, int check){//mengecek apakah node graph terhubung
        return graph[location][check] != 0;
    }

    void dfsall(vector<bool>& visited, int vertexnow, int& visitedCount){ //fungsi dfs semua lokasi
        visited[vertexnow] = true;//track lokasi yang dilalui
        visitedCount++;//track berapa yang sudah dilalui
        cout << intchar(vertexnow);
        if (visitedCount < MAX) cout << " -> ";

        if (visitedCount == MAX) return;//jika semua sudah dilalui

        while (true) {
            int minWeight = 9999;//pengganti weight terbesar
            int next = -1;

            for (int i = 0; i < MAX; i++) {
                if (adjvalid(vertexnow, i) && !visited[i]) {//cek apakah valid dan apakah sudah dilalui
                    if (weight[vertexnow][i] > 0 && weight[vertexnow][i] < minWeight){//pengecekan weight terkecil
                        minWeight = weight[vertexnow][i];
                        next = i;//menentukan lokasi yang dilalui selanjutnya
                    }
                }
            }

            if (next == -1) {//jika tidak ada yang bisa dilalui
                break;
            }

            journey += minWeight;//track sejauh apa perjalanan yang ditempuh
            dfsall(visited, next, visitedCount);//rekursif
            if (visitedCount == MAX) return;//jika semua sudah dilalui
        }
    }

    void dfs(char start){ //fungsu start dfs
        vector<bool> visited(MAX, false);//deklarasi vector boolean untuk tracking lokasi yang sudah dilalui
        int visitedCount = 0;//berapa lokasi yang sudah dilalui
        cout << "PENJELAJAHAN PARUL (DFS dari "<<start<<"):\n";
        dfsall(visited, charint(start), visitedCount);//panggil fungsi dfsall
        cout << "\nTotal weight = " << journey <<" meter\n\n";
    }


    void bfs(char startChar, char goalChar){//fungsi bfs
        //konversi char ke int
        int start = charint(startChar);//identifikasi lokasi awal
        int goal = charint(goalChar);//identifikasi lokasi tujuan
        int edge=0;//track total langkah
        vector<bool> visited(MAX, false);//track sudah dilewati
        vector<int> parent(MAX, -1);//
        queue<int> q;//queue int
        visited[start] = true;
        q.push(start);//lokasi awal masuk ke queue

        bool found = false; //boolean jika lokasi tujuan ditemukan

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == goal) {
                found = true;
                break;
            }

            vector<pair<int,int>> neighbors;//track adjacency current
            for (int i=0; i<MAX; i++) {
                if (graph[current][i] == 1 && !visited[i]) {
                    neighbors.push_back({weight[current][i], i});//masukkan ke neighbors
                }
            }

            while (!neighbors.empty()) {//jika current memiliki adjacency yang valid
                int minIndex = 0;
                for (int i=1; i<neighbors.size(); i++) {
                    if (neighbors[i].first < neighbors[minIndex].first) {
                        minIndex = i;//pilih berdasarkan weight terkecil, lalu masukkan lokasi ke minIndex
                    }
                }

                int next = neighbors[minIndex].second;//shift ke index selanjutnya 
                neighbors.erase(neighbors.begin() + minIndex);//hapus yang sudah dilewati

                visited[next] = true; //track sudah dilewati
                parent[next] = current; 
                q.push(next);//next masuk ke queue
            }
        }

        if (!found) {//jika lokasi tujuan ditemukan
            cout << "Goal " << goalChar << " not found from " << startChar << endl;
            return;
        }

        cout << "Jalur Terpendek: \n";//tampilkan perjalanan
        vector<int> path;
        int current = goal;
        while (current != -1) {
            path.insert(path.begin(), current);
            current = parent[current];
        }

        cout <<daftar[start]<<"("<<intchar(path[0])<<")"<< endl;
        for (int i = 0; i < path.size(); i++) {
            if (i > 0) {
            cout<<weight[path[i]][path[i-1]]<<"m"<< endl;
            cout <<daftar[path[i]]<<"("<<intchar(path[i])<<")"<< endl;
            }
        }


        int totalWeight = 0;
        for (int i=0; i<path.size(); i++) {
            cout << intchar(path[i]);
            if (i < path.size()-1) {
                cout << " -> ";
                edge++;
                totalWeight += weight[path[i]][path[i+1]];
            }
        }
        cout<<"\nTotal langkah: "<<edge<<" edge";
        cout << "\nTotal jarak: " << totalWeight <<" meter"<< endl;
    }
    
};
int main() {
    system("cls");
    Graph g;
    string x,y;
    cin>>x;
    g.dfs(x);
    g.bfs('A','E');
}
