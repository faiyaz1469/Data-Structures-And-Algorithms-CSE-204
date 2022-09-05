#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>
#include <queue>
using namespace std;

template<typename T>
class LineParser
{
private:

    string str;
    char delim;
    vector<T> output;

public:
    LineParser()
    {
        // pass
    }

    LineParser(string line, char delimeter)
    {
        str = line;
        delim = delimeter;
    }

    vector<T> parseLineToInteger()
    {
        stringstream ss(str);
        string token;
        int num;

        while(getline(ss, token, delim))
        {
            num = stoi(token);
            output.push_back(num);
        }
        return output;
    }

};

// An entry in queue used in BFS
struct queueEntry
{
    int v;     // Vertex number
    int dist;  // Distance of this vertex from source
};

int reachable (int move[], int X, int n){

    bool *visited = new bool[X+1];
    for (int i = 1; i <= X; i++)
        visited[i] = false;

    queue <queueEntry> q;

    visited[1] = true;
    queueEntry s = {1, 0};  // distance of 1st vertex is also 0
    q.push(s);  // Enqueue 1st vertex

    // Do a BFS starting from vertex at index 1
    queueEntry qe;  // A queue entry (qe)
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v;
        q.pop();
        for (int j=v+1; j<=(v+n) && j<=X; ++j)
        {
            // If this cell is already visited, then ignore
            if (!visited[j])
            {
                // Otherwise calculate its distance and mark it
                // as visited
                queueEntry a;
                visited[j] = true;

                if (move[j] != -1){
                    int n = move[j];
                    a.v = n;
                }

                else{
                    a.v = j;
                }
                q.push(a);
            }
        }
    }

            int count = 0;
            for (int i = 1; i <= X; i++){
                if (visited[i] == false){
                    cout<<i<<" ";
                    count++;
                }
            }

            return count;
}

void getMinDiceThrows(int move[], int X, int n)
{

    vector<int>numbers;
    bool *visited = new bool[X+1];
    for (int i = 1; i <= X; i++)
        visited[i] = false;

    // Create a queue for BFS
    queue <queueEntry> q;

    // Mark the node 1 as visited and enqueue it.
    visited[1] = true;
    queueEntry s = {1, 0};  // distance of 1st vertex is also 0
    q.push(s);  // Enqueue 1st vertex

    int E[n+1];
    int p = 1;
    int totalMax = 0;

    // Do a BFS starting from vertex at index 1
    queueEntry qe;  // A queue entry (qe)
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v; // vertex no. of queue entry

        // If front vertex is the destination vertex,
        // we are done
        if (v == X){
            break;
        }

         // Otherwise dequeue the front vertex and enqueue
        // its adjacent vertices (or cell numbers reachable
        // through a die throw)
        q.pop();
        for (int j=v+1; j<=(v+n) && j<=X; ++j)
        {
            // If this cell is already visited, then ignore
            if (!visited[j])
            {
                // Otherwise calculate its distance and mark it
                // as visited
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;

                // Check if there a snake or ladder at 'j'
                // then tail of snake or top of ladder
                // become the adjacent of 'i'
                if (move[j] != -1){

                    int n = move[j];
                    a.v = n;
                    E[p]= n;
                    p++;
                }

                else{
                    a.v = j;
                    E[p]=j;
                    p++;
                }
                q.push(a);
            }
        }
        int max = E[1];
        for ( int i = 2; i<=n; i++){
            if (E[i] > max)
                max = E[i];
            else if ( E[i] < max)
                max = max;
        }

        if ( max >= totalMax + n  ){
            totalMax = max;
            numbers.push_back(totalMax);
        }
        p = 1;
    }

    if(visited[X] == false){

            qe.dist = -1;
            cout << "Min Dice throws required is " <<qe.dist<<endl;
            cout<<"No solution"<<endl;
            reachable(move,X,n);
    }
    else{
        cout << "Min Dice throws required is " <<qe.dist<<endl;
        cout<<"1 -> ";
        for(int i=0; i<numbers.size(); i++){
            for (int j = 1; j<=X; j++){
                if( numbers[i] == move[j]){
                    if(visited[j]==true && move[j] > j)
                       cout<< j <<" -> ";
                }
            }
             if ( i < numbers.size() - 1 && numbers[i] != X){
                cout<< numbers[i] <<" -> ";
             }
             else if (numbers[numbers.size()-1] == X-1){
                cout<<X-1<<" -> "<<X<<endl;

             }
             else{
                cout<<X<<endl;

             }
        }

         if (reachable(move,X,n) == 0){
             cout<<"All reachable"<<endl;
         }
         else{
            cout<<endl;
         }
    }
}



// Driver program to test methods of graph class
int main()
{

    fstream fin;
    fstream fs;
    string text;
    fs.open("output.txt", ios::out);

    // Make a backup of stream buffer
    streambuf* sb_cout = cout.rdbuf();
    streambuf* sb_cin = cin.rdbuf();
    // Get the file stream buffer
    streambuf* sb_file = fs.rdbuf();
    // Now cout will point to file
    cout.rdbuf(sb_file);

    fin.open("input2.txt", ios::in);
    getline(fin, text);
    int test_cases = atoi(text.c_str());
    int m = 0;
    while(test_cases > 0)
    {
      m++;
      cout<<"Test case: "<<m<<endl;
      getline(fin, text);
      LineParser<int> parser(text, ' ');
      auto words = parser.parseLineToInteger();
       int n = words[0];
       int N = words[1];

      if(n>1 && n<=16 && N>1 && N<=10000 ){

          int moves[N+1];
          for (int i = 1; i<=N; i++)
            moves[i] = -1;

          getline(fin, text);
          LineParser<int> parser2(text, ' ');
          auto words2 = parser2.parseLineToInteger();
          int ladders = words2[0];
          for ( int i = ladders; i>0; i--){
                 getline(fin, text);
                 LineParser<int> parser(text, ' ');
                 auto words = parser.parseLineToInteger();
                 moves[words[0]] = words[1];

          }

          getline(fin, text);
          LineParser<int> parser3(text, ' ');
          auto words3 = parser3.parseLineToInteger();
          int snakes = words3[0];
          for ( int i = snakes; i>0; i--){
             getline(fin, text);
             LineParser<int> parser(text, ' ');
             auto words = parser.parseLineToInteger();
              moves[words[0]] = words[1];

          }

          getMinDiceThrows(moves, N, n);
      }
      else{
           cout<<"Invalid input"<<endl;
           int moves[10001];
           for (int i = 1; i<=N; i++)
              moves[i] = -1;

          getline(fin, text);
          LineParser<int> parser2(text, ' ');
          auto words2 = parser2.parseLineToInteger();
          int ladders = words2[0];
          for ( int i = ladders; i>0; i--){
                 getline(fin, text);
                 LineParser<int> parser(text, ' ');
                 auto words = parser.parseLineToInteger();
                 moves[words[0]] = words[1];

          }

          getline(fin, text);
          LineParser<int> parser3(text, ' ');
          auto words3 = parser3.parseLineToInteger();
          int snakes = words3[0];
          for ( int i = snakes; i>0; i--){
             getline(fin, text);
             LineParser<int> parser(text, ' ');
             auto words = parser.parseLineToInteger();
              moves[words[0]] = words[1];

          }
      }

      test_cases--;

    }

    fin.close();
    fs.close();

    return 0;
}
