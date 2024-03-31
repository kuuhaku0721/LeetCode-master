#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Team {
    Team(int id1, int id2, int id3, int tid, pair<int, int> xy) {
        player1 = id1;
        player2 = id2;
        player3 = id3;
        teamId = tid;
        pos = xy;
    }
    int teamId;
    int player1;
    int player2;
    int player3;
    pair<int, int> pos;
};

struct PLAYER 
{
    PLAYER(int pid, pair<int, int> xy, int tid)
    {
        id = pid;
        pos = xy;
        down = false;
        teamid = tid;
        cnt = 0;
        ghost = false;
        flower = true;
    }
    int id;             // 玩家id
    int teamid;         // 所在队伍id
    bool down;          // 是否倒地
    pair<int, int> pos; // 当前位置
    int cnt;            // 暗域累计值
    bool ghost;         // 是否为幽灵状态
    bool flower;        // 是否具有还魂花
};

class Solution 
{
public:
    void Hard() 
    {
        // 队伍数量
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) 
        {
            int id1, id2, id3, tid, x, y;
            cin >> id1 >> id2 >> id3 >> tid >> x >> y;
            Team team(id1, id2, id3, tid, make_pair(x, y));
            m_players[id1] = PLAYER(id1, make_pair(x, y), tid);
            m_players[id2] = PLAYER(id2, make_pair(x, y), tid);
            m_players[id3] = PLAYER(id3, make_pair(x, y), tid);
            m_mp[tid] = team;
        }
        // 事件数量
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string cmd;
            cin >> cmd;
            if (cmd == "KO") {
                int idA, idB;
                cin >> idA >> idB;  // id为A的玩家击倒了B
                // 玩家B被击倒
                (*m_players.find(idB)).second.down = true;

                ShowStatus();
            }
            else if (cmd == "UP") {
                int idA, idB;
                cin >> idA >> idB;  // id为A的玩家拉起了B
                // 玩家B又活了
                (*m_players.find(idB)).second.down = false;
            }
            else if (cmd == "Respawn") {
                int id, x, y;
                cin >> id >> x >> y; // id玩家移动到了坐标xy并在此处复活
                // 玩家活了并且移动到了xy
                auto it = m_players.find(id);
                it->second.down = false;
                it->second.pos.first = x;
                it->second.pos.second = y;
            }
            else if (cmd == "Move") {
                int id, x, y;
                cin >> id >> x >> y; // id玩家移动到了坐标xy
                // 玩家移动到了xy
                auto it = m_players.find(id);
                it->second.pos.first = x;
                it->second.pos.second = y;
            }
            else if (cmd == "Shrink") {
                // 暗域事件，缩小一圈
                
                areaLU.first++; areaLU.second++;
                areaRU.first++; areaRU.second--;
                areaLD.first--; areaLD.second++;
                areaRD.first--; areaRD.second--;
                /*
                 1.  若此时暗域未覆盖的区域大小为16 x 16，剥夺所有仍有返魂花角色的返魂花，此时所有幽灵状态角色倒地。

                 2.  在暗域内的存活玩家，累计暗域值+1。

                 3.  暗域值为2的存活玩家立刻触发倒地。

                 4.  暗域从四周向内缩小一圈（下面是暗域向内缩小一圈的示意图）
                */
            }
            else if (cmd == "Quit") {
                int teamID;
                cin >> teamID;  // id为teamID的队伍退出游戏
                // 找到队伍，然后把队伍里三个玩家状态全变为down
                auto Team = m_mp.find(teamID)->second;
                m_players.find(Team.player1)->second.down = true;
                m_players.find(Team.player2)->second.down = true;
                m_players.find(Team.player3)->second.down = true;
                
                m_players.erase(Team.player1);
                m_players.erase(Team.player2);
                m_players.erase(Team.player3);
                m_mp.erase(teamID);

                ShowStatus();
            }
        }
    }

    void ShowStatus()
    {
        /*
        若事件发生时有角色倒地，输出：
        Fall A B C D E ......（ABCDE为倒地角色，按id升序输出，空格分隔，行尾空格不计）

        然后，若事件发生时有队伍淘汰，输出：
        Exit A B C D E .....（ABCDE为淘汰队伍，按id升序输出，空格分隔 行尾空格不计）

        然后，输出：
        A B（A为存在角色数（不计幽灵状态角色）B为未淘汰队伍数量）

        所有事件结束后若游戏结束，输出一行：
        Winner ID
        ID为胜利小队ID
        */
    }

private:
    map<int, Team> m_mp;
    map<int, PLAYER> m_players;
    // 暗域 30*30
    pair<int, int> areaLU{0, 0};    // 左上
    pair<int, int> areaRU{0, 29};   // 右上
    pair<int, int> areaLD{29, 0};   // 左下
    pair<int, int> areaRD{29, 29};  // 右下
};

int main() 
{
    Solution().Hard();
}
// 64 位输出请用 printf("%lld")