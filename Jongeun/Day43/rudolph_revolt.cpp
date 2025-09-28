#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>

#define MaxSanta 30

using namespace std;

int rdx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int rdy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int sdx[] = {-1, 0, 1, 0}; // north, east, south, west
int sdy[] = {0, 1, 0, -1};

class Santa
{
public:
    Santa(int id, int row, int col, bool dead) : m_id(id), r(row), c(col), isDead(false) {}

    int addScore(int num)
    {
        score += num;
        return score;
    }

    void makeShock(int turn)
    {
        shock = turn;
    }

    void makeDead()
    {
        isDead = true;
    }

    int score{0};
    int r;
    int c;
    bool isDead{true};
    int shock{0};
    int m_id;
};

class Rudolph
{

public:
    Rudolph(int row, int col) : r(row), c(col) {}
    int r;
    int c;
};

class Board
{
    // return all function earlier if game is End
    //  TODO 4. collideCheck function
    //  TODO 6. SantasTurn function
    //  TODO 7. floodEffect
    //  santa 죽이고 죽일때 보드에서 id 도 지워, game end 하는 것 까지

public:
    Board(int n, Rudolph r, int rPower, int sPower, int alive) : N(n), r1(r), rudolPower(rPower), santaPower(sPower), board(N + 1, vector<int>(N + 1, 0)), numAlive(alive)
    {
        santas.resize(MaxSanta + 1);
        board[r1.r][r1.c] = -1; //-1 denote the rudolph
    }

    void createSanta(int id, int r, int c)
    {
        santas[id] = Santa{id, r, c, false};
        board[r][c] = id;
    }

    void endGame()
    {
        gameEnd = true;
    }

    void releaseShock()
    {
        if (gameEnd)
        {
            return;
        }

        for (int i = 0; i < MaxSanta + 1; i++)
        {
            if (!santas[i].isDead && santa[i].shock > 0)
            {
                if (turn - santa[i].shock >= 2)
                {
                    santa[i].shock = 0;
                }
            }
        }
    }

    void addLivingScore()
    {
        if (gameEnd)
        {
            return;
        }

        for (int i = 0; i < MaxSanta + 1; i++)
        {
            if (!santas[i].isDead)
            {
                santas[i].addScore(1);
            }
        }
    }

    int getDistance(int r1, int c1, int r2, int c2)
    {
        return (r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2);
    }

    bool isValidRange(int r, int c)
    {
        return (r >= 1 && r <= N && c >= 1 && c <= N);
    }

    void moveDolph()
    {
        if (gameEnd)
        {
            return;
        }

        // calculate minimum distance santa
        vector<tuple<int, int, int, int>> temp; //  distance, -santaRow, -santaCol, id

        for (int i = 0; i < MaxSanta + 1; i++)
        {
            if (!santas[i].isDead)
            {
                int distance = getDistance(r1.r, r1.c, santas[i].r, santas[i].c);
                temp.push_back({distance, -santas[i].r, -santas[i].c, santas[i].m_id});
            }
        }

        sort(temp);
        int id = get<3>(temp[0]);

        int minDistance = INT_MAX;
        int minR = r1.r;
        int minC = r1.c;
        int dir;

        // calculate the minmum direction and r, c
        for (int i = 0; i < rdx.size(); i++)
        {
            int nextR = r1.r + rdx[0];
            int nextC = r1.c + rdy[0];

            if (isValidRange(nextR, nextC) && getDistance(nextR, nextC, santas[id].r, santas[id].c) < minDistance)
            {
                minDistance = getDistance(nextR, nextC, santas[id].r, santas[id].c);
                minR = nextR;
                minC = nextC;
                dir = i;
            }
        }

        // reset the rudolph's orinal position
        board[r1.r][r1.c] = 0;

        r1.r = minR;
        r1.c = minC;

        // collideCheck
        collideCheck(dir, nullptr);

        // denote the rudolph's position int the board
        board[minR][minC] = -1;
    }

    void santaTurn()
    {
        if (gameEnd)
        {
            return;
        }

        for (int i = 0; i < MaxSanta + 1; i++)
        {
            vector<tuple<int, int, int, int>> temp; // distance , direction, nextR, nextC

            if (!santas[i].isDead)
            {
                Santa old = santas[i]; // copy assignment
                int curDistance = getDistance(r1.r, r1.c, old.r, old.c);

                for (int j = 0; j < sdx.size(); j++)
                {
                    int nextR = old.r + sdx[j];
                    int nextC = old.c + sdx[j];
                    int distance = getDistance(nextR, nextC, r1.r, r1.c);

                    if (isValidRange(nextR, nextC) && (!board[nextR][nextC] || board[nextR][nextC] == -1) && distance < curDistance)
                    {
                        temp.push_back(distance, j, nextR, nextC);
                    }
                }

                sort(temp.begin(), temp.end());
                if (!temp.empty())
                { // move the santa
                    int nextR, nextC;
                    int dir;
                    tie(ignore, dir, nextR, nextC) = temp[0];
                    collideCheck(dir, &santas[i]);
                    // reset original position
                    board[old.r][old.c] = 0;
                }
            }
        }
    }

    void collideCheck(int direction, Santa *santa)
    {
        if (gameEnd)
        {
            return;
        }

        if (santa == nullptr && !board[r1.r][r1.c])
        { // rudolph move and collide santa

            santa = &santas[board[r1.r][r1.c]];
            santa->makeShock(turn);
            santa->addScore(rudolPower);
            int nextR = santa->r + rudolPower * rdx[direction];
            int nextC = santa->c + rudolPower * rdy[direction];

            if (isValidRange(nextR, nextC))
            { // floodEffect and set the santa's position in the board

                if (!board[nextR][nextC])
                {
                    // TODO implement the floodEffect
                    floodEffect();
                }
                board[nextR][nextC] = santa->m_id;
            }
            else
            { // kill the santa , check the isGameEnded
                santa->makeDead();
                numAlive--;
                if (numAlive == 0)
                {
                    endGame();
                }
            }
        }
        else
        {
            // santa move
                }
    }

    int N;
    vector<vector<int>> board;
    Rudolph r1;
    vector<Santa> santas;
    int rudolPower{};
    int santaPower{};
    bool gameEnd{false};
    int numAlive;
    int turn{1};
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, P, C, D;
    cin >> N >> M >> P >> C >> D;
    int Rr, Rc;
    cin >> Rr >> Rc;
    Rudolph r{Rr, Rc};
    Board b(N, r, C, D, P);

    int Pn, Sr, Sc;
    for (int i = 0; i < P; i++)
    {
        cin >> Pn >> Sr >> Sc;
        b.createSanta(Pn, Sr, Sc);
    }

    // game Start for M turn
    int i = 0;
    while (b.turn <= M && !b.gameEnd)
    {
        b.releaseShock();
        b.moveDolph();
        b.santaTurn();
        b.addLivingScore();
        b.turn += 1;
    }

    return 0;
}
